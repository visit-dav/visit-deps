## Copyright 2009 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

# Called if we failed to find OSPRay or any of it's required dependencies,
# unsets all public (designed to be used externally) variables and reports
# error message at priority depending upon [REQUIRED/QUIET/<NONE>] argument.
macro(ospray_report_not_found REASON_MSG)
  unset(OSPRAY_FOUND)
  unset(OSPRAY_INCLUDE_DIRS)
  unset(OSPRAY_LIBRARIES)

  # Reset the CMake module path to its state when this script was called.
  set(CMAKE_MODULE_PATH ${CALLERS_CMAKE_MODULE_PATH})

  # Note <package>_FIND_[REQUIRED/QUIETLY] variables defined by FindPackage()
  # use the camelcase library name, not uppercase.
  if (OSPRAY_FIND_QUIETLY)
    set(MSG_TYPE STATUS)
  elseif(OSPRAY_FIND_REQUIRED)
    set(MSG_TYPE FATAL_ERROR)
  else()
    # Neither QUIETLY nor REQUIRED, use SEND_ERROR which emits an error
    # that prevents generation, but continues configuration.
   set(MSG_TYPE SEND_ERROR)
  endif()
  message(${MSG_TYPE} "Failed to find OSPRay - " ${REASON_MSG} ${ARGN})
  return()
endmacro()

###############################################################################
# Attempt to find OSPRay

# Get the (current, i.e. installed) directory containing this file.
set(CURRENT_CONFIG_INSTALL_DIR ${CMAKE_CURRENT_LIST_DIR})

# Record the state of the CMake module path when this script was called so
# that we can ensure that we leave it in the same state on exit as it was
# on entry, but modify it locally.
set(OSPRAY_CALLERS_CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

# Reset CMake module path to the installation directory of this script,
# thus we will use the FindPackage() scripts shipped with OSPRay to find
# OSPRay's dependencies, even if the user has equivalently named FindPackage()
# scripts in their project.
set(CMAKE_MODULE_PATH ${CURRENT_CONFIG_INSTALL_DIR})

# Build the absolute root install directory as a relative path (determined when
# OSPRay was configured & built) from the current install directory for this
# this file. This allows for the install tree to be relocated, after OSPRay
# was built, outside of CMake.
get_filename_component(CURRENT_ROOT_INSTALL_DIR
  ${CURRENT_CONFIG_INSTALL_DIR}/../../../ ABSOLUTE
)

if (NOT EXISTS ${CURRENT_ROOT_INSTALL_DIR})
  ospray_report_not_found(
    "OSPRay install root: ${CURRENT_ROOT_INSTALL_DIR}, "
    "determined from relative path from osprayConfig.cmake install location:  "
    "${CURRENT_CONFIG_INSTALL_DIR}, does not exist.  Either the install "
    "directory was deleted, or the install tree was only partially relocated "
    "outside of CMake after OSPRay was built.")
endif()

set(OSPRAY_ROOT ${CURRENT_ROOT_INSTALL_DIR})

# Set the include directories for OSPRay (itself).
set(OSPRAY_INCLUDE_DIR "${OSPRAY_ROOT}/include")
if (NOT EXISTS ${OSPRAY_INCLUDE_DIR}/ospray/version.h)
  ospray_report_not_found(
    "OSPRay install root:  ${OSPRAY_ROOT}, "
    "determined from relative path from osprayConfg.cmake install location:  "
    "${CURRENT_CONFIG_INSTALL_DIR}, does not contain OSPRay headers. "
    "Either the install directory was deleted, or the install tree was only "
    "partially relocated outside of CMake after OSPRay was built.")
endif()

###############################################################################
# OSPRay build configuration

set(OSPRAY_VERSION   3.0.0)
set(OSPRAY_SOVERSION 3)

set(OSPRAY_INSTALL_DEPENDENCIES ON)

set(OSPRAY_BUILD_DEBUG          FALSE)
set(OSPRAY_BUILD_RELWITHDEBINFO FALSE)
set(OSPRAY_BUILD_RELEASE        TRUE)

set(OSPRAY_COMPILER_ICC   FALSE)
set(OSPRAY_COMPILER_GCC   FALSE)
set(OSPRAY_COMPILER_CLANG FALSE)
set(OSPRAY_COMPILER_MSVC  TRUE)

set(OSPRAY_ISPC_TARGET_LIST    sse4;avx;avx2;avx512skx-i32x16)
set(OSPRAY_ISPC_ADDRESSING     )
set(OSPRAY_ENABLE_VOLUMES      ON)

set(OSPRAY_TILE_SIZE      )

set(RKCOMMON_VERSION_REQUIRED 1.12.0)
set(EMBREE_VERSION_REQUIRED 4.3.0)

if (OSPRAY_ENABLE_VOLUMES)
  set(OPENVKL_VERSION_REQUIRED 2.0.0)
endif()

if (OSPRAY_MODULE_DENOISER)
  set(OIDN_VERSION_REQUIRED 2.1.0)
endif()

###############################################################################
# OSPRay dependencies

# Save state
set(OSPRAY_CMAKE_CURRENT_LIST_DIR     ${CMAKE_CURRENT_LIST_DIR})
set(OSPRAY_CURRENT_CONFIG_INSTALL_DIR ${CURRENT_CONFIG_INSTALL_DIR})
set(OSPRAY_CURRENT_ROOT_INSTALL_DIR   ${CURRENT_ROOT_INSTALL_DIR})

# Setup library path vars
if (WIN32)
  set(LIBRARY_PATH_PREFIX ${OSPRAY_ROOT}/lib/${CMAKE_IMPORT_LIBRARY_PREFIX})
  set(LIBRARY_SUFFIX ${CMAKE_IMPORT_LIBRARY_SUFFIX})
else()
  set(LIBRARY_PATH_PREFIX ${OSPRAY_ROOT}/lib/${CMAKE_SHARED_LIBRARY_PREFIX})
  set(LIBRARY_SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

# Include macros for finding embree
include(ospray_macros)

if (OSPRAY_INSTALL_DEPENDENCIES)
  # Dependencies installed with OSPRay
  if (WIN32)
    file(GLOB_RECURSE EMBREE_LIBRARY    ${LIBRARY_PATH_PREFIX}embree*.lib)
    file(GLOB_RECURSE RKCOMMON_LIBRARY ${LIBRARY_PATH_PREFIX}rkcommon*.lib)
    if (OSPRAY_ENABLE_VOLUMES)
      file(GLOB_RECURSE OPENVKL_LIBRARY   ${LIBRARY_PATH_PREFIX}openvkl*.lib)
    endif()
    if (OSPRAY_MODULE_DENOISER)
      file(GLOB_RECURSE OIDN_LIBRARY   ${LIBRARY_PATH_PREFIX}OpenImageDenoise*.lib)
    endif()
  else()
    file(GLOB_RECURSE EMBREE_LIBRARY    ${LIBRARY_PATH_PREFIX}embree*)
    file(GLOB_RECURSE RKCOMMON_LIBRARY ${LIBRARY_PATH_PREFIX}rkcommon*)
    if (OSPRAY_MODULE_DENOISER)
      file(GLOB_RECURSE OIDN_LIBRARY   ${LIBRARY_PATH_PREFIX}OpenImageDenoise*)
    endif()
  endif()
else()
  # Find existing Dependencies on the machine
  if (NOT TARGET embree)
    ospray_find_embree(${EMBREE_VERSION_REQUIRED} TRUE)
    ospray_verify_embree_features()
  endif()

  if (NOT TARGET rkcommon::rkcommon)
    find_dependency(rkcommon ${RKCOMMON_VERSION_REQUIRED})
    get_target_property(RKCOMMON_INCLUDE_DIRS rkcommon::rkcommon
      INTERFACE_INCLUDE_DIRECTORIES)
  endif()

  if (OSPRAY_ENABLE_VOLUMES)
    if (NOT TARGET openvkl::openvkl)
      ospray_find_openvkl(${OPENVKL_VERSION_REQUIRED} TRUE)
    endif()
    set(OPENVKL_LIBRARY openvkl::openvkl)
  endif()

  if (OSPRAY_MODULE_DENOISER)
    if (NOT TARGET OpenImageDenoise)
      find_dependency(OpenImageDenoise ${OIDN_VERSION_REQUIRED} TRUE)
    endif()
    set(OIDN_LIBRARY OpenImageDenoise)
  endif()

  set(EMBREE_LIBRARY embree)
  set(RKCOMMON_LIBRARY rkcommon::rkcommon)
endif()

# Restore state
set(CMAKE_CURRENT_LIST_DIR     ${OSPRAY_CMAKE_CURRENT_LIST_DIR})
set(CURRENT_CONFIG_INSTALL_DIR ${OSPRAY_CURRENT_CONFIG_INSTALL_DIR})
set(CURRENT_ROOT_INSTALL_DIR   ${OSPRAY_CURRENT_ROOT_INSTALL_DIR})


###############################################################################
# Finish OSPRay

# Include target exports
include(${CMAKE_CURRENT_LIST_DIR}/ospray_Exports.cmake)

# Add missing targets to libraries
set_target_properties(ospray::ospray PROPERTIES
  INTERFACE_LINK_LIBRARIES "${RKCOMMON_LIBRARY}")
set_target_properties(ospray::ospray_module_cpu PROPERTIES
  INTERFACE_LINK_LIBRARIES "ospray::ospray;${OPENVKL_LIBRARY};${EMBREE_LIBRARY}")

# Reset CMake module path to its state when this script was called.
set(CMAKE_MODULE_PATH ${OSPRAY_CALLERS_CMAKE_MODULE_PATH})

set(OSPRAY_CMAKE_ROOT ${OSPRAY_ROOT}/lib/cmake/ospray-3.0.0)

# Include definitions for clients to use ospray header files
set(OSPRAY_USE_FILE ${OSPRAY_CMAKE_ROOT}/osprayUse.cmake)
set(OSPRAY_SDK_USE_FILE ${OSPRAY_USE_FILE})

# OSPRAY_REPORT_NOT_FOUND() aborts, so if we made it this far,
# we have found ospray and all required dependencies.
include(FindPackageMessage)
find_package_MESSAGE(ospray "Found OSPRay: ${OSPRAY_ROOT}" "[${OSPRAY_ROOT}]")
