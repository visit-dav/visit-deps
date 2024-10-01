# Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
# Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
# other details. No copyright assignment is required to contribute to Conduit.

###############################################################################
# Note:
# This file is named ConduitConfig.cmake because once upon a time
# when it was named conduit-config.cmake, we found that CMake's exported
# targets script includes all "ascent-*.cmake" files. This logic would
# cause this script to be included more than once, seeding instability
# that caused great harm to the kingdom.
###############################################################################


cmake_minimum_required(VERSION 3.8 FATAL_ERROR)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ConduitConfig.cmake.in                            ########

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

if(NOT CONDUIT_FOUND)

    # Compute the installation prefix relative to this file.
    get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
    get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
    get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
    if(_IMPORT_PREFIX STREQUAL "/")
      set(_IMPORT_PREFIX "")
    endif()

    set(CONDUIT_VERSION "0.9.2")
    # keep CONDUIT_USE_CXX11 to support old install logic
    set(CONDUIT_USE_CXX11   "TRUE")
    set(CONDUIT_USE_CXX14   "TRUE")
    set(CONDUIT_USE_FMT     "TRUE")
    set(CONDUIT_USE_CALIPER "")
    set(CONDUIT_USE_OPENMP  "OFF")
    set(CONDUIT_INSTALL_PREFIX "${_IMPORT_PREFIX}")
    set(CONDUIT_ZLIB_DIR  "${ZLIB_DIR}")
    set(CONDUIT_HDF5_DIR  "${HDF5_DIR}")
    set(CONDUIT_ADIOS_DIR "")
    set(CONDUIT_SILO_DIR "${SILO_DIR}")
    set(CONDUIT_METIS_DIR "")
    set(CONDUIT_PARMETIS_DIR "")
    set(CONDUIT_ADIAK_DIR "")
    set(CONDUIT_CALIPER_DIR "")
    set(CONDUIT_PYTHON_ENABLED "TRUE")
    set(CONDUIT_PYTHON_EXECUTABLE "${PYTHON_EXECUTABLE}")
    set(CONDUIT_PYTHON_MODULE_DIR "${_IMPORT_PREFIX}/python-modules/")
    set(CONDUIT_USE_CMAKE_MPI_TARGETS   "TRUE")

    get_filename_component(CONDUIT_CMAKE_CONFIG_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

    # setup dependent pkgs
    include(${CONDUIT_CMAKE_CONFIG_DIR}/conduit_setup_deps.cmake)

    # include targets exported by cmake
    include(${CONDUIT_CMAKE_CONFIG_DIR}/conduit.cmake)

    # finally setup our final imported targets
    include(${CONDUIT_CMAKE_CONFIG_DIR}/conduit_setup_targets.cmake)

    set(CONDUIT_FOUND TRUE)

endif()

