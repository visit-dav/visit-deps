#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ospray::ospray" for configuration "Release"
set_property(TARGET ospray::ospray APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ospray::ospray PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ospray.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ospray.dll"
  )

list(APPEND _cmake_import_check_targets ospray::ospray )
list(APPEND _cmake_import_check_files_for_ospray::ospray "${_IMPORT_PREFIX}/lib/ospray.lib" "${_IMPORT_PREFIX}/bin/ospray.dll" )

# Import target "ospray::ospray_module_cpu" for configuration "Release"
set_property(TARGET ospray::ospray_module_cpu APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ospray::ospray_module_cpu PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ospray_module_cpu.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ospray_module_cpu.dll"
  )

list(APPEND _cmake_import_check_targets ospray::ospray_module_cpu )
list(APPEND _cmake_import_check_files_for_ospray::ospray_module_cpu "${_IMPORT_PREFIX}/lib/ospray_module_cpu.lib" "${_IMPORT_PREFIX}/bin/ospray_module_cpu.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
