
#ifndef VTKGEOVISCORE_EXPORT_H
#define VTKGEOVISCORE_EXPORT_H

#ifdef VTKGEOVISCORE_STATIC_DEFINE
#  define VTKGEOVISCORE_EXPORT
#  define VTKGEOVISCORE_NO_EXPORT
#else
#  ifndef VTKGEOVISCORE_EXPORT
#    ifdef GeovisCore_EXPORTS
        /* We are building this library */
#      define VTKGEOVISCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKGEOVISCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKGEOVISCORE_NO_EXPORT
#    define VTKGEOVISCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKGEOVISCORE_DEPRECATED
#  define VTKGEOVISCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKGEOVISCORE_DEPRECATED_EXPORT
#  define VTKGEOVISCORE_DEPRECATED_EXPORT VTKGEOVISCORE_EXPORT VTKGEOVISCORE_DEPRECATED
#endif

#ifndef VTKGEOVISCORE_DEPRECATED_NO_EXPORT
#  define VTKGEOVISCORE_DEPRECATED_NO_EXPORT VTKGEOVISCORE_NO_EXPORT VTKGEOVISCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKGEOVISCORE_NO_DEPRECATED
#    define VTKGEOVISCORE_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkGeovisCoreModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKGEOVISCORE_EXPORT_H */
