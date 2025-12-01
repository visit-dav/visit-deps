
#ifndef VTKFILTERSTEMPORAL_EXPORT_H
#define VTKFILTERSTEMPORAL_EXPORT_H

#ifdef VTKFILTERSTEMPORAL_STATIC_DEFINE
#  define VTKFILTERSTEMPORAL_EXPORT
#  define VTKFILTERSTEMPORAL_NO_EXPORT
#else
#  ifndef VTKFILTERSTEMPORAL_EXPORT
#    ifdef FiltersTemporal_EXPORTS
        /* We are building this library */
#      define VTKFILTERSTEMPORAL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSTEMPORAL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSTEMPORAL_NO_EXPORT
#    define VTKFILTERSTEMPORAL_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSTEMPORAL_DEPRECATED
#  define VTKFILTERSTEMPORAL_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSTEMPORAL_DEPRECATED_EXPORT
#  define VTKFILTERSTEMPORAL_DEPRECATED_EXPORT VTKFILTERSTEMPORAL_EXPORT VTKFILTERSTEMPORAL_DEPRECATED
#endif

#ifndef VTKFILTERSTEMPORAL_DEPRECATED_NO_EXPORT
#  define VTKFILTERSTEMPORAL_DEPRECATED_NO_EXPORT VTKFILTERSTEMPORAL_NO_EXPORT VTKFILTERSTEMPORAL_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSTEMPORAL_NO_DEPRECATED
#    define VTKFILTERSTEMPORAL_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkFiltersTemporalModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKFILTERSTEMPORAL_EXPORT_H */
