# Additional target information for Qt6Linguist
if(NOT DEFINED QT_DEFAULT_IMPORT_CONFIGURATION)
    set(QT_DEFAULT_IMPORT_CONFIGURATION RELEASE)
endif()
__qt_internal_promote_target_to_global_checked(Qt6::Linguist)
__qt_internal_promote_target_to_global_checked(Qt6::LinguistPrivate)

