#-----------------------------------------------------------------------------
# HDF5 Config file for compiling against hdf5 install directory
#-----------------------------------------------------------------------------
GET_FILENAME_COMPONENT (SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
#message ("self dir: ${SELF_DIR}")
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${SELF_DIR}" PATH)
#message ("import prefix 1: ${_IMPORT_PREFIX}")
#GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
#message ("import prefix 2: ${_IMPORT_PREFIX}")

#-----------------------------------------------------------------------------
# User Options
#-----------------------------------------------------------------------------
set (HDF5_ENABLE_PARALLEL OFF)
set (HDF5_BUILD_FORTRAN   OFF)
set (HDF5_ENABLE_F2003    )
set (HDF5_BUILD_CPP_LIB   ON)
set (HDF5_BUILD_TOOLS     OFF)
set (HDF5_BUILD_HL_LIB    ON)
set (HDF5_ENABLE_Z_LIB_SUPPORT ON)
set (HDF5_ENABLE_SZIP_SUPPORT  ON)
set (HDF5_ENABLE_SZIP_ENCODING OFF)
set (HDF5_BUILD_SHARED_LIBS    ON)
set (HDF5_PACKAGE_EXTLIBS      OFF)

#-----------------------------------------------------------------------------
# Dependencies
#-----------------------------------------------------------------------------
IF(HDF5_ENABLE_PARALLEL)
  SET(HDF5_MPI_C_INCLUDE_PATH "")
  SET(HDF5_MPI_C_LIBRARIES    "")
ENDIF(HDF5_ENABLE_PARALLEL)

#-----------------------------------------------------------------------------
# Directories
#-----------------------------------------------------------------------------
set (HDF5_INCLUDE_DIR "${_IMPORT_PREFIX}/include" "${HDF5_MPI_C_INCLUDE_PATH}" )

if (HDF5_BUILD_FORTRAN)
  set (HDF5_INCLUDE_DIR_FORTRAN "${_IMPORT_PREFIX}/include" )
endif (HDF5_BUILD_FORTRAN)
  
if (HDF5_BUILD_CPP_LIB)
  set (HDF5_INCLUDE_DIR_CPP "${_IMPORT_PREFIX}/include" )
endif (HDF5_BUILD_CPP_LIB)

if (HDF5_BUILD_HL_LIB)
  set (HDF5_INCLUDE_DIR_HL "${_IMPORT_PREFIX}/include" )
endif (HDF5_BUILD_HL_LIB)

if (HDF5_BUILD_HL_LIB AND HDF5_BUILD_CPP_LIB)
  set (HDF5_INCLUDE_DIR_HL_CPP "${_IMPORT_PREFIX}/include" )
endif (HDF5_BUILD_HL_LIB AND HDF5_BUILD_CPP_LIB)

if (HDF5_BUILD_TOOLS)
  set (HDF5_INCLUDE_DIR_TOOLS "${_IMPORT_PREFIX}/include" )
  set (HDF5_TOOLS_DIR "${_IMPORT_PREFIX}/bin" )
endif (HDF5_BUILD_TOOLS)

#-----------------------------------------------------------------------------
# Version Strings
#-----------------------------------------------------------------------------
set (HDF5_VERSION_STRING 1.8.19)
set (HDF5_VERSION_MAJOR  1.8)
set (HDF5_VERSION_MINOR  19)

#-----------------------------------------------------------------------------
# Don't include targets if this file is being picked up by another
# project which has already built hdf5 as a subproject
#-----------------------------------------------------------------------------
if (NOT TARGET "hdf5")
  include (${SELF_DIR}/hdf5-targets.cmake)
  set (HDF5_LIBRARIES "hdf5;hdf5_cpp;hdf5_hl;hdf5_hl_cpp")
endif (NOT TARGET "hdf5")

