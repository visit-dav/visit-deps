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

#define CONDUIT_INSTALL_PREFIX ""

// version info
#define CONDUIT_VERSION "0.8.3"
#define CONDUIT_VERSION_MAJOR 0
#define CONDUIT_VERSION_MINOR 8
#define CONDUIT_VERSION_PATCH 3

#define CONDUIT_GIT_SHA1 "unknown"
#define CONDUIT_GIT_SHA1_ABBREV "unknown"
#define CONDUIT_GIT_TAG "unknown"

#define CONDUIT_SYSTEM_TYPE "Windows-10.0.19042"

#define CONDUIT_CPP_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe"

/* #undef CONDUIT_FORTRAN_COMPILER */

#define CONDUIT_USE_FMT

#define CONDUIT_USE_CXX11

#endif



