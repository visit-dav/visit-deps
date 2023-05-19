#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Designer" for configuration "Release"
set_property(TARGET Qt6::Designer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Designer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/Qt6Designer.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6Designer.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::Designer )
list(APPEND _cmake_import_check_files_for_Qt6::Designer "${_IMPORT_PREFIX}/lib/Qt6Designer.lib" "${_IMPORT_PREFIX}/bin/Qt6Designer.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
