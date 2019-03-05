These instructions are for building 64bit cfitsio on Windows, using
Visual Studio 8 or 9 with x64 extensions installed.

The zip files contains new and modified build files expressly for 64bit.

1)  Get the cfitsio tarball form VisIt's third_party libs, and unpack it.
2)  Extract the nmake files from the zip file to the root cfitsio directory.
    One file will be overwritten, two are new.

3)  Open a command window and execute the vcvarsamd64.bat file from the 
    vc\bin\amd64 directory where VS 8 is installed.
4)  cd to the cfitsio directory
5)  enter the following commands:
        nmake winDumpExts_x64.mak
        nmake makefile.vcc_x64



This creates the cfitsio.def, cfitsio.dll, and cfitsio.lib files.  The
fitsio.h and longnam.h files are also needed to compile any programs
that use CFITSIO.

