#-----------------------------------------------------------------------------
# HDF5 Version file for install directory
#-----------------------------------------------------------------------------

set (PACKAGE_VERSION "1.8.19")

if ("${PACKAGE_FIND_VERSION_MAJOR}" EQUAL 1)

  # exact match for version 1.8
  if ("${PACKAGE_FIND_VERSION_MINOR}" EQUAL 8)

    # compatible with any version 1.8.x
    set (PACKAGE_VERSION_COMPATIBLE 1) 
    
    if ("${PACKAGE_FIND_VERSION_PATCH}" EQUAL 19)
      set (PACKAGE_VERSION_EXACT 1)    

    endif ("${PACKAGE_FIND_VERSION_PATCH}" EQUAL 19)
    
  endif ("${PACKAGE_FIND_VERSION_MINOR}" EQUAL 8)
endif ("${PACKAGE_FIND_VERSION_MAJOR}" EQUAL 1)


