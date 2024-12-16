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
foreach(_cmake_expected_target IN ITEMS VTK::vtkbuild VTK::WrappingTools VTK::WrapHierarchy VTK::WrapPython VTK::WrapPythonInit VTK::ParseJava VTK::WrapJava VTK::loguru VTK::kwiml VTK::vtksys VTK::utf8 VTK::CommonCore VTK::CommonCore-private-kit-links VTK::kissfft VTK::CommonMath VTK::CommonTransforms VTK::exprtk VTK::CommonMisc VTK::CommonSystem VTK::CommonSystem-private-kit-links VTK::pugixml VTK::CommonDataModel VTK::CommonExecutionModel VTK::doubleconversion VTK::lz4 VTK::lzma VTK::zlib VTK::IOCore VTK::IOLegacy VTK::expat VTK::IOXMLParser VTK::FiltersCore VTK::CommonColor VTK::CommonComputationalGeometry VTK::fmt VTK::FiltersGeneral VTK::FiltersGeometry VTK::FiltersSources VTK::RenderingCore VTK::DomainsChemistry VTK::ImagingCore VTK::ImagingSources VTK::FiltersHybrid VTK::FiltersHyperTree VTK::RenderingHyperTreeGrid VTK::opengl VTK::RenderingUI VTK::glew VTK::vtkTestOpenGLVersion VTK::RenderingOpenGL2 VTK::vtkProbeOpenGLVersion VTK::RenderingSceneGraph VTK::RenderingVolume VTK::DICOMParser VTK::jpeg VTK::metaio VTK::png VTK::tiff VTK::IOImage VTK::IOXML VTK::ImagingMath VTK::RenderingVolumeOpenGL2 VTK::ParallelCore VTK::FiltersAMR VTK::RenderingVolumeAMR VTK::jsoncpp VTK::RenderingRayTracing VTK::Python VTK::PythonUsed VTK::WrappingPythonCore VTK::PythonInterpreter VTK::IOPLY VTK::libxml2 VTK::IOEnSight VTK::nlohmannjson VTK::IOGeometry VTK::freetype VTK::RenderingFreeType VTK::RenderingContext2D VTK::FiltersModeling VTK::FiltersTexture VTK::ImagingColor VTK::ImagingGeneral VTK::ImagingHybrid VTK::eigen VTK::FiltersStatistics VTK::diy2 VTK::ParallelDIY VTK::FiltersExtraction VTK::InteractionStyle VTK::RenderingAnnotation VTK::InteractionWidgets VTK::GUISupportQt VTK::InfovisCore VTK::ViewsCore VTK::sqlite VTK::libproj VTK::InfovisLayout VTK::GeovisCore VTK::FiltersFlowPaths)
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

# Create imported target VTK::vtkbuild
add_library(VTK::vtkbuild INTERFACE IMPORTED)

# Create imported target VTK::WrappingTools
add_library(VTK::WrappingTools SHARED IMPORTED)

set_target_properties(VTK::WrappingTools PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
)

# Create imported target VTK::WrapHierarchy
add_executable(VTK::WrapHierarchy IMPORTED)

# Create imported target VTK::WrapPython
add_executable(VTK::WrapPython IMPORTED)

# Create imported target VTK::WrapPythonInit
add_executable(VTK::WrapPythonInit IMPORTED)

# Create imported target VTK::ParseJava
add_executable(VTK::ParseJava IMPORTED)

# Create imported target VTK::WrapJava
add_executable(VTK::WrapJava IMPORTED)

# Create imported target VTK::loguru
add_library(VTK::loguru SHARED IMPORTED)

set_target_properties(VTK::loguru PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::kwiml
add_library(VTK::kwiml INTERFACE IMPORTED)

set_target_properties(VTK::kwiml PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::vtksys
add_library(VTK::vtksys SHARED IMPORTED)

set_target_properties(VTK::vtksys PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_LINK_LIBRARIES "ws2_32;dbghelp;psapi"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::utf8
add_library(VTK::utf8 INTERFACE IMPORTED)

set_target_properties(VTK::utf8 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::CommonCore
add_library(VTK::CommonCore SHARED IMPORTED)

set_target_properties(VTK::CommonCore PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::kwiml;VTK::vtksys;Threads::Threads"
)

# Create imported target VTK::CommonCore-private-kit-links
add_library(VTK::CommonCore-private-kit-links INTERFACE IMPORTED)

set_target_properties(VTK::CommonCore-private-kit-links PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:\$<\$<PLATFORM_ID:SunOS>:socket>>;\$<LINK_ONLY:\$<\$<PLATFORM_ID:SunOS>:nsl>>;\$<LINK_ONLY:\$<\$<PLATFORM_ID:Android>:log>>"
)

# Create imported target VTK::kissfft
add_library(VTK::kissfft SHARED IMPORTED)

set_target_properties(VTK::kissfft PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "kiss_fft_scalar=double;KISSFFT_DLL_IMPORT=1"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::CommonMath
add_library(VTK::CommonMath SHARED IMPORTED)

set_target_properties(VTK::CommonMath PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::kissfft"
)

# Create imported target VTK::CommonTransforms
add_library(VTK::CommonTransforms SHARED IMPORTED)

set_target_properties(VTK::CommonTransforms PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonMath"
)

# Create imported target VTK::exprtk
add_library(VTK::exprtk INTERFACE IMPORTED)

set_target_properties(VTK::exprtk PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::CommonMisc
add_library(VTK::CommonMisc SHARED IMPORTED)

set_target_properties(VTK::CommonMisc PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonMath"
)

# Create imported target VTK::CommonSystem
add_library(VTK::CommonSystem SHARED IMPORTED)

set_target_properties(VTK::CommonSystem PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore"
)

# Create imported target VTK::CommonSystem-private-kit-links
add_library(VTK::CommonSystem-private-kit-links INTERFACE IMPORTED)

set_target_properties(VTK::CommonSystem-private-kit-links PROPERTIES
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:\$<\$<PLATFORM_ID:WIN32>:wsock32>>;\$<LINK_ONLY:Threads::Threads>"
)

# Create imported target VTK::pugixml
add_library(VTK::pugixml SHARED IMPORTED)

set_target_properties(VTK::pugixml PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::CommonDataModel
add_library(VTK::CommonDataModel SHARED IMPORTED)

set_target_properties(VTK::CommonDataModel PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonMath;VTK::CommonTransforms"
)

# Create imported target VTK::CommonExecutionModel
add_library(VTK::CommonExecutionModel SHARED IMPORTED)

set_target_properties(VTK::CommonExecutionModel PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel"
)

# Create imported target VTK::doubleconversion
add_library(VTK::doubleconversion SHARED IMPORTED)

set_target_properties(VTK::doubleconversion PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::lz4
add_library(VTK::lz4 SHARED IMPORTED)

set_target_properties(VTK::lz4 PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "LZ4_DLL_IMPORT=1"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::lzma
add_library(VTK::lzma SHARED IMPORTED)

set_target_properties(VTK::lzma PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::zlib
add_library(VTK::zlib SHARED IMPORTED)

set_target_properties(VTK::zlib PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::IOCore
add_library(VTK::IOCore SHARED IMPORTED)

set_target_properties(VTK::IOCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel"
)

# Create imported target VTK::IOLegacy
add_library(VTK::IOLegacy SHARED IMPORTED)

set_target_properties(VTK::IOLegacy PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::IOCore"
)

# Create imported target VTK::expat
add_library(VTK::expat SHARED IMPORTED)

set_target_properties(VTK::expat PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::IOXMLParser
add_library(VTK::IOXMLParser SHARED IMPORTED)

set_target_properties(VTK::IOXMLParser PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel"
)

# Create imported target VTK::FiltersCore
add_library(VTK::FiltersCore SHARED IMPORTED)

set_target_properties(VTK::FiltersCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMisc"
)

# Create imported target VTK::CommonColor
add_library(VTK::CommonColor SHARED IMPORTED)

set_target_properties(VTK::CommonColor PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel"
)

# Create imported target VTK::CommonComputationalGeometry
add_library(VTK::CommonComputationalGeometry SHARED IMPORTED)

set_target_properties(VTK::CommonComputationalGeometry PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel"
)

# Create imported target VTK::fmt
add_library(VTK::fmt SHARED IMPORTED)

set_target_properties(VTK::fmt PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "FMT_SHARED"
  INTERFACE_COMPILE_FEATURES "cxx_variadic_templates"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::FiltersGeneral
add_library(VTK::FiltersGeneral SHARED IMPORTED)

set_target_properties(VTK::FiltersGeneral PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMisc;VTK::FiltersCore"
)

# Create imported target VTK::FiltersGeometry
add_library(VTK::FiltersGeometry SHARED IMPORTED)

set_target_properties(VTK::FiltersGeometry PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel"
)

# Create imported target VTK::FiltersSources
add_library(VTK::FiltersSources SHARED IMPORTED)

set_target_properties(VTK::FiltersSources PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonDataModel;VTK::CommonExecutionModel"
)

# Create imported target VTK::RenderingCore
add_library(VTK::RenderingCore SHARED IMPORTED)

set_target_properties(VTK::RenderingCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath;VTK::FiltersCore"
)

# Create imported target VTK::DomainsChemistry
add_library(VTK::DomainsChemistry SHARED IMPORTED)

set_target_properties(VTK::DomainsChemistry PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::IOLegacy;VTK::IOXMLParser;VTK::RenderingCore"
)

# Create imported target VTK::ImagingCore
add_library(VTK::ImagingCore SHARED IMPORTED)

set_target_properties(VTK::ImagingCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel"
)

# Create imported target VTK::ImagingSources
add_library(VTK::ImagingSources SHARED IMPORTED)

set_target_properties(VTK::ImagingSources PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel"
)

# Create imported target VTK::FiltersHybrid
add_library(VTK::FiltersHybrid SHARED IMPORTED)

set_target_properties(VTK::FiltersHybrid PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonTransforms;VTK::FiltersGeometry"
)

# Create imported target VTK::FiltersHyperTree
add_library(VTK::FiltersHyperTree SHARED IMPORTED)

set_target_properties(VTK::FiltersHyperTree PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMisc;VTK::FiltersCore;VTK::FiltersGeneral"
)

# Create imported target VTK::RenderingHyperTreeGrid
add_library(VTK::RenderingHyperTreeGrid SHARED IMPORTED)

set_target_properties(VTK::RenderingHyperTreeGrid PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath;VTK::RenderingCore"
)

# Create imported target VTK::opengl
add_library(VTK::opengl INTERFACE IMPORTED)

set_target_properties(VTK::opengl PROPERTIES
  INTERFACE_LINK_LIBRARIES "OpenGL::GL"
)

# Create imported target VTK::RenderingUI
add_library(VTK::RenderingUI SHARED IMPORTED)

set_target_properties(VTK::RenderingUI PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::RenderingCore"
)

# Create imported target VTK::glew
add_library(VTK::glew SHARED IMPORTED)

set_target_properties(VTK::glew PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_LINK_LIBRARIES "VTK::opengl"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::vtkTestOpenGLVersion
add_executable(VTK::vtkTestOpenGLVersion IMPORTED)

# Create imported target VTK::RenderingOpenGL2
add_library(VTK::RenderingOpenGL2 SHARED IMPORTED)

set_target_properties(VTK::RenderingOpenGL2 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::FiltersGeneral;VTK::RenderingCore;VTK::RenderingHyperTreeGrid;VTK::RenderingUI;VTK::glew"
)

# Create imported target VTK::vtkProbeOpenGLVersion
add_executable(VTK::vtkProbeOpenGLVersion IMPORTED)

# Create imported target VTK::RenderingSceneGraph
add_library(VTK::RenderingSceneGraph SHARED IMPORTED)

set_target_properties(VTK::RenderingSceneGraph PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore"
)

# Create imported target VTK::RenderingVolume
add_library(VTK::RenderingVolume SHARED IMPORTED)

set_target_properties(VTK::RenderingVolume PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::RenderingCore"
)

# Create imported target VTK::DICOMParser
add_library(VTK::DICOMParser SHARED IMPORTED)

set_target_properties(VTK::DICOMParser PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
)

# Create imported target VTK::jpeg
add_library(VTK::jpeg SHARED IMPORTED)

set_target_properties(VTK::jpeg PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::metaio
add_library(VTK::metaio SHARED IMPORTED)

set_target_properties(VTK::metaio PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::png
add_library(VTK::png SHARED IMPORTED)

set_target_properties(VTK::png PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_LINK_LIBRARIES "VTK::zlib"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::tiff
add_library(VTK::tiff SHARED IMPORTED)

set_target_properties(VTK::tiff PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::IOImage
add_library(VTK::IOImage SHARED IMPORTED)

set_target_properties(VTK::IOImage PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::ImagingCore"
)

# Create imported target VTK::IOXML
add_library(VTK::IOXML SHARED IMPORTED)

set_target_properties(VTK::IOXML PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::IOXMLParser"
)

# Create imported target VTK::ImagingMath
add_library(VTK::ImagingMath SHARED IMPORTED)

set_target_properties(VTK::ImagingMath PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel"
)

# Create imported target VTK::RenderingVolumeOpenGL2
add_library(VTK::RenderingVolumeOpenGL2 SHARED IMPORTED)

set_target_properties(VTK::RenderingVolumeOpenGL2 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingCore;VTK::ImagingMath;VTK::RenderingCore;VTK::RenderingOpenGL2;VTK::RenderingVolume"
)

# Create imported target VTK::ParallelCore
add_library(VTK::ParallelCore SHARED IMPORTED)

set_target_properties(VTK::ParallelCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore"
)

# Create imported target VTK::FiltersAMR
add_library(VTK::FiltersAMR SHARED IMPORTED)

set_target_properties(VTK::FiltersAMR PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonDataModel;VTK::CommonExecutionModel"
)

# Create imported target VTK::RenderingVolumeAMR
add_library(VTK::RenderingVolumeAMR SHARED IMPORTED)

set_target_properties(VTK::RenderingVolumeAMR PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::ImagingCore;VTK::RenderingVolume;VTK::RenderingVolumeOpenGL2"
)

# Create imported target VTK::jsoncpp
add_library(VTK::jsoncpp SHARED IMPORTED)

set_target_properties(VTK::jsoncpp PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::RenderingRayTracing
add_library(VTK::RenderingRayTracing SHARED IMPORTED)

set_target_properties(VTK::RenderingRayTracing PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::DomainsChemistry;VTK::RenderingCore;VTK::RenderingOpenGL2;VTK::RenderingSceneGraph;VTK::RenderingVolume;ospray::ospray"
)

# Create imported target VTK::Python
add_library(VTK::Python INTERFACE IMPORTED)

set_target_properties(VTK::Python PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;Python3::Python"
)

# Create imported target VTK::PythonUsed
add_library(VTK::PythonUsed INTERFACE IMPORTED)

# Create imported target VTK::WrappingPythonCore
add_library(VTK::WrappingPythonCore SHARED IMPORTED)

set_target_properties(VTK::WrappingPythonCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::Python;VTK::vtksys"
)

# Create imported target VTK::PythonInterpreter
add_library(VTK::PythonInterpreter SHARED IMPORTED)

set_target_properties(VTK::PythonInterpreter PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::Python;VTK::vtksys"
)

# Create imported target VTK::IOPLY
add_library(VTK::IOPLY SHARED IMPORTED)

set_target_properties(VTK::IOPLY PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::IOCore"
)

# Create imported target VTK::libxml2
add_library(VTK::libxml2 SHARED IMPORTED)

set_target_properties(VTK::libxml2 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/vtklibxml2/include;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_LINK_LIBRARIES "VTK::zlib"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::IOEnSight
add_library(VTK::IOEnSight SHARED IMPORTED)

set_target_properties(VTK::IOEnSight PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel"
)

# Create imported target VTK::nlohmannjson
add_library(VTK::nlohmannjson INTERFACE IMPORTED)

set_target_properties(VTK::nlohmannjson PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/vtknlohmannjson/include;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::IOGeometry
add_library(VTK::IOGeometry SHARED IMPORTED)

set_target_properties(VTK::IOGeometry PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::IOCore;VTK::IOLegacy;VTK::nlohmannjson"
)

# Create imported target VTK::freetype
add_library(VTK::freetype SHARED IMPORTED)

set_target_properties(VTK::freetype PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/vtkfreetype/include;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_LINK_LIBRARIES "VTK::kwiml;VTK::zlib"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::RenderingFreeType
add_library(VTK::RenderingFreeType SHARED IMPORTED)

set_target_properties(VTK::RenderingFreeType PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::RenderingCore;VTK::freetype"
)

# Create imported target VTK::RenderingContext2D
add_library(VTK::RenderingContext2D SHARED IMPORTED)

set_target_properties(VTK::RenderingContext2D PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::RenderingCore"
)

# Create imported target VTK::FiltersModeling
add_library(VTK::FiltersModeling SHARED IMPORTED)

set_target_properties(VTK::FiltersModeling PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel;VTK::CommonMisc;VTK::FiltersGeneral"
)

# Create imported target VTK::FiltersTexture
add_library(VTK::FiltersTexture SHARED IMPORTED)

set_target_properties(VTK::FiltersTexture PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel"
)

# Create imported target VTK::ImagingColor
add_library(VTK::ImagingColor SHARED IMPORTED)

set_target_properties(VTK::ImagingColor PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel;VTK::ImagingCore"
)

# Create imported target VTK::ImagingGeneral
add_library(VTK::ImagingGeneral SHARED IMPORTED)

set_target_properties(VTK::ImagingGeneral PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonExecutionModel;VTK::ImagingCore"
)

# Create imported target VTK::ImagingHybrid
add_library(VTK::ImagingHybrid SHARED IMPORTED)

set_target_properties(VTK::ImagingHybrid PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel"
)

# Create imported target VTK::eigen
add_library(VTK::eigen INTERFACE IMPORTED)

set_target_properties(VTK::eigen PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::FiltersStatistics
add_library(VTK::FiltersStatistics SHARED IMPORTED)

set_target_properties(VTK::FiltersStatistics PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel"
)

# Create imported target VTK::diy2
add_library(VTK::diy2 INTERFACE IMPORTED)

set_target_properties(VTK::diy2 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::ParallelDIY
add_library(VTK::ParallelDIY SHARED IMPORTED)

set_target_properties(VTK::ParallelDIY PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "DIY_NO_THREADS"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonSystem;VTK::ParallelCore;VTK::diy2"
)

# Create imported target VTK::FiltersExtraction
add_library(VTK::FiltersExtraction SHARED IMPORTED)

set_target_properties(VTK::FiltersExtraction PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::FiltersGeneral"
)

# Create imported target VTK::InteractionStyle
add_library(VTK::InteractionStyle SHARED IMPORTED)

set_target_properties(VTK::InteractionStyle PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonDataModel;VTK::RenderingCore"
)

# Create imported target VTK::RenderingAnnotation
add_library(VTK::RenderingAnnotation SHARED IMPORTED)

set_target_properties(VTK::RenderingAnnotation PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::RenderingCore"
)

# Create imported target VTK::InteractionWidgets
add_library(VTK::InteractionWidgets SHARED IMPORTED)

set_target_properties(VTK::InteractionWidgets PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::FiltersGeneral;VTK::FiltersSources;VTK::RenderingCore;VTK::RenderingContext2D"
)

# Create imported target VTK::GUISupportQt
add_library(VTK::GUISupportQt SHARED IMPORTED)

set_target_properties(VTK::GUISupportQt PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::RenderingCore;VTK::RenderingOpenGL2;VTK::InteractionWidgets;Qt6::OpenGL;Qt6::Widgets;Qt6::OpenGLWidgets"
)

# Create imported target VTK::InfovisCore
add_library(VTK::InfovisCore SHARED IMPORTED)

set_target_properties(VTK::InfovisCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonColor;VTK::IOImage;VTK::ImagingCore;VTK::ImagingSources;VTK::RenderingFreeType"
)

# Create imported target VTK::ViewsCore
add_library(VTK::ViewsCore SHARED IMPORTED)

set_target_properties(VTK::ViewsCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonExecutionModel;VTK::InteractionWidgets"
)

# Create imported target VTK::sqlite
add_library(VTK::sqlite SHARED IMPORTED)

set_target_properties(VTK::sqlite PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::libproj
add_library(VTK::libproj SHARED IMPORTED)

set_target_properties(VTK::libproj PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2;${_IMPORT_PREFIX}/include/vtk-9.2/vtklibproj/src;${_IMPORT_PREFIX}/include/vtk-9.2/"
  INTERFACE_LINK_LIBRARIES "VTK::nlohmannjson"
  INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "include/vtk-9.2/"
)

# Create imported target VTK::InfovisLayout
add_library(VTK::InfovisLayout SHARED IMPORTED)

set_target_properties(VTK::InfovisLayout PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel"
)

# Create imported target VTK::GeovisCore
add_library(VTK::GeovisCore SHARED IMPORTED)

set_target_properties(VTK::GeovisCore PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonTransforms;VTK::InfovisCore;VTK::InteractionStyle;VTK::InteractionWidgets;VTK::RenderingCore;VTK::ViewsCore;VTK::libproj"
)

# Create imported target VTK::FiltersFlowPaths
add_library(VTK::FiltersFlowPaths SHARED IMPORTED)

set_target_properties(VTK::FiltersFlowPaths PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/vtk-9.2"
  INTERFACE_LINK_LIBRARIES "VTK::CommonCore;VTK::CommonComputationalGeometry;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath"
)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/VTK-targets-*.cmake")
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
