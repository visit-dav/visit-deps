
#ifndef VTKRENDERINGANARI_EXPORT_H
#define VTKRENDERINGANARI_EXPORT_H

#ifdef VTKRENDERINGANARI_STATIC_DEFINE
#  define VTKRENDERINGANARI_EXPORT
#  define VTKRENDERINGANARI_NO_EXPORT
#else
#  ifndef VTKRENDERINGANARI_EXPORT
#    ifdef RenderingAnari_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGANARI_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGANARI_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGANARI_NO_EXPORT
#    define VTKRENDERINGANARI_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGANARI_DEPRECATED
#  define VTKRENDERINGANARI_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGANARI_DEPRECATED_EXPORT
#  define VTKRENDERINGANARI_DEPRECATED_EXPORT VTKRENDERINGANARI_EXPORT VTKRENDERINGANARI_DEPRECATED
#endif

#ifndef VTKRENDERINGANARI_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGANARI_DEPRECATED_NO_EXPORT VTKRENDERINGANARI_NO_EXPORT VTKRENDERINGANARI_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGANARI_NO_DEPRECATED
#    define VTKRENDERINGANARI_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkRenderingAnariModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"
/* AutoInit dependencies. */
#include "vtkRenderingOpenGL2Module.h"
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingVolumeModule.h"
#include "vtkRenderingVolumeOpenGL2Module.h"


/* AutoInit implementations. */
#ifdef vtkRenderingAnari_AUTOINIT_INCLUDE
#include vtkRenderingAnari_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingAnari_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingAnari)
#endif

#endif /* VTKRENDERINGANARI_EXPORT_H */
