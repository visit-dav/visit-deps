# Additional target information for Qt6ToolsTools
if(NOT DEFINED QT_DEFAULT_IMPORT_CONFIGURATION)
    set(QT_DEFAULT_IMPORT_CONFIGURATION RELEASE)
endif()
get_target_property(_qt_imported_location Qt6::qhelpgenerator IMPORTED_LOCATION_RELEASE)
get_target_property(_qt_imported_location_default Qt6::qhelpgenerator IMPORTED_LOCATION_${QT_DEFAULT_IMPORT_CONFIGURATION})

# Import target "Qt6::qhelpgenerator" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::qhelpgenerator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)

if(_qt_imported_location)
    set_property(TARGET Qt6::qhelpgenerator PROPERTY IMPORTED_LOCATION_RELWITHDEBINFO "${_qt_imported_location}")
endif()

# Import target "Qt6::qhelpgenerator" for configuration "MinSizeRel"
set_property(TARGET Qt6::qhelpgenerator APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)

if(_qt_imported_location)
    set_property(TARGET Qt6::qhelpgenerator PROPERTY IMPORTED_LOCATION_MINSIZEREL "${_qt_imported_location}")
endif()

# Default configuration
if(_qt_imported_location_default)
    set_property(TARGET Qt6::qhelpgenerator PROPERTY IMPORTED_LOCATION "${_qt_imported_location_default}")
endif()
get_target_property(_qt_imported_location Qt6::qtattributionsscanner IMPORTED_LOCATION_RELEASE)
get_target_property(_qt_imported_location_default Qt6::qtattributionsscanner IMPORTED_LOCATION_${QT_DEFAULT_IMPORT_CONFIGURATION})

# Import target "Qt6::qtattributionsscanner" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::qtattributionsscanner APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)

if(_qt_imported_location)
    set_property(TARGET Qt6::qtattributionsscanner PROPERTY IMPORTED_LOCATION_RELWITHDEBINFO "${_qt_imported_location}")
endif()

# Import target "Qt6::qtattributionsscanner" for configuration "MinSizeRel"
set_property(TARGET Qt6::qtattributionsscanner APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)

if(_qt_imported_location)
    set_property(TARGET Qt6::qtattributionsscanner PROPERTY IMPORTED_LOCATION_MINSIZEREL "${_qt_imported_location}")
endif()

# Default configuration
if(_qt_imported_location_default)
    set_property(TARGET Qt6::qtattributionsscanner PROPERTY IMPORTED_LOCATION "${_qt_imported_location_default}")
endif()

unset(_qt_imported_location)
unset(_qt_imported_location_default)
unset(_qt_imported_soname)
unset(_qt_imported_soname_default)
unset(_qt_imported_configs)
