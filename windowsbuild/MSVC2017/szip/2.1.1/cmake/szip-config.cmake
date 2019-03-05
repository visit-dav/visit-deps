#-----------------------------------------------------------------------------
# SZIP Config file for compiling against SZIP build directory
#-----------------------------------------------------------------------------

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was szip-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

####################################################################################

string(TOUPPER szip SZIP_PACKAGE_NAME)

set (${SZIP_PACKAGE_NAME}_VALID_COMPONENTS shared)

#-----------------------------------------------------------------------------
# User Options
#-----------------------------------------------------------------------------
set (${SZIP_PACKAGE_NAME}_ENABLE_ENCODING      ON)
set (${SZIP_PACKAGE_NAME}_BUILD_SHARED_LIBS    ON)
set (${SZIP_PACKAGE_NAME}_EXPORT_LIBRARIES     szip)

#-----------------------------------------------------------------------------
# Directories
#-----------------------------------------------------------------------------
set (${SZIP_PACKAGE_NAME}_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")

set (${SZIP_PACKAGE_NAME}_SHARE_DIR "${PACKAGE_PREFIX_DIR}/cmake")

#-----------------------------------------------------------------------------
# Version Strings
#-----------------------------------------------------------------------------
set (${SZIP_PACKAGE_NAME}_VERSION_STRING 2.1)
set (${SZIP_PACKAGE_NAME}_VERSION_MAJOR  2.1)
set (${SZIP_PACKAGE_NAME}_VERSION_MINOR  1)

#-----------------------------------------------------------------------------
# Don't include targets if this file is being picked up by another
# project which has already build SZIP as a subproject
#-----------------------------------------------------------------------------
if (NOT TARGET "szip")
  include (${PACKAGE_PREFIX_DIR}/cmake/szip-targets.cmake)
endif ()

set(SZIP_FOUND TRUE)
