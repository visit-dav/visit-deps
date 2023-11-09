//
// C:/A_VisIt/ThirdParty/ospray-3.0.0-build/ospray/build/modules/cpu/lights/AmbientLight_ispc.h
// (Header automatically generated by the ispc compiler.)
// DO NOT EDIT THIS FILE.
//

#pragma once
#include <stdint.h>



#ifdef __cplusplus
namespace ispc { /* namespace */
#endif // __cplusplus


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

#ifndef __ISPC_STRUCT___VKLObject__
#define __ISPC_STRUCT___VKLObject__
struct __VKLObject {
    void * host;
    void * device;
};
#endif

#ifndef __ISPC_STRUCT___vkl_vec3f__
#define __ISPC_STRUCT___vkl_vec3f__
struct __vkl_vec3f {
    float x;
    float y;
    float z;
};
#endif

#ifndef __ISPC_STRUCT___vkl_box3f__
#define __ISPC_STRUCT___vkl_box3f__
struct __vkl_box3f {
    struct __vkl_vec3f lower;
    struct __vkl_vec3f upper;
};
#endif

#ifndef __ISPC_STRUCT___vkl_box1f__
#define __ISPC_STRUCT___vkl_box1f__
struct __vkl_box1f {
    float lower;
    float upper;
};
#endif


///////////////////////////////////////////////////////////////////////////
// Functions exported from ispc code
///////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus) && (! defined(__ISPC_NO_EXTERN_C) || !__ISPC_NO_EXTERN_C )
extern "C" {
#endif // __cplusplus
    extern void *  AmbientLight_eval_addr();
    extern void *  AmbientLight_sample_addr();
#if defined(__cplusplus) && (! defined(__ISPC_NO_EXTERN_C) || !__ISPC_NO_EXTERN_C )
} /* end extern C */
#endif // __cplusplus


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
