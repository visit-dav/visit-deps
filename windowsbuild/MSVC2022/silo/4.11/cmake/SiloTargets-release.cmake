#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "silo" for configuration "Release"
set_property(TARGET silo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(silo PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/siloh5.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/siloh5.dll"
  )

list(APPEND _cmake_import_check_targets silo )
list(APPEND _cmake_import_check_files_for_silo "${_IMPORT_PREFIX}/lib/siloh5.lib" "${_IMPORT_PREFIX}/bin/siloh5.dll" )

# Import target "silex" for configuration "Release"
set_property(TARGET silex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(silex PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/silex.exe"
  )

list(APPEND _cmake_import_check_targets silex )
list(APPEND _cmake_import_check_files_for_silex "${_IMPORT_PREFIX}/bin/silex.exe" )

# Import target "browser" for configuration "Release"
set_property(TARGET browser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(browser PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/browser.exe"
  )

list(APPEND _cmake_import_check_targets browser )
list(APPEND _cmake_import_check_files_for_browser "${_IMPORT_PREFIX}/bin/browser.exe" )

# Import target "SiloPy" for configuration "Release"
set_property(TARGET SiloPy APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SiloPy PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/SiloPy.pyd"
  )

list(APPEND _cmake_import_check_targets SiloPy )
list(APPEND _cmake_import_check_files_for_SiloPy "${_IMPORT_PREFIX}/bin/SiloPy.pyd" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
