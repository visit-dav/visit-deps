
#ifndef VTKCOMMONSYSTEM_EXPORT_H
#define VTKCOMMONSYSTEM_EXPORT_H

#ifdef VTKCOMMONSYSTEM_STATIC_DEFINE
#  define VTKCOMMONSYSTEM_EXPORT
#  define VTKCOMMONSYSTEM_NO_EXPORT
#else
#  ifndef VTKCOMMONSYSTEM_EXPORT
#    ifdef CommonSystem_EXPORTS
        /* We are building this library */
#      define VTKCOMMONSYSTEM_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONSYSTEM_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONSYSTEM_NO_EXPORT
#    define VTKCOMMONSYSTEM_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONSYSTEM_DEPRECATED
#  define VTKCOMMONSYSTEM_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCOMMONSYSTEM_DEPRECATED_EXPORT
#  define VTKCOMMONSYSTEM_DEPRECATED_EXPORT VTKCOMMONSYSTEM_EXPORT VTKCOMMONSYSTEM_DEPRECATED
#endif

#ifndef VTKCOMMONSYSTEM_DEPRECATED_NO_EXPORT
#  define VTKCOMMONSYSTEM_DEPRECATED_NO_EXPORT VTKCOMMONSYSTEM_NO_EXPORT VTKCOMMONSYSTEM_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONSYSTEM_NO_DEPRECATED
#    define VTKCOMMONSYSTEM_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkCommonSystemModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKCOMMONSYSTEM_EXPORT_H */
