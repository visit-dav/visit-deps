# Copyright (c) 2010-2025, Lawrence Livermore National Security, LLC. Produced
# at the Lawrence Livermore National Laboratory. All Rights reserved. See files
# LICENSE and NOTICE for details. LLNL-CODE-806117.
#
# This file is part of the MFEM library. For more information and source code
# availability visit https://mfem.org.
#
# MFEM is free software; you can redistribute it and/or modify it under the
# terms of the BSD-3 license. We welcome feedback and contributions, see file
# CONTRIBUTING.md for details.

# Variables corresponding to defines in config.hpp (YES, NO, or value)
MFEM_VERSION           = 40800
MFEM_VERSION_STRING    = 4.8.0
MFEM_SOURCE_DIR        = C:/A_VisIt/TPBuilds/Build/MFEM/src/MFEM
MFEM_INSTALL_DIR       = C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/mfem/4.8
MFEM_GIT_STRING        = (unknown)
MFEM_USE_MPI           = NO
MFEM_USE_METIS         = NO
MFEM_USE_METIS_5       = NO
MFEM_USE_DOUBLE        = YES
MFEM_USE_SINGLE        = NO
MFEM_DEBUG             = NO
MFEM_USE_EXCEPTIONS    = YES
MFEM_USE_ZLIB          = YES
MFEM_USE_LIBUNWIND     = NO
MFEM_USE_LAPACK        = NO
MFEM_THREAD_SAFE       = NO
MFEM_USE_LEGACY_OPENMP = NO
MFEM_USE_OPENMP        = NO
MFEM_USE_MEMALLOC      = YES
MFEM_TIMER_TYPE        = 3
MFEM_USE_SUNDIALS      = NO
MFEM_USE_SUITESPARSE   = NO
MFEM_USE_SUPERLU       = NO
MFEM_USE_SUPERLU5      = NO
MFEM_USE_MUMPS         = NO
MFEM_USE_STRUMPACK     = NO
MFEM_USE_GINKGO        = NO
MFEM_USE_AMGX          = NO
MFEM_USE_MAGMA         = NO
MFEM_USE_GNUTLS        = NO
MFEM_USE_NETCDF        = NO
MFEM_USE_PETSC         = NO
MFEM_USE_SLEPC         = NO
MFEM_USE_MPFR          = NO
MFEM_USE_SIDRE         = NO
MFEM_USE_FMS           = NO
MFEM_USE_CONDUIT       = YES
MFEM_USE_PUMI          = NO
MFEM_USE_HIOP          = NO
MFEM_USE_GSLIB         = NO
MFEM_USE_CUDA          = NO
MFEM_USE_HIP           = NO
MFEM_USE_RAJA          = NO
MFEM_USE_OCCA          = NO
MFEM_USE_CEED          = NO
MFEM_USE_CALIPER       = NO
MFEM_USE_UMPIRE        = NO
MFEM_USE_SIMD          = NO
MFEM_USE_ADIOS2        = NO
MFEM_USE_MKL_CPARDISO  = NO
MFEM_USE_MKL_PARDISO   = NO
MFEM_USE_MOONOLITH     = NO
MFEM_USE_ADFORWARD     = NO
MFEM_USE_CODIPACK      = NO
MFEM_USE_BENCHMARK     = NO
MFEM_USE_PARELAG       = NO
MFEM_USE_TRIBOL        = NO
MFEM_USE_ENZYME        = NO

# Compiler, compile options, and link options
MFEM_CXX       = C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe
MFEM_HOST_CXX  = C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe
MFEM_CPPFLAGS  = 
MFEM_CXXFLAGS  = /O2 /Ob2 /DNDEBUG /DWIN32 /D_WINDOWS /EHsc
MFEM_TPLFLAGS  =  -IC:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/conduit/0.9.4/include/conduit -IC:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/include -IC:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/zlib/1.2.13/include
MFEM_INCFLAGS  = -I$(MFEM_INC_DIR) $(MFEM_TPLFLAGS)
MFEM_PICFLAG   = 
MFEM_FLAGS     = $(MFEM_CPPFLAGS) $(MFEM_CXXFLAGS) $(MFEM_INCFLAGS)
MFEM_EXT_LIBS  =  C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/conduit/0.9.4/lib/conduit.lib C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/conduit/0.9.4/lib/conduit_blueprint.lib C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/conduit/0.9.4/lib/conduit_relay.lib C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/lib/hdf5_hl.lib C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/lib/hdf5.lib C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/zlib/1.2.13/lib/zlib.lib
MFEM_LIBS      = -Wl,-rpath,$(MFEM_LIB_DIR) -L$(MFEM_LIB_DIR) -lmfem $(MFEM_EXT_LIBS)
MFEM_LIB_FILE  = $(MFEM_LIB_DIR)/libmfem.dll.4.8.0
MFEM_STATIC    = NO
MFEM_SHARED    = YES
MFEM_BUILD_TAG = Windows-10.0.22631
MFEM_PREFIX    = C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/mfem/4.8
MFEM_INC_DIR   = C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/mfem/4.8/include
MFEM_LIB_DIR   = C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/mfem/4.8/lib

# Location of test.mk
MFEM_TEST_MK = C:/A_VisIt/Develop/visit-deps/windowsbuild/MSVC2022/mfem/4.8/share/mfem/test.mk

# Command used to launch MPI jobs
MFEM_MPIEXEC    = mpirun
MFEM_MPIEXEC_NP = -np
MFEM_MPI_NP     = 4

# The NVCC compiler cannot link with -x=cu
MFEM_LINK_FLAGS := $(filter-out -x=cu -xhip, $(MFEM_FLAGS))

# Optional extra configuration

