# Copyright (c) 2010, Lawrence Livermore National Security, LLC. Produced at the
# Lawrence Livermore National Laboratory. LLNL-CODE-443211. All Rights reserved.
# See file COPYRIGHT for details.
#
# This file is part of the MFEM library. For more information and source code
# availability see http://mfem.org.
#
# MFEM is free software; you can redistribute it and/or modify it under the
# terms of the GNU Lesser General Public License (as published by the Free
# Software Foundation) version 2.1 dated February 1999.

# Variables corresponding to defines in config.hpp (YES, NO, or value)
MFEM_VERSION           = 40000
MFEM_VERSION_STRING    = 4.0
MFEM_SOURCE_DIR        = C:/A_Visit/ThirdParty/mfem-4.0
MFEM_INSTALL_DIR       = C:/A_Visit/3.1RC/visit-deps/windowsbuild/MSVC2017/mfem/4.0
MFEM_GIT_STRING        = (unknown)
MFEM_USE_MPI           = NO
MFEM_USE_METIS         = NO
MFEM_USE_METIS_5       = NO
MFEM_DEBUG             = NO
MFEM_USE_EXCEPTIONS    = NO
MFEM_USE_GZSTREAM      = NO
MFEM_USE_LIBUNWIND     = NO
MFEM_USE_LAPACK        = NO
MFEM_THREAD_SAFE       = NO
MFEM_USE_LEGACY_OPENMP = NO
MFEM_USE_OPENMP        = NO
MFEM_USE_MEMALLOC      = YES
MFEM_TIMER_TYPE        = 3
MFEM_USE_SUNDIALS      = NO
MFEM_USE_MESQUITE      = NO
MFEM_USE_SUITESPARSE   = NO
MFEM_USE_SUPERLU       = NO
MFEM_USE_STRUMPACK     = NO
MFEM_USE_GECKO         = NO
MFEM_USE_GNUTLS        = NO
MFEM_USE_NETCDF        = NO
MFEM_USE_PETSC         = NO
MFEM_USE_MPFR          = NO
MFEM_USE_SIDRE         = NO
MFEM_USE_CONDUIT       = NO
MFEM_USE_PUMI          = NO
MFEM_USE_CUDA          = NO
MFEM_USE_RAJA          = NO
MFEM_USE_OCCA          = NO

# Compiler, compile options, and link options
MFEM_CXX       = C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe
MFEM_CPPFLAGS  = 
MFEM_CXXFLAGS  = /MD /O2 /Ob2 /DNDEBUG /DWIN32 /D_WINDOWS /W3 /GR /EHsc
MFEM_TPLFLAGS  = 
MFEM_INCFLAGS  = -I$(MFEM_INC_DIR) $(MFEM_TPLFLAGS)
MFEM_PICFLAG   = 
MFEM_FLAGS     = $(MFEM_CPPFLAGS) $(MFEM_CXXFLAGS) $(MFEM_INCFLAGS)
MFEM_EXT_LIBS  = 
MFEM_LIBS      = -L$(MFEM_LIB_DIR) -lmfem $(MFEM_EXT_LIBS)
MFEM_LIB_FILE  = $(MFEM_LIB_DIR)/libmfem.a
MFEM_STATIC    = YES
MFEM_SHARED    = NO
MFEM_BUILD_TAG = Windows-10.0.16299
MFEM_PREFIX    = C:/A_Visit/3.1RC/visit-deps/windowsbuild/MSVC2017/mfem/4.0
MFEM_INC_DIR   = C:/A_Visit/3.1RC/visit-deps/windowsbuild/MSVC2017/mfem/4.0/include
MFEM_LIB_DIR   = C:/A_Visit/3.1RC/visit-deps/windowsbuild/MSVC2017/mfem/4.0/lib

# Location of test.mk
MFEM_TEST_MK = C:/A_Visit/3.1RC/visit-deps/windowsbuild/MSVC2017/mfem/4.0/share/mfem/test.mk

# Command used to launch MPI jobs
MFEM_MPIEXEC    = mpirun
MFEM_MPIEXEC_NP = -np
MFEM_MPI_NP     = 4

# The NVCC compiler cannot link with -x=cu
MFEM_LINK_FLAGS := $(filter-out -x=cu, $(MFEM_FLAGS))

# Optional extra configuration

