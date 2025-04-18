
#ifndef VTKRENDERINGFREETYPE_EXPORT_H
#define VTKRENDERINGFREETYPE_EXPORT_H

#ifdef VTKRENDERINGFREETYPE_STATIC_DEFINE
#  define VTKRENDERINGFREETYPE_EXPORT
#  define VTKRENDERINGFREETYPE_NO_EXPORT
#else
#  ifndef VTKRENDERINGFREETYPE_EXPORT
#    ifdef RenderingFreeType_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGFREETYPE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGFREETYPE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGFREETYPE_NO_EXPORT
#    define VTKRENDERINGFREETYPE_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGFREETYPE_DEPRECATED
#  define VTKRENDERINGFREETYPE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGFREETYPE_DEPRECATED_EXPORT
#  define VTKRENDERINGFREETYPE_DEPRECATED_EXPORT VTKRENDERINGFREETYPE_EXPORT VTKRENDERINGFREETYPE_DEPRECATED
#endif

#ifndef VTKRENDERINGFREETYPE_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGFREETYPE_DEPRECATED_NO_EXPORT VTKRENDERINGFREETYPE_NO_EXPORT VTKRENDERINGFREETYPE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGFREETYPE_NO_DEPRECATED
#    define VTKRENDERINGFREETYPE_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkRenderingFreeTypeModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingFreeType_AUTOINIT_INCLUDE
#include vtkRenderingFreeType_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingFreeType_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingFreeType)
#endif

#endif /* VTKRENDERINGFREETYPE_EXPORT_H */
