Windows Build Notes for libtiff-4.2.0

libtiff has a straightforward CMake build system.

This directory contains a modified CMakeLists.txt that
should be copied into the root directory of libtiff-4.2.0.

The modification turns off USE_WIN32_FILEIO, which when
on causes problems with Pillow-7.2.1

If building libtiff for VisIt's use, change
CMAKE_INSTALL_PREFIX to point to the correct location of
VisIt's visit-deps/windowsbuild. 


