#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QWindowsVistaStylePlugin" for configuration "Release"
set_property(TARGET Qt6::QWindowsVistaStylePlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::QWindowsVistaStylePlugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./plugins/styles/qwindowsvistastyle.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::QWindowsVistaStylePlugin )
list(APPEND _cmake_import_check_files_for_Qt6::QWindowsVistaStylePlugin "${_IMPORT_PREFIX}/./plugins/styles/qwindowsvistastyle.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
