
#ifndef HELIDE_EXPORT_H
#define HELIDE_EXPORT_H

#ifdef ANARI_LIBRARY_HELIDE_STATIC_DEFINE
#  define HELIDE_EXPORT
#  define ANARI_LIBRARY_HELIDE_NO_EXPORT
#else
#  ifndef HELIDE_EXPORT
#    ifdef anari_library_helide_EXPORTS
        /* We are building this library */
#      define HELIDE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define HELIDE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ANARI_LIBRARY_HELIDE_NO_EXPORT
#    define ANARI_LIBRARY_HELIDE_NO_EXPORT 
#  endif
#endif

#ifndef ANARI_LIBRARY_HELIDE_DEPRECATED
#  define ANARI_LIBRARY_HELIDE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ANARI_LIBRARY_HELIDE_DEPRECATED_EXPORT
#  define ANARI_LIBRARY_HELIDE_DEPRECATED_EXPORT HELIDE_EXPORT ANARI_LIBRARY_HELIDE_DEPRECATED
#endif

#ifndef ANARI_LIBRARY_HELIDE_DEPRECATED_NO_EXPORT
#  define ANARI_LIBRARY_HELIDE_DEPRECATED_NO_EXPORT ANARI_LIBRARY_HELIDE_NO_EXPORT ANARI_LIBRARY_HELIDE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ANARI_LIBRARY_HELIDE_NO_DEPRECATED
#    define ANARI_LIBRARY_HELIDE_NO_DEPRECATED
#  endif
#endif

#endif /* HELIDE_EXPORT_H */
