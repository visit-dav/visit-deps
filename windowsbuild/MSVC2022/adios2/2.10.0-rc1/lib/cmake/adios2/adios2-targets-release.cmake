#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "adios2::core" for configuration "Release"
set_property(TARGET adios2::core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::core PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_core.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_core.dll"
  )

list(APPEND _cmake_import_check_targets adios2::core )
list(APPEND _cmake_import_check_files_for_adios2::core "${_IMPORT_PREFIX}/lib/adios2_core.lib" "${_IMPORT_PREFIX}/bin/adios2_core.dll" )

# Import target "adios2::core_mpi" for configuration "Release"
set_property(TARGET adios2::core_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(adios2::core_mpi PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/adios2_core_mpi.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/adios2_core_mpi.dll"
  )

list(APPEND _cmake_import_check_targets adios2::core_mpi )
list(APPEND _cmake_import_check_files_for_adios2::core_mpi "${_IMPORT_PREFIX}/lib/adios2_core_mpi.lib" "${_IMPORT_PREFIX}/bin/adios2_core_mpi.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
