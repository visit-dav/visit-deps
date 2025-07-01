#[==[.md
# vtk-config.cmake

This file is used by CMake when finding VTK. It provides the [VTK module
API][] as well as some VTK-specific APIs.

The following variables are provided by this module:

  * `VTK_VERSION`: The version of VTK found.
  * `VTK_MAJOR_VERSION`: The major version of VTK found.
  * `VTK_MINOR_VERSION`: The minor version of VTK found.
  * `VTK_BUILD_VERSION`: The build version of VTK found.
  * `VTK_AVAILABLE_COMPONENTS`: Components available with VTK.
  * `VTK_PREFIX_PATH`: Install prefix for VTK.
  * `VTK_LEGACY_REMOVE`: Whether VTK's deprecated APIs are
    compiled out or not.
  * `VTK_HAS_VTKm: [Deprecated, use VTK_HAS_VISKORES] If VTK provides VTK-m.
  * `VTK_HAS_VISKORES`: If VTK provides Viskores.
  * `VTK_OPENGL_HAS_EGL`: If VTK can use EGL for OpenGL context.
  * `VTK_USE_X`: If VTK uses X windows.
  * `VTK_PYTHON_VERSION`: The major version of Python used by VTK. Empty if
    Python support is not available.
  * `VTK_WRAP_PYTHON`: If VTK itself provides Python wrapping. If so, the
    Python parts of the module API are available.
  * `VTK_WRAP_JAVA`: If VTK itself provides Java wrapping. If so, the
    Java parts of the module API are available.
  * `VTK_WRAP_SERIALIZATION`: If VTK itself provides serialization wrappings
    for marshallable classes in modules with `INCLUDE_MARSHAL`.
  * `VTK_PYTHONPATH`: Where VTK's Python modules live inside the install
    prefix. Unset if Python is not available.
  * `VTK_LIBRARIES`: The list of modules specified by `COMPONENTS` and
    `OPTIONAL_COMPONENTS`. However, if no components are specified, all
    available components are added to this variable. This may be used in
    `MODULES` arguments in the API (e.g., `vtk_module_autoinit`). All modules
    are also targets and may be linked to using `target_link_libraries`.
  * `VTK_AUTOINIT_INCLUDE`: The header to include for access to VTK's autoinit
    support.
  * `VTK_QT_VERSION`: The major version of Qt used by VTK if Qt support enabled.
  * `VTK_QML_DIR`: Where VTK's QML plugins live if QML support is enabled.
  * `VTK_ENABLE_VR_COLLABORATION`: Is VR collaboration enabled when VR is enabled.
  * `VTK_SMP_BACKENDS`: The list of available SMP backends.

For more information about the Python in use by VTK, (note that the `Python`
component must be found to guarantee that this happens), see the
[FindPython3][] documentation for what is available. Of particular use are
likely to be:

  - the `Python3_VERSION` variable; and
  - the `Python3::Python` target.

[FindPython3]: https://cmake.org/cmake/help/v3.13/module/FindPython3.html
[VTK module API]: TODO: Link to hosted documentation.
#]==]

if (CMAKE_VERSION VERSION_LESS "3.12")
  set("${CMAKE_FIND_PACKAGE_NAME}_FOUND" 0)
  set("${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE"
    "VTK requires CMake 3.12 in order to reliably be used.")
  return ()
endif ()

cmake_policy(PUSH)
cmake_policy(VERSION 3.12)

set("${CMAKE_FIND_PACKAGE_NAME}_AVAILABLE_COMPONENTS" "WrappingTools;PythonInterpreter;Python;vtksys;CommonMisc;loguru;RenderingRayTracing;DomainsChemistry;RenderingCore;RenderingSceneGraph;RenderingVolume;IOImage;ImagingCore;RenderingVolumeAMR;jsoncpp;CommonExecutionModel;CommonMath;CommonSystem;FiltersAMR;RenderingAnari;RenderingVolumeOpenGL2;ImagingMath;CommonTransforms;FiltersCore;FiltersGeneral;FiltersSources;glad;IOPLY;IOCore;libxml2;zlib;IOEnSight;FiltersTemporal;fmt;ParallelCore;IOGeometry;nlohmannjson;FiltersVerdict;GUISupportQt;InteractionWidgets;FiltersExtraction;RenderingContext2D;CommonComputationalGeometry;ImagingColor;ImagingGeneral;ImagingHybrid;RenderingAnnotation;InteractionStyle;GeovisCore;libproj;sqlite;ImagingSources;FiltersFlowPaths;eigen;FiltersTexture;FiltersModeling;RenderingOpenGL2;RenderingHyperTreeGrid;RenderingUI;CommonColor;FiltersHyperTree;FiltersHybrid;IOXMLParser;WrappingPythonCore;FiltersStatistics;ParallelDIY;diy2;IOXML;expat;IOLegacy;IOCellGrid;FiltersCellGrid;token;lz4;lzma;utf8;fast_float;DICOMParser;jpeg;metaio;png;pugixml;tiff;RenderingFreeType;freetype;kwiml;verdict;FiltersGeometry;FiltersReduction;CommonDataModel;pegtl;exprtk;kissfft;CommonCore;doubleconversion;WrapHierarchy;vtkbuild;vtkpython;WrapPython;WrapPythonInit;ParseJava;WrapJava")

set(_vtk_temp_variables)
set(_vtk_real_components)
foreach (_vtk_component IN LISTS "${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS")
  # Handle component requests that are not VTK.
  if (NOT _vtk_component IN_LIST "${CMAKE_FIND_PACKAGE_NAME}_AVAILABLE_COMPONENTS")
    set("${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_NOT_FOUND_MESSAGE"
      "The ${_vtk_component} component is not recognized.")
  endif ()
  if (_vtk_component MATCHES "^vtk" AND
      NOT _vtk_component STREQUAL "vtksys" AND
      NOT _vtk_component STREQUAL "vtkjava")
    string(SUBSTRING "${_vtk_component}" 3 -1 _vtk_actual_component)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_VERSION)
      if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
        message(DEPRECATION
          "The new name for the '${_vtk_component}' component is "
          "'${_vtk_actual_component}'")
      endif ()
    elseif (${CMAKE_FIND_PACKAGE_NAME}_FIND_VERSION VERSION_LESS "8.90")
      # Ignore for compatibility.
    else ()
      message(FATAL_ERROR
        "The new name for the '${_vtk_component}' component is "
        "'${_vtk_actual_component}'. By requesting at least version 8.90, the "
        "new component names are now required.")
    endif ()
    list(APPEND _vtk_real_components
      "${_vtk_actual_component}")
    list(APPEND _vtk_temp_variables
      "${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_${_vtk_actual_component}")
    set("${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_${_vtk_actual_component}"
      "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_${_vtk_component}}")
    unset(_vtk_actual_component)
  else ()
    list(APPEND _vtk_real_components
      "${_vtk_component}")
  endif ()
endforeach ()
unset(_vtk_component)
set("${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS"
  ${_vtk_real_components})
unset(_vtk_real_components)

set("${CMAKE_FIND_PACKAGE_NAME}_CMAKE_MODULE_PATH_save" "${CMAKE_MODULE_PATH}")
list(INSERT CMAKE_MODULE_PATH 0
  "${CMAKE_CURRENT_LIST_DIR}")

set("${CMAKE_FIND_PACKAGE_NAME}_CMAKE_PREFIX_PATH_save" "${CMAKE_PREFIX_PATH}")
include("${CMAKE_CURRENT_LIST_DIR}/vtk-prefix.cmake")
set("${CMAKE_FIND_PACKAGE_NAME}_PREFIX_PATH"
  "${_vtk_module_import_prefix}")
unset(_vtk_module_import_prefix)
list(INSERT CMAKE_PREFIX_PATH 0
  "${${CMAKE_FIND_PACKAGE_NAME}_PREFIX_PATH}")

set("${CMAKE_FIND_PACKAGE_NAME}_VERSION" "9.5.0")
set("${CMAKE_FIND_PACKAGE_NAME}_MAJOR_VERSION" "9")
set("${CMAKE_FIND_PACKAGE_NAME}_MINOR_VERSION" "5")
set("${CMAKE_FIND_PACKAGE_NAME}_BUILD_VERSION" "0")
set("${CMAKE_FIND_PACKAGE_NAME}_LEGACY_REMOVE" "OFF")
set("${CMAKE_FIND_PACKAGE_NAME}_AUTOINIT_INCLUDE" "\"vtkAutoInit.h\"")
set("${CMAKE_FIND_PACKAGE_NAME}_SMP_BACKENDS" "STDThread;Sequential")

unset("${CMAKE_FIND_PACKAGE_NAME}_FOUND")
set("${CMAKE_FIND_PACKAGE_NAME}_HAS_VISKORES" "OFF")
set("${CMAKE_FIND_PACKAGE_NAME}_HAS_VTKm" "OFF")
if (${CMAKE_FIND_PACKAGE_NAME}_HAS_VISKORES)
  if (NOT "") # VTK_MODULE_USE_EXTERNAL_VTK_vtkviskores
    find_package(Viskores
      PATHS "${CMAKE_CURRENT_LIST_DIR}/viskores"
      NO_DEFAULT_PATH)
    if (NOT Viskores_FOUND)
      set("${CMAKE_FIND_PACKAGE_NAME}_FOUND" 0)
      set("${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE" "VTK internal enabled Viskores cannot be founded")
    endif ()
  endif ()
endif ()

include("${CMAKE_CURRENT_LIST_DIR}/vtkCMakeBackports.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/${CMAKE_FIND_PACKAGE_NAME}-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/${CMAKE_FIND_PACKAGE_NAME}-vtk-module-properties.cmake")

include("${CMAKE_CURRENT_LIST_DIR}/vtk-find-package-helpers.cmake" OPTIONAL)

# Ensure that the right OpenGL preference is in place when finding the OpenGL
# libraries.
if (0) # vtk_opengl_preference_set
  if (DEFINED OpenGL_GL_PREFERENCE)
    set("${CMAKE_FIND_PACKAGE_NAME}_OpenGL_GL_PREFERENCE_save" "${OpenGL_GL_PREFERENCE}")
  endif ()
  set(OpenGL_GL_PREFERENCE "")
endif ()

# Ensure that python is found based on location, not on version
# See https://cmake.org/cmake/help/latest/module/FindPython.html
if (DEFINED Python3_FIND_STRATEGY)
  set("${CMAKE_FIND_PACKAGE_NAME}_Python3_FIND_STRATEGY_save" "${Python3_FIND_STRATEGY}")
endif ()
set(Python3_FIND_STRATEGY LOCATION)

# Ensures that the OpenGL::GLES3 is found.
include("${CMAKE_CURRENT_LIST_DIR}/vtkMobileDevices.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/${CMAKE_FIND_PACKAGE_NAME}-vtk-module-find-packages.cmake")

if (0) # vtk_opengl_preference_set
  if (DEFINED "${CMAKE_FIND_PACKAGE_NAME}_OpenGL_GL_PREFERENCE_save")
    set(OpenGL_GL_PREFERENCE "${${CMAKE_FIND_PACKAGE_NAME}_OpenGL_GL_PREFERENCE_save}")
    unset("${CMAKE_FIND_PACKAGE_NAME}_OpenGL_GL_PREFERENCE_save")
  else ()
    unset(OpenGL_GL_PREFERENCE)
  endif ()
endif ()

if (DEFINED "${CMAKE_FIND_PACKAGE_NAME}_Python3_FIND_STRATEGY_save")
  set(Python3_FIND_STRATEGY "${${CMAKE_FIND_PACKAGE_NAME}_Python3_FIND_STRATEGY_save}")
  unset("${CMAKE_FIND_PACKAGE_NAME}_Python3_FIND_STRATEGY_save")
else ()
  unset(Python3_FIND_STRATEGY)
endif ()

set(VTK_OPENGL_HAS_EGL "OFF")
set(VTK_USE_X "OFF")

if (TARGET VTK::RenderingVR)
  set("${CMAKE_FIND_PACKAGE_NAME}_ENABLE_VR_COLLABORATION" "")
endif ()

if (6) # VTK_QT_VERSION
  set("${CMAKE_FIND_PACKAGE_NAME}_QT_VERSION" "6")
endif ()

if (0) # vtk_has_qml
  set("${CMAKE_FIND_PACKAGE_NAME}_QML_DIR" "${${CMAKE_FIND_PACKAGE_NAME}_PREFIX_PATH}/lib/qml")
endif ()

include("${CMAKE_CURRENT_LIST_DIR}/vtkModule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/vtkEncodeString.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/vtkHashSource.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/vtkObjectFactory.cmake")

include("${CMAKE_CURRENT_LIST_DIR}/vtkModuleJson.cmake")

set("${CMAKE_FIND_PACKAGE_NAME}_PYTHON_VERSION" "3")
set("${CMAKE_FIND_PACKAGE_NAME}_WRAP_PYTHON" "true")
if (${CMAKE_FIND_PACKAGE_NAME}_WRAP_PYTHON)
  include("${CMAKE_CURRENT_LIST_DIR}/VTKPython-targets.cmake")
  include("${CMAKE_CURRENT_LIST_DIR}/vtkmodules-vtk-python-module-properties.cmake")
  include("${CMAKE_CURRENT_LIST_DIR}/vtkModuleWrapPython.cmake")
  set("${CMAKE_FIND_PACKAGE_NAME}_PYTHONPATH" "lib/site-packages")
endif ()

set("${CMAKE_FIND_PACKAGE_NAME}_WRAP_JAVA" "OFF")
if (${CMAKE_FIND_PACKAGE_NAME}_WRAP_JAVA)
  include("${CMAKE_CURRENT_LIST_DIR}/vtkModuleWrapJava.cmake")

  if () # VTK_JAVA_JOGL_COMPONENT
    set(_vtk_find_jogl_args)
    if (${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      list(APPEND _vtk_find_jogl_args QUIET)
    endif ()
    find_package(JOGL ${_vtk_find_jogl_args})
    unset(_vtk_find_jogl_args)

    if (JOGL_FOUND)
      include("${CMAKE_CURRENT_LIST_DIR}/VTKJava-targets.cmake")
      set("${CMAKE_FIND_PACKAGE_NAME}_vtkjava_FOUND" 1)
    else ()
      set("${CMAKE_FIND_PACKAGE_NAME}_vtkjava_FOUND" 0)
      set("${CMAKE_FIND_PACKAGE_NAME}_vtkjava_NOT_FOUND_MESSAGE"
        "JOGL was not found")
    endif ()
  endif ()
endif ()

set("${CMAKE_FIND_PACKAGE_NAME}_WRAP_SERIALIZATION" "OFF")
include("${CMAKE_CURRENT_LIST_DIR}/vtkModuleSerialization.cmake")

set(_vtk_search_components
  ${${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS})
if (NOT _vtk_search_components)
  set(_vtk_search_components
    ${${CMAKE_FIND_PACKAGE_NAME}_AVAILABLE_COMPONENTS})
endif ()
list(REMOVE_ITEM _vtk_search_components
  # These components need to always be requested explicitly since they are
  # not modules.
  WrapHierarchy;vtkbuild;vtkpython;pvtkpython;WrapPython;WrapPythonInit;vtkjava;ParseJava;WrapJava;vtkWebAssemblyTestLinkOptions)
set(_vtk_components_to_check)
foreach (_vtk_component IN LISTS _vtk_search_components)
  if (DEFINED "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND")
    # It was already not-found (likely due to `find-package` failures).
  elseif (TARGET "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_component}")
    list(APPEND _vtk_components_to_check
      "${_vtk_component}")
  else ()
    set("${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_NOT_FOUND_MESSAGE"
      "The ${_vtk_component} component is not available.")
  endif ()
endforeach ()
unset(_vtk_component)
unset(_vtk_search_components)

while (_vtk_components_to_check)
  list(GET _vtk_components_to_check 0 _vtk_component)
  list(REMOVE_AT _vtk_components_to_check 0)
  if (DEFINED "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND")
    # We've already made a determiniation.
    continue ()
  endif ()

  get_property(_vtk_public_dependencies
    TARGET    "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_component}"
    PROPERTY  "INTERFACE_vtk_module_depends")
  get_property(_vtk_private_dependencies
    TARGET    "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_component}"
    PROPERTY  "INTERFACE_vtk_module_private_depends")
  get_property(_vtk_optional_dependencies
    TARGET    "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_component}"
    PROPERTY  "INTERFACE_vtk_module_optional_depends")
  set(_vtk_dependencies
    ${_vtk_public_dependencies}
    ${_vtk_private_dependencies})
  foreach (_vtk_optional_dependency IN LISTS _vtk_optional_dependencies)
    if (TARGET "${_vtk_optional_dependency}")
      list(APPEND _vtk_dependencies
        "${_vtk_optional_dependency}")
    endif ()
  endforeach ()
  unset(_vtk_public_dependencies)
  unset(_vtk_private_dependencies)
  unset(_vtk_optional_dependency)
  unset(_vtk_optional_dependencies)

  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _vtk_dependencies "${_vtk_dependencies}")
  set(_vtk_all_dependencies_checked TRUE)
  foreach (_vtk_dependency IN LISTS _vtk_dependencies)
    if (DEFINED "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_dependency}_FOUND")
      if (NOT ${CMAKE_FIND_PACKAGE_NAME}_${_vtk_dependency}_FOUND)
        set("${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND" 0)
        list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_NOT_FOUND_MESSAGE"
          "Failed to find the ${_vtk_dependency} component.")
      endif ()
    else ()
      # Check its dependencies.
      list(APPEND _vtk_components_to_check
        "${_vtk_dependency}")
      set(_vtk_all_found FALSE)
    endif ()
  endforeach ()
  if (NOT DEFINED "${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND")
    if (_vtk_all_dependencies_checked)
      set("${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND" 1)
    else ()
      list(APPEND _vtk_components_to_check
        "${_vtk_component}")
    endif ()
  endif ()
  unset(_vtk_all_dependencies_checked)
  unset(_vtk_dependency)
  unset(_vtk_dependencies)
endwhile ()
unset(_vtk_component)
unset(_vtk_components_to_check)

set(_vtk_missing_components)
foreach (_vtk_component IN LISTS "${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS")
  if (NOT ${CMAKE_FIND_PACKAGE_NAME}_${_vtk_component}_FOUND AND ${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_${_vtk_component})
    list(APPEND _vtk_missing_components
      "${_vtk_component}")
  endif ()
endforeach ()

if (_vtk_missing_components)
  list(REMOVE_DUPLICATES _vtk_missing_components)
  list(SORT _vtk_missing_components)
  string(REPLACE ";" ", " _vtk_missing_components "${_vtk_missing_components}")
  set("${CMAKE_FIND_PACKAGE_NAME}_FOUND" 0)
  set("${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE"
    "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package with the following required components: ${_vtk_missing_components}.")
endif ()
unset(_vtk_missing_components)

set("${CMAKE_FIND_PACKAGE_NAME}_LIBRARIES")
if (NOT DEFINED "${CMAKE_FIND_PACKAGE_NAME}_FOUND")
  # If nothing went wrong, we've successfully found the package.
  set("${CMAKE_FIND_PACKAGE_NAME}_FOUND" 1)
  set(_vtk_found_components
    ${${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS})
  if (NOT _vtk_found_components)
    set(_vtk_found_components
      ${${CMAKE_FIND_PACKAGE_NAME}_AVAILABLE_COMPONENTS})
  endif ()
  list(REMOVE_ITEM _vtk_found_components
    # These components need to always be requested explicitly since they are
    # not modules.
    WrapHierarchy;vtkbuild;vtkpython;pvtkpython;WrapPython;WrapPythonInit;vtkjava;ParseJava;WrapJava;vtkWebAssemblyTestLinkOptions)
  # Build the `_LIBRARIES` variable.
  foreach (_vtk_component IN LISTS _vtk_found_components)
    if (TARGET "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_component}")
      list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_LIBRARIES"
        "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_component}")
    endif ()
  endforeach ()
  unset(_vtk_component)
  unset(_vtk_found_components)
endif ()

set(CMAKE_PREFIX_PATH "${${CMAKE_FIND_PACKAGE_NAME}_CMAKE_PREFIX_PATH_save}")
unset("${CMAKE_FIND_PACKAGE_NAME}_CMAKE_PREFIX_PATH_save")

set(CMAKE_MODULE_PATH "${${CMAKE_FIND_PACKAGE_NAME}_CMAKE_MODULE_PATH_save}")
unset("${CMAKE_FIND_PACKAGE_NAME}_CMAKE_MODULE_PATH_save")

foreach (_vtk_temp_variable IN LISTS _vtk_temp_variables)
  unset("${_vtk_temp_variable}")
endforeach ()
unset(_vtk_temp_variable)
unset(_vtk_temp_variables)

# Compatibility with old code.
if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_VERSION)
  set(VTK_USE_FILE "${CMAKE_CURRENT_LIST_DIR}/vtk-use-file-deprecated.cmake")
elseif (${CMAKE_FIND_PACKAGE_NAME}_FIND_VERSION VERSION_LESS "8.90")
  set(VTK_USE_FILE "${CMAKE_CURRENT_LIST_DIR}/vtk-use-file-compat.cmake")
else ()
  set(VTK_USE_FILE "${CMAKE_CURRENT_LIST_DIR}/vtk-use-file-error.cmake")
endif ()

cmake_policy(POP)
