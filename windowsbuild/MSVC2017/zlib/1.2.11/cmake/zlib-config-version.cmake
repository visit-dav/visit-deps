#-----------------------------------------------------------------------------
# ZLIB Version file for install directory
#-----------------------------------------------------------------------------

set (PACKAGE_VERSION 1.2.11)

if ("${PACKAGE_FIND_VERSION_MAJOR}" EQUAL 1)

  # exact match for version 1.2.11
  if ("${PACKAGE_FIND_VERSION_MINOR}" EQUAL 2)

    # compatible with any version 1.2.x
    set (PACKAGE_VERSION_COMPATIBLE 1)

    if ("${PACKAGE_FIND_VERSION_PATCH}" EQUAL 11)
      set (PACKAGE_VERSION_EXACT 1)

      if ("${PACKAGE_FIND_VERSION_TWEAK}" EQUAL )
        # not using this yet
      endif ()

    endif ()

  endif ()
endif ()


