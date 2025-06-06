
#ifndef VTKCOMMONMISC_EXPORT_H
#define VTKCOMMONMISC_EXPORT_H

#ifdef VTKCOMMONMISC_STATIC_DEFINE
#  define VTKCOMMONMISC_EXPORT
#  define VTKCOMMONMISC_NO_EXPORT
#else
#  ifndef VTKCOMMONMISC_EXPORT
#    ifdef CommonMisc_EXPORTS
        /* We are building this library */
#      define VTKCOMMONMISC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONMISC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONMISC_NO_EXPORT
#    define VTKCOMMONMISC_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONMISC_DEPRECATED
#  define VTKCOMMONMISC_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCOMMONMISC_DEPRECATED_EXPORT
#  define VTKCOMMONMISC_DEPRECATED_EXPORT VTKCOMMONMISC_EXPORT VTKCOMMONMISC_DEPRECATED
#endif

#ifndef VTKCOMMONMISC_DEPRECATED_NO_EXPORT
#  define VTKCOMMONMISC_DEPRECATED_NO_EXPORT VTKCOMMONMISC_NO_EXPORT VTKCOMMONMISC_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONMISC_NO_DEPRECATED
#    define VTKCOMMONMISC_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkCommonMiscModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKCOMMONMISC_EXPORT_H */
