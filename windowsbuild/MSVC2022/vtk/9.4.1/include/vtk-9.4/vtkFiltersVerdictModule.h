
#ifndef VTKFILTERSVERDICT_EXPORT_H
#define VTKFILTERSVERDICT_EXPORT_H

#ifdef VTKFILTERSVERDICT_STATIC_DEFINE
#  define VTKFILTERSVERDICT_EXPORT
#  define VTKFILTERSVERDICT_NO_EXPORT
#else
#  ifndef VTKFILTERSVERDICT_EXPORT
#    ifdef FiltersVerdict_EXPORTS
        /* We are building this library */
#      define VTKFILTERSVERDICT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSVERDICT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSVERDICT_NO_EXPORT
#    define VTKFILTERSVERDICT_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSVERDICT_DEPRECATED
#  define VTKFILTERSVERDICT_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSVERDICT_DEPRECATED_EXPORT
#  define VTKFILTERSVERDICT_DEPRECATED_EXPORT VTKFILTERSVERDICT_EXPORT VTKFILTERSVERDICT_DEPRECATED
#endif

#ifndef VTKFILTERSVERDICT_DEPRECATED_NO_EXPORT
#  define VTKFILTERSVERDICT_DEPRECATED_NO_EXPORT VTKFILTERSVERDICT_NO_EXPORT VTKFILTERSVERDICT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSVERDICT_NO_DEPRECATED
#    define VTKFILTERSVERDICT_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkFiltersVerdictModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKFILTERSVERDICT_EXPORT_H */
