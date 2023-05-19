#-----------------------------------------------------------------------------
# ZLIB Config file for compiling against ZLIB build directory
#-----------------------------------------------------------------------------


get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

string(TOUPPER zlib ZLIB_PACKAGE_NAME)

set (${ZLIB_PACKAGE_NAME}_VALID_COMPONENTS shared)

#-----------------------------------------------------------------------------
# User Options
#-----------------------------------------------------------------------------
set (${ZLIB_PACKAGE_NAME}_BUILD_SHARED_LIBS    ON)
set (${ZLIB_PACKAGE_NAME}_EXPORT_LIBRARIES     zlib)

#-----------------------------------------------------------------------------
# Directories
#-----------------------------------------------------------------------------
set (${ZLIB_PACKAGE_NAME}_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")

set (${ZLIB_PACKAGE_NAME}_SHARE_DIR "${PACKAGE_PREFIX_DIR}/cmake")

#-----------------------------------------------------------------------------
# Version Strings
#-----------------------------------------------------------------------------
set (${ZLIB_PACKAGE_NAME}_VERSION_STRING 1.2.11)
set (${ZLIB_PACKAGE_NAME}_VERSION_MAJOR  1)
set (${ZLIB_PACKAGE_NAME}_VERSION_MINOR  2)

#-----------------------------------------------------------------------------
# Don't include targets if this file is being picked up by another
# project which has already build ZLIB as a subproject
#-----------------------------------------------------------------------------
if (NOT TARGET "zlib")
  include (${PACKAGE_PREFIX_DIR}/cmake/zlib-targets.cmake)
endif ()

set(ZLIB_FOUND TRUE)
