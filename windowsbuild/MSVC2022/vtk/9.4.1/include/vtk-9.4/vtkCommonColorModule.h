
#ifndef VTKCOMMONCOLOR_EXPORT_H
#define VTKCOMMONCOLOR_EXPORT_H

#ifdef VTKCOMMONCOLOR_STATIC_DEFINE
#  define VTKCOMMONCOLOR_EXPORT
#  define VTKCOMMONCOLOR_NO_EXPORT
#else
#  ifndef VTKCOMMONCOLOR_EXPORT
#    ifdef CommonColor_EXPORTS
        /* We are building this library */
#      define VTKCOMMONCOLOR_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONCOLOR_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONCOLOR_NO_EXPORT
#    define VTKCOMMONCOLOR_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED
#  define VTKCOMMONCOLOR_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED_EXPORT
#  define VTKCOMMONCOLOR_DEPRECATED_EXPORT VTKCOMMONCOLOR_EXPORT VTKCOMMONCOLOR_DEPRECATED
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED_NO_EXPORT
#  define VTKCOMMONCOLOR_DEPRECATED_NO_EXPORT VTKCOMMONCOLOR_NO_EXPORT VTKCOMMONCOLOR_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONCOLOR_NO_DEPRECATED
#    define VTKCOMMONCOLOR_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkCommonColorModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKCOMMONCOLOR_EXPORT_H */
