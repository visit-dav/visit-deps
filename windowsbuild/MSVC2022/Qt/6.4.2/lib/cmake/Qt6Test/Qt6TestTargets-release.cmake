#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Test" for configuration "Release"
set_property(TARGET Qt6::Test APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Test PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/Qt6Test.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6Test.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::Test )
list(APPEND _cmake_import_check_files_for_Qt6::Test "${_IMPORT_PREFIX}/lib/Qt6Test.lib" "${_IMPORT_PREFIX}/bin/Qt6Test.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
