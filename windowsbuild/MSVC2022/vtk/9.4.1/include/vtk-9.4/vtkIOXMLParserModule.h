
#ifndef VTKIOXMLPARSER_EXPORT_H
#define VTKIOXMLPARSER_EXPORT_H

#ifdef VTKIOXMLPARSER_STATIC_DEFINE
#  define VTKIOXMLPARSER_EXPORT
#  define VTKIOXMLPARSER_NO_EXPORT
#else
#  ifndef VTKIOXMLPARSER_EXPORT
#    ifdef IOXMLParser_EXPORTS
        /* We are building this library */
#      define VTKIOXMLPARSER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOXMLPARSER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOXMLPARSER_NO_EXPORT
#    define VTKIOXMLPARSER_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOXMLPARSER_DEPRECATED
#  define VTKIOXMLPARSER_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOXMLPARSER_DEPRECATED_EXPORT
#  define VTKIOXMLPARSER_DEPRECATED_EXPORT VTKIOXMLPARSER_EXPORT VTKIOXMLPARSER_DEPRECATED
#endif

#ifndef VTKIOXMLPARSER_DEPRECATED_NO_EXPORT
#  define VTKIOXMLPARSER_DEPRECATED_NO_EXPORT VTKIOXMLPARSER_NO_EXPORT VTKIOXMLPARSER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOXMLPARSER_NO_DEPRECATED
#    define VTKIOXMLPARSER_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkIOXMLParserModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKIOXMLPARSER_EXPORT_H */
