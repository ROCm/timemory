#
#
# Builds libunwind at the CMake build stage (via ExternalProject_Add).
#
#

include(ExternalProject)

# finds an executable and fails if not found
macro(timemory_libunwind_find_exe VAR MSG)
    find_program(${VAR} NAMES ${ARGN})
    mark_as_advanced(${VAR})

    if(NOT ${VAR})
        message(FATAL_ERROR "Building libunwind submodule requires ${MSG}")
    endif()
endmacro()

timemory_libunwind_find_exe(AUTORECONF_EXE "autoreconf" autoreconf)
timemory_libunwind_find_exe(MAKE_EXE "make / gmake" make gmake)

find_program(CHRPATH_EXECUTABLE chrpath)
find_program(PATCHELF_EXECUTABLE patchelf)
mark_as_advanced(CHRPATH_EXECUTABLE PATCHELF_EXECUTABLE)

# -----------------------------------------------------------------------------
# Paths
# -----------------------------------------------------------------------------
set(_libunwind_src ${PROJECT_SOURCE_DIR}/external/libunwind)
set(_libunwind_work ${PROJECT_BINARY_DIR}/external/libunwind)
set(_libunwind_build ${_libunwind_work}/source)
set(_libunwind_install ${_libunwind_work}/install)
set(_libunwind_libdir ${_libunwind_install}/lib)
set(_libunwind_incdir ${_libunwind_install}/include)
set(_libunwind_lib
    ${_libunwind_libdir}/libunwind${CMAKE_SHARED_LIBRARY_SUFFIX}
)

# -----------------------------------------------------------------------------
# Helper scripts written once at configure time, executed at build time.
# -----------------------------------------------------------------------------

# Patch step: rewrite SOVERSION in src/Makefile.am to avoid clashing with the
# system libunwind. Operates on the ExternalProject working copy, never on the
# submodule source.
set(_libunwind_patch_script ${_libunwind_work}/_patch_soversion.cmake)
file(
    WRITE ${_libunwind_patch_script}
    [=[
file(READ "${SRC}/src/Makefile.am" _content)
string(REGEX REPLACE
    "SOVERSION=([0-9]+):([0-9]+):([0-9]+)" "SOVERSION=99:0:0"
    _content "${_content}")
file(WRITE "${SRC}/src/Makefile.am" "${_content}")
]=]
)

# Post-install step: strip and rewrite RPATH on every installed shared object.
set(_libunwind_postinstall_script ${_libunwind_work}/_postinstall.cmake)
file(
    WRITE ${_libunwind_postinstall_script}
    [=[
file(GLOB _libs "${LIBDIR}/*")
foreach(_lib ${_libs})
    if(IS_DIRECTORY "${_lib}")
        continue()
    endif()
    if("${_lib}" MATCHES "\\.so($|\\.)")
        execute_process(COMMAND "${STRIP}" "${_lib}")
        if(CHRPATH)
            execute_process(COMMAND "${CHRPATH}" -r "$ORIGIN" "${_lib}")
        elseif(PATCHELF)
            execute_process(COMMAND "${PATCHELF}" --set-rpath "$ORIGIN" "${_lib}")
        else()
            message(WARNING
                "Neither chrpath nor patchelf available; skipping rpath fix for ${_lib}")
        endif()
    endif()
endforeach()
]=]
)

# -----------------------------------------------------------------------------
# ExternalProject_Add: download (copy from submodule), patch, configure, build,
# install. All steps run at build time.
# -----------------------------------------------------------------------------
ExternalProject_Add(
    build-timemory-libunwind
    PREFIX ${_libunwind_work}
    SOURCE_DIR ${_libunwind_build}
    BUILD_IN_SOURCE 1
    DOWNLOAD_COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${_libunwind_src} ${_libunwind_build}
    UPDATE_COMMAND ""
    PATCH_COMMAND
        ${CMAKE_COMMAND} -DSRC=${_libunwind_build} -P ${_libunwind_patch_script}
    CONFIGURE_COMMAND
        ${AUTORECONF_EXE} -i
    COMMAND
        ${CMAKE_COMMAND} -E env CC=${CMAKE_C_COMPILER}
        CFLAGS=-fPIC\ -O3\ -Wno-unused-result\ -Wno-unused-but-set-variable\ -Wno-cpp
        CXX=${CMAKE_CXX_COMPILER}
        CXXFLAGS=-fPIC\ -O3\ -Wno-unused-result\ -Wno-unused-but-set-variable\ -Wno-cpp
        ./configure --enable-shared=yes --enable-static=no
        --prefix=${_libunwind_install} --libdir=${_libunwind_libdir}
    BUILD_COMMAND ${MAKE_EXE}
    INSTALL_COMMAND ${MAKE_EXE} install
    COMMAND
        ${CMAKE_COMMAND} -DLIBDIR=${_libunwind_libdir} -DSTRIP=${CMAKE_STRIP}
        -DCHRPATH=${CHRPATH_EXECUTABLE} -DPATCHELF=${PATCHELF_EXECUTABLE} -P
        ${_libunwind_postinstall_script}
    BUILD_BYPRODUCTS ${_libunwind_lib}
    LOG_DOWNLOAD ON
    LOG_PATCH ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    LOG_INSTALL ON
)

# -----------------------------------------------------------------------------
# Install rules. Evaluated at `cmake --install` time, so they pick up whatever
# the build step produced.
# -----------------------------------------------------------------------------
if(TIMEMORY_INSTALL_HEADERS)
    install(
        DIRECTORY ${_libunwind_incdir}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/timemory/libunwind
        FILES_MATCHING
        PATTERN "*.h"
    )
endif()

install(
    DIRECTORY ${_libunwind_libdir}/
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/timemory/libunwind
    FILES_MATCHING
    PATTERN "*${CMAKE_SHARED_LIBRARY_SUFFIX}*"
    PATTERN "pkgconfig" EXCLUDE
)

install(
    DIRECTORY ${_libunwind_libdir}/pkgconfig
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/timemory/libunwind
    OPTIONAL
)

# -----------------------------------------------------------------------------
# Interface target wiring. The generator-expression paths are resolved at
# compile/link time, so the underlying files don't need to exist at configure.
# The add_dependencies() edge ensures the ExternalProject runs before any
# consumer of timemory-libunwind is compiled or linked.
# -----------------------------------------------------------------------------
add_dependencies(timemory-libunwind build-timemory-libunwind)

# Add include directories with BEFORE to ensure they come first in include search path
# This ensures GNU libunwind headers are found before LLVM libunwind headers
target_include_directories(
    timemory-libunwind BEFORE
    INTERFACE $<BUILD_INTERFACE:${_libunwind_incdir}>
              $<INSTALL_INTERFACE:include/timemory/libunwind>
)
target_link_directories(
    timemory-libunwind
    INTERFACE
    $<BUILD_INTERFACE:${_libunwind_libdir}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_LIBDIR}/timemory/libunwind>
)
target_link_libraries(
    timemory-libunwind
    INTERFACE
        $<BUILD_INTERFACE:${_libunwind_lib}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/timemory/libunwind/libunwind${CMAKE_SHARED_LIBRARY_SUFFIX}>
)
timemory_target_compile_definitions(
    timemory-libunwind
    INTERFACE TIMEMORY_USE_LIBUNWIND UNW_LOCAL_ONLY
)
