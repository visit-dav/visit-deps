QT_CPU_FEATURES.x86_64 = sse sse2
QT.global_private.enabled_features = sse2 alloca_malloc_h alloca avx2 gui network sql testlib widgets xml
QT.global_private.disabled_features = alloca_h android-style-assets private_tests dbus dbus-linked libudev posix_fallocate qml-debug reduce_exports reduce_relocations release_tools stack-protector-strong system-zlib
QT_COORD_TYPE = double
CONFIG += sse2 aesni sse3 ssse3 sse4_1 sse4_2 avx avx2 compile_examples f16c largefile ltcg msvc_mp precompile_header rdrnd shani
QT_BUILD_PARTS += libs tools
QT_HOST_CFLAGS_DBUS += 
