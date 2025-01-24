
#ifndef VTKFILTERSHYPERTREE_EXPORT_H
#define VTKFILTERSHYPERTREE_EXPORT_H

#ifdef VTKFILTERSHYPERTREE_STATIC_DEFINE
#  define VTKFILTERSHYPERTREE_EXPORT
#  define VTKFILTERSHYPERTREE_NO_EXPORT
#else
#  ifndef VTKFILTERSHYPERTREE_EXPORT
#    ifdef FiltersHyperTree_EXPORTS
        /* We are building this library */
#      define VTKFILTERSHYPERTREE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSHYPERTREE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSHYPERTREE_NO_EXPORT
#    define VTKFILTERSHYPERTREE_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSHYPERTREE_DEPRECATED
#  define VTKFILTERSHYPERTREE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSHYPERTREE_DEPRECATED_EXPORT
#  define VTKFILTERSHYPERTREE_DEPRECATED_EXPORT VTKFILTERSHYPERTREE_EXPORT VTKFILTERSHYPERTREE_DEPRECATED
#endif

#ifndef VTKFILTERSHYPERTREE_DEPRECATED_NO_EXPORT
#  define VTKFILTERSHYPERTREE_DEPRECATED_NO_EXPORT VTKFILTERSHYPERTREE_NO_EXPORT VTKFILTERSHYPERTREE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSHYPERTREE_NO_DEPRECATED
#    define VTKFILTERSHYPERTREE_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkFiltersHyperTreeModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKFILTERSHYPERTREE_EXPORT_H */
