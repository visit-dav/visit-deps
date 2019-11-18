/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 */

#ifndef ADIOSCONFIG_H_
#define ADIOSCONFIG_H_

/* ADIOS Version Information */
#define ADIOS2_VERSION_STR   "2.5.0"
#define ADIOS2_VERSION_MAJOR 2
#define ADIOS2_VERSION_MINOR 5
#define ADIOS2_VERSION_PATCH 0
/* #undef ADIOS2_VERSION_TWEAK */

/*
 * ADIOS Build Information:
 *
 * Compiler:
 *   C: C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe
 *     Id: MSVC 19.16.27034.0
 *   CXX: C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe
 *     Id: MSVC 19.16.27034.0
 *   Fortran: C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe
 *     Id:  19.16.27034.0
 */

/* Everything past this line is programatically generated */


/* CMake Option: ADIOS_USE_Blosc=OFF */
/* #undef ADIOS2_HAVE_BLOSC */

/* CMake Option: ADIOS_USE_BZip2=OFF */
/* #undef ADIOS2_HAVE_BZIP2 */

/* CMake Option: ADIOS_USE_ZFP=OFF */
/* #undef ADIOS2_HAVE_ZFP */

/* CMake Option: ADIOS_USE_SZ=OFF */
/* #undef ADIOS2_HAVE_SZ */

/* CMake Option: ADIOS_USE_MGARD=OFF */
/* #undef ADIOS2_HAVE_MGARD */

/* CMake Option: ADIOS_USE_PNG=OFF */
/* #undef ADIOS2_HAVE_PNG */

/* CMake Option: ADIOS_USE_MPI=OFF */
#define ADIOS2_HAVE_MPI

/* CMake Option: ADIOS_USE_DataMan=OFF */
/* #undef ADIOS2_HAVE_DATAMAN */

/* CMake Option: ADIOS_USE_Table=OFF */
/* #undef ADIOS2_HAVE_TABLE */

/* CMake Option: ADIOS_USE_SSC=OFF */
/* #undef ADIOS2_HAVE_SSC */

/* CMake Option: ADIOS_USE_SST=OFF */
/* #undef ADIOS2_HAVE_SST */

/* CMake Option: ADIOS_USE_DataSpaces=OFF */
/* #undef ADIOS2_HAVE_DATASPACES */

/* CMake Option: ADIOS_USE_ZeroMQ=OFF */
/* #undef ADIOS2_HAVE_ZEROMQ */

/* CMake Option: ADIOS_USE_HDF5=OFF */
/* #undef ADIOS2_HAVE_HDF5 */

/* CMake Option: ADIOS_USE_Python=OFF */
/* #undef ADIOS2_HAVE_PYTHON */

/* CMake Option: ADIOS_USE_Fortran=OFF */
/* #undef ADIOS2_HAVE_FORTRAN */

/* CMake Option: ADIOS_USE_SysVShMem=OFF */
/* #undef ADIOS2_HAVE_SYSVSHMEM */

/* CMake Option: ADIOS_USE_Profiling=OFF */
#define ADIOS2_HAVE_PROFILING

/* CMake Option: ADIOS_USE_Endian_Reverse=OFF */
/* #undef ADIOS2_HAVE_ENDIAN_REVERSE */


#endif /* ADIOSCONFIG_H_ */
