
#ifndef VTKIMAGINGCORE_EXPORT_H
#define VTKIMAGINGCORE_EXPORT_H

#ifdef VTKIMAGINGCORE_STATIC_DEFINE
#  define VTKIMAGINGCORE_EXPORT
#  define VTKIMAGINGCORE_NO_EXPORT
#else
#  ifndef VTKIMAGINGCORE_EXPORT
#    ifdef ImagingCore_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGCORE_NO_EXPORT
#    define VTKIMAGINGCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGCORE_DEPRECATED
#  define VTKIMAGINGCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIMAGINGCORE_DEPRECATED_EXPORT
#  define VTKIMAGINGCORE_DEPRECATED_EXPORT VTKIMAGINGCORE_EXPORT VTKIMAGINGCORE_DEPRECATED
#endif

#ifndef VTKIMAGINGCORE_DEPRECATED_NO_EXPORT
#  define VTKIMAGINGCORE_DEPRECATED_NO_EXPORT VTKIMAGINGCORE_NO_EXPORT VTKIMAGINGCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIMAGINGCORE_NO_DEPRECATED
#    define VTKIMAGINGCORE_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkImagingCoreModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKIMAGINGCORE_EXPORT_H */
