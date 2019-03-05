Windows Build Notes for zlib-1.2.3

zlib-1.2.3-projects.tar.gz contains projects for
MSVC7 (.Net 2003), MSVC8 (2005) and MSVC9 (2008)
and this readme.


Get zlib-1.2.3.tar.gz from VisIt's third_party libs.
Extract it to the location on your computer where you
wish to build the third-party libs. (eg. "C:\")
to create:
C:\zlib-1.2.3

Extract the zlib projects to the root of zlib,
e.g
C:\zlib-1.2.3\

There will be three directories, visualc7, visualc8, and
visualc9. Open the folder for the compiler you wish to use,
and open the corresponding solution file.

For use with VisIt, select the DLL_Release configuration 
and build.  With MSV8 and MSVC9 builds you have the option
of building for 64bits (choose x64 platform).


If building other VisIt 3rd party libs that depend on zlib,
add to your environment these vars:

ZLIB_INC_DIR=C:\zlib-1.2.3\
ZLIB_LIB_DIR=C:\zlib-1.2.3\projects\visualc8\DLL_Release
