# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.22)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS VTK::vtkCommonCorePython VTK::vtkCommonMathPython VTK::vtkCommonMiscPython VTK::vtkCommonTransformsPython VTK::vtkCommonDataModelPython VTK::vtkCommonExecutionModelPython VTK::vtkIOCorePython VTK::vtkFiltersCellGridPython VTK::vtkIOCellGridPython VTK::vtkIOLegacyPython VTK::vtkIOXMLParserPython VTK::vtkFiltersCorePython VTK::vtkRenderingCorePython VTK::vtkDomainsChemistryPython VTK::vtkFiltersGeneralPython VTK::vtkImagingCorePython VTK::vtkIOImagePython VTK::vtkRenderingHyperTreeGridPython VTK::vtkRenderingUIPython VTK::vtkRenderingOpenGL2Python VTK::vtkRenderingSceneGraphPython VTK::vtkRenderingVolumePython VTK::vtkRenderingRayTracingPython VTK::vtkImagingMathPython VTK::vtkRenderingVolumeOpenGL2Python VTK::vtkRenderingVolumeAMRPython VTK::vtkCommonSystemPython VTK::vtkFiltersAMRPython VTK::vtkRenderingAnariPython VTK::vtkFiltersSourcesPython VTK::vtkIOPLYPython VTK::vtkIOEnSightPython VTK::vtkFiltersTemporalPython VTK::vtkParallelCorePython VTK::vtkIOGeometryPython VTK::vtkFiltersVerdictPython VTK::vtkRenderingContext2DPython VTK::vtkInteractionWidgetsPython VTK::vtkFiltersExtractionPython VTK::vtkCommonComputationalGeometryPython VTK::vtkImagingColorPython VTK::vtkImagingGeneralPython VTK::vtkImagingHybridPython VTK::vtkRenderingAnnotationPython VTK::vtkInteractionStylePython VTK::vtkGeovisCorePython VTK::vtkImagingSourcesPython VTK::vtkFiltersFlowPathsPython VTK::vtkFiltersTexturePython VTK::vtkFiltersModelingPython VTK::vtkCommonColorPython VTK::vtkFiltersHyperTreePython VTK::vtkFiltersGeometryPython VTK::vtkFiltersHybridPython VTK::vtkFiltersStatisticsPython VTK::vtkIOXMLPython VTK::vtkRenderingFreeTypePython VTK::vtkFiltersReductionPython VTK::vtkpythonmodules VTK::vtkpython)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target VTK::vtkCommonCorePython
add_library(VTK::vtkCommonCorePython MODULE IMPORTED)

# Create imported target VTK::vtkCommonMathPython
add_library(VTK::vtkCommonMathPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonMiscPython
add_library(VTK::vtkCommonMiscPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonTransformsPython
add_library(VTK::vtkCommonTransformsPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonDataModelPython
add_library(VTK::vtkCommonDataModelPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonExecutionModelPython
add_library(VTK::vtkCommonExecutionModelPython MODULE IMPORTED)

# Create imported target VTK::vtkIOCorePython
add_library(VTK::vtkIOCorePython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersCellGridPython
add_library(VTK::vtkFiltersCellGridPython MODULE IMPORTED)

# Create imported target VTK::vtkIOCellGridPython
add_library(VTK::vtkIOCellGridPython MODULE IMPORTED)

# Create imported target VTK::vtkIOLegacyPython
add_library(VTK::vtkIOLegacyPython MODULE IMPORTED)

# Create imported target VTK::vtkIOXMLParserPython
add_library(VTK::vtkIOXMLParserPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersCorePython
add_library(VTK::vtkFiltersCorePython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingCorePython
add_library(VTK::vtkRenderingCorePython MODULE IMPORTED)

# Create imported target VTK::vtkDomainsChemistryPython
add_library(VTK::vtkDomainsChemistryPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersGeneralPython
add_library(VTK::vtkFiltersGeneralPython MODULE IMPORTED)

# Create imported target VTK::vtkImagingCorePython
add_library(VTK::vtkImagingCorePython MODULE IMPORTED)

# Create imported target VTK::vtkIOImagePython
add_library(VTK::vtkIOImagePython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingHyperTreeGridPython
add_library(VTK::vtkRenderingHyperTreeGridPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingUIPython
add_library(VTK::vtkRenderingUIPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingOpenGL2Python
add_library(VTK::vtkRenderingOpenGL2Python MODULE IMPORTED)

# Create imported target VTK::vtkRenderingSceneGraphPython
add_library(VTK::vtkRenderingSceneGraphPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingVolumePython
add_library(VTK::vtkRenderingVolumePython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingRayTracingPython
add_library(VTK::vtkRenderingRayTracingPython MODULE IMPORTED)

# Create imported target VTK::vtkImagingMathPython
add_library(VTK::vtkImagingMathPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingVolumeOpenGL2Python
add_library(VTK::vtkRenderingVolumeOpenGL2Python MODULE IMPORTED)

# Create imported target VTK::vtkRenderingVolumeAMRPython
add_library(VTK::vtkRenderingVolumeAMRPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonSystemPython
add_library(VTK::vtkCommonSystemPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersAMRPython
add_library(VTK::vtkFiltersAMRPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingAnariPython
add_library(VTK::vtkRenderingAnariPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersSourcesPython
add_library(VTK::vtkFiltersSourcesPython MODULE IMPORTED)

# Create imported target VTK::vtkIOPLYPython
add_library(VTK::vtkIOPLYPython MODULE IMPORTED)

# Create imported target VTK::vtkIOEnSightPython
add_library(VTK::vtkIOEnSightPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersTemporalPython
add_library(VTK::vtkFiltersTemporalPython MODULE IMPORTED)

# Create imported target VTK::vtkParallelCorePython
add_library(VTK::vtkParallelCorePython MODULE IMPORTED)

# Create imported target VTK::vtkIOGeometryPython
add_library(VTK::vtkIOGeometryPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersVerdictPython
add_library(VTK::vtkFiltersVerdictPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingContext2DPython
add_library(VTK::vtkRenderingContext2DPython MODULE IMPORTED)

# Create imported target VTK::vtkInteractionWidgetsPython
add_library(VTK::vtkInteractionWidgetsPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersExtractionPython
add_library(VTK::vtkFiltersExtractionPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonComputationalGeometryPython
add_library(VTK::vtkCommonComputationalGeometryPython MODULE IMPORTED)

# Create imported target VTK::vtkImagingColorPython
add_library(VTK::vtkImagingColorPython MODULE IMPORTED)

# Create imported target VTK::vtkImagingGeneralPython
add_library(VTK::vtkImagingGeneralPython MODULE IMPORTED)

# Create imported target VTK::vtkImagingHybridPython
add_library(VTK::vtkImagingHybridPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingAnnotationPython
add_library(VTK::vtkRenderingAnnotationPython MODULE IMPORTED)

# Create imported target VTK::vtkInteractionStylePython
add_library(VTK::vtkInteractionStylePython MODULE IMPORTED)

# Create imported target VTK::vtkGeovisCorePython
add_library(VTK::vtkGeovisCorePython MODULE IMPORTED)

# Create imported target VTK::vtkImagingSourcesPython
add_library(VTK::vtkImagingSourcesPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersFlowPathsPython
add_library(VTK::vtkFiltersFlowPathsPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersTexturePython
add_library(VTK::vtkFiltersTexturePython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersModelingPython
add_library(VTK::vtkFiltersModelingPython MODULE IMPORTED)

# Create imported target VTK::vtkCommonColorPython
add_library(VTK::vtkCommonColorPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersHyperTreePython
add_library(VTK::vtkFiltersHyperTreePython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersGeometryPython
add_library(VTK::vtkFiltersGeometryPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersHybridPython
add_library(VTK::vtkFiltersHybridPython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersStatisticsPython
add_library(VTK::vtkFiltersStatisticsPython MODULE IMPORTED)

# Create imported target VTK::vtkIOXMLPython
add_library(VTK::vtkIOXMLPython MODULE IMPORTED)

# Create imported target VTK::vtkRenderingFreeTypePython
add_library(VTK::vtkRenderingFreeTypePython MODULE IMPORTED)

# Create imported target VTK::vtkFiltersReductionPython
add_library(VTK::vtkFiltersReductionPython MODULE IMPORTED)

# Create imported target VTK::vtkpythonmodules
add_library(VTK::vtkpythonmodules INTERFACE IMPORTED)

set_target_properties(VTK::vtkpythonmodules PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.5/vtkpythonmodules"
)

# Create imported target VTK::vtkpython
add_executable(VTK::vtkpython IMPORTED)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/VTKPython-targets-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(_cmake_target IN LISTS _cmake_import_check_targets)
  foreach(_cmake_file IN LISTS "_cmake_import_check_files_for_${_cmake_target}")
    if(NOT EXISTS "${_cmake_file}")
      message(FATAL_ERROR "The imported target \"${_cmake_target}\" references the file
   \"${_cmake_file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_cmake_file)
  unset("_cmake_import_check_files_for_${_cmake_target}")
endforeach()
unset(_cmake_target)
unset(_cmake_import_check_targets)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
