Windows Build Notes for h5part-1.6.6

Contents of hfpart-1.6.6-projects.zip:
 projects for MSVC 2012 (in folder visualc11) and MSVC 2013 (in folder visualc12)
 Modified headers and source code for a clean compile and for building a dll on windows.
 This readme.

++++++++
Get h5part_1.6.6.tar.gz from VisIt's third_party libs.
(or from the web: 
https://codeforge.lbl.gov/frs/download.php/358/H5Part-1.6.6.tar.gz)
Extract it to the location on your computer where you
wish to build the third-party libs. (eg. "C:\")

Extract the h5part projects to the root dir of h5part,
e.g
c:\H5Part-1.6.6\
When prompted if you want to overwrite existing files, select 'yes',
in order for the modified headers to be installed.

To build H5Part on Windows using these project files,
the following variables must be defined:

HDF5_INC_DIR       /* Path to the HDF5 includes */
HDF5_INC_DIR_X64   /* Path to the HDF5 x64 includes */
HDF5_LIB_DIR       /* Path to the HDF5 libraries */
HDF5_LIB_DIR_X64   /* Path to the 64bit hdf5 libraries */

ZLIB_INC_DIR       /* Path to the zlib includes */
ZLIB_LIB_DIR       /* Path to the zlib libraries */
ZLIB_LIB_DIR_X64   /* Path to the 64bit zlib libraries */

SZIP_INC_DIR       /* Path to the szip includes */
SZIP_LIB_DIR       /* Path to the szip libraries */
SZIP_LIB_DIR_X64   /* Path to the 64bit szip libraries */

There is a property sheet available which can be hand-edited to point to the appropriate paths before opening the solution file.

To build with MSVC 2012:
   Open the visualc11 folder, modify DependentLibs.vsprops, Open the solution file, and build. 

To build with MSVC 2013:
   Open the visualc12 folder, modify DependentLibs.props file.  Open the solution file, and build. 

