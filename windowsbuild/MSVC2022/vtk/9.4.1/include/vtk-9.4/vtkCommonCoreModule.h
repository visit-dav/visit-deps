
#ifndef VTKCOMMONCORE_EXPORT_H
#define VTKCOMMONCORE_EXPORT_H

#ifdef VTKCOMMONCORE_STATIC_DEFINE
#  define VTKCOMMONCORE_EXPORT
#  define VTKCOMMONCORE_NO_EXPORT
#else
#  ifndef VTKCOMMONCORE_EXPORT
#    ifdef CommonCore_EXPORTS
        /* We are building this library */
#      define VTKCOMMONCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONCORE_NO_EXPORT
#    define VTKCOMMONCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONCORE_DEPRECATED
#  define VTKCOMMONCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCOMMONCORE_DEPRECATED_EXPORT
#  define VTKCOMMONCORE_DEPRECATED_EXPORT VTKCOMMONCORE_EXPORT VTKCOMMONCORE_DEPRECATED
#endif

#ifndef VTKCOMMONCORE_DEPRECATED_NO_EXPORT
#  define VTKCOMMONCORE_DEPRECATED_NO_EXPORT VTKCOMMONCORE_NO_EXPORT VTKCOMMONCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONCORE_NO_DEPRECATED
#    define VTKCOMMONCORE_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkCommonCoreModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKCOMMONCORE_EXPORT_H */
