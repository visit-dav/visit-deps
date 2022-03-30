#==============================================================================
# See License.txt
#==============================================================================

# When this file is run by CMake through the find_package command, the
# following variables will be defined:
#
# <TBD>
#
# Note that the VTK-h package supports several components. It is important
# to request the components being used (as done through find_package arguments).
# If no components are requested, then the dependent packages will not be
# found and loaded. The following components are supported:
#
# Core Rendering Filters
#

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was VTKhConfig.cmake.in                            ########

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


# The VTKh version number
set(VTKh_VERSION_MAJOR "0")
set(VTKh_VERSION_MINOR "7")
set(VTKh_VERSION_PATCH "0")
set(VTKh_VERSION_FULL "")
set(VTKh_VERSION "0.7.0")

set(VTKh_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")

message(STATUS "VTKh using provided path  VTKM_DIR: ${VTKM_DIR}")

# set this before we load vtkm because package is overridden by vtkm
# Load the library exports, but only if not compiling VTK-h itself
set_and_check(VTKh_CONFIG_DIR "${PACKAGE_PREFIX_DIR}/lib")
include(${VTKh_CONFIG_DIR}/VTKhTargets.cmake)

# use VTKM_DIR to setup the options that cmake's find VTKm needs
file(GLOB VTKm_DIR "${VTKM_DIR}/lib/cmake/vtkm-*")
if(NOT VTKm_DIR)
    MESSAGE(FATAL_ERROR "Failed to find VTKm at VTKM_DIR=${VTKM_DIR}/lib/cmake/vtk-*")
endif()
include(${VTKm_DIR}/VTKmConfig.cmake)
find_package(VTKm REQUIRED QUIET) 
set(VTKM_FOUND TRUE)
