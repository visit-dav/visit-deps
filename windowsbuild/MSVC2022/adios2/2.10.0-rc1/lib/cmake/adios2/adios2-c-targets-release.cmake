#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "adios2::c" for configuration "Release"
set_property(TARGET adios2::c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::c PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_c.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "adios2::core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_c.dll"
  )

list(APPEND _cmake_import_check_targets adios2::c )
list(APPEND _cmake_import_check_files_for_adios2::c "${_IMPORT_PREFIX}/lib/adios2_c.lib" "${_IMPORT_PREFIX}/bin/adios2_c.dll" )

# Import target "adios2::c_mpi" for configuration "Release"
set_property(TARGET adios2::c_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::c_mpi PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_c_mpi.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "adios2::core_mpi"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_c_mpi.dll"
  )

list(APPEND _cmake_import_check_targets adios2::c_mpi )
list(APPEND _cmake_import_check_files_for_adios2::c_mpi "${_IMPORT_PREFIX}/lib/adios2_c_mpi.lib" "${_IMPORT_PREFIX}/bin/adios2_c_mpi.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
