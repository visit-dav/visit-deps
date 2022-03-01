#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "vtkh_lodepng" for configuration "Release"
set_property(TARGET vtkh_lodepng APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkh_lodepng PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/vtkh_lodepng.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkh_lodepng )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkh_lodepng "${_IMPORT_PREFIX}/lib/vtkh_lodepng.lib" )

# Import target "vtkh_utils" for configuration "Release"
set_property(TARGET vtkh_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkh_utils PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/vtkh_utils.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkh_utils )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkh_utils "${_IMPORT_PREFIX}/lib/vtkh_utils.lib" )

# Import target "vtkh_core" for configuration "Release"
set_property(TARGET vtkh_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkh_core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/vtkh_core.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkh_core )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkh_core "${_IMPORT_PREFIX}/lib/vtkh_core.lib" )

# Import target "vtkh_filters" for configuration "Release"
set_property(TARGET vtkh_filters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkh_filters PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/vtkh_filters.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkh_filters )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkh_filters "${_IMPORT_PREFIX}/lib/vtkh_filters.lib" )

# Import target "vtkh_rendering" for configuration "Release"
set_property(TARGET vtkh_rendering APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkh_rendering PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/vtkh_rendering.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkh_rendering )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkh_rendering "${_IMPORT_PREFIX}/lib/vtkh_rendering.lib" )

# Import target "vtkh_compositing" for configuration "Release"
set_property(TARGET vtkh_compositing APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkh_compositing PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/vtkh_compositing.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkh_compositing )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkh_compositing "${_IMPORT_PREFIX}/lib/vtkh_compositing.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
