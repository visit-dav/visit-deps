##============================================================================
##  Copyright (c) Kitware, Inc.
##  All rights reserved.
##  See LICENSE.txt for details.
##
##  This software is distributed WITHOUT ANY WARRANTY; without even
##  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
##  PURPOSE.  See the above copyright notice for more information.
##============================================================================

# When this file is run by CMake through the find_package command, the
# following targets will exist:
#   vtkm_cont       Target that contains most of VTK-m
#
#   vtkm_rendering  Target that contains all the rendering code
#
#   vtkm_filter     Target that contains all of VTK-m pre-built filters
#
#   vtkm_source     Target that contains all of VTK-m pre-built sources
#
#   vtkm::tbb       Target that contains tbb related link information
#                   implicitly linked to by `vtkm_cont` if tbb is enabled
#
#   vtkm::openmp    Target that contains openmp related link information
#                   implicitly linked to by `vtkm_cont` if openmp is enabled
#
#   vtkm::cuda      Target that contains cuda related link information
#                   implicitly linked to by `vtkm_cont` if cuda is enabled
#
# The following local variables will also be defined:
#
#  VTKm_VERSION         Holds the version string of "Major.Minor"
#  VTKm_VERSION_FULL    Holds the version string of "Major.Minor.Patch.GitSha1"
#  VTKm_VERSION_MAJOR   Holds just the major version number
#  VTKm_VERSION_MINOR   Holds just the minor version number
#  VTKm_VERSION_PATCH   Holds just the patch version number
#
#  VTKm_BUILD_SHARED_LIBS     Will be enabled if VTK-m was built shared/dynamic
#  VTKm_ENABLE_CUDA           Will be enabled if VTK-m was built with CUDA support
#  VTKm_ENABLE_TBB            Will be enabled if VTK-m was built with TBB support
#  VTKm_ENABLE_OPENMP         Will be enabled if VTK-m was built with OpenMP support
#  VTKm_ENABLE_KOKKOS         Will be enabled if VTK-m was built with Kokkos support
#  VTKm_ENABLE_LOGGING        Will be enabled if VTK-m was built with logging support
#  VTKm_ENABLE_MPI            Will be enabled if VTK-m was built with MPI support
#  VTKm_ENABLE_RENDERING      Will be enabled if VTK-m was built with rendering support
#  VTKm_ENABLE_GL_CONTEXT     Will be enabled if VTK-m rendering was built with a GL context
#  VTKm_ENABLE_OSMESA_CONTEXT Will be enabled if VTK-m rendering was built with a osmesa context
#  VTKm_ENABLE_EGL_CONTEXT    Will be enabled if VTK-m rendering was built with a EGL context
#
#

if (CMAKE_VERSION VERSION_LESS "3.12")
  message(FATAL_ERROR "VTK-m requires CMake 3.12+")
endif()
if("${CMAKE_GENERATOR}" MATCHES "Visual Studio" AND
   CMAKE_VERSION VERSION_LESS "3.11")
  message(FATAL_ERROR "VTK-m requires CMake 3.11+ when using the Visual Studio Generators")
endif()


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was VTKmConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

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

# The VTKm version number
set(VTKm_VERSION_MAJOR "1")
set(VTKm_VERSION_MINOR "7")
set(VTKm_VERSION_PATCH "0")
set(VTKm_VERSION_FULL "1.7.0")
set(VTKm_VERSION "1.7")

set(VTKm_BUILD_SHARED_LIBS "OFF")
set(VTKm_ENABLE_CUDA "OFF")
set(VTKm_ENABLE_KOKKOS "OFF")
set(VTKm_ENABLE_OPENMP "OFF")
set(VTKm_ENABLE_TBB "OFF")
set(VTKm_ENABLE_LOGGING "ON")
set(VTKm_ENABLE_RENDERING "ON")
set(VTKm_ENABLE_GL_CONTEXT "")
set(VTKm_ENABLE_OSMESA_CONTEXT "")
set(VTKm_ENABLE_EGL_CONTEXT "")
set(VTKm_ENABLE_MPI "OFF")
set(VTKm_ENABLE_TESTING_LIBRARY "OFF")

# This is true when the package is still in the build directory (not installed)
if(CMAKE_CURRENT_LIST_DIR STREQUAL "C:/A_Visit/ThirdParty/vtk-m-v1.7.0-build/lib/cmake/vtkm-1.7")
  set(VTKm_PACKAGE_IN_BUILD TRUE)
endif()

if(VTKm_PACKAGE_IN_BUILD)
  set_and_check(VTKm_CMAKE_MODULE_PATH "C:/A_Visit/ThirdParty/vtk-m-v1.7.0/CMake")
else()
  set_and_check(VTKm_CMAKE_MODULE_PATH "${PACKAGE_PREFIX_DIR}/share/vtkm-1.7/cmake")
endif()

include(CMakeFindDependencyMacro)

set(CMAKE_MODULE_PATH_save_vtkm "${CMAKE_MODULE_PATH}")
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_LIST_DIR}")

if (VTKm_ENABLE_TBB)
  find_dependency(TBB)
  if (NOT TBB_FOUND)
    set(VTKm_FOUND 0)
    list(APPEND VTKm_NOT_FOUND_REASON "TBB not found: ${TBB_NOT_FOUND_MESSAGE}")
  endif()
endif()

# Load the library exports, but only if not compiling VTK-m itself
set_and_check(VTKm_CONFIG_DIR "${PACKAGE_PREFIX_DIR}/lib/cmake/vtkm-1.7")
set(VTKM_FROM_INSTALL_DIR FALSE)
if(NOT "${CMAKE_BINARY_DIR}" STREQUAL "C:/A_Visit/ThirdParty/vtk-m-v1.7.0-build")
  set(VTKM_FROM_INSTALL_DIR TRUE)
  include(${VTKm_CONFIG_DIR}/VTKmTargets.cmake)
endif()

# Once we can require CMake 3.15 for all cuda builds we can
# replace this with setting `cuda_architecture_flags` as part of the
# EXPORT_PROPERTIES of the vtkm_cuda target
if(VTKm_ENABLE_CUDA AND VTKM_FROM_INSTALL_DIR)
  set_target_properties(vtkm::cuda PROPERTIES cuda_architecture_flags "")
  set_target_properties(vtkm::cuda PROPERTIES requires_static_builds TRUE)

  # If VTK-m is built with 3.18+ and the consumer is < 3.18 we need to drop
  # these properties as they break the VTK-m cuda flag logic
  if(CMAKE_VERSION VERSION_LESS 3.18)
    set_target_properties(vtkm::cuda PROPERTIES INTERFACE_LINK_OPTIONS "")
  endif()
endif()

# VTKm requires some CMake Find modules not included with CMake, so
# include the CMake modules distributed with VTKm.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH_save_vtkm} ${VTKm_CMAKE_MODULE_PATH})
unset(CMAKE_MODULE_PATH_save_vtkm)

if(VTKm_ENABLE_CUDA)
  if (CMAKE_VERSION VERSION_LESS 3.13)
    message(FATAL_ERROR "VTK-m with CUDA requires CMake 3.13+")
  endif()
endif()

# This includes a host of functions used by VTK-m CMake.
include(VTKmWrappers)
include(VTKmRenderingContexts)

# Setup diy magic of chosing the appropriate mpi/no_mpi library to link against
include(VTKmDIYUtils)
vtkm_diy_init_target()
