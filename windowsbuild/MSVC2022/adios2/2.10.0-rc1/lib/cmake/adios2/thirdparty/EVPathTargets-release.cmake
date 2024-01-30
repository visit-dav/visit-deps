#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "EVPath::EVPath" for configuration "Release"
set_property(TARGET EVPath::EVPath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(EVPath::EVPath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_evpath.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "dill::dill"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_evpath.dll"
  )

list(APPEND _cmake_import_check_targets EVPath::EVPath )
list(APPEND _cmake_import_check_files_for_EVPath::EVPath "${_IMPORT_PREFIX}/lib/adios2_evpath.lib" "${_IMPORT_PREFIX}/bin/adios2_evpath.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
