// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_exports.h
///
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef CONDUIT_EXPORTS_H
#define CONDUIT_EXPORTS_H
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- define proper lib exports for various platforms -- 
//-----------------------------------------------------------------------------

#define CONDUIT_WINDOWS_DLL_EXPORTS "TRUE"

#if defined(CONDUIT_EXPORTS) || defined(conduit_EXPORTS)
    /* define catch all def */
    #define CONDUIT_EXPORTS_DEFINED 1
#endif

#if defined(_WIN32)
    #if defined(CONDUIT_WINDOWS_DLL_EXPORTS)
        #if defined(CONDUIT_EXPORTS_DEFINED)
            #define CONDUIT_API __declspec(dllexport)
        #else
            #define CONDUIT_API __declspec(dllimport)
        #endif
    #else
        #define CONDUIT_API /* empty for static builds */
    #endif

    #if defined(_MSC_VER)
        /* Turn off warning about lack of DLL interface */
        #pragma warning(disable:4251)
        /* Turn off warning non-dll class is base for dll-interface class */
        #pragma warning(disable:4275)
        /* Turn off warning about identifier truncation */
        #pragma warning(disable:4786)
    #endif
#else
    #if __GNUC__ >= 4 && defined(CONDUIT_EXPORTS_DEFINED)
       #define CONDUIT_API __attribute__ ((visibility("default")))
    #else
        #define CONDUIT_API /* hidden by default */
    #endif
#endif

//-----------------------------------------------------------------------------
// CONDUIT_EXPORTS_H
//-----------------------------------------------------------------------------
#endif




