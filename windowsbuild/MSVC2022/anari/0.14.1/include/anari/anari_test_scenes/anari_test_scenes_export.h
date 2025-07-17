
#ifndef ANARI_TEST_SCENES_INTERFACE_H
#define ANARI_TEST_SCENES_INTERFACE_H

#ifdef ANARI_TEST_SCENES_STATIC_DEFINE
#  define ANARI_TEST_SCENES_INTERFACE
#  define ANARI_TEST_SCENES_NO_EXPORT
#else
#  ifndef ANARI_TEST_SCENES_INTERFACE
#    ifdef anari_test_scenes_EXPORTS
        /* We are building this library */
#      define ANARI_TEST_SCENES_INTERFACE __declspec(dllexport)
#    else
        /* We are using this library */
#      define ANARI_TEST_SCENES_INTERFACE __declspec(dllimport)
#    endif
#  endif

#  ifndef ANARI_TEST_SCENES_NO_EXPORT
#    define ANARI_TEST_SCENES_NO_EXPORT 
#  endif
#endif

#ifndef ANARI_TEST_SCENES_DEPRECATED
#  define ANARI_TEST_SCENES_DEPRECATED __declspec(deprecated)
#endif

#ifndef ANARI_TEST_SCENES_DEPRECATED_EXPORT
#  define ANARI_TEST_SCENES_DEPRECATED_EXPORT ANARI_TEST_SCENES_INTERFACE ANARI_TEST_SCENES_DEPRECATED
#endif

#ifndef ANARI_TEST_SCENES_DEPRECATED_NO_EXPORT
#  define ANARI_TEST_SCENES_DEPRECATED_NO_EXPORT ANARI_TEST_SCENES_NO_EXPORT ANARI_TEST_SCENES_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ANARI_TEST_SCENES_NO_DEPRECATED
#    define ANARI_TEST_SCENES_NO_DEPRECATED
#  endif
#endif

#endif /* ANARI_TEST_SCENES_INTERFACE_H */
