
#ifndef VTKRENDERINGVOLUMEOPENGL2_EXPORT_H
#define VTKRENDERINGVOLUMEOPENGL2_EXPORT_H

#ifdef VTKRENDERINGVOLUMEOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGVOLUMEOPENGL2_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGVOLUMEOPENGL2_EXPORT
#    ifdef RenderingVolumeOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGVOLUMEOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGVOLUMEOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT
#    define VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_EXPORT VTKRENDERINGVOLUMEOPENGL2_EXPORT VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGVOLUMEOPENGL2_NO_DEPRECATED
#    define VTKRENDERINGVOLUMEOPENGL2_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkRenderingVolumeOpenGL2Module.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingOpenGL2Module.h"
#include "vtkRenderingVolumeModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingVolumeOpenGL2_AUTOINIT_INCLUDE
#include vtkRenderingVolumeOpenGL2_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingVolumeOpenGL2_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingVolumeOpenGL2)
#endif

#endif /* VTKRENDERINGVOLUMEOPENGL2_EXPORT_H */
