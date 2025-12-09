## Copyright 2021-2025 The Khronos Group
## SPDX-License-Identifier: Apache-2.0


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was anariConfig.cmake.in                            ########

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

include(CMakeFindDependencyMacro)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_dependency(Threads)

if (OFF)
  find_dependency(draco)
endif()
if (OFF)
  find_dependency(WebP)
endif()
if (OFF)
  find_dependency(Ktx)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/anari_Exports.cmake)

if (NOT TARGET anari::anari)
  message(FATAL_ERROR "CMAKE_PREFIX_PATH or anari_DIR are pointing to an \
  ANARI-SDK build directory. Please do a full install of the SDK \
  (e.g. 'make install') and point to where you installed it \
  (CMAKE_INSTALL_PREFIX in your build of ANARI-SDK). \
  Consuming ANARI-SDK from a build directory is not supported.")
endif()

set(ANARI_DATAROOTDIR
  ${CMAKE_CURRENT_LIST_DIR}/../../../share/anari
)

if (ON)
  set(ANARI_CODE_GEN_ROOT ${ANARI_DATAROOTDIR}/code_gen)
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/anari_generate_frontend.cmake)
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/anari_generate_codegen.cmake)
  set(anari_code_gen_FOUND 1)
elseif(anari_FIND_REQUIRED_code_gen)
  message(ERROR "The 'code_gen' component was requested but not found. To
  enable this component, the SDK must be built with \
  INSTALL_CODE_GEN_SCRIPTS=ON")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmake/anari_sdk_fetch_project.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/cmake_project_commands.cmake)

if (TARGET anari::anari_viewer)
  set(anari_viewer_FOUND 1)
elseif (anari_FIND_REQUIRED_viewer AND ON)
  add_subdirectory(
    ${ANARI_DATAROOTDIR}/anari_viewer
    ${CMAKE_CURRENT_BINARY_DIR}/anari_viewer
  )
  set(anari_viewer_FOUND 1)
elseif(anari_FIND_REQUIRED_viewer)
  message(ERROR "The 'viewer' component was requested but not found. To
  enable this component, the SDK must be built with INSTALL_VIEWER_LIBRARY=ON")
endif()

check_required_components(anari-sdk)
