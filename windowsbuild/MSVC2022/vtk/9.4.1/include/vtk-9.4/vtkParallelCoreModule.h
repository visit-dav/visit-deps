
#ifndef VTKPARALLELCORE_EXPORT_H
#define VTKPARALLELCORE_EXPORT_H

#ifdef VTKPARALLELCORE_STATIC_DEFINE
#  define VTKPARALLELCORE_EXPORT
#  define VTKPARALLELCORE_NO_EXPORT
#else
#  ifndef VTKPARALLELCORE_EXPORT
#    ifdef ParallelCore_EXPORTS
        /* We are building this library */
#      define VTKPARALLELCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPARALLELCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPARALLELCORE_NO_EXPORT
#    define VTKPARALLELCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKPARALLELCORE_DEPRECATED
#  define VTKPARALLELCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKPARALLELCORE_DEPRECATED_EXPORT
#  define VTKPARALLELCORE_DEPRECATED_EXPORT VTKPARALLELCORE_EXPORT VTKPARALLELCORE_DEPRECATED
#endif

#ifndef VTKPARALLELCORE_DEPRECATED_NO_EXPORT
#  define VTKPARALLELCORE_DEPRECATED_NO_EXPORT VTKPARALLELCORE_NO_EXPORT VTKPARALLELCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKPARALLELCORE_NO_DEPRECATED
#    define VTKPARALLELCORE_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkParallelCoreModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKPARALLELCORE_EXPORT_H */
