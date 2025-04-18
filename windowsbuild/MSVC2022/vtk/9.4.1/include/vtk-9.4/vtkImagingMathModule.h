
#ifndef VTKIMAGINGMATH_EXPORT_H
#define VTKIMAGINGMATH_EXPORT_H

#ifdef VTKIMAGINGMATH_STATIC_DEFINE
#  define VTKIMAGINGMATH_EXPORT
#  define VTKIMAGINGMATH_NO_EXPORT
#else
#  ifndef VTKIMAGINGMATH_EXPORT
#    ifdef ImagingMath_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGMATH_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGMATH_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGMATH_NO_EXPORT
#    define VTKIMAGINGMATH_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGMATH_DEPRECATED
#  define VTKIMAGINGMATH_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIMAGINGMATH_DEPRECATED_EXPORT
#  define VTKIMAGINGMATH_DEPRECATED_EXPORT VTKIMAGINGMATH_EXPORT VTKIMAGINGMATH_DEPRECATED
#endif

#ifndef VTKIMAGINGMATH_DEPRECATED_NO_EXPORT
#  define VTKIMAGINGMATH_DEPRECATED_NO_EXPORT VTKIMAGINGMATH_NO_EXPORT VTKIMAGINGMATH_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIMAGINGMATH_NO_DEPRECATED
#    define VTKIMAGINGMATH_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkImagingMathModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKIMAGINGMATH_EXPORT_H */
