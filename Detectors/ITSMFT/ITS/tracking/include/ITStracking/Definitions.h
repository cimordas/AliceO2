// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
///
/// \file Definitions.h
/// \brief
///

#ifndef TRACKINGITSU_INCLUDE_CADEFINITIONS_H_
#define TRACKINGITSU_INCLUDE_CADEFINITIONS_H_

#include <array>

//#define CA_DEBUG

#ifdef CA_DEBUG
#define CA_DEBUGGER(x) x
#else
#define CA_DEBUGGER(x) \
  do {                 \
  } while (0)
#ifndef NDEBUG
#define NDEBUG 1
#endif
#endif

#if defined(ENABLE_CUDA)
#define TRACKINGITSU_GPU_MODE true
#else
#define TRACKINGITSU_GPU_MODE false
#endif

#if defined(__CUDACC__)
#define TRACKINGITSU_GPU_COMPILING
#endif

#if defined(__CUDA_ARCH__)
#define TRACKINGITSU_GPU_DEVICE
#endif

#if defined(__CUDACC__)

#define GPU_HOST __host__
#define GPU_DEVICE __device__
#define GPU_HOST_DEVICE __host__ __device__
#define GPU_GLOBAL __global__
#define GPU_SHARED __shared__
#define GPU_SYNC __syncthreads()

#define MATH_ABS abs
#define MATH_ATAN2 atan2
#define MATH_MAX max
#define MATH_MIN min
#define MATH_SQRT sqrt

#include "ITStrackingCUDA/Array.h"

template <typename T, std::size_t Size>
using GPUArray = o2::ITS::GPU::Array<T, Size>;

typedef cudaStream_t GPUStream;

#else

#define GPU_HOST
#define GPU_DEVICE
#define GPU_HOST_DEVICE
#define GPU_GLOBAL
#define GPU_SHARED
#define GPU_SYNC

#define MATH_ABS std::abs
#define MATH_ATAN2 std::atan2
#define MATH_MAX std::max
#define MATH_MIN std::min
#define MATH_SQRT std::sqrt

#ifndef __VECTOR_TYPES_H__

#include "AliTPCCommonDefGPU.h"

#endif

template <typename T, std::size_t Size>
using GPUArray = std::array<T, Size>;

typedef struct _dummyStream {
} GPUStream;

#endif

#endif /* TRACKINGITSU_INCLUDE_CADEFINITIONS_H_ */
