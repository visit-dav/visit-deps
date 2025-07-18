//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================

// The intention of the header file is to configure VTK-m to compile its algorithms
// and filters for some set of types and data storage. You can customize the types
// for which VTK-m is compiled for by setting the VTKm_DEFAULT_TYPES_HEADER CMake
// variable. This CMake variable can be set to a header file that defines one or
// more of the following macros:
//
// VTKM_DEFAULT_TYPE_LIST - a vtkm::List of value types for fields that filters
//     should directly operate on (where applicable).
// VTKM_DEFAULT_STORAGE_LIST - a vtkm::List of storage tags for fields that
//     filters should directly operate on.
// VTKM_DEFAULT_CELL_SET_LIST_STRUCTURED - a vtkm::List of vtkm::cont::CellSet types
//     that filters should operate on as a strutured cell set.
// VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED - a vtkm::List of vtkm::cont::CellSet types
//     that filters should operate on as an unstrutured cell set.
// VTKM_DEFAULT_CELL_SET_LIST - a vtkm::List of vtkm::cont::CellSet types that filters
//     should operate on (where applicable). The default of
//     vtkm::ListAppend<VTKM_STRUCTURED_CELL_SET_LIST, VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED>
//     is usually correct.
//
// Note that if you specify VTKm_DEFAULT_TYPES_HEADER, that file will be copied
// to the VTK-m build directory. Thus, be careful about editing the file included
// by this one (if it exists).

#ifndef vtk_m_cont_DefaultTypes_h
#define vtk_m_cont_DefaultTypes_h

#define VTK_M_HAS_DEFAULT_TYPES_HEADER

#ifdef VTK_M_HAS_DEFAULT_TYPES_HEADER
#include "internal/DefaultTypesVTK.h"
#endif

#ifndef VTKM_DEFAULT_TYPE_LIST
#include <vtkm/TypeList.h>
#define VTKM_DEFAULT_TYPE_LIST ::vtkm::TypeListCommon
#endif //VTKM_DEFAULT_TYPE_LIST

#ifndef VTKM_DEFAULT_STORAGE_LIST
#include <vtkm/cont/StorageList.h>
#define VTKM_DEFAULT_STORAGE_LIST ::vtkm::cont::StorageListCommon
#endif // VTKM_DEFAULT_STORAGE_LIST

#ifndef VTKM_DEFAULT_CELL_SET_LIST_STRUCTURED
#include <vtkm/cont/CellSetList.h>
#define VTKM_DEFAULT_CELL_SET_LIST_STRUCTURED ::vtkm::cont::CellSetListStructured
#endif // VTKM_DEFAULT_CELL_SET_LIST_STRUCTURED

#ifndef VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED
#include <vtkm/cont/CellSetList.h>
#define VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED ::vtkm::cont::CellSetListUnstructured
#endif // VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED

#ifndef VTKM_DEFAULT_CELL_SET_LIST
namespace vtkm
{
namespace cont
{
namespace internal
{

using CellSetList = vtkm::ListAppend<VTKM_DEFAULT_CELL_SET_LIST_STRUCTURED, VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED>;

}
}
} // namespace vtkm::cont::internal

#define VTKM_DEFAULT_CELL_SET_LIST ::vtkm::cont::internal::CellSetList
#endif // VTKM_CELL_SET_LIST

#endif //vtk_m_cont_DefaultTypes_h
