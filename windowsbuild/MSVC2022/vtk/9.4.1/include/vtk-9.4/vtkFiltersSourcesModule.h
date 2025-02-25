
#ifndef VTKFILTERSSOURCES_EXPORT_H
#define VTKFILTERSSOURCES_EXPORT_H

#ifdef VTKFILTERSSOURCES_STATIC_DEFINE
#  define VTKFILTERSSOURCES_EXPORT
#  define VTKFILTERSSOURCES_NO_EXPORT
#else
#  ifndef VTKFILTERSSOURCES_EXPORT
#    ifdef FiltersSources_EXPORTS
        /* We are building this library */
#      define VTKFILTERSSOURCES_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSSOURCES_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSSOURCES_NO_EXPORT
#    define VTKFILTERSSOURCES_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSSOURCES_DEPRECATED
#  define VTKFILTERSSOURCES_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSSOURCES_DEPRECATED_EXPORT
#  define VTKFILTERSSOURCES_DEPRECATED_EXPORT VTKFILTERSSOURCES_EXPORT VTKFILTERSSOURCES_DEPRECATED
#endif

#ifndef VTKFILTERSSOURCES_DEPRECATED_NO_EXPORT
#  define VTKFILTERSSOURCES_DEPRECATED_NO_EXPORT VTKFILTERSSOURCES_NO_EXPORT VTKFILTERSSOURCES_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSSOURCES_NO_DEPRECATED
#    define VTKFILTERSSOURCES_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkFiltersSourcesModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKFILTERSSOURCES_EXPORT_H */
