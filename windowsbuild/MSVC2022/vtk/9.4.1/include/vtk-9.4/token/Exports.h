
#ifndef TOKEN_EXPORT_H
#define TOKEN_EXPORT_H

#ifdef TOKEN_STATIC_DEFINE
#  define TOKEN_EXPORT
#  define TOKEN_NO_EXPORT
#else
#  ifndef TOKEN_EXPORT
#    ifdef token_EXPORTS
        /* We are building this library */
#      define TOKEN_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define TOKEN_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef TOKEN_NO_EXPORT
#    define TOKEN_NO_EXPORT 
#  endif
#endif

#ifndef TOKEN_DEPRECATED
#  define TOKEN_DEPRECATED __declspec(deprecated)
#endif

#ifndef TOKEN_DEPRECATED_EXPORT
#  define TOKEN_DEPRECATED_EXPORT TOKEN_EXPORT TOKEN_DEPRECATED
#endif

#ifndef TOKEN_DEPRECATED_NO_EXPORT
#  define TOKEN_DEPRECATED_NO_EXPORT TOKEN_NO_EXPORT TOKEN_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef TOKEN_NO_DEPRECATED
#    define TOKEN_NO_DEPRECATED
#  endif
#endif

#endif /* TOKEN_EXPORT_H */
