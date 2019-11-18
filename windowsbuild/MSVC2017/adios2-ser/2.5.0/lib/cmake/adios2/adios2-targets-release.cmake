#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "adios2::adios2" for configuration "Release"
set_property(TARGET adios2::adios2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::adios2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS adios2::adios2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_adios2::adios2 "${_IMPORT_PREFIX}/lib/adios2.lib" "${_IMPORT_PREFIX}/bin/adios2.dll" )

# Import target "adios2::taustubs" for configuration "Release"
set_property(TARGET adios2::taustubs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::taustubs PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/taustubs.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/taustubs.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS adios2::taustubs )
list(APPEND _IMPORT_CHECK_FILES_FOR_adios2::taustubs "${_IMPORT_PREFIX}/lib/taustubs.lib" "${_IMPORT_PREFIX}/bin/taustubs.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
