// Copyright (c) 2010-2025, Lawrence Livermore National Security, LLC. Produced
// at the Lawrence Livermore National Laboratory. All Rights reserved. See files
// LICENSE and NOTICE for details. LLNL-CODE-806117.
//
// This file is part of the MFEM library. For more information and source code
// availability visit https://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the BSD-3 license. We welcome feedback and contributions, see file
// CONTRIBUTING.md for details.

#ifndef MFEM_CONFIG_HEADER
#define MFEM_CONFIG_HEADER

// MFEM version: integer of the form: (major*100 + minor)*100 + patch.
#define MFEM_VERSION 40800

// MFEM version string of the form "3.3" or "3.3.1".
#define MFEM_VERSION_STRING "4.8.0"

// MFEM version type, see the MFEM_VERSION_TYPE_* constants below.
#define MFEM_VERSION_TYPE ((MFEM_VERSION)%2)

// MFEM version type constants.
#define MFEM_VERSION_TYPE_RELEASE 0
#define MFEM_VERSION_TYPE_DEVELOPMENT 1

// Separate MFEM version numbers for major, minor, and patch.
#define MFEM_VERSION_MAJOR ((MFEM_VERSION)/10000)
#define MFEM_VERSION_MINOR (((MFEM_VERSION)/100)%100)
#define MFEM_VERSION_PATCH ((MFEM_VERSION)%100)

// MFEM source directory.
/* #undef MFEM_SOURCE_DIR  */

// MFEM install directory.
/* #undef MFEM_INSTALL_DIR */

// Description of the git commit used to build MFEM.
#define MFEM_GIT_STRING "(unknown)"

// Enable shared library build of MFEM.
#define MFEM_SHARED_BUILD

// Build the parallel MFEM library.
// Requires an MPI compiler, and the libraries HYPRE and METIS.
/* #undef MFEM_USE_MPI */

// Use double-precision floating point type
#define MFEM_USE_DOUBLE

// Use single-precision floating point type
/* #undef MFEM_USE_SINGLE */

// Enable debug checks in MFEM.
/* #undef MFEM_DEBUG */

// Throw an exception on errors.
#define MFEM_USE_EXCEPTIONS

// Enable zlib in MFEM.
#define MFEM_USE_ZLIB

// Enable backtraces for mfem_error through libunwind.
/* #undef MFEM_USE_LIBUNWIND */

// Enable MFEM features that use the METIS library (parallel MFEM).
/* #undef MFEM_USE_METIS */

// Enable this option if linking with METIS version 5 (parallel MFEM).
/* #undef MFEM_USE_METIS_5 */

// Use LAPACK routines for various dense linear algebra operations.
/* #undef MFEM_USE_LAPACK */

// Use thread-safe implementation. This comes at the cost of extra memory
// allocation and de-allocation.
/* #undef MFEM_THREAD_SAFE */

// Enable the OpenMP backend.
/* #undef MFEM_USE_OPENMP */

// [Deprecated] Enable experimental OpenMP support. Requires MFEM_THREAD_SAFE.
/* #undef MFEM_USE_LEGACY_OPENMP */

// Internal MFEM option: enable group/batch allocation for some small objects.
#define MFEM_USE_MEMALLOC

// Which library functions to use in class StopWatch for measuring time.
// For a list of the available options, see INSTALL.
// If not defined, an option is selected automatically.
#define MFEM_TIMER_TYPE 3

// Enable MFEM functionality based on the SUNDIALS libraries.
/* #undef MFEM_USE_SUNDIALS */

// Enable MFEM functionality based on the SuiteSparse library.
/* #undef MFEM_USE_SUITESPARSE */

// Enable MFEM functionality based on the SuperLU_DIST library.
/* #undef MFEM_USE_SUPERLU */
/* #undef MFEM_USE_SUPERLU5 */

// Enable MFEM functionality based on the MUMPS library.
/* #undef MFEM_USE_MUMPS */
/* #undef MFEM_MUMPS_VERSION */

// Enable MFEM functionality based on the STRUMPACK library.
/* #undef MFEM_USE_STRUMPACK */

// Enable functionality based on the Ginkgo library.
/* #undef MFEM_USE_GINKGO */

// Enable MFEM functionality based on the AmgX library.
/* #undef MFEM_USE_AMGX */

// Enable MFEM functionality based on the MAGMA library.
/* #undef MFEM_USE_MAGMA */

// Enable secure socket streams based on the GNUTLS library.
/* #undef MFEM_USE_GNUTLS */

// Enable Sidre support.
/* #undef MFEM_USE_SIDRE */

// Enable the use of SIMD in the high performance templated classes.
/* #undef MFEM_USE_SIMD */

// Enable FMS support.
/* #undef MFEM_USE_FMS */

// Enable Conduit support.
#define MFEM_USE_CONDUIT

// Enable functionality based on the NetCDF library (reading CUBIT files).
/* #undef MFEM_USE_NETCDF */

// Enable functionality based on the PETSc library.
/* #undef MFEM_USE_PETSC */

// Enable functionality based on the SLEPc library.
/* #undef MFEM_USE_SLEPC */

// Enable functionality based on the MPFR library.
/* #undef MFEM_USE_MPFR */

// Enable MFEM functionality based on the PUMI library.
/* #undef MFEM_USE_PUMI */

// Enable Moonolith-based general interpolation between finite element spaces.
/* #undef MFEM_USE_MOONOLITH */

// Enable MFEM functionality based on the HIOP library.
/* #undef MFEM_USE_HIOP */

// Enable MFEM functionality based on the GSLIB library.
/* #undef MFEM_USE_GSLIB */

// Build the NVIDIA GPU/CUDA-enabled version of the MFEM library.
// Requires a CUDA compiler (nvcc).
/* #undef MFEM_USE_CUDA */

// Build the AMD GPU/HIP-enabled version of the MFEM library.
// Requires a HIP compiler (hipcc).
/* #undef MFEM_USE_HIP */

// Enable functionality based on the RAJA library.
/* #undef MFEM_USE_RAJA */

// Enable functionality based on the OCCA library.
/* #undef MFEM_USE_OCCA */

// Enable functionality based on the libCEED library.
/* #undef MFEM_USE_CEED */

// Enable functionality based on the Caliper library.
/* #undef MFEM_USE_CALIPER */

// Enable functionality based on the Algoim library.
/* #undef MFEM_USE_ALGOIM */

// Enable functionality based on the Umpire library.
/* #undef MFEM_USE_UMPIRE */

// Enable IO functionality based on the ADIOS2 library.
/* #undef MFEM_USE_ADIOS2 */

// Version of HYPRE used for building MFEM.
/* #undef MFEM_HYPRE_VERSION */

// Macro defined when PUMI is built with support for the Simmetrix SimModSuite
// library.
/* #undef MFEM_USE_SIMMETRIX */

// Enable interface to the MKL CPardiso library.
/* #undef MFEM_USE_MKL_CPARDISO */

// Enable interface to the MKL Pardiso library.
/* #undef MFEM_USE_MKL_PARDISO */

// Use forward mode for automatic differentiation.
/* #undef MFEM_USE_ADFORWARD */

// Enable the use of the CoDiPack library for AD.
/* #undef MFEM_USE_CODIPACK */

// Enable functionality based on the Google Benchmark library.
/* #undef MFEM_USE_BENCHMARK */

// Enable Enzyme for AD
/* #undef MFEM_USE_ENZYME */

#endif // MFEM_CONFIG_HEADER
