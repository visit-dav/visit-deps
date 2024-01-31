#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ffs::ffs" for configuration "Release"
set_property(TARGET ffs::ffs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ffs::ffs PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_ffs.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "dill::dill"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_ffs.dll"
  )

list(APPEND _cmake_import_check_targets ffs::ffs )
list(APPEND _cmake_import_check_files_for_ffs::ffs "${_IMPORT_PREFIX}/lib/adios2_ffs.lib" "${_IMPORT_PREFIX}/bin/adios2_ffs.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
