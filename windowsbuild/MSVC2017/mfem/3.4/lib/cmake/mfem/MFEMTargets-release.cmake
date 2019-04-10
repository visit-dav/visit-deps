#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mfem" for configuration "Release"
set_property(TARGET mfem APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(mfem PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "${CONDUIT_LIBRARY};${ZLIB_LIBRARY}"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/mfem.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS mfem )
list(APPEND _IMPORT_CHECK_FILES_FOR_mfem "${_IMPORT_PREFIX}/lib/mfem.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
