//
// C:/A_Visit/ThirdParty/ospray-2.8.0-build2/ospray/build/ospray/texture/TextureParam_ispc.h
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

#ifndef __ISPC_ENUM_TransformFlags__
#define __ISPC_ENUM_TransformFlags__
enum TransformFlags {
    TRANSFORM_FLAG_NONE = 0,
    TRANSFORM_FLAG_2D = 1,
    TRANSFORM_FLAG_3D = 2 
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

#ifndef __ISPC_STRUCT_vec2f__
#define __ISPC_STRUCT_vec2f__
struct vec2f {
    float x;
    float y;
};
#endif

#ifndef __ISPC_STRUCT_LinearSpace2f__
#define __ISPC_STRUCT_LinearSpace2f__
struct LinearSpace2f {
    struct vec2f vx;
    struct vec2f vy;
};
#endif

#ifndef __ISPC_STRUCT_AffineSpace2f__
#define __ISPC_STRUCT_AffineSpace2f__
struct AffineSpace2f {
    struct LinearSpace2f l;
    struct vec2f p;
};
#endif

#ifndef __ISPC_STRUCT_vec3f__
#define __ISPC_STRUCT_vec3f__
struct vec3f {
    float x;
    float y;
    float z;
};
#endif

#ifndef __ISPC_STRUCT_LinearSpace3f__
#define __ISPC_STRUCT_LinearSpace3f__
struct LinearSpace3f {
    struct vec3f vx;
    struct vec3f vy;
    struct vec3f vz;
};
#endif

#ifndef __ISPC_STRUCT_AffineSpace3f__
#define __ISPC_STRUCT_AffineSpace3f__
struct AffineSpace3f {
    struct LinearSpace3f l;
    struct vec3f p;
};
#endif

#ifndef __ISPC_STRUCT_TextureParam__
#define __ISPC_STRUCT_TextureParam__
struct TextureParam {
    struct Texture2D * ptr;
    enum TransformFlags transformFlags;
    struct AffineSpace2f xform2f;
    struct AffineSpace3f xform3f;
};
#endif

#ifndef __ISPC_STRUCT_vec2i__
#define __ISPC_STRUCT_vec2i__
struct vec2i {
    int32_t x;
    int32_t y;
};
#endif

#ifndef __ISPC_STRUCT_Texture2D__
#define __ISPC_STRUCT_Texture2D__
struct Texture2D {
    struct vec2i size;
    struct vec2f sizef;
    struct vec2f halfTexel;
    struct v4_varying_vec4f ( * get)(const struct Texture2D * self, const struct v4_varying_DifferentialGeometry &dg);
    struct v4_varying_vec3f ( * getNormal)(const struct Texture2D * self, const struct v4_varying_DifferentialGeometry &dg);
    void * data;
    bool hasAlpha;
};
#endif

#ifndef __ISPC_STRUCT_v4_varying_vec4f__
#define __ISPC_STRUCT_v4_varying_vec4f__
__ISPC_ALIGNED_STRUCT__(16) v4_varying_vec4f {
    __ISPC_ALIGN__(16) float x[4];
    __ISPC_ALIGN__(16) float y[4];
    __ISPC_ALIGN__(16) float z[4];
    __ISPC_ALIGN__(16) float w[4];
};
#endif

#ifndef __ISPC_STRUCT_v4_varying_vec3f__
#define __ISPC_STRUCT_v4_varying_vec3f__
__ISPC_ALIGNED_STRUCT__(16) v4_varying_vec3f {
    __ISPC_ALIGN__(16) float x[4];
    __ISPC_ALIGN__(16) float y[4];
    __ISPC_ALIGN__(16) float z[4];
};
#endif

#ifndef __ISPC_STRUCT_v4_varying_vec2f__
#define __ISPC_STRUCT_v4_varying_vec2f__
__ISPC_ALIGNED_STRUCT__(16) v4_varying_vec2f {
    __ISPC_ALIGN__(16) float x[4];
    __ISPC_ALIGN__(16) float y[4];
};
#endif

#ifndef __ISPC_STRUCT_v4_varying_DifferentialGeometry__
#define __ISPC_STRUCT_v4_varying_DifferentialGeometry__
__ISPC_ALIGNED_STRUCT__(32) v4_varying_DifferentialGeometry {
    struct v4_varying_vec3f P;
    struct v4_varying_vec3f lP;
    struct v4_varying_vec3f Ng;
    struct v4_varying_vec3f Ns;
    struct v4_varying_vec3f dPds;
    struct v4_varying_vec3f dPdt;
    struct v4_varying_vec2f st;
    struct v4_varying_vec4f color;
    __ISPC_ALIGN__(16) int32_t primID[4];
    __ISPC_ALIGN__(16) float areaPDF[4];
    __ISPC_ALIGN__(16) float epsilon[4];
    __ISPC_ALIGN__(32) struct Material * material;
    const struct Renderer * renderer;
};
#endif


///////////////////////////////////////////////////////////////////////////
// Functions exported from ispc code
///////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus) && (! defined(__ISPC_NO_EXTERN_C) || !__ISPC_NO_EXTERN_C )
extern "C" {
#endif // __cplusplus
    extern void TextureParam_set(struct TextureParam * self, void * ptr, enum TransformFlags transformFlags, const struct AffineSpace2f &xform2f, const struct AffineSpace3f &xform3f);
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

#ifndef __ISPC_STRUCT_v8_varying_vec4f__
#define __ISPC_STRUCT_v8_varying_vec4f__
__ISPC_ALIGNED_STRUCT__(32) v8_varying_vec4f {
    __ISPC_ALIGN__(32) float x[8];
    __ISPC_ALIGN__(32) float y[8];
    __ISPC_ALIGN__(32) float z[8];
    __ISPC_ALIGN__(32) float w[8];
};
#endif

#ifndef __ISPC_STRUCT_v8_varying_vec3f__
#define __ISPC_STRUCT_v8_varying_vec3f__
__ISPC_ALIGNED_STRUCT__(32) v8_varying_vec3f {
    __ISPC_ALIGN__(32) float x[8];
    __ISPC_ALIGN__(32) float y[8];
    __ISPC_ALIGN__(32) float z[8];
};
#endif

#ifndef __ISPC_STRUCT_v8_varying_vec2f__
#define __ISPC_STRUCT_v8_varying_vec2f__
__ISPC_ALIGNED_STRUCT__(32) v8_varying_vec2f {
    __ISPC_ALIGN__(32) float x[8];
    __ISPC_ALIGN__(32) float y[8];
};
#endif

#ifndef __ISPC_STRUCT_v8_varying_DifferentialGeometry__
#define __ISPC_STRUCT_v8_varying_DifferentialGeometry__
__ISPC_ALIGNED_STRUCT__(64) v8_varying_DifferentialGeometry {
    struct v8_varying_vec3f P;
    struct v8_varying_vec3f lP;
    struct v8_varying_vec3f Ng;
    struct v8_varying_vec3f Ns;
    struct v8_varying_vec3f dPds;
    struct v8_varying_vec3f dPdt;
    struct v8_varying_vec2f st;
    struct v8_varying_vec4f color;
    __ISPC_ALIGN__(32) int32_t primID[8];
    __ISPC_ALIGN__(32) float areaPDF[8];
    __ISPC_ALIGN__(32) float epsilon[8];
    __ISPC_ALIGN__(64) struct Material * material;
    const struct Renderer * renderer;
};
#endif



#ifdef __cplusplus
} /* namespace */
#endif // __cplusplus
