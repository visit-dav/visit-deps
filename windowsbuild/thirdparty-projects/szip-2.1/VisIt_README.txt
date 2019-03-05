Windows Build Notes for Szip-2.1

The zip file contains projects for MSVC7 (.Net 2003),
MSVC8 (2005), MSVC9 (2008), and MSVC 2010.


Get the szip-2.1.tar.gz from VisIt's third_party libs.
Extract it to the location on your computer where you
wish to build the third-party libs.

Extract the szip projects to the root of you szip-2.1
e.g
If you extracted szip to
c:
then extract the projects to
c:\szip-2.1\windows


There will be three new folders in the szip windows
folder: MSVC7, MSVC8, MSVC9, MSVC2010.
Open the folder for the compiler you wish to use,
and open the corresponding solution file.

Select the desired configuration (Debug, Release) and build.
The solutions for MSVC8, MSVC9, MSVC2010 have x64 configurations
as well as win32 configurations.

If desired, copy the .dll's and .lib's to simpler path.

If building other VisIt 3rd parth libs that depend on szip,
add to your environment these vars, having them point to
the corrrect location for your build configuration. e.g.

SZIP_INC_DIR=C:\szip-2.1\src
SZIP_LIB_DIR=C:\szip-2.1\windows\MSVC7\Release
