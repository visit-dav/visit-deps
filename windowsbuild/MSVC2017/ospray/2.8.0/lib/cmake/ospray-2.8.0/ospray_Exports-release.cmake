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

list(APPEND _IMPORT_CHECK_TARGETS ospray::ospray )
list(APPEND _IMPORT_CHECK_FILES_FOR_ospray::ospray "${_IMPORT_PREFIX}/lib/ospray.lib" "${_IMPORT_PREFIX}/bin/ospray.dll" )

# Import target "ospray::ospray_module_ispc" for configuration "Release"
set_property(TARGET ospray::ospray_module_ispc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ospray::ospray_module_ispc PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ospray_module_ispc.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ospray_module_ispc.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ospray::ospray_module_ispc )
list(APPEND _IMPORT_CHECK_FILES_FOR_ospray::ospray_module_ispc "${_IMPORT_PREFIX}/lib/ospray_module_ispc.lib" "${_IMPORT_PREFIX}/bin/ospray_module_ispc.dll" )

# Import target "ospray::ospray_imgui" for configuration "Release"
set_property(TARGET ospray::ospray_imgui APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ospray::ospray_imgui PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ospray_imgui.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ospray_imgui.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ospray::ospray_imgui )
list(APPEND _IMPORT_CHECK_FILES_FOR_ospray::ospray_imgui "${_IMPORT_PREFIX}/lib/ospray_imgui.lib" "${_IMPORT_PREFIX}/bin/ospray_imgui.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
