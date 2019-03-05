// Copyright (c) 2010, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. LLNL-CODE-443211. All Rights
// reserved. See file COPYRIGHT for details.
//
// This file is part of the MFEM library. For more information and source code
// availability see http://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License (as published by the Free
// Software Foundation) version 2.1 dated February 1999.

#ifndef MFEM_CONFIG_HEADER
#define MFEM_CONFIG_HEADER

// Build the parallel MFEM library.
// Requires an MPI compiler, and the libraries HYPRE and METIS.
/* #undef MFEM_USE_MPI */

// Enable debug checks in MFEM.
/* #undef MFEM_DEBUG */

// Enable gzstream in MFEM.
#define MFEM_USE_GZSTREAM

// Enable backtraces for mfem_error through libunwind.
/* #undef MFEM_USE_LIBUNWIND */

// Enable this option if linking with METIS version 5 (parallel MFEM).
/* #undef MFEM_USE_METIS_5 */

// Use LAPACK routines for various dense linear algebra operations.
/* #undef MFEM_USE_LAPACK */

// Use thread-safe implementation. This comes at the cost of extra memory
// allocation and de-allocation.
/* #undef MFEM_THREAD_SAFE */

// Enable experimental OpenMP support. Requires MFEM_THREAD_SAFE.
/* #undef MFEM_USE_OPENMP */

// Enable MFEM functionality based on the Mesquite library.
/* #undef MFEM_USE_MESQUITE */

// Enable MFEM functionality based on the SuiteSparse library.
/* #undef MFEM_USE_SUITESPARSE */

// Enable MFEM functionality based on the SuperLU_DIST library.
/* #undef MFEM_USE_SUPERLU */

// Internal MFEM option: enable group/batch allocation for some small objects.
#define MFEM_USE_MEMALLOC

// Enable functionality based on the Gecko library
/* #undef MFEM_USE_GECKO */

// Enable MFEM functionality based on the GnuTLS library
/* #undef MFEM_USE_GNUTLS */

// Enable MFEM functionality based on the NetCDF library
/* #undef MFEM_USE_NETCDF */

// Enable MFEM functionality based on the PETSc library
/* #undef MFEM_USE_PETSC */

// Enable MFEM functionality based on the Sidre library
/* #undef MFEM_USE_SIDRE */

// Which library functions to use in class StopWatch for measuring time.
// The available options are:
//   0 - use std::clock from <ctime>
//   1 - use times from <sys/times.h>
//   2 - use high-resolution POSIX clocks
//   3 - use QueryPerformanceCounter from <windows.h>
// If not defined, an option is selected automatically.
#define MFEM_TIMER_TYPE 3

// Enable MFEM functionality based on the SUNDIALS libraries.
/* #undef MFEM_USE_SUNDIALS */

// Windows specific options
// Macro needed to get defines like M_PI from <cmath>. (Visual Studio C++ only?)
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#endif // MFEM_CONFIG_HEADER
