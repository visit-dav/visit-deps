#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::SvgWidgets" for configuration "Release"
set_property(TARGET Qt6::SvgWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::SvgWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/Qt6SvgWidgets.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/Qt6SvgWidgets.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::SvgWidgets )
list(APPEND _cmake_import_check_files_for_Qt6::SvgWidgets "${_IMPORT_PREFIX}/lib/Qt6SvgWidgets.lib" "${_IMPORT_PREFIX}/bin/Qt6SvgWidgets.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
