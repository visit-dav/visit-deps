
#ifndef VTKFILTERSAMR_EXPORT_H
#define VTKFILTERSAMR_EXPORT_H

#ifdef VTKFILTERSAMR_STATIC_DEFINE
#  define VTKFILTERSAMR_EXPORT
#  define VTKFILTERSAMR_NO_EXPORT
#else
#  ifndef VTKFILTERSAMR_EXPORT
#    ifdef FiltersAMR_EXPORTS
        /* We are building this library */
#      define VTKFILTERSAMR_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSAMR_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSAMR_NO_EXPORT
#    define VTKFILTERSAMR_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSAMR_DEPRECATED
#  define VTKFILTERSAMR_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSAMR_DEPRECATED_EXPORT
#  define VTKFILTERSAMR_DEPRECATED_EXPORT VTKFILTERSAMR_EXPORT VTKFILTERSAMR_DEPRECATED
#endif

#ifndef VTKFILTERSAMR_DEPRECATED_NO_EXPORT
#  define VTKFILTERSAMR_DEPRECATED_NO_EXPORT VTKFILTERSAMR_NO_EXPORT VTKFILTERSAMR_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSAMR_NO_DEPRECATED
#    define VTKFILTERSAMR_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkFiltersAMRModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKFILTERSAMR_EXPORT_H */
