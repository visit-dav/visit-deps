# Copyright (C) 1994-2021 Lawrence Livermore National Security, LLC.
# LLNL-CODE-425250.
# All rights reserved.
#
# This file is part of Silo. For details, see silo.llnl.gov.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the disclaimer below.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the disclaimer (as noted
#      below) in the documentation and/or other materials provided with
#      the distribution.
#    * Neither the name of the LLNS/LLNL nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
# THIS SOFTWARE  IS PROVIDED BY  THE COPYRIGHT HOLDERS  AND CONTRIBUTORS
# "AS  IS" AND  ANY EXPRESS  OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT
# LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A  PARTICULAR  PURPOSE ARE  DISCLAIMED.  IN  NO  EVENT SHALL  LAWRENCE
# LIVERMORE  NATIONAL SECURITY, LLC,  THE U.S.  DEPARTMENT OF  ENERGY OR
# CONTRIBUTORS BE LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR  CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT  LIMITED TO,
# PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS  OF USE,  DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER  IN CONTRACT, STRICT LIABILITY,  OR TORT (INCLUDING
# NEGLIGENCE OR  OTHERWISE) ARISING IN  ANY WAY OUT  OF THE USE  OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# This work was produced at Lawrence Livermore National Laboratory under
# Contract No.  DE-AC52-07NA27344 with the DOE.
#
# Neither the  United States Government nor  Lawrence Livermore National
# Security, LLC nor any of  their employees, makes any warranty, express
# or  implied,  or  assumes  any  liability or  responsibility  for  the
# accuracy, completeness,  or usefulness of  any information, apparatus,
# product, or  process disclosed, or  represents that its use  would not
# infringe privately-owned rights.
#
# Any reference herein to  any specific commercial products, process, or
# services by trade name,  trademark, manufacturer or otherwise does not
# necessarily  constitute or imply  its endorsement,  recommendation, or
# favoring  by  the  United  States  Government  or  Lawrence  Livermore
# National Security,  LLC. The views  and opinions of  authors expressed
# herein do not necessarily state  or reflect those of the United States
# Government or Lawrence Livermore National Security, LLC, and shall not
# be used for advertising or product endorsement purposes.
#
##############################################################################

#-----------------------------------------------------------------------------
# SILO Config file
#-----------------------------------------------------------------------------

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was SiloConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

string(TOUPPER silo SILO_PACKAGE_NAME)


#-----------------------------------------------------------------------------
# User Options
#-----------------------------------------------------------------------------
# Should compiler information used for the build be provided?

set(SILO_ENABLE_SHARED    ON)

set(SILO_ENABLE_SILEX ON)
set(SILO_ENABLE_BROWSER ON)
set(SILO_ENABLE_FORTRAN OFF)
set(SILO_ENABLE_HDF5 ON)
set(SILO_ENABLE_JSON OFF)
set(SILO_ENABLE_PYTHON_MODULE ON)
set(SILO_ENABLE_TESTS OFF)
set(SILO_BUILD_FOR_BSD_LICENSE ON)
set(SILO_ENABLE_ZFP )

if(NOT SILO_BUILD_FOR_BSD_LICENSE)
  set(SILO_ENABLE_FPZIP OFF)
  set(SILO_ENABLE_HZIP OFF)
endif()

#-----------------------------------------------------------------------------
# Directories
#-----------------------------------------------------------------------------
set(${SILO_PACKAGE_NAME}_INCLUDE_DIR ${PACKAGE_PREFIX_DIR}/include)

#-----------------------------------------------------------------------------
# Version Strings
#-----------------------------------------------------------------------------
set(${SILO_PACKAGE_NAME}_VERSION_STRING 4.10.3)
set(${SILO_PACKAGE_NAME}_VERSION_MAJOR  4)
set(${SILO_PACKAGE_NAME}_VERSION_MINOR  10)

#-----------------------------------------------------------------------------
# Don't include targets if this file is being picked up by another
# project which has already built SILO as a subproject
#-----------------------------------------------------------------------------
if(NOT TARGET silo)
  include (${PACKAGE_PREFIX_DIR}/cmake/SiloTargets.cmake)

  if(SILO_ENABLE_HDF5)
      include(CMakeFindDependencyMacro)
      find_dependency(hdf5 1.8.19 PATHS ${HDF5_DIR})
  endif()
endif()


