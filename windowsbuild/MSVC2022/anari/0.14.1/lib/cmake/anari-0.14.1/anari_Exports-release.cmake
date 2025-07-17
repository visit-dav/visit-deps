#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "anari::anari" for configuration "Release"
set_property(TARGET anari::anari APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/anari.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/anari.dll"
  )

list(APPEND _cmake_import_check_targets anari::anari )
list(APPEND _cmake_import_check_files_for_anari::anari "${_IMPORT_PREFIX}/lib/anari.lib" "${_IMPORT_PREFIX}/bin/anari.dll" )

# Import target "anari::anari_static" for configuration "Release"
set_property(TARGET anari::anari_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/anari_static.lib"
  )

list(APPEND _cmake_import_check_targets anari::anari_static )
list(APPEND _cmake_import_check_files_for_anari::anari_static "${_IMPORT_PREFIX}/lib/anari_static.lib" )

# Import target "anari::anari_backend" for configuration "Release"
set_property(TARGET anari::anari_backend APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari_backend PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/anari_backend.lib"
  )

list(APPEND _cmake_import_check_targets anari::anari_backend )
list(APPEND _cmake_import_check_files_for_anari::anari_backend "${_IMPORT_PREFIX}/lib/anari_backend.lib" )

# Import target "anari::anari_test_scenes" for configuration "Release"
set_property(TARGET anari::anari_test_scenes APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari_test_scenes PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/anari_test_scenes.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/anari_test_scenes.dll"
  )

list(APPEND _cmake_import_check_targets anari::anari_test_scenes )
list(APPEND _cmake_import_check_files_for_anari::anari_test_scenes "${_IMPORT_PREFIX}/lib/anari_test_scenes.lib" "${_IMPORT_PREFIX}/bin/anari_test_scenes.dll" )

# Import target "anari::helium" for configuration "Release"
set_property(TARGET anari::helium APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::helium PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/helium.lib"
  )

list(APPEND _cmake_import_check_targets anari::helium )
list(APPEND _cmake_import_check_files_for_anari::helium "${_IMPORT_PREFIX}/lib/helium.lib" )

# Import target "anari::anari_library_debug" for configuration "Release"
set_property(TARGET anari::anari_library_debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari_library_debug PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/anari_library_debug.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/anari_library_debug.dll"
  )

list(APPEND _cmake_import_check_targets anari::anari_library_debug )
list(APPEND _cmake_import_check_files_for_anari::anari_library_debug "${_IMPORT_PREFIX}/lib/anari_library_debug.lib" "${_IMPORT_PREFIX}/bin/anari_library_debug.dll" )

# Import target "anari::anari_library_sink" for configuration "Release"
set_property(TARGET anari::anari_library_sink APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari_library_sink PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/anari_library_sink.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/anari_library_sink.dll"
  )

list(APPEND _cmake_import_check_targets anari::anari_library_sink )
list(APPEND _cmake_import_check_files_for_anari::anari_library_sink "${_IMPORT_PREFIX}/lib/anari_library_sink.lib" "${_IMPORT_PREFIX}/bin/anari_library_sink.dll" )

# Import target "anari::anari_library_helide" for configuration "Release"
set_property(TARGET anari::anari_library_helide APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(anari::anari_library_helide PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/anari_library_helide.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/anari_library_helide.dll"
  )

list(APPEND _cmake_import_check_targets anari::anari_library_helide )
list(APPEND _cmake_import_check_files_for_anari::anari_library_helide "${_IMPORT_PREFIX}/lib/anari_library_helide.lib" "${_IMPORT_PREFIX}/bin/anari_library_helide.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
