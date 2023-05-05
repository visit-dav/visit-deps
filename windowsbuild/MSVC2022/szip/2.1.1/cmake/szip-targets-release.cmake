#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "szip-shared" for configuration "Release"
set_property(TARGET szip-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(szip-shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/szip.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/szip.dll"
  )


list(APPEND _cmake_import_check_targets szip-shared )
list(APPEND _cmake_import_check_files_for_szip-shared "${_IMPORT_PREFIX}/lib/szip.lib" "${_IMPORT_PREFIX}/bin/szip.dll" )

add_library(szip ALIAS szip-shared)
# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
