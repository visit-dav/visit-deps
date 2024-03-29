#
# Copyright by The HDF Group.
# All rights reserved.
#
# This file is part of HDF5.  The full HDF5 copyright notice, including
# terms governing use, modification, and redistribution, is contained in
# the COPYING file, which can be found at the root of the source code
# distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.
# If you do not have access to either file, you may request a copy from
# help@hdfgroup.org.

#-----------------------------------------------------------------------------
# HDF5 Config file for compiling against hdf5 build/install directory
#-----------------------------------------------------------------------------

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was hdf5-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

string(TOUPPER hdf5 HDF5_PACKAGE_NAME)

set (${HDF5_PACKAGE_NAME}_VALID_COMPONENTS
    static
    shared
    C
    CXX
    Fortran
    HL
    CXX_HL
    Fortran_HL
    Tools
)

#-----------------------------------------------------------------------------
# User Options
#-----------------------------------------------------------------------------
set (${HDF5_PACKAGE_NAME}_ENABLE_PARALLEL OFF)
set (${HDF5_PACKAGE_NAME}_BUILD_FORTRAN   OFF)
set (${HDF5_PACKAGE_NAME}_ENABLE_F2003    )
set (${HDF5_PACKAGE_NAME}_BUILD_CPP_LIB   ON)
set (${HDF5_PACKAGE_NAME}_BUILD_TOOLS     OFF)
set (${HDF5_PACKAGE_NAME}_BUILD_HL_LIB    ON)
set (${HDF5_PACKAGE_NAME}_ENABLE_Z_LIB_SUPPORT ON)
set (${HDF5_PACKAGE_NAME}_ENABLE_SZIP_SUPPORT  ON)
set (${HDF5_PACKAGE_NAME}_ENABLE_SZIP_ENCODING OFF)
set (${HDF5_PACKAGE_NAME}_BUILD_SHARED_LIBS    ON)
set (${HDF5_PACKAGE_NAME}_PACKAGE_EXTLIBS      OFF)
set (${HDF5_PACKAGE_NAME}_EXPORT_LIBRARIES hdf5-shared;hdf5_hl-shared;hdf5_cpp-shared;hdf5_hl_cpp-shared)
set (${HDF5_PACKAGE_NAME}_TOOLSET "host=x64")

#-----------------------------------------------------------------------------
# Dependencies
#-----------------------------------------------------------------------------
if (${HDF5_PACKAGE_NAME}_ENABLE_PARALLEL)
  set (${HDF5_PACKAGE_NAME}_MPI_C_INCLUDE_PATH "")
  set (${HDF5_PACKAGE_NAME}_MPI_C_LIBRARIES    "")
endif ()

#-----------------------------------------------------------------------------
# Directories
#-----------------------------------------------------------------------------
set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include" "${${HDF5_PACKAGE_NAME}_MPI_C_INCLUDE_PATH}")

set (${HDF5_PACKAGE_NAME}_SHARE_DIR "${PACKAGE_PREFIX_DIR}/cmake")
set_and_check (${HDF5_PACKAGE_NAME}_BUILD_DIR "${PACKAGE_PREFIX_DIR}")

if (${HDF5_PACKAGE_NAME}_BUILD_CPP_LIB)
  set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR_CPP "${PACKAGE_PREFIX_DIR}/include")
endif ()

if (${HDF5_PACKAGE_NAME}_BUILD_HL_LIB)
  set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR_HL "${PACKAGE_PREFIX_DIR}/include")
endif ()

if (${HDF5_PACKAGE_NAME}_BUILD_HL_LIB AND ${HDF5_PACKAGE_NAME}_BUILD_CPP_LIB)
  set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR_HL_CPP "${PACKAGE_PREFIX_DIR}/include")
endif ()

if (${HDF5_PACKAGE_NAME}_BUILD_TOOLS)
  set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR_TOOLS "${PACKAGE_PREFIX_DIR}/include")
  set_and_check (${HDF5_PACKAGE_NAME}_TOOLS_DIR "${PACKAGE_PREFIX_DIR}/bin")
endif ()

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
  include (${PACKAGE_PREFIX_DIR}/cmake/hdf5-targets.cmake)
endif ()

# Handle requested components:
list (REMOVE_DUPLICATES ${HDF5_PACKAGE_NAME}_FIND_COMPONENTS)
foreach (comp IN LISTS ${HDF5_PACKAGE_NAME}_FIND_COMPONENTS)
  if (${comp} STREQUAL "shared")
    list (REMOVE_ITEM ${HDF5_PACKAGE_NAME}_FIND_COMPONENTS ${comp})
    set (${HDF5_PACKAGE_NAME}_LIB_TYPE ${${HDF5_PACKAGE_NAME}_LIB_TYPE} ${comp})

    if (${HDF5_PACKAGE_NAME}_BUILD_FORTRAN)
      set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR_FORTRAN "${PACKAGE_PREFIX_DIR}/include/shared")
    endif ()
  elseif (${comp} STREQUAL "static")
    list (REMOVE_ITEM ${HDF5_PACKAGE_NAME}_FIND_COMPONENTS ${comp})
    set (${HDF5_PACKAGE_NAME}_LIB_TYPE ${${HDF5_PACKAGE_NAME}_LIB_TYPE} ${comp})

    if (${HDF5_PACKAGE_NAME}_BUILD_FORTRAN)
      set (${HDF5_PACKAGE_NAME}_INCLUDE_DIR_FORTRAN "${PACKAGE_PREFIX_DIR}/include/static")
    endif ()
  endif ()
endforeach ()
foreach (libtype IN LISTS ${HDF5_PACKAGE_NAME}_LIB_TYPE)
  foreach (comp IN LISTS ${HDF5_PACKAGE_NAME}_FIND_COMPONENTS)
    set (hdf5_comp2)
    if (${comp} STREQUAL "C")
      set (hdf5_comp "hdf5")
    elseif (${comp} STREQUAL "CXX")
      set (hdf5_comp "hdf5_cpp")
    elseif (${comp} STREQUAL "HL")
      set (hdf5_comp "hdf5_hl")
    elseif (${comp} STREQUAL "CXX_HL")
      set (hdf5_comp "hdf5_hl_cpp")
    elseif (${comp} STREQUAL "Tools")
      set (hdf5_comp "hdf5_tools")
    elseif (${comp} STREQUAL "Fortran")
      set (hdf5_comp2 "hdf5_f90cstub")
      set (hdf5_comp "hdf5_fortran")
    elseif (${comp} STREQUAL "Fortran_HL")
      set (hdf5_comp2 "hdf5_hl_f90cstub")
      set (hdf5_comp "hdf5_hl_fortran")
    endif ()
    list (FIND ${HDF5_PACKAGE_NAME}_EXPORT_LIBRARIES "${hdf5_comp}-${libtype}" HAVE_COMP)
    if (${HAVE_COMP} LESS 0)
      set (${HDF5_PACKAGE_NAME}_${libtype}_${comp}_FOUND 0)
    else ()
      if (hdf5_comp2)
        list (FIND ${HDF5_PACKAGE_NAME}_EXPORT_LIBRARIES "${hdf5_comp2}-${libtype}" HAVE_COMP2)
        if (${HAVE_COMP2} LESS 0)
          set (${HDF5_PACKAGE_NAME}_${libtype}_${comp}_FOUND 0)
        else ()
          set (${HDF5_PACKAGE_NAME}_${libtype}_${comp}_FOUND 1)
          string(TOUPPER ${HDF5_PACKAGE_NAME}_${comp}_${libtype}_LIBRARY COMP_LIBRARY)
          set (${COMP_LIBRARY} ${${COMP_LIBRARY}} hdf5::${hdf5_comp2}-${libtype} hdf5::${hdf5_comp}-${libtype})
        endif ()
      else ()
        set (${HDF5_PACKAGE_NAME}_${libtype}_${comp}_FOUND 1)
        string(TOUPPER ${HDF5_PACKAGE_NAME}_${comp}_${libtype}_LIBRARY COMP_LIBRARY)
        set (${COMP_LIBRARY} ${${COMP_LIBRARY}} hdf5::${hdf5_comp}-${libtype})
      endif ()
    endif ()
  endforeach ()
endforeach ()

foreach (libtype IN LISTS ${HDF5_PACKAGE_NAME}_LIB_TYPE)
  check_required_components(${HDF5_PACKAGE_NAME}_${libtype})
endforeach ()
