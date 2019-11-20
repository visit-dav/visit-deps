#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "adios2::adios2_mpi" for configuration "Release"
set_property(TARGET adios2::adios2_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::adios2_mpi PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_mpi.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "adios2::taustubs"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_mpi.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS adios2::adios2_mpi )
list(APPEND _IMPORT_CHECK_FILES_FOR_adios2::adios2_mpi "${_IMPORT_PREFIX}/lib/adios2_mpi.lib" "${_IMPORT_PREFIX}/bin/adios2_mpi.dll" )

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
