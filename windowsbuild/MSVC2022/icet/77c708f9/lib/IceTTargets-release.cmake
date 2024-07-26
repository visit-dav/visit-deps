#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "IceTCore" for configuration "Release"
set_property(TARGET IceTCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IceTCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/IceTCore.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/IceTCore.dll"
  )

list(APPEND _cmake_import_check_targets IceTCore )
list(APPEND _cmake_import_check_files_for_IceTCore "${_IMPORT_PREFIX}/lib/IceTCore.lib" "${_IMPORT_PREFIX}/bin/IceTCore.dll" )

# Import target "IceTMPI" for configuration "Release"
set_property(TARGET IceTMPI APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IceTMPI PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/IceTMPI.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "IceTCore;C:/Program Files (x86)/Microsoft SDKs/MPI/Lib/x64/msmpi.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/IceTMPI.dll"
  )

list(APPEND _cmake_import_check_targets IceTMPI )
list(APPEND _cmake_import_check_files_for_IceTMPI "${_IMPORT_PREFIX}/lib/IceTMPI.lib" "${_IMPORT_PREFIX}/bin/IceTMPI.dll" )

# Import target "IceTGL" for configuration "Release"
set_property(TARGET IceTGL APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(IceTGL PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/IceTGL.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "IceTCore;opengl32;glu32"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/IceTGL.dll"
  )

list(APPEND _cmake_import_check_targets IceTGL )
list(APPEND _cmake_import_check_files_for_IceTGL "${_IMPORT_PREFIX}/lib/IceTGL.lib" "${_IMPORT_PREFIX}/bin/IceTGL.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
