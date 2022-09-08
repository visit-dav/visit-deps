#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VTK::WrappingTools" for configuration "Release"
set_property(TARGET VTK::WrappingTools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrappingTools PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkWrappingTools-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrappingTools-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrappingTools )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrappingTools "${_IMPORT_PREFIX}/lib/vtkWrappingTools-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkWrappingTools-9.1.dll" )

# Import target "VTK::WrapHierarchy" for configuration "Release"
set_property(TARGET VTK::WrapHierarchy APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapHierarchy PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapHierarchy-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapHierarchy )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapHierarchy "${_IMPORT_PREFIX}/bin/vtkWrapHierarchy-9.1.exe" )

# Import target "VTK::WrapPython" for configuration "Release"
set_property(TARGET VTK::WrapPython APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapPython PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapPython-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapPython )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapPython "${_IMPORT_PREFIX}/bin/vtkWrapPython-9.1.exe" )

# Import target "VTK::WrapPythonInit" for configuration "Release"
set_property(TARGET VTK::WrapPythonInit APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapPythonInit PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapPythonInit-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapPythonInit )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapPythonInit "${_IMPORT_PREFIX}/bin/vtkWrapPythonInit-9.1.exe" )

# Import target "VTK::ParseJava" for configuration "Release"
set_property(TARGET VTK::ParseJava APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ParseJava PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkParseJava-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ParseJava )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ParseJava "${_IMPORT_PREFIX}/bin/vtkParseJava-9.1.exe" )

# Import target "VTK::WrapJava" for configuration "Release"
set_property(TARGET VTK::WrapJava APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapJava PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapJava-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapJava )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapJava "${_IMPORT_PREFIX}/bin/vtkWrapJava-9.1.exe" )

# Import target "VTK::loguru" for configuration "Release"
set_property(TARGET VTK::loguru APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::loguru PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkloguru-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkloguru-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::loguru )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::loguru "${_IMPORT_PREFIX}/lib/vtkloguru-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkloguru-9.1.dll" )

# Import target "VTK::vtksys" for configuration "Release"
set_property(TARGET VTK::vtksys APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtksys PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtksys-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtksys-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtksys )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtksys "${_IMPORT_PREFIX}/lib/vtksys-9.1.lib" "${_IMPORT_PREFIX}/bin/vtksys-9.1.dll" )

# Import target "VTK::CommonCore" for configuration "Release"
set_property(TARGET VTK::CommonCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::loguru"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonCore "${_IMPORT_PREFIX}/lib/vtkCommonCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonCore-9.1.dll" )

# Import target "VTK::kissfft" for configuration "Release"
set_property(TARGET VTK::kissfft APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::kissfft PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkkissfft-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkkissfft-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::kissfft )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::kissfft "${_IMPORT_PREFIX}/lib/vtkkissfft-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkkissfft-9.1.dll" )

# Import target "VTK::CommonMath" for configuration "Release"
set_property(TARGET VTK::CommonMath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonMath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonMath-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonMath-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonMath "${_IMPORT_PREFIX}/lib/vtkCommonMath-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonMath-9.1.dll" )

# Import target "VTK::CommonTransforms" for configuration "Release"
set_property(TARGET VTK::CommonTransforms APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonTransforms PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonTransforms-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonTransforms-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonTransforms )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonTransforms "${_IMPORT_PREFIX}/lib/vtkCommonTransforms-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonTransforms-9.1.dll" )

# Import target "VTK::CommonMisc" for configuration "Release"
set_property(TARGET VTK::CommonMisc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonMisc PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonMisc-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonMisc-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonMisc )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonMisc "${_IMPORT_PREFIX}/lib/vtkCommonMisc-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonMisc-9.1.dll" )

# Import target "VTK::CommonSystem" for configuration "Release"
set_property(TARGET VTK::CommonSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonSystem PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonSystem-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonSystem-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonSystem "${_IMPORT_PREFIX}/lib/vtkCommonSystem-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonSystem-9.1.dll" )

# Import target "VTK::pugixml" for configuration "Release"
set_property(TARGET VTK::pugixml APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::pugixml PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkpugixml-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkpugixml-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::pugixml )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::pugixml "${_IMPORT_PREFIX}/lib/vtkpugixml-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkpugixml-9.1.dll" )

# Import target "VTK::CommonDataModel" for configuration "Release"
set_property(TARGET VTK::CommonDataModel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonDataModel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonDataModel-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem;VTK::pugixml;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonDataModel-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonDataModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonDataModel "${_IMPORT_PREFIX}/lib/vtkCommonDataModel-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonDataModel-9.1.dll" )

# Import target "VTK::CommonExecutionModel" for configuration "Release"
set_property(TARGET VTK::CommonExecutionModel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonExecutionModel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonExecutionModel-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonExecutionModel-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonExecutionModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonExecutionModel "${_IMPORT_PREFIX}/lib/vtkCommonExecutionModel-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonExecutionModel-9.1.dll" )

# Import target "VTK::doubleconversion" for configuration "Release"
set_property(TARGET VTK::doubleconversion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::doubleconversion PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkdoubleconversion-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkdoubleconversion-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::doubleconversion )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::doubleconversion "${_IMPORT_PREFIX}/lib/vtkdoubleconversion-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkdoubleconversion-9.1.dll" )

# Import target "VTK::lz4" for configuration "Release"
set_property(TARGET VTK::lz4 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::lz4 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklz4-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklz4-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::lz4 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::lz4 "${_IMPORT_PREFIX}/lib/vtklz4-9.1.lib" "${_IMPORT_PREFIX}/bin/vtklz4-9.1.dll" )

# Import target "VTK::lzma" for configuration "Release"
set_property(TARGET VTK::lzma APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::lzma PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklzma-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklzma-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::lzma )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::lzma "${_IMPORT_PREFIX}/lib/vtklzma-9.1.lib" "${_IMPORT_PREFIX}/bin/vtklzma-9.1.dll" )

# Import target "VTK::IOCore" for configuration "Release"
set_property(TARGET VTK::IOCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::doubleconversion;VTK::lz4;VTK::lzma;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOCore "${_IMPORT_PREFIX}/lib/vtkIOCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOCore-9.1.dll" )

# Import target "VTK::IOLegacy" for configuration "Release"
set_property(TARGET VTK::IOLegacy APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOLegacy PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOLegacy-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOLegacy-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOLegacy )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOLegacy "${_IMPORT_PREFIX}/lib/vtkIOLegacy-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOLegacy-9.1.dll" )

# Import target "VTK::expat" for configuration "Release"
set_property(TARGET VTK::expat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::expat PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkexpat-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkexpat-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::expat )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::expat "${_IMPORT_PREFIX}/lib/vtkexpat-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkexpat-9.1.dll" )

# Import target "VTK::IOXMLParser" for configuration "Release"
set_property(TARGET VTK::IOXMLParser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOXMLParser PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOXMLParser-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::IOCore;VTK::expat;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOXMLParser-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOXMLParser )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOXMLParser "${_IMPORT_PREFIX}/lib/vtkIOXMLParser-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOXMLParser-9.1.dll" )

# Import target "VTK::FiltersCore" for configuration "Release"
set_property(TARGET VTK::FiltersCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersCore "${_IMPORT_PREFIX}/lib/vtkFiltersCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersCore-9.1.dll" )

# Import target "VTK::CommonColor" for configuration "Release"
set_property(TARGET VTK::CommonColor APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonColor PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonColor-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonColor-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonColor )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonColor "${_IMPORT_PREFIX}/lib/vtkCommonColor-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonColor-9.1.dll" )

# Import target "VTK::CommonComputationalGeometry" for configuration "Release"
set_property(TARGET VTK::CommonComputationalGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonComputationalGeometry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonComputationalGeometry-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonComputationalGeometry-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonComputationalGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonComputationalGeometry "${_IMPORT_PREFIX}/lib/vtkCommonComputationalGeometry-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkCommonComputationalGeometry-9.1.dll" )

# Import target "VTK::fmt" for configuration "Release"
set_property(TARGET VTK::fmt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::fmt PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkfmt-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkfmt-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::fmt )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::fmt "${_IMPORT_PREFIX}/lib/vtkfmt-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkfmt-9.1.dll" )

# Import target "VTK::FiltersGeneral" for configuration "Release"
set_property(TARGET VTK::FiltersGeneral APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersGeneral PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersGeneral-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::fmt"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersGeneral-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersGeneral )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersGeneral "${_IMPORT_PREFIX}/lib/vtkFiltersGeneral-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeneral-9.1.dll" )

# Import target "VTK::FiltersGeometry" for configuration "Release"
set_property(TARGET VTK::FiltersGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersGeometry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersGeometry-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersGeometry-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersGeometry "${_IMPORT_PREFIX}/lib/vtkFiltersGeometry-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeometry-9.1.dll" )

# Import target "VTK::FiltersSources" for configuration "Release"
set_property(TARGET VTK::FiltersSources APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersSources PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersSources-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonCore;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersSources-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersSources )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersSources "${_IMPORT_PREFIX}/lib/vtkFiltersSources-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSources-9.1.dll" )

# Import target "VTK::RenderingCore" for configuration "Release"
set_property(TARGET VTK::RenderingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonColor;VTK::CommonComputationalGeometry;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral;VTK::FiltersGeometry;VTK::FiltersSources;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingCore "${_IMPORT_PREFIX}/lib/vtkRenderingCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingCore-9.1.dll" )

# Import target "VTK::DomainsChemistry" for configuration "Release"
set_property(TARGET VTK::DomainsChemistry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::DomainsChemistry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkDomainsChemistry-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersSources;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkDomainsChemistry-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::DomainsChemistry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::DomainsChemistry "${_IMPORT_PREFIX}/lib/vtkDomainsChemistry-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkDomainsChemistry-9.1.dll" )

# Import target "VTK::RenderingUI" for configuration "Release"
set_property(TARGET VTK::RenderingUI APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingUI PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingUI-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingUI-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingUI )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingUI "${_IMPORT_PREFIX}/lib/vtkRenderingUI-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingUI-9.1.dll" )

# Import target "VTK::glew" for configuration "Release"
set_property(TARGET VTK::glew APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::glew PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkglew-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkglew-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::glew )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::glew "${_IMPORT_PREFIX}/lib/vtkglew-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkglew-9.1.dll" )

# Import target "VTK::vtkTestOpenGLVersion" for configuration "Release"
set_property(TARGET VTK::vtkTestOpenGLVersion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtkTestOpenGLVersion PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkTestOpenGLVersion-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtkTestOpenGLVersion )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtkTestOpenGLVersion "${_IMPORT_PREFIX}/bin/vtkTestOpenGLVersion-9.1.exe" )

# Import target "VTK::RenderingOpenGL2" for configuration "Release"
set_property(TARGET VTK::RenderingOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingOpenGL2-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonExecutionModel;VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingOpenGL2-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingOpenGL2-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingOpenGL2-9.1.dll" )

# Import target "VTK::vtkProbeOpenGLVersion" for configuration "Release"
set_property(TARGET VTK::vtkProbeOpenGLVersion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtkProbeOpenGLVersion PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkProbeOpenGLVersion-9.1.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtkProbeOpenGLVersion )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtkProbeOpenGLVersion "${_IMPORT_PREFIX}/bin/vtkProbeOpenGLVersion-9.1.exe" )

# Import target "VTK::RenderingSceneGraph" for configuration "Release"
set_property(TARGET VTK::RenderingSceneGraph APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingSceneGraph PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingSceneGraph-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::RenderingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingSceneGraph-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingSceneGraph )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingSceneGraph "${_IMPORT_PREFIX}/lib/vtkRenderingSceneGraph-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingSceneGraph-9.1.dll" )

# Import target "VTK::ImagingCore" for configuration "Release"
set_property(TARGET VTK::ImagingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonTransforms"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingCore "${_IMPORT_PREFIX}/lib/vtkImagingCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkImagingCore-9.1.dll" )

# Import target "VTK::RenderingVolume" for configuration "Release"
set_property(TARGET VTK::RenderingVolume APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingVolume PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingVolume-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingVolume-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingVolume )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingVolume "${_IMPORT_PREFIX}/lib/vtkRenderingVolume-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolume-9.1.dll" )

# Import target "VTK::DICOMParser" for configuration "Release"
set_property(TARGET VTK::DICOMParser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::DICOMParser PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkDICOMParser-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkDICOMParser-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::DICOMParser )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::DICOMParser "${_IMPORT_PREFIX}/lib/vtkDICOMParser-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkDICOMParser-9.1.dll" )

# Import target "VTK::metaio" for configuration "Release"
set_property(TARGET VTK::metaio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::metaio PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkmetaio-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkmetaio-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::metaio )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::metaio "${_IMPORT_PREFIX}/lib/vtkmetaio-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkmetaio-9.1.dll" )

# Import target "VTK::png" for configuration "Release"
set_property(TARGET VTK::png APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::png PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkpng-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkpng-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::png )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::png "${_IMPORT_PREFIX}/lib/vtkpng-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkpng-9.1.dll" )

# Import target "VTK::tiff" for configuration "Release"
set_property(TARGET VTK::tiff APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::tiff PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtktiff-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtktiff-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::tiff )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::tiff "${_IMPORT_PREFIX}/lib/vtktiff-9.1.lib" "${_IMPORT_PREFIX}/bin/vtktiff-9.1.dll" )

# Import target "VTK::IOImage" for configuration "Release"
set_property(TARGET VTK::IOImage APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOImage PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOImage-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::DICOMParser;VTK::metaio;VTK::png;VTK::pugixml;VTK::tiff;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOImage-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOImage "${_IMPORT_PREFIX}/lib/vtkIOImage-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOImage-9.1.dll" )

# Import target "VTK::IOXML" for configuration "Release"
set_property(TARGET VTK::IOXML APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOXML PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOXML-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::CommonSystem;VTK::IOCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOXML-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOXML )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOXML "${_IMPORT_PREFIX}/lib/vtkIOXML-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOXML-9.1.dll" )

# Import target "VTK::ImagingMath" for configuration "Release"
set_property(TARGET VTK::ImagingMath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingMath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingMath-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingMath-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingMath "${_IMPORT_PREFIX}/lib/vtkImagingMath-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkImagingMath-9.1.dll" )

# Import target "VTK::RenderingVolumeOpenGL2" for configuration "Release"
set_property(TARGET VTK::RenderingVolumeOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingVolumeOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeOpenGL2-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersSources;VTK::glew;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeOpenGL2-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingVolumeOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingVolumeOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeOpenGL2-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeOpenGL2-9.1.dll" )

# Import target "VTK::ParallelCore" for configuration "Release"
set_property(TARGET VTK::ParallelCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ParallelCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkParallelCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonSystem;VTK::IOLegacy;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkParallelCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ParallelCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ParallelCore "${_IMPORT_PREFIX}/lib/vtkParallelCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkParallelCore-9.1.dll" )

# Import target "VTK::FiltersAMR" for configuration "Release"
set_property(TARGET VTK::FiltersAMR APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersAMR PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersAMR-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonMath;VTK::CommonSystem;VTK::FiltersCore;VTK::IOXML;VTK::ParallelCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersAMR-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersAMR )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersAMR "${_IMPORT_PREFIX}/lib/vtkFiltersAMR-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersAMR-9.1.dll" )

# Import target "VTK::RenderingVolumeAMR" for configuration "Release"
set_property(TARGET VTK::RenderingVolumeAMR APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingVolumeAMR PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeAMR-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath;VTK::CommonSystem;VTK::FiltersAMR;VTK::RenderingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeAMR-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingVolumeAMR )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingVolumeAMR "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeAMR-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeAMR-9.1.dll" )

# Import target "VTK::jsoncpp" for configuration "Release"
set_property(TARGET VTK::jsoncpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::jsoncpp PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkjsoncpp-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkjsoncpp-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::jsoncpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::jsoncpp "${_IMPORT_PREFIX}/lib/vtkjsoncpp-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkjsoncpp-9.1.dll" )

# Import target "VTK::RenderingRayTracing" for configuration "Release"
set_property(TARGET VTK::RenderingRayTracing APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingRayTracing PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingRayTracing-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::IOImage;VTK::IOLegacy;VTK::IOXML;VTK::ImagingCore;VTK::RenderingVolumeAMR;VTK::jsoncpp;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingRayTracing-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingRayTracing )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingRayTracing "${_IMPORT_PREFIX}/lib/vtkRenderingRayTracing-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingRayTracing-9.1.dll" )

# Import target "VTK::WrappingPythonCore" for configuration "Release"
set_property(TARGET VTK::WrappingPythonCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrappingPythonCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkWrappingPythonCore3.7-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrappingPythonCore3.7-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrappingPythonCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrappingPythonCore "${_IMPORT_PREFIX}/lib/vtkWrappingPythonCore3.7-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkWrappingPythonCore3.7-9.1.dll" )

# Import target "VTK::PythonInterpreter" for configuration "Release"
set_property(TARGET VTK::PythonInterpreter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::PythonInterpreter PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkPythonInterpreter-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::WrappingPythonCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkPythonInterpreter-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::PythonInterpreter )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::PythonInterpreter "${_IMPORT_PREFIX}/lib/vtkPythonInterpreter-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkPythonInterpreter-9.1.dll" )

# Import target "VTK::IOPLY" for configuration "Release"
set_property(TARGET VTK::IOPLY APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOPLY PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOPLY-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOPLY-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOPLY )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOPLY "${_IMPORT_PREFIX}/lib/vtkIOPLY-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOPLY-9.1.dll" )

# Import target "VTK::libxml2" for configuration "Release"
set_property(TARGET VTK::libxml2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::libxml2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklibxml2-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklibxml2-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::libxml2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::libxml2 "${_IMPORT_PREFIX}/lib/vtklibxml2-9.1.lib" "${_IMPORT_PREFIX}/bin/vtklibxml2-9.1.dll" )

# Import target "VTK::ImagingSources" for configuration "Release"
set_property(TARGET VTK::ImagingSources APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingSources PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingSources-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingSources-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingSources )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingSources "${_IMPORT_PREFIX}/lib/vtkImagingSources-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkImagingSources-9.1.dll" )

# Import target "VTK::FiltersHybrid" for configuration "Release"
set_property(TARGET VTK::FiltersHybrid APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersHybrid PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersHybrid-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonMisc;VTK::FiltersCore;VTK::FiltersGeneral;VTK::ImagingCore;VTK::ImagingSources;VTK::RenderingCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersHybrid-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersHybrid )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersHybrid "${_IMPORT_PREFIX}/lib/vtkFiltersHybrid-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersHybrid-9.1.dll" )

# Import target "VTK::IOGeometry" for configuration "Release"
set_property(TARGET VTK::IOGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOGeometry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOGeometry-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral;VTK::FiltersHybrid;VTK::ImagingCore;VTK::IOImage;VTK::RenderingCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOGeometry-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOGeometry "${_IMPORT_PREFIX}/lib/vtkIOGeometry-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOGeometry-9.1.dll" )

# Import target "VTK::IOEnSight" for configuration "Release"
set_property(TARGET VTK::IOEnSight APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOEnSight PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOEnSight-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOEnSight-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOEnSight )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOEnSight "${_IMPORT_PREFIX}/lib/vtkIOEnSight-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkIOEnSight-9.1.dll" )

# Import target "VTK::freetype" for configuration "Release"
set_property(TARGET VTK::freetype APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::freetype PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkfreetype-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkfreetype-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::freetype )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::freetype "${_IMPORT_PREFIX}/lib/vtkfreetype-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkfreetype-9.1.dll" )

# Import target "VTK::RenderingFreeType" for configuration "Release"
set_property(TARGET VTK::RenderingFreeType APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingFreeType PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingFreeType-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingFreeType-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingFreeType )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingFreeType "${_IMPORT_PREFIX}/lib/vtkRenderingFreeType-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingFreeType-9.1.dll" )

# Import target "VTK::RenderingContext2D" for configuration "Release"
set_property(TARGET VTK::RenderingContext2D APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingContext2D PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingContext2D-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral;VTK::RenderingFreeType"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingContext2D-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingContext2D )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingContext2D "${_IMPORT_PREFIX}/lib/vtkRenderingContext2D-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingContext2D-9.1.dll" )

# Import target "VTK::FiltersModeling" for configuration "Release"
set_property(TARGET VTK::FiltersModeling APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersModeling PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersModeling-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersModeling-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersModeling )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersModeling "${_IMPORT_PREFIX}/lib/vtkFiltersModeling-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersModeling-9.1.dll" )

# Import target "VTK::FiltersTexture" for configuration "Release"
set_property(TARGET VTK::FiltersTexture APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersTexture PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersTexture-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonTransforms;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersTexture-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersTexture )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersTexture "${_IMPORT_PREFIX}/lib/vtkFiltersTexture-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersTexture-9.1.dll" )

# Import target "VTK::ImagingColor" for configuration "Release"
set_property(TARGET VTK::ImagingColor APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingColor PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingColor-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingColor-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingColor )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingColor "${_IMPORT_PREFIX}/lib/vtkImagingColor-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkImagingColor-9.1.dll" )

# Import target "VTK::ImagingGeneral" for configuration "Release"
set_property(TARGET VTK::ImagingGeneral APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingGeneral PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingGeneral-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingGeneral-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingGeneral )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingGeneral "${_IMPORT_PREFIX}/lib/vtkImagingGeneral-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkImagingGeneral-9.1.dll" )

# Import target "VTK::ImagingHybrid" for configuration "Release"
set_property(TARGET VTK::ImagingHybrid APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingHybrid PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingHybrid-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::IOImage;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingHybrid-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingHybrid )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingHybrid "${_IMPORT_PREFIX}/lib/vtkImagingHybrid-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkImagingHybrid-9.1.dll" )

# Import target "VTK::FiltersStatistics" for configuration "Release"
set_property(TARGET VTK::FiltersStatistics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersStatistics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersStatistics-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersStatistics-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersStatistics )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersStatistics "${_IMPORT_PREFIX}/lib/vtkFiltersStatistics-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersStatistics-9.1.dll" )

# Import target "VTK::ParallelDIY" for configuration "Release"
set_property(TARGET VTK::ParallelDIY APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ParallelDIY PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkParallelDIY-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersGeneral;VTK::FiltersGeometry;VTK::IOXML"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkParallelDIY-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ParallelDIY )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ParallelDIY "${_IMPORT_PREFIX}/lib/vtkParallelDIY-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkParallelDIY-9.1.dll" )

# Import target "VTK::FiltersExtraction" for configuration "Release"
set_property(TARGET VTK::FiltersExtraction APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersExtraction PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersExtraction-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersCore;VTK::FiltersStatistics;VTK::ParallelDIY"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersExtraction-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersExtraction )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersExtraction "${_IMPORT_PREFIX}/lib/vtkFiltersExtraction-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersExtraction-9.1.dll" )

# Import target "VTK::InteractionStyle" for configuration "Release"
set_property(TARGET VTK::InteractionStyle APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InteractionStyle PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInteractionStyle-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonMath;VTK::CommonTransforms;VTK::FiltersExtraction;VTK::FiltersSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInteractionStyle-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InteractionStyle )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InteractionStyle "${_IMPORT_PREFIX}/lib/vtkInteractionStyle-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionStyle-9.1.dll" )

# Import target "VTK::RenderingAnnotation" for configuration "Release"
set_property(TARGET VTK::RenderingAnnotation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingAnnotation PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingAnnotation-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersSources;VTK::ImagingColor;VTK::RenderingFreeType"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingAnnotation-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingAnnotation )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingAnnotation "${_IMPORT_PREFIX}/lib/vtkRenderingAnnotation-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingAnnotation-9.1.dll" )

# Import target "VTK::InteractionWidgets" for configuration "Release"
set_property(TARGET VTK::InteractionWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InteractionWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInteractionWidgets-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonDataModel;VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersHybrid;VTK::FiltersModeling;VTK::FiltersTexture;VTK::ImagingColor;VTK::ImagingCore;VTK::ImagingGeneral;VTK::ImagingHybrid;VTK::InteractionStyle;VTK::RenderingAnnotation;VTK::RenderingFreeType;VTK::RenderingVolume"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInteractionWidgets-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InteractionWidgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InteractionWidgets "${_IMPORT_PREFIX}/lib/vtkInteractionWidgets-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionWidgets-9.1.dll" )

# Import target "VTK::GUISupportQt" for configuration "Release"
set_property(TARGET VTK::GUISupportQt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::GUISupportQt PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkGUISupportQt-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonSystem;VTK::FiltersExtraction;VTK::InteractionStyle"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkGUISupportQt-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::GUISupportQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::GUISupportQt "${_IMPORT_PREFIX}/lib/vtkGUISupportQt-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkGUISupportQt-9.1.dll" )

# Import target "VTK::InfovisCore" for configuration "Release"
set_property(TARGET VTK::InfovisCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InfovisCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInfovisCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersExtraction;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInfovisCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InfovisCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InfovisCore "${_IMPORT_PREFIX}/lib/vtkInfovisCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkInfovisCore-9.1.dll" )

# Import target "VTK::ViewsCore" for configuration "Release"
set_property(TARGET VTK::ViewsCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ViewsCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkViewsCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersGeneral;VTK::RenderingCore;VTK::RenderingUI"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkViewsCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ViewsCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ViewsCore "${_IMPORT_PREFIX}/lib/vtkViewsCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkViewsCore-9.1.dll" )

# Import target "VTK::libproj" for configuration "Release"
set_property(TARGET VTK::libproj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::libproj PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklibproj-9.1.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklibproj-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::libproj )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::libproj "${_IMPORT_PREFIX}/lib/vtklibproj-9.1.lib" "${_IMPORT_PREFIX}/bin/vtklibproj-9.1.dll" )

# Import target "VTK::InfovisLayout" for configuration "Release"
set_property(TARGET VTK::InfovisLayout APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InfovisLayout PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInfovisLayout-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersModeling;VTK::FiltersSources;VTK::ImagingHybrid;VTK::InfovisCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInfovisLayout-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InfovisLayout )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InfovisLayout "${_IMPORT_PREFIX}/lib/vtkInfovisLayout-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkInfovisLayout-9.1.dll" )

# Import target "VTK::GeovisCore" for configuration "Release"
set_property(TARGET VTK::GeovisCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::GeovisCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkGeovisCore-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonSystem;VTK::FiltersCore;VTK::FiltersGeneral;VTK::IOImage;VTK::IOXML;VTK::ImagingCore;VTK::ImagingSources;VTK::InfovisLayout"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkGeovisCore-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::GeovisCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::GeovisCore "${_IMPORT_PREFIX}/lib/vtkGeovisCore-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkGeovisCore-9.1.dll" )

# Import target "VTK::FiltersFlowPaths" for configuration "Release"
set_property(TARGET VTK::FiltersFlowPaths APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersFlowPaths PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersFlowPaths-9.1.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersGeometry;VTK::FiltersModeling;VTK::FiltersSources;VTK::IOCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersFlowPaths-9.1.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersFlowPaths )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersFlowPaths "${_IMPORT_PREFIX}/lib/vtkFiltersFlowPaths-9.1.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersFlowPaths-9.1.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
