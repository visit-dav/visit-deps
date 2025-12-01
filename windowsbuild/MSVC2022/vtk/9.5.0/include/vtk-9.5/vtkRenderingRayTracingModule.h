
#ifndef VTKRENDERINGRAYTRACING_EXPORT_H
#define VTKRENDERINGRAYTRACING_EXPORT_H

#ifdef VTKRENDERINGRAYTRACING_STATIC_DEFINE
#  define VTKRENDERINGRAYTRACING_EXPORT
#  define VTKRENDERINGRAYTRACING_NO_EXPORT
#else
#  ifndef VTKRENDERINGRAYTRACING_EXPORT
#    ifdef RenderingRayTracing_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGRAYTRACING_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGRAYTRACING_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGRAYTRACING_NO_EXPORT
#    define VTKRENDERINGRAYTRACING_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGRAYTRACING_DEPRECATED
#  define VTKRENDERINGRAYTRACING_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGRAYTRACING_DEPRECATED_EXPORT
#  define VTKRENDERINGRAYTRACING_DEPRECATED_EXPORT VTKRENDERINGRAYTRACING_EXPORT VTKRENDERINGRAYTRACING_DEPRECATED
#endif

#ifndef VTKRENDERINGRAYTRACING_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGRAYTRACING_DEPRECATED_NO_EXPORT VTKRENDERINGRAYTRACING_NO_EXPORT VTKRENDERINGRAYTRACING_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGRAYTRACING_NO_DEPRECATED
#    define VTKRENDERINGRAYTRACING_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkRenderingRayTracingModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"
/* AutoInit dependencies. */
#include "vtkDomainsChemistryModule.h"
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingOpenGL2Module.h"
#include "vtkRenderingVolumeModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingRayTracing_AUTOINIT_INCLUDE
#include vtkRenderingRayTracing_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingRayTracing_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingRayTracing)
#endif

#endif /* VTKRENDERINGRAYTRACING_EXPORT_H */
