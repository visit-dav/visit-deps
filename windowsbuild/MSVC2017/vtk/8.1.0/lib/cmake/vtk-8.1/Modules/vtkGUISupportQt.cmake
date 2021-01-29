set(vtkGUISupportQt_LOADED 1)
set(vtkGUISupportQt_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkFiltersExtraction;vtkInteractionStyle;vtkRenderingCore;vtkRenderingOpenGL2")
set(vtkGUISupportQt_LIBRARIES "vtkGUISupportQt")
set(vtkGUISupportQt_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.1")
set(vtkGUISupportQt_LIBRARY_DIRS "")
set(vtkGUISupportQt_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkGUISupportQt_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkGUISupportQtHierarchy.txt")
set(vtkGUISupportQt_KIT "")
set(vtkGUISupportQt_TARGETS_FILE "")
set(VTK_QT_RCC_EXECUTABLE "")
set(VTK_QT_MOC_EXECUTABLE "${QT_DIR}/lib/moc.exe")
set(VTK_QT_UIC_EXECUTABLE "")
set(VTK_QT_QMAKE_EXECUTABLE "${QT_DIR}/lib/qmake.exe")
set(vtkGUISupportQt_EXCLUDE_FROM_WRAPPING 1)



