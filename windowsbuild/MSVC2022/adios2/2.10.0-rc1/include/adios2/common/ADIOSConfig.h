/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 */

#ifndef ADIOSCONFIG_H_
#define ADIOSCONFIG_H_

/* ADIOS Version Information */
#define ADIOS2_VERSION_STR   "2.10.0"
#define ADIOS2_VERSION_MAJOR 2
#define ADIOS2_VERSION_MINOR 10
#define ADIOS2_VERSION_PATCH 0
/* #undef ADIOS2_VERSION_TWEAK */

#define ADIOS2_VERSION (ADIOS2_VERSION_MAJOR* 10000 + ADIOS2_VERSION_MINOR * 100 + ADIOS2_VERSION_PATCH)

/*
 * ADIOS Build Information:
 *
 * Compiler:
 *   C: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.38.33130/bin/Hostx64/x64/cl.exe
 *     Id: MSVC 19.38.33134.0
 *   CXX: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.38.33130/bin/Hostx64/x64/cl.exe
 *     Id: MSVC 19.38.33134.0
 *   Fortran: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.38.33130/bin/Hostx64/x64/cl.exe
 *     Id:  19.38.33134.0
 */

/* Everything between here and the note below is programatically generated */


/* CMake Option: ADIOS2_USE_DataMan=OFF */
/* #undef ADIOS2_HAVE_DATAMAN */

/* CMake Option: ADIOS2_USE_DataSpaces=OFF */
/* #undef ADIOS2_HAVE_DATASPACES */

/* CMake Option: ADIOS2_USE_HDF5=OFF */
#define ADIOS2_HAVE_HDF5

/* CMake Option: ADIOS2_USE_HDF5_VOL=OFF */
/* #undef ADIOS2_HAVE_HDF5_VOL */

/* CMake Option: ADIOS2_USE_MHS=OFF */
#define ADIOS2_HAVE_MHS

/* CMake Option: ADIOS2_USE_SST=OFF */
/* #undef ADIOS2_HAVE_SST */

/* CMake Option: ADIOS2_USE_Fortran=OFF */
/* #undef ADIOS2_HAVE_FORTRAN */

/* CMake Option: ADIOS2_USE_MPI=OFF */
#define ADIOS2_HAVE_MPI

/* CMake Option: ADIOS2_USE_Python=OFF */
/* #undef ADIOS2_HAVE_PYTHON */

/* CMake Option: ADIOS2_USE_PIP=OFF */
/* #undef ADIOS2_HAVE_PIP */

/* CMake Option: ADIOS2_USE_Blosc2=OFF */
#define ADIOS2_HAVE_BLOSC2

/* CMake Option: ADIOS2_USE_BZip2=OFF */
/* #undef ADIOS2_HAVE_BZIP2 */

/* CMake Option: ADIOS2_USE_LIBPRESSIO=OFF */
/* #undef ADIOS2_HAVE_LIBPRESSIO */

/* CMake Option: ADIOS2_USE_MGARD=OFF */
/* #undef ADIOS2_HAVE_MGARD */

/* CMake Option: ADIOS2_USE_MGARD_MDR=OFF */
/* #undef ADIOS2_HAVE_MGARD_MDR */

/* CMake Option: ADIOS2_USE_PNG=OFF */
/* #undef ADIOS2_HAVE_PNG */

/* CMake Option: ADIOS2_USE_SZ=OFF */
/* #undef ADIOS2_HAVE_SZ */

/* CMake Option: ADIOS2_USE_ZFP=OFF */
/* #undef ADIOS2_HAVE_ZFP */

/* CMake Option: ADIOS2_USE_DAOS=OFF */
/* #undef ADIOS2_HAVE_DAOS */

/* CMake Option: ADIOS2_USE_IME=OFF */
/* #undef ADIOS2_HAVE_IME */

/* CMake Option: ADIOS2_USE_O_DIRECT=OFF */
/* #undef ADIOS2_HAVE_O_DIRECT */

/* CMake Option: ADIOS2_USE_Sodium=OFF */
/* #undef ADIOS2_HAVE_SODIUM */

/* CMake Option: ADIOS2_USE_Catalyst=OFF */
/* #undef ADIOS2_HAVE_CATALYST */

/* CMake Option: ADIOS2_USE_SysVShMem=OFF */
/* #undef ADIOS2_HAVE_SYSVSHMEM */

/* CMake Option: ADIOS2_USE_UCX=OFF */
/* #undef ADIOS2_HAVE_UCX */

/* CMake Option: ADIOS2_USE_ZeroMQ=OFF */
/* #undef ADIOS2_HAVE_ZEROMQ */

/* CMake Option: ADIOS2_USE_Profiling=OFF */
#define ADIOS2_HAVE_PROFILING

/* CMake Option: ADIOS2_USE_Endian_Reverse=OFF */
/* #undef ADIOS2_HAVE_ENDIAN_REVERSE */

/* CMake Option: ADIOS2_USE_Derived_Variable=OFF */
/* #undef ADIOS2_HAVE_DERIVED_VARIABLE */

/* CMake Option: ADIOS2_USE_AWSSDK=OFF */
/* #undef ADIOS2_HAVE_AWSSDK */

/* CMake Option: ADIOS2_USE_GPU_Support=OFF */
/* #undef ADIOS2_HAVE_GPU_SUPPORT */

/* CMake Option: ADIOS2_USE_CUDA=OFF */
/* #undef ADIOS2_HAVE_CUDA */

/* CMake Option: ADIOS2_USE_Kokkos=OFF */
/* #undef ADIOS2_HAVE_KOKKOS */

/* CMake Option: ADIOS2_USE_Kokkos_CUDA=OFF */
/* #undef ADIOS2_HAVE_KOKKOS_CUDA */

/* CMake Option: ADIOS2_USE_Kokkos_HIP=OFF */
/* #undef ADIOS2_HAVE_KOKKOS_HIP */

/* CMake Option: ADIOS2_USE_Kokkos_SYCL=OFF */
/* #undef ADIOS2_HAVE_KOKKOS_SYCL */

/* CMake Option: ADIOS2_USE_Campaign=OFF */
/* #undef ADIOS2_HAVE_CAMPAIGN */


#define ADIOS2_FEATURE_LIST "HDF5","MHS","MPI","BLOSC2","PROFILING",nullptr

/* Everything between here and the note above is programatically generated */

#ifndef ADIOS2_USE_MPI
#  define ADIOS2_USE_MPI 0
#endif

#if ADIOS2_USE_MPI && !defined(ADIOS2_HAVE_MPI)
#  error "ADIOS2 was not built with MPI enabled."
#endif

#ifndef ADIOS2_DEPRECATED
#  if defined(__GNUC__) || defined (__clang__)
#    define ADIOS2_DEPRECATED __attribute__((deprecated))
#  elif defined(_MSC_VER)
#    define ADIOS2_DEPRECATED __declspec(deprecated)
#  else
#    define ADIOS2_DEPRECATED
#  endif
#endif

#endif /* ADIOSCONFIG_H_ */
