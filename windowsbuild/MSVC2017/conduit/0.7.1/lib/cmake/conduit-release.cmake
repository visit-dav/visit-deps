#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "conduit" for configuration "Release"
set_property(TARGET conduit APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/conduit.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/conduit.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit "${_IMPORT_PREFIX}/lib/conduit.lib" "${_IMPORT_PREFIX}/bin/conduit.dll" )

# Import target "conduit_python" for configuration "Release"
set_property(TARGET conduit_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/conduit_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_python "${_IMPORT_PREFIX}/python-modules/conduit/conduit_python.pyd" )

# Import target "conduit_utils_python" for configuration "Release"
set_property(TARGET conduit_utils_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_utils_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/utils/conduit_utils_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_utils_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_utils_python "${_IMPORT_PREFIX}/python-modules/conduit/utils/conduit_utils_python.pyd" )

# Import target "conduit_relay" for configuration "Release"
set_property(TARGET conduit_relay APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/conduit_relay.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/conduit_relay.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay "${_IMPORT_PREFIX}/lib/conduit_relay.lib" "${_IMPORT_PREFIX}/bin/conduit_relay.dll" )

# Import target "conduit_relay_python" for configuration "Release"
set_property(TARGET conduit_relay_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/relay/conduit_relay_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_python "${_IMPORT_PREFIX}/python-modules/conduit/relay/conduit_relay_python.pyd" )

# Import target "conduit_relay_io_python" for configuration "Release"
set_property(TARGET conduit_relay_io_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_io_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/relay/io/conduit_relay_io_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_io_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_io_python "${_IMPORT_PREFIX}/python-modules/conduit/relay/io/conduit_relay_io_python.pyd" )

# Import target "conduit_relay_io_blueprint_python" for configuration "Release"
set_property(TARGET conduit_relay_io_blueprint_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_io_blueprint_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/relay/io/blueprint/conduit_relay_io_blueprint_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_io_blueprint_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_io_blueprint_python "${_IMPORT_PREFIX}/python-modules/conduit/relay/io/blueprint/conduit_relay_io_blueprint_python.pyd" )

# Import target "conduit_relay_web_python" for configuration "Release"
set_property(TARGET conduit_relay_web_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_web_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/relay/web/conduit_relay_web_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_web_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_web_python "${_IMPORT_PREFIX}/python-modules/conduit/relay/web/conduit_relay_web_python.pyd" )

# Import target "conduit_relay_mpi_python" for configuration "Release"
set_property(TARGET conduit_relay_mpi_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_mpi_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/relay/mpi/conduit_relay_mpi_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_mpi_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_mpi_python "${_IMPORT_PREFIX}/python-modules/conduit/relay/mpi/conduit_relay_mpi_python.pyd" )

# Import target "conduit_relay_mpi" for configuration "Release"
set_property(TARGET conduit_relay_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_mpi PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/conduit_relay_mpi.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/conduit_relay_mpi.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_mpi )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_mpi "${_IMPORT_PREFIX}/lib/conduit_relay_mpi.lib" "${_IMPORT_PREFIX}/bin/conduit_relay_mpi.dll" )

# Import target "conduit_relay_mpi_io" for configuration "Release"
set_property(TARGET conduit_relay_mpi_io APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_relay_mpi_io PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/conduit_relay_mpi_io.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/conduit_relay_mpi_io.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_relay_mpi_io )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_relay_mpi_io "${_IMPORT_PREFIX}/lib/conduit_relay_mpi_io.lib" "${_IMPORT_PREFIX}/bin/conduit_relay_mpi_io.dll" )

# Import target "conduit_blueprint" for configuration "Release"
set_property(TARGET conduit_blueprint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/conduit_blueprint.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/conduit_blueprint.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint "${_IMPORT_PREFIX}/lib/conduit_blueprint.lib" "${_IMPORT_PREFIX}/bin/conduit_blueprint.dll" )

# Import target "conduit_blueprint_python" for configuration "Release"
set_property(TARGET conduit_blueprint_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/conduit_blueprint_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint_python "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/conduit_blueprint_python.pyd" )

# Import target "conduit_blueprint_mcarray_python" for configuration "Release"
set_property(TARGET conduit_blueprint_mcarray_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint_mcarray_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mcarray/conduit_blueprint_mcarray_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint_mcarray_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint_mcarray_python "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mcarray/conduit_blueprint_mcarray_python.pyd" )

# Import target "conduit_blueprint_mcarray_examples_python" for configuration "Release"
set_property(TARGET conduit_blueprint_mcarray_examples_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint_mcarray_examples_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mcarray/examples/conduit_blueprint_mcarray_examples_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint_mcarray_examples_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint_mcarray_examples_python "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mcarray/examples/conduit_blueprint_mcarray_examples_python.pyd" )

# Import target "conduit_blueprint_mesh_python" for configuration "Release"
set_property(TARGET conduit_blueprint_mesh_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint_mesh_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mesh/conduit_blueprint_mesh_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint_mesh_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint_mesh_python "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mesh/conduit_blueprint_mesh_python.pyd" )

# Import target "conduit_blueprint_mesh_examples_python" for configuration "Release"
set_property(TARGET conduit_blueprint_mesh_examples_python APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint_mesh_examples_python PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mesh/examples/conduit_blueprint_mesh_examples_python.pyd"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint_mesh_examples_python )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint_mesh_examples_python "${_IMPORT_PREFIX}/python-modules/conduit/blueprint/mesh/examples/conduit_blueprint_mesh_examples_python.pyd" )

# Import target "conduit_blueprint_mpi" for configuration "Release"
set_property(TARGET conduit_blueprint_mpi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(conduit_blueprint_mpi PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/conduit_blueprint_mpi.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/conduit_blueprint_mpi.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS conduit_blueprint_mpi )
list(APPEND _IMPORT_CHECK_FILES_FOR_conduit_blueprint_mpi "${_IMPORT_PREFIX}/lib/conduit_blueprint_mpi.lib" "${_IMPORT_PREFIX}/bin/conduit_blueprint_mpi.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
