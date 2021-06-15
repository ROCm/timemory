// MIT License
//
// Copyright (c) 2020, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to receipt of any
// required approvals from the U.S. Dept. of Energy).  All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/** \file timemory/enum.h
 * \headerfile timemory/enum.h "timemory/enum.h"
 * This provides the core enumeration for components
 *
 */

#pragma once

#include "timemory/compat/macros.h"

//======================================================================================//
//
//      Enumeration
//
//======================================================================================//
//
/// \macro TIMEMORY_USER_COMPONENT_ENUM
/// \brief Extra enumerated components provided by a downstream application. If this
/// macro is used, be sure to end the list with a comma
///
/// \code{.cpp}
/// #define TIMEMORY_USER_COMPONENT_ENUM MY_COMPONENT,
/// \endcode
//
#if !defined(TIMEMORY_USER_COMPONENT_ENUM)
#    define TIMEMORY_USER_COMPONENT_ENUM
#endif

/// \enum TIMEMORY_USER_COMPONENT_ENUM_SIZE
/// \brief Macro specifying how many user component enumerations are provided
#if !defined(TIMEMORY_USER_COMPONENT_ENUM_SIZE)
#    define TIMEMORY_USER_COMPONENT_ENUM_SIZE 16
#endif
//
/// \enum TIMEMORY_NATIVE_COMPONENT
/// \brief Enumerated identifiers for timemory-provided components.
//
enum TIMEMORY_NATIVE_COMPONENT
{
    TIMEMORY_ALLINEA_MAP_idx = 0,
    TIMEMORY_CALIPER_MARKER_idx,
    TIMEMORY_CALIPER_CONFIG_idx,
    TIMEMORY_CALIPER_LOOP_MARKER_idx,
    TIMEMORY_CPU_CLOCK_idx,
    TIMEMORY_CPU_ROOFLINE_DP_FLOPS_idx,
    TIMEMORY_CPU_ROOFLINE_FLOPS_idx,
    TIMEMORY_CPU_ROOFLINE_SP_FLOPS_idx,
    TIMEMORY_CPU_UTIL_idx,
    TIMEMORY_CRAYPAT_COUNTERS_idx,
    TIMEMORY_CRAYPAT_FLUSH_BUFFER_idx,
    TIMEMORY_CRAYPAT_HEAP_STATS_idx,
    TIMEMORY_CRAYPAT_RECORD_idx,
    TIMEMORY_CRAYPAT_REGION_idx,
    TIMEMORY_CUDA_EVENT_idx,
    TIMEMORY_CUDA_PROFILER_idx,
    TIMEMORY_CUPTI_ACTIVITY_idx,
    TIMEMORY_CUPTI_COUNTERS_idx,
    TIMEMORY_CUPTI_PCSAMPLING_idx,
    TIMEMORY_CURRENT_PEAK_RSS_idx,
    TIMEMORY_DATA_TRACKER_INTEGER_idx,
    TIMEMORY_DATA_TRACKER_UNSIGNED_idx,
    TIMEMORY_DATA_TRACKER_FLOATING_idx,
    TIMEMORY_GPERFTOOLS_CPU_PROFILER_idx,
    TIMEMORY_GPERFTOOLS_HEAP_PROFILER_idx,
    TIMEMORY_GPU_ROOFLINE_DP_FLOPS_idx,
    TIMEMORY_GPU_ROOFLINE_FLOPS_idx,
    TIMEMORY_GPU_ROOFLINE_HP_FLOPS_idx,
    TIMEMORY_GPU_ROOFLINE_SP_FLOPS_idx,
    TIMEMORY_KERNEL_MODE_TIME_idx,
    TIMEMORY_LIKWID_MARKER_idx,
    TIMEMORY_LIKWID_NVMARKER_idx,
    TIMEMORY_MALLOC_GOTCHA_idx,
    TIMEMORY_MEMORY_ALLOCATIONS_idx,
    TIMEMORY_MONOTONIC_CLOCK_idx,
    TIMEMORY_MONOTONIC_RAW_CLOCK_idx,
    TIMEMORY_NETWORK_STATS_idx,
    TIMEMORY_NUM_IO_IN_idx,
    TIMEMORY_NUM_IO_OUT_idx,
    TIMEMORY_NUM_MAJOR_PAGE_FAULTS_idx,
    TIMEMORY_NUM_MINOR_PAGE_FAULTS_idx,
    TIMEMORY_NVTX_MARKER_idx,
    TIMEMORY_OMPT_HANDLE_idx,
    TIMEMORY_PAGE_RSS_idx,
    TIMEMORY_PAPI_ARRAY_idx,
    TIMEMORY_PAPI_VECTOR_idx,
    TIMEMORY_PEAK_RSS_idx,
    TIMEMORY_PRIORITY_CONTEXT_SWITCH_idx,
    TIMEMORY_PROCESS_CPU_CLOCK_idx,
    TIMEMORY_PROCESS_CPU_UTIL_idx,
    TIMEMORY_READ_BYTES_idx,
    TIMEMORY_READ_CHAR_idx,
    TIMEMORY_SYS_CLOCK_idx,
    TIMEMORY_TAU_MARKER_idx,
    TIMEMORY_THREAD_CPU_CLOCK_idx,
    TIMEMORY_THREAD_CPU_UTIL_idx,
    TIMEMORY_TRIP_COUNT_idx,
    TIMEMORY_USER_CLOCK_idx,
    TIMEMORY_USER_MODE_TIME_idx,
    TIMEMORY_USER_GLOBAL_BUNDLE_idx,
    TIMEMORY_USER_KOKKOSP_BUNDLE_idx,   // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_LIST_BUNDLE_idx,      // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_MPIP_BUNDLE_idx,      // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_NCCLP_BUNDLE_idx,     // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_OMPT_BUNDLE_idx,      // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_TUPLE_BUNDLE_idx,     // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_PROFILER_BUNDLE_idx,  // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_USER_TRACE_BUNDLE_idx,     // excluded from TIMEMORY_COMPONENT_TYPES
    TIMEMORY_VIRTUAL_MEMORY_idx,
    TIMEMORY_VOLUNTARY_CONTEXT_SWITCH_idx,
    TIMEMORY_VTUNE_EVENT_idx,
    TIMEMORY_VTUNE_FRAME_idx,
    TIMEMORY_VTUNE_PROFILER_idx,
    TIMEMORY_WALL_CLOCK_idx,
    TIMEMORY_WRITTEN_BYTES_idx,
    TIMEMORY_WRITTEN_CHAR_idx,
    TIMEMORY_NATIVE_COMPONENTS_END_idx,
    TIMEMORY_USER_COMPONENT_ENUM TIMEMORY_COMPONENTS_END_idx =
        (TIMEMORY_NATIVE_COMPONENTS_END_idx + TIMEMORY_USER_COMPONENT_ENUM_SIZE)
};
//
#if !defined(TIMEMORY_NATIVE_COMPONENTS_END)
#    define TIMEMORY_NATIVE_COMPONENTS_END TIMEMORY_NATIVE_COMPONENTS_END_idx
#endif
//
#if !defined(TIMEMORY_COMPONENTS_END)
#    define TIMEMORY_COMPONENTS_END TIMEMORY_COMPONENTS_END_idx
#endif
//
//  backwards compatibility
//
#if !defined(ALLINEA_MAP)
#    define ALLINEA_MAP TIMEMORY_ALLINEA_MAP_idx
#endif
#if !defined(CALIPER_MARKER)
#    define CALIPER_MARKER TIMEMORY_CALIPER_MARKER_idx
#endif
#if !defined(CALIPER_CONFIG)
#    define CALIPER_CONFIG TIMEMORY_CALIPER_CONFIG_idx
#endif
#if !defined(CALIPER_LOOP_MARKER)
#    define CALIPER_LOOP_MARKER TIMEMORY_CALIPER_LOOP_MARKER_idx
#endif
#if !defined(CPU_CLOCK)
#    define CPU_CLOCK TIMEMORY_CPU_CLOCK_idx
#endif
#if !defined(CPU_ROOFLINE_DP_FLOPS)
#    define CPU_ROOFLINE_DP_FLOPS TIMEMORY_CPU_ROOFLINE_DP_FLOPS_idx
#endif
#if !defined(CPU_ROOFLINE_FLOPS)
#    define CPU_ROOFLINE_FLOPS TIMEMORY_CPU_ROOFLINE_FLOPS_idx
#endif
#if !defined(CPU_ROOFLINE_SP_FLOPS)
#    define CPU_ROOFLINE_SP_FLOPS TIMEMORY_CPU_ROOFLINE_SP_FLOPS_idx
#endif
#if !defined(CPU_UTIL)
#    define CPU_UTIL TIMEMORY_CPU_UTIL_idx
#endif
#if !defined(CRAYPAT_COUNTERS)
#    define CRAYPAT_COUNTERS TIMEMORY_CRAYPAT_COUNTERS_idx
#endif
#if !defined(CRAYPAT_FLUSH_BUFFER)
#    define CRAYPAT_FLUSH_BUFFER TIMEMORY_CRAYPAT_FLUSH_BUFFER_idx
#endif
#if !defined(CRAYPAT_HEAP_STATS)
#    define CRAYPAT_HEAP_STATS TIMEMORY_CRAYPAT_HEAP_STATS_idx
#endif
#if !defined(CRAYPAT_RECORD)
#    define CRAYPAT_RECORD TIMEMORY_CRAYPAT_RECORD_idx
#endif
#if !defined(CRAYPAT_REGION)
#    define CRAYPAT_REGION TIMEMORY_CRAYPAT_REGION_idx
#endif
#if !defined(CUDA_EVENT)
#    define CUDA_EVENT TIMEMORY_CUDA_EVENT_idx
#endif
#if !defined(CUDA_PROFILER)
#    define CUDA_PROFILER TIMEMORY_CUDA_PROFILER_idx
#endif
#if !defined(CUPTI_ACTIVITY)
#    define CUPTI_ACTIVITY TIMEMORY_CUPTI_ACTIVITY_idx
#endif
#if !defined(CUPTI_COUNTERS)
#    define CUPTI_COUNTERS TIMEMORY_CUPTI_COUNTERS_idx
#endif
#if !defined(CUPTI_PCSAMPLING)
#    define CUPTI_PCSAMPLING TIMEMORY_CUPTI_PCSAMPLING_idx
#endif
#if !defined(CURRENT_PEAK_RSS)
#    define CURRENT_PEAK_RSS TIMEMORY_CURRENT_PEAK_RSS_idx
#endif
#if !defined(DATA_TRACKER_INTEGER)
#    define DATA_TRACKER_INTEGER TIMEMORY_DATA_TRACKER_INTEGER_idx
#endif
#if !defined(DATA_TRACKER_UNSIGNED)
#    define DATA_TRACKER_UNSIGNED TIMEMORY_DATA_TRACKER_UNSIGNED_idx
#endif
#if !defined(DATA_TRACKER_FLOATING)
#    define DATA_TRACKER_FLOATING TIMEMORY_DATA_TRACKER_FLOATING_idx
#endif
#if !defined(GPERFTOOLS_CPU_PROFILER)
#    define GPERFTOOLS_CPU_PROFILER TIMEMORY_GPERFTOOLS_CPU_PROFILER_idx
#endif
#if !defined(GPERFTOOLS_HEAP_PROFILER)
#    define GPERFTOOLS_HEAP_PROFILER TIMEMORY_GPERFTOOLS_HEAP_PROFILER_idx
#endif
#if !defined(GPU_ROOFLINE_DP_FLOPS)
#    define GPU_ROOFLINE_DP_FLOPS TIMEMORY_GPU_ROOFLINE_DP_FLOPS_idx
#endif
#if !defined(GPU_ROOFLINE_FLOPS)
#    define GPU_ROOFLINE_FLOPS TIMEMORY_GPU_ROOFLINE_FLOPS_idx
#endif
#if !defined(GPU_ROOFLINE_HP_FLOPS)
#    define GPU_ROOFLINE_HP_FLOPS TIMEMORY_GPU_ROOFLINE_HP_FLOPS_idx
#endif
#if !defined(GPU_ROOFLINE_SP_FLOPS)
#    define GPU_ROOFLINE_SP_FLOPS TIMEMORY_GPU_ROOFLINE_SP_FLOPS_idx
#endif
#if !defined(KERNEL_MODE_TIME)
#    define KERNEL_MODE_TIME TIMEMORY_KERNEL_MODE_TIME_idx
#endif
#if !defined(LIKWID_MARKER)
#    define LIKWID_MARKER TIMEMORY_LIKWID_MARKER_idx
#endif
#if !defined(LIKWID_NVMARKER)
#    define LIKWID_NVMARKER TIMEMORY_LIKWID_NVMARKER_idx
#endif
#if !defined(MALLOC_GOTCHA)
#    define MALLOC_GOTCHA TIMEMORY_MALLOC_GOTCHA_idx
#endif
#if !defined(MEMORY_ALLOCATIONS)
#    define MEMORY_ALLOCATIONS TIMEMORY_MEMORY_ALLOCATIONS_idx
#endif
#if !defined(MONOTONIC_CLOCK)
#    define MONOTONIC_CLOCK TIMEMORY_MONOTONIC_CLOCK_idx
#endif
#if !defined(MONOTONIC_RAW_CLOCK)
#    define MONOTONIC_RAW_CLOCK TIMEMORY_MONOTONIC_RAW_CLOCK_idx
#endif
#if !defined(NETWORK_STATS)
#    define NETWORK_STATS TIMEMORY_NETWORK_STATS_idx
#endif
#if !defined(NUM_IO_IN)
#    define NUM_IO_IN TIMEMORY_NUM_IO_IN_idx
#endif
#if !defined(NUM_IO_OUT)
#    define NUM_IO_OUT TIMEMORY_NUM_IO_OUT_idx
#endif
#if !defined(NUM_MAJOR_PAGE_FAULTS)
#    define NUM_MAJOR_PAGE_FAULTS TIMEMORY_NUM_MAJOR_PAGE_FAULTS_idx
#endif
#if !defined(NUM_MINOR_PAGE_FAULTS)
#    define NUM_MINOR_PAGE_FAULTS TIMEMORY_NUM_MINOR_PAGE_FAULTS_idx
#endif
#if !defined(NVTX_MARKER)
#    define NVTX_MARKER TIMEMORY_NVTX_MARKER_idx
#endif
#if !defined(OMPT_HANDLE)
#    define OMPT_HANDLE TIMEMORY_OMPT_HANDLE_idx
#endif
#if !defined(PAGE_RSS)
#    define PAGE_RSS TIMEMORY_PAGE_RSS_idx
#endif
#if !defined(PAPI_ARRAY)
#    define PAPI_ARRAY TIMEMORY_PAPI_ARRAY_idx
#endif
#if !defined(PAPI_VECTOR)
#    define PAPI_VECTOR TIMEMORY_PAPI_VECTOR_idx
#endif
#if !defined(PEAK_RSS)
#    define PEAK_RSS TIMEMORY_PEAK_RSS_idx
#endif
#if !defined(PRIORITY_CONTEXT_SWITCH)
#    define PRIORITY_CONTEXT_SWITCH TIMEMORY_PRIORITY_CONTEXT_SWITCH_idx
#endif
#if !defined(PROCESS_CPU_CLOCK)
#    define PROCESS_CPU_CLOCK TIMEMORY_PROCESS_CPU_CLOCK_idx
#endif
#if !defined(PROCESS_CPU_UTIL)
#    define PROCESS_CPU_UTIL TIMEMORY_PROCESS_CPU_UTIL_idx
#endif
#if !defined(READ_BYTES)
#    define READ_BYTES TIMEMORY_READ_BYTES_idx
#endif
#if !defined(READ_CHAR)
#    define READ_CHAR TIMEMORY_READ_CHAR_idx
#endif
#if !defined(SYS_CLOCK)
#    define SYS_CLOCK TIMEMORY_SYS_CLOCK_idx
#endif
#if !defined(TAU_MARKER)
#    define TAU_MARKER TIMEMORY_TAU_MARKER_idx
#endif
#if !defined(THREAD_CPU_CLOCK)
#    define THREAD_CPU_CLOCK TIMEMORY_THREAD_CPU_CLOCK_idx
#endif
#if !defined(THREAD_CPU_UTIL)
#    define THREAD_CPU_UTIL TIMEMORY_THREAD_CPU_UTIL_idx
#endif
#if !defined(TRIP_COUNT)
#    define TRIP_COUNT TIMEMORY_TRIP_COUNT_idx
#endif
#if !defined(USER_CLOCK)
#    define USER_CLOCK TIMEMORY_USER_CLOCK_idx
#endif
#if !defined(USER_MODE_TIME)
#    define USER_MODE_TIME TIMEMORY_USER_MODE_TIME_idx
#endif
#if !defined(USER_GLOBAL_BUNDLE)
#    define USER_GLOBAL_BUNDLE TIMEMORY_USER_GLOBAL_BUNDLE_idx
#endif
#if !defined(USER_KOKKOSP_BUNDLE)
#    define USER_KOKKOSP_BUNDLE TIMEMORY_USER_KOKKOSP_BUNDLE_idx
#endif
#if !defined(USER_LIST_BUNDLE)
#    define USER_LIST_BUNDLE TIMEMORY_USER_LIST_BUNDLE_idx
#endif
#if !defined(USER_MPIP_BUNDLE)
#    define USER_MPIP_BUNDLE TIMEMORY_USER_MPIP_BUNDLE_idx
#endif
#if !defined(USER_NCCLP_BUNDLE)
#    define USER_NCCLP_BUNDLE TIMEMORY_USER_NCCLP_BUNDLE_idx
#endif
#if !defined(USER_OMPT_BUNDLE)
#    define USER_OMPT_BUNDLE TIMEMORY_USER_OMPT_BUNDLE_idx
#endif
#if !defined(USER_TUPLE_BUNDLE)
#    define USER_TUPLE_BUNDLE TIMEMORY_USER_TUPLE_BUNDLE_idx
#endif
#if !defined(USER_PROFILER_BUNDLE)
#    define USER_PROFILER_BUNDLE TIMEMORY_USER_PROFILER_BUNDLE_idx
#endif
#if !defined(USER_TRACE_BUNDLE)
#    define USER_TRACE_BUNDLE TIMEMORY_USER_TRACE_BUNDLE_idx
#endif
#if !defined(VIRTUAL_MEMORY)
#    define VIRTUAL_MEMORY TIMEMORY_VIRTUAL_MEMORY_idx
#endif
#if !defined(VOLUNTARY_CONTEXT_SWITCH)
#    define VOLUNTARY_CONTEXT_SWITCH TIMEMORY_VOLUNTARY_CONTEXT_SWITCH_idx
#endif
#if !defined(VTUNE_EVENT)
#    define VTUNE_EVENT TIMEMORY_VTUNE_EVENT_idx
#endif
#if !defined(VTUNE_FRAME)
#    define VTUNE_FRAME TIMEMORY_VTUNE_FRAME_idx
#endif
#if !defined(VTUNE_PROFILER)
#    define VTUNE_PROFILER TIMEMORY_VTUNE_PROFILER_idx
#endif
#if !defined(WALL_CLOCK)
#    define WALL_CLOCK TIMEMORY_WALL_CLOCK_idx
#endif
#if !defined(WRITTEN_BYTES)
#    define WRITTEN_BYTES TIMEMORY_WRITTEN_BYTES_idx
#endif
#if !defined(WRITTEN_CHAR)
#    define WRITTEN_CHAR TIMEMORY_WRITTEN_CHAR_idx
#endif
//
//  timemory-prefixed variants
//
#if !defined(TIMEMORY_ALLINEA_MAP)
#    define TIMEMORY_ALLINEA_MAP TIMEMORY_ALLINEA_MAP_idx
#endif
#if !defined(TIMEMORY_CALIPER_MARKER)
#    define TIMEMORY_CALIPER_MARKER TIMEMORY_CALIPER_MARKER_idx
#endif
#if !defined(TIMEMORY_CALIPER_CONFIG)
#    define TIMEMORY_CALIPER_CONFIG TIMEMORY_CALIPER_CONFIG_idx
#endif
#if !defined(TIMEMORY_CALIPER_LOOP_MARKER)
#    define TIMEMORY_CALIPER_LOOP_MARKER TIMEMORY_CALIPER_LOOP_MARKER_idx
#endif
#if !defined(TIMEMORY_CPU_CLOCK)
#    define TIMEMORY_CPU_CLOCK TIMEMORY_CPU_CLOCK_idx
#endif
#if !defined(TIMEMORY_CPU_ROOFLINE_DP_FLOPS)
#    define TIMEMORY_CPU_ROOFLINE_DP_FLOPS TIMEMORY_CPU_ROOFLINE_DP_FLOPS_idx
#endif
#if !defined(TIMEMORY_CPU_ROOFLINE_FLOPS)
#    define TIMEMORY_CPU_ROOFLINE_FLOPS TIMEMORY_CPU_ROOFLINE_FLOPS_idx
#endif
#if !defined(TIMEMORY_CPU_ROOFLINE_SP_FLOPS)
#    define TIMEMORY_CPU_ROOFLINE_SP_FLOPS TIMEMORY_CPU_ROOFLINE_SP_FLOPS_idx
#endif
#if !defined(TIMEMORY_CPU_UTIL)
#    define TIMEMORY_CPU_UTIL TIMEMORY_CPU_UTIL_idx
#endif
#if !defined(TIMEMORY_CRAYPAT_COUNTERS)
#    define TIMEMORY_CRAYPAT_COUNTERS TIMEMORY_CRAYPAT_COUNTERS_idx
#endif
#if !defined(TIMEMORY_CRAYPAT_FLUSH_BUFFER)
#    define TIMEMORY_CRAYPAT_FLUSH_BUFFER TIMEMORY_CRAYPAT_FLUSH_BUFFER_idx
#endif
#if !defined(TIMEMORY_CRAYPAT_HEAP_STATS)
#    define TIMEMORY_CRAYPAT_HEAP_STATS TIMEMORY_CRAYPAT_HEAP_STATS_idx
#endif
#if !defined(TIMEMORY_CRAYPAT_RECORD)
#    define TIMEMORY_CRAYPAT_RECORD TIMEMORY_CRAYPAT_RECORD_idx
#endif
#if !defined(TIMEMORY_CRAYPAT_REGION)
#    define TIMEMORY_CRAYPAT_REGION TIMEMORY_CRAYPAT_REGION_idx
#endif
#if !defined(TIMEMORY_CUDA_EVENT)
#    define TIMEMORY_CUDA_EVENT TIMEMORY_CUDA_EVENT_idx
#endif
#if !defined(TIMEMORY_CUDA_PROFILER)
#    define TIMEMORY_CUDA_PROFILER TIMEMORY_CUDA_PROFILER_idx
#endif
#if !defined(TIMEMORY_CUPTI_ACTIVITY)
#    define TIMEMORY_CUPTI_ACTIVITY TIMEMORY_CUPTI_ACTIVITY_idx
#endif
#if !defined(TIMEMORY_CUPTI_COUNTERS)
#    define TIMEMORY_CUPTI_COUNTERS TIMEMORY_CUPTI_COUNTERS_idx
#endif
#if !defined(TIMEMORY_CUPTI_PCSAMPLING)
#    define TIMEMORY_CUPTI_PCSAMPLING TIMEMORY_CUPTI_PCSAMPLING_idx
#endif
#if !defined(TIMEMORY_CURRENT_PEAK_RSS)
#    define TIMEMORY_CURRENT_PEAK_RSS TIMEMORY_CURRENT_PEAK_RSS_idx
#endif
#if !defined(TIMEMORY_DATA_TRACKER_INTEGER)
#    define TIMEMORY_DATA_TRACKER_INTEGER TIMEMORY_DATA_TRACKER_INTEGER_idx
#endif
#if !defined(TIMEMORY_DATA_TRACKER_UNSIGNED)
#    define TIMEMORY_DATA_TRACKER_UNSIGNED TIMEMORY_DATA_TRACKER_UNSIGNED_idx
#endif
#if !defined(TIMEMORY_DATA_TRACKER_FLOATING)
#    define TIMEMORY_DATA_TRACKER_FLOATING TIMEMORY_DATA_TRACKER_FLOATING_idx
#endif
#if !defined(TIMEMORY_GPERFTOOLS_CPU_PROFILER)
#    define TIMEMORY_GPERFTOOLS_CPU_PROFILER TIMEMORY_GPERFTOOLS_CPU_PROFILER_idx
#endif
#if !defined(TIMEMORY_GPERFTOOLS_HEAP_PROFILER)
#    define TIMEMORY_GPERFTOOLS_HEAP_PROFILER TIMEMORY_GPERFTOOLS_HEAP_PROFILER_idx
#endif
#if !defined(TIMEMORY_GPU_ROOFLINE_DP_FLOPS)
#    define TIMEMORY_GPU_ROOFLINE_DP_FLOPS TIMEMORY_GPU_ROOFLINE_DP_FLOPS_idx
#endif
#if !defined(TIMEMORY_GPU_ROOFLINE_FLOPS)
#    define TIMEMORY_GPU_ROOFLINE_FLOPS TIMEMORY_GPU_ROOFLINE_FLOPS_idx
#endif
#if !defined(TIMEMORY_GPU_ROOFLINE_HP_FLOPS)
#    define TIMEMORY_GPU_ROOFLINE_HP_FLOPS TIMEMORY_GPU_ROOFLINE_HP_FLOPS_idx
#endif
#if !defined(TIMEMORY_GPU_ROOFLINE_SP_FLOPS)
#    define TIMEMORY_GPU_ROOFLINE_SP_FLOPS TIMEMORY_GPU_ROOFLINE_SP_FLOPS_idx
#endif
#if !defined(TIMEMORY_KERNEL_MODE_TIME)
#    define TIMEMORY_KERNEL_MODE_TIME TIMEMORY_KERNEL_MODE_TIME_idx
#endif
#if !defined(TIMEMORY_LIKWID_MARKER)
#    define TIMEMORY_LIKWID_MARKER TIMEMORY_LIKWID_MARKER_idx
#endif
#if !defined(TIMEMORY_LIKWID_NVMARKER)
#    define TIMEMORY_LIKWID_NVMARKER TIMEMORY_LIKWID_NVMARKER_idx
#endif
#if !defined(TIMEMORY_MALLOC_GOTCHA)
#    define TIMEMORY_MALLOC_GOTCHA TIMEMORY_MALLOC_GOTCHA_idx
#endif
#if !defined(TIMEMORY_MEMORY_ALLOCATIONS)
#    define TIMEMORY_MEMORY_ALLOCATIONS TIMEMORY_MEMORY_ALLOCATIONS_idx
#endif
#if !defined(TIMEMORY_MONOTONIC_CLOCK)
#    define TIMEMORY_MONOTONIC_CLOCK TIMEMORY_MONOTONIC_CLOCK_idx
#endif
#if !defined(TIMEMORY_MONOTONIC_RAW_CLOCK)
#    define TIMEMORY_MONOTONIC_RAW_CLOCK TIMEMORY_MONOTONIC_RAW_CLOCK_idx
#endif
#if !defined(TIMEMORY_NETWORK_STATS)
#    define TIMEMORY_NETWORK_STATS TIMEMORY_NETWORK_STATS_idx
#endif
#if !defined(TIMEMORY_NUM_IO_IN)
#    define TIMEMORY_NUM_IO_IN TIMEMORY_NUM_IO_IN_idx
#endif
#if !defined(TIMEMORY_NUM_IO_OUT)
#    define TIMEMORY_NUM_IO_OUT TIMEMORY_NUM_IO_OUT_idx
#endif
#if !defined(TIMEMORY_NUM_MAJOR_PAGE_FAULTS)
#    define TIMEMORY_NUM_MAJOR_PAGE_FAULTS TIMEMORY_NUM_MAJOR_PAGE_FAULTS_idx
#endif
#if !defined(TIMEMORY_NUM_MINOR_PAGE_FAULTS)
#    define TIMEMORY_NUM_MINOR_PAGE_FAULTS TIMEMORY_NUM_MINOR_PAGE_FAULTS_idx
#endif
#if !defined(TIMEMORY_NVTX_MARKER)
#    define TIMEMORY_NVTX_MARKER TIMEMORY_NVTX_MARKER_idx
#endif
#if !defined(TIMEMORY_OMPT_HANDLE)
#    define TIMEMORY_OMPT_HANDLE TIMEMORY_OMPT_HANDLE_idx
#endif
#if !defined(TIMEMORY_PAGE_RSS)
#    define TIMEMORY_PAGE_RSS TIMEMORY_PAGE_RSS_idx
#endif
#if !defined(TIMEMORY_PAPI_ARRAY)
#    define TIMEMORY_PAPI_ARRAY TIMEMORY_PAPI_ARRAY_idx
#endif
#if !defined(TIMEMORY_PAPI_VECTOR)
#    define TIMEMORY_PAPI_VECTOR TIMEMORY_PAPI_VECTOR_idx
#endif
#if !defined(TIMEMORY_PEAK_RSS)
#    define TIMEMORY_PEAK_RSS TIMEMORY_PEAK_RSS_idx
#endif
#if !defined(TIMEMORY_PRIORITY_CONTEXT_SWITCH)
#    define TIMEMORY_PRIORITY_CONTEXT_SWITCH TIMEMORY_PRIORITY_CONTEXT_SWITCH_idx
#endif
#if !defined(TIMEMORY_PROCESS_CPU_CLOCK)
#    define TIMEMORY_PROCESS_CPU_CLOCK TIMEMORY_PROCESS_CPU_CLOCK_idx
#endif
#if !defined(TIMEMORY_PROCESS_CPU_UTIL)
#    define TIMEMORY_PROCESS_CPU_UTIL TIMEMORY_PROCESS_CPU_UTIL_idx
#endif
#if !defined(TIMEMORY_READ_BYTES)
#    define TIMEMORY_READ_BYTES TIMEMORY_READ_BYTES_idx
#endif
#if !defined(TIMEMORY_READ_CHAR)
#    define TIMEMORY_READ_CHAR TIMEMORY_READ_CHAR_idx
#endif
#if !defined(TIMEMORY_SYS_CLOCK)
#    define TIMEMORY_SYS_CLOCK TIMEMORY_SYS_CLOCK_idx
#endif
#if !defined(TIMEMORY_TAU_MARKER)
#    define TIMEMORY_TAU_MARKER TIMEMORY_TAU_MARKER_idx
#endif
#if !defined(TIMEMORY_THREAD_CPU_CLOCK)
#    define TIMEMORY_THREAD_CPU_CLOCK TIMEMORY_THREAD_CPU_CLOCK_idx
#endif
#if !defined(TIMEMORY_THREAD_CPU_UTIL)
#    define TIMEMORY_THREAD_CPU_UTIL TIMEMORY_THREAD_CPU_UTIL_idx
#endif
#if !defined(TIMEMORY_TRIP_COUNT)
#    define TIMEMORY_TRIP_COUNT TIMEMORY_TRIP_COUNT_idx
#endif
#if !defined(TIMEMORY_USER_CLOCK)
#    define TIMEMORY_USER_CLOCK TIMEMORY_USER_CLOCK_idx
#endif
#if !defined(TIMEMORY_USER_MODE_TIME)
#    define TIMEMORY_USER_MODE_TIME TIMEMORY_USER_MODE_TIME_idx
#endif
#if !defined(TIMEMORY_USER_GLOBAL_BUNDLE)
#    define TIMEMORY_USER_GLOBAL_BUNDLE TIMEMORY_USER_GLOBAL_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_KOKKOSP_BUNDLE)
#    define TIMEMORY_USER_KOKKOSP_BUNDLE TIMEMORY_USER_KOKKOSP_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_LIST_BUNDLE)
#    define TIMEMORY_USER_LIST_BUNDLE TIMEMORY_USER_LIST_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_MPIP_BUNDLE)
#    define TIMEMORY_USER_MPIP_BUNDLE TIMEMORY_USER_MPIP_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_NCCLP_BUNDLE)
#    define TIMEMORY_USER_NCCLP_BUNDLE TIMEMORY_USER_NCCLP_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_OMPT_BUNDLE)
#    define TIMEMORY_USER_OMPT_BUNDLE TIMEMORY_USER_OMPT_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_TUPLE_BUNDLE)
#    define TIMEMORY_USER_TUPLE_BUNDLE TIMEMORY_USER_TUPLE_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_PROFILER_BUNDLE)
#    define TIMEMORY_USER_PROFILER_BUNDLE TIMEMORY_USER_PROFILER_BUNDLE_idx
#endif
#if !defined(TIMEMORY_USER_TRACE_BUNDLE)
#    define TIMEMORY_USER_TRACE_BUNDLE TIMEMORY_USER_TRACE_BUNDLE_idx
#endif
#if !defined(TIMEMORY_VIRTUAL_MEMORY)
#    define TIMEMORY_VIRTUAL_MEMORY TIMEMORY_VIRTUAL_MEMORY_idx
#endif
#if !defined(TIMEMORY_VOLUNTARY_CONTEXT_SWITCH)
#    define TIMEMORY_VOLUNTARY_CONTEXT_SWITCH TIMEMORY_VOLUNTARY_CONTEXT_SWITCH_idx
#endif
#if !defined(TIMEMORY_VTUNE_EVENT)
#    define TIMEMORY_VTUNE_EVENT TIMEMORY_VTUNE_EVENT_idx
#endif
#if !defined(TIMEMORY_VTUNE_FRAME)
#    define TIMEMORY_VTUNE_FRAME TIMEMORY_VTUNE_FRAME_idx
#endif
#if !defined(TIMEMORY_VTUNE_PROFILER)
#    define TIMEMORY_VTUNE_PROFILER TIMEMORY_VTUNE_PROFILER_idx
#endif
#if !defined(TIMEMORY_WALL_CLOCK)
#    define TIMEMORY_WALL_CLOCK TIMEMORY_WALL_CLOCK_idx
#endif
#if !defined(TIMEMORY_WRITTEN_BYTES)
#    define TIMEMORY_WRITTEN_BYTES TIMEMORY_WRITTEN_BYTES_idx
#endif
#if !defined(TIMEMORY_WRITTEN_CHAR)
#    define TIMEMORY_WRITTEN_CHAR TIMEMORY_WRITTEN_CHAR_idx
#endif
//
/// \macro TIMEMORY_NATIVE_COMPONENT_ENUM_SIZE
/// \brief The number of enumerated components natively defined by timemory
//
#if !defined(TIMEMORY_NATIVE_COMPONENT_ENUM_SIZE)
#    define TIMEMORY_NATIVE_COMPONENT_ENUM_SIZE TIMEMORY_NATIVE_COMPONENTS_END
#endif
//
/// \macro TIMEMORY_NATIVE_COMPONENT_INTERNAL_SIZE
/// \brief The number of enumerated components which are private to
/// TIMEMORY_COMPONENT_TYPES. This is mainly just used by the validation checks
/// between the number of enumerations and the types specified in TIMEMORY_COMPONENT_TYPES
//
#if !defined(TIMEMORY_NATIVE_COMPONENT_INTERNAL_SIZE)
#    define TIMEMORY_NATIVE_COMPONENT_INTERNAL_SIZE 8
#endif
//
//--------------------------------------------------------------------------------------//
//
typedef int TIMEMORY_COMPONENT;
//
#if !defined(CALIPER)
#    define CALIPER CALIPER_MARKER
#endif
//
#if !defined(USER_TUPLE_BUNDLE)
#    define USER_TUPLE_BUNDLE USER_GLOBAL_BUNDLE
#endif
//
#if !defined(USER_LIST_BUNDLE)
#    define USER_LIST_BUNDLE USER_GLOBAL_BUNDLE
#endif
//
//--------------------------------------------------------------------------------------//
//
/// \enum TIMEMORY_OPERATION
/// \brief Enumerated identifiers for subset of common operations for usage in C code
/// and specializations of \ref tim::trait::python_args.
enum TIMEMORY_OPERATION
{
    TIMEMORY_CONSTRUCT = 0,
    TIMEMORY_GET,
    TIMEMORY_AUDIT,
    TIMEMORY_START,
    TIMEMORY_STOP,
    TIMEMORY_STORE,
    TIMEMORY_RECORD,
    TIMEMORY_SAMPLE,
    TIMEMORY_MEASURE,
    TIMEMORY_MARK_BEGIN,
    TIMEMORY_MARK_END,
    TIMEMORY_OPERATION_END
};
//
//--------------------------------------------------------------------------------------//
//
