#-----------------------------------------------------------------------------
#
# XDMFConfig.cmake - XDMF CMake configuration file for external projects.
#
# This file is configured by XDMF and used by the UseXDMF.cmake module
# to load XDMF's settings for an external project.

# Top level for development or install
SET(XDMF_INSTALL_DIR "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/xdmf-vtk9.4/2.1.1")

# The XDMF include file directories.
SET(XDMF_INCLUDE_DIRS "${XDMF_INSTALL_DIR}/include/;C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/include")

# The XDMF library directories.
SET(XDMF_LIBRARY_DIRS "${XDMF_INSTALL_DIR}/lib")

# The location of the UseXDMF.cmake file.
SET(XDMF_USE_FILE "${XDMF_INSTALL_DIR}/lib/XdmfCMake/UseXDMF.cmake")

# The build settings file.
SET(XDMF_BUILD_SETTINGS_FILE "${XDMF_INSTALL_DIR}/lib/XdmfCMake/XDMFBuildSettings.cmake")

# The directory containing class list files for each kit.
SET(XDMF_KITS_DIR "${XDMF_INSTALL_DIR}/vtk")

# Utility libraries used by XDMF.
# To include a utility library in another project:
# LINK_DIRECTORIES(${XDMF_***_LIBRARY_PATH})
# TARGET_LINK_LIBRARIES(target ${XDMF_***_LIBRARIES})
SET(XDMF_HDF5_INCLUDE "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/include")
SET(XDMF_HDF5_LIBRARY_PATH "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/lib")
SET(XDMF_HDF5_LIBRARIES "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/hdf5/1.8.19/lib/hdf5.lib")
SET(XDMF_SYSTEM_HDF5 "ON")

SET(XDMF_LIBXML2_INCLUDE "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/vtk/9.4.1/include/vtk-9.4/vtklibxml2/include")
SET(XDMF_LIBXML2_LIBRARY_PATH "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/vtk/9.4.1/lib")
SET(XDMF_LIBXML2_LIBRARIES "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/vtk/9.4.1/lib/vtklibxml2-9.4.lib")
SET(XDMF_SYSTEM_LIBXML2 "ON")

SET(XDMF_ZLIB_INCLUDE "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/zlib/1.2.13/include")
SET(XDMF_ZLIB_LIBRARY_PATH "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/zlib/1.2.13/lib")
SET(XDMF_ZLIB_LIBRARIES "C:/A_VisIt/3.4RC/visit-deps/windowsbuild/MSVC2022/zlib/1.2.13/lib/zlib.lib")
SET(XDMF_SYSTEM_ZLIB "ON")

# The XDMF library dependencies.
IF(NOT XDMF_NO_LIBRARY_DEPENDS)
  INCLUDE("${XDMF_INSTALL_DIR}/lib/XdmfCMake/XDMFLibraryDepends.cmake")
ENDIF(NOT XDMF_NO_LIBRARY_DEPENDS)

# Information about this particular XDMF Installation
SET(XDMF_BUILD_MPI "OFF")
SET(XDMF_BUILD_UTILS "OFF")
SET(XDMF_BUILD_VTK "OFF")
SET(XDMF_WRAP_PYTHON "OFF")

IF(XDMF_BUILD_MPI)
  SET(XDMF_MPI_LIBRARIES "")
  SET(XDMF_MPI_INCLUDE_PATH "")
ENDIF(XDMF_BUILD_MPI)

IF(XDMF_BUILD_UTILS)
  SET(XDMF_EXODUSII_INCLUDE "")
  SET(XDMF_EXODUSII_LIBRARY_PATH "")
  SET(XDMF_EXODUSII_LIBRARIES "")
  SET(XDMF_METIS_INCLUDE "")
  SET(XDMF_METIS_LIBRARY_PATH "")
  SET(XDMF_METIS_LIBRARIES "")
  SET(XDMF_NETCDF_INCLUDE "")
  SET(XDMF_NETCDF_LIBRARY_PATH "")
  SET(XDMF_NETCDF_LIBRARIES "")
ENDIF(XDMF_BUILD_UTILS)

IF(XDMF_BUILD_VTK)
  SET(XDMF_VTK_DIR "")
ENDIF(XDMF_BUILD_VTK)
