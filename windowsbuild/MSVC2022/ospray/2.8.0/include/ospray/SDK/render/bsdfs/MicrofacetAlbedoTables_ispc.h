//
// C:/A_Visit/ThirdParty/ospray-2.8.0-build/ospray/build/ospray/render/bsdfs/MicrofacetAlbedoTables_ispc.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#pragma once
#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus

///////////////////////////////////////////////////////////////////////////
// Enumerator types with external visibility from ispc code
///////////////////////////////////////////////////////////////////////////

#ifndef __ISPC_ENUM___
#define __ISPC_ENUM___
enum {
    ISPC_MSG_SPHERES = 0,
    ISPC_MSG_SHADING_CONTEXT = 1,
    ISPC_MSG_MAX = 2 
};
#endif

#ifndef __ISPC_ENUM___
#define __ISPC_ENUM___
enum {
    OSP_LOG_DEBUG = 1,
    OSP_LOG_INFO = 2,
    OSP_LOG_WARNING = 3,
    OSP_LOG_ERROR = 4,
    OSP_LOG_NONE = 5 
};
#endif


#ifndef __ISPC_ALIGN__
#if defined(__clang__) || !defined(_MSC_VER)
// Clang, GCC, ICC
#define __ISPC_ALIGN__(s) __attribute__((aligned(s)))
#define __ISPC_ALIGNED_STRUCT__(s) struct __ISPC_ALIGN__(s)
#else
// Visual Studio
#define __ISPC_ALIGN__(s) __declspec(align(s))
#define __ISPC_ALIGNED_STRUCT__(s) __ISPC_ALIGN__(s) struct
#endif
#endif


#ifndef __ISPC_ALIGN__
#if defined(__clang__) || !defined(_MSC_VER)
// Clang, GCC, ICC
#define __ISPC_ALIGN__(s) __attribute__((aligned(s)))
#define __ISPC_ALIGNED_STRUCT__(s) struct __ISPC_ALIGN__(s)
#else
// Visual Studio
#define __ISPC_ALIGN__(s) __declspec(align(s))
#define __ISPC_ALIGNED_STRUCT__(s) __ISPC_ALIGN__(s) struct
#endif
#endif



#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus