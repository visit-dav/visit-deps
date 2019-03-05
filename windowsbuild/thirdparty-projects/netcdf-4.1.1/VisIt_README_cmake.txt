Windows Build Notes for netcdf 4.1.1 using CMake.

netcdf-4.1.1-cmake.zip contains  CMakeLists.txt files and modifications to 
netcdf source files necessary for building dlls on windows.  This has only 
been tested with Visual Studio as the generator, and only in the context of 
using the resultant libs with VisIt.

Get netcdf-4.1.1.tar.gz from VisIt's third_party libs.  Extract it to the 
location on your computer where you wish to build the third-party libs. 
(eg. "C:\") to create: C:\netcdf-4.1.1

Extract the netcdf-4.1.1-cmake.zip files to the root dir of netcdf, answering 
'yes' when prompted to overwrite files.

You will need CMake 2.8.0 to build using these files.
You will also need hdf5, szip and zlib.

Run cmake-gui.exe.
Specify location of root netcdf source.
Specify a build location where CMake can create build files.
Click configure.

You will need to specify locations for hdf5, szip and zlib. 
For example, if you are building against the prebuilt binaries in VisIt's trunk, 
building 64-bit using Visual Studio 2010:

Settings:
HDF5_HL_LIB:FILEPATH=/path/to/visit/trunk/windowsbuild/ThirdParty/hdf5-1.8.7/MSVC2010-x64/lib/hdf5_hldll.lib
HDF5_INCLUDE_DIR:PATH=/path/to/visit/trunk/windowsbuild/ThirdParty/MSVC2010-x64/include
HDF5_LIB:FILEPATH=/path/to/visit/trunk/windowsbuild/ThirdParty/MSVC2010-x64/lib/hdf5dll.lib
SZIP_INCLUDE_DIR:PATH=/path/to/visit/trunk/windowsbuild/ThirdParty/szip/include
SZIP_LIB:FILEPATH=/path/to/visit/trunk/windowsbuild/ThirdParty/szip/lib/MSVC2010-x64/szlibdll.lib
ZLIB_INCLUDE_DIR:PATH=/path/to/visit/trunk/windowsbuild/ThirdParty/zlib/include
ZLIB_LIB:FILEPATH=/path/to/visit/trunk/windowsbuild/ThirdParty/zlib/lib/MSVC2010-x64/zlib1.lib

If you are not using VisIt's hdf5 prebuilt libs, you may need to add "/D_HDF5USEDLL_" to CMAKE_CXX_FLAGS, if your version of HDF5 was not built using CMake.

Click configure again.
Click generate.

Open the generated Visual Studio solution and build.

The generated netcdf lib is version 4 (based on version3).
Both the version 3 and version 4 c++ libs are built.

import libraries will be in lib/<CONFIGURATION_TYPE> eg lib/Release
netcdf.lib, netcdf_c++.lib and netcdf_c++4.lib

dlls will be in exe/<CONFIGURATION_TYPE>
netcdf.dll, netcdf_c++.dll and netcdf_c++4.dll


