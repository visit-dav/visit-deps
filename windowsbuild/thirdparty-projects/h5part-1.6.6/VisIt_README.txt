Windows Build Notes for h5part-1.6.6

Contents of hfpart-1.6.6-projects.zip:
 projects for MSVC 2022 (in folder visualc2022)
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
HDF5_LIB_DIR       /* Path to the HDF5 libraries */

ZLIB_INC_DIR       /* Path to the zlib includes */
ZLIB_LIB_DIR       /* Path to the zlib libraries */

SZIP_INC_DIR       /* Path to the szip includes */
SZIP_LIB_DIR       /* Path to the szip libraries */

There is a property sheet available which can be hand-edited to point to the appropriate paths before opening the solution file.

Open the visualc2022 folder, modify DependentLibs.vsprops, Open the solution file, and build. 

