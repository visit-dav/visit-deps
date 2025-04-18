
#ifndef VTKDICOMPARSER_EXPORT_H
#define VTKDICOMPARSER_EXPORT_H

#ifdef VTKDICOMPARSER_STATIC_DEFINE
#  define VTKDICOMPARSER_EXPORT
#  define VTKDICOMPARSER_NO_EXPORT
#else
#  ifndef VTKDICOMPARSER_EXPORT
#    ifdef DICOMParser_EXPORTS
        /* We are building this library */
#      define VTKDICOMPARSER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKDICOMPARSER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKDICOMPARSER_NO_EXPORT
#    define VTKDICOMPARSER_NO_EXPORT 
#  endif
#endif

#ifndef VTKDICOMPARSER_DEPRECATED
#  define VTKDICOMPARSER_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKDICOMPARSER_DEPRECATED_EXPORT
#  define VTKDICOMPARSER_DEPRECATED_EXPORT VTKDICOMPARSER_EXPORT VTKDICOMPARSER_DEPRECATED
#endif

#ifndef VTKDICOMPARSER_DEPRECATED_NO_EXPORT
#  define VTKDICOMPARSER_DEPRECATED_NO_EXPORT VTKDICOMPARSER_NO_EXPORT VTKDICOMPARSER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKDICOMPARSER_NO_DEPRECATED
#    define VTKDICOMPARSER_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkDICOMParserModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKDICOMPARSER_EXPORT_H */
