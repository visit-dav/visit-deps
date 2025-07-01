// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_config.h
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_CONFIG_H
#define CONDUIT_CONFIG_H

//-----------------------------------------------------------------------------
//
// #define platform check helpers
//
//-----------------------------------------------------------------------------

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define CONDUIT_PLATFORM_WINDOWS
#elif  defined(__APPLE__)
#define CONDUIT_PLATFORM_APPLE
#else
#define CONDUIT_PLATFORM_UNIX
#endif

#define CONDUIT_INSTALL_PREFIX "C:\\A_VisIt\\3.4RC\\visit-deps\\windowsbuild\\MSVC2022\\conduit\\0.9.4"

// version info
#define CONDUIT_VERSION "0.9.4"
#define CONDUIT_VERSION_MAJOR 0
#define CONDUIT_VERSION_MINOR 9
#define CONDUIT_VERSION_PATCH 4

#define CONDUIT_GIT_SHA1 "unknown-dirty"
#define CONDUIT_GIT_SHA1_ABBREV "unknown"
#define CONDUIT_GIT_TAG "unknown"

#define CONDUIT_SYSTEM_TYPE "Windows-10.0.22631"

#define CONDUIT_CPP_COMPILER "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe"

/* #undef CONDUIT_FORTRAN_COMPILER */

#define CONDUIT_USE_FMT

// keep CONDUIT_USE_CXX11 to support old logic
#define CONDUIT_USE_CXX11

#define CONDUIT_USE_CXX14

#define CONDUIT_USE_YYJSON

/* #undef CONDUIT_USE_CALIPER */

/* #undef CONDUIT_USE_OPENMP */

/* #undef CONDUIT_USE_PARMETIS */

/* #undef CONDUIT_USE_TOTALVIEW */


#endif


