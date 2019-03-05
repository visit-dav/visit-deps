Windows Build Notes for mfem-3.3.

1) Get mfem.3.3.tar.gz

2) Extract it to the location on your computer where you
wish to build the third-party libs. (eg. "C:\")

3) copy the CMakeLists.txt file in this directory to the mfem-3.3 root directory.  It moves the 'project' declaration higher up in the file in order for the compiler to be found before it is queried.


Run cmake-gui.exe.
Specify location of root mfem source.
Specify a build location where CMake can create build files.
Click configure.
Modify CMAKE_INSTALL_PREFIX to location where you want mfem installed.
Click configure again.
Click generate.

Open the generated Visual Studio solution and build.


