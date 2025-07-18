//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
#ifndef vtk_m_cont_internal_DefaultTypesVTK_h
#define vtk_m_cont_internal_DefaultTypesVTK_h

// This configures the default types to use when compiling VTK-m for use as an
// accelerator in VTK.

#include <vtkm/TypeList.h>

#include <vtkm/cont/CellSetList.h>
#include <vtkm/cont/StorageList.h>

/* #undef VTKM_ADD_XGC_DEFAULT_TYPES */

#ifdef VTKM_ADD_XGC_DEFAULT_TYPES
#include <vtkm/cont/ArrayHandleCartesianProduct.h>
#include <vtkm/cont/ArrayHandleUniformPointCoordinates.h>
#include <vtkm/cont/ArrayHandleXGCCoordinates.h>
#include <vtkm/cont/StorageList.h>
#endif

namespace tovtkm
{

//------------------------------------------------------------------------------
// All scalar types in vtkType.h
using VTKScalarTypes = vtkm::List< //
  signed char,                     //
  unsigned char,                   //
  short,                           //
  unsigned short,                  //
  int,                             //
  unsigned int,                    //
  long long,                       //
  unsigned long long,              //
  float,                           //
  double,                          //
  char,                            //
  long,                            //
  unsigned long                    //
  >;

using SpecialGradientOutTypes =
  vtkm::List<vtkm::Vec<vtkm::Vec<vtkm::Float32, 3>, 3>, vtkm::Vec<vtkm::Vec<vtkm::Float64, 3>, 3> >;

using FieldTypeInVTK = vtkm::ListAppend<vtkm::TypeListVecCommon, VTKScalarTypes>;

using FieldTypeOutVTK =
  vtkm::ListAppend<vtkm::TypeListVecCommon, SpecialGradientOutTypes, VTKScalarTypes>;

//------------------------------------------------------------------------------
using CellListStructuredInVTK =
  vtkm::List<vtkm::cont::CellSetStructured<3>, vtkm::cont::CellSetStructured<2>, vtkm::cont::CellSetStructured<1> >;
using CellListStructuredOutVTK = CellListStructuredInVTK;

// vtkCellArray may use either 32 or 64 bit arrays to hold connectivity/offset
// data, so we may be using ArrayHandleCast to convert to vtkm::Ids.
#ifdef VTKM_USE_64BIT_IDS
using Int32AOSHandle = vtkm::cont::ArrayHandle<vtkm::Int32>;
using Int32AsIdAOSHandle = vtkm::cont::ArrayHandleCast<vtkm::Id, Int32AOSHandle>;
using Int32AsIdAOSStorage = typename Int32AsIdAOSHandle::StorageTag;

using CellSetExplicit32Bit = vtkm::cont::CellSetExplicit<vtkm::cont::StorageTagBasic,
  Int32AsIdAOSStorage, Int32AsIdAOSStorage>;
using CellSetExplicit64Bit = vtkm::cont::CellSetExplicit<vtkm::cont::StorageTagBasic,
  vtkm::cont::StorageTagBasic, vtkm::cont::StorageTagBasic>;
using CellSetSingleType32Bit = vtkm::cont::CellSetSingleType<Int32AsIdAOSStorage>;
using CellSetSingleType64Bit = vtkm::cont::CellSetSingleType<vtkm::cont::StorageTagBasic>;
#else  // VTKM_USE_64BIT_IDS
using Int64AOSHandle = vtkm::cont::ArrayHandle<vtkm::Int64, vtkm::cont::StorageTagBasic>;
using Int64AsIdAOSHandle = vtkm::cont::ArrayHandleCast<vtkm::Id, Int64AOSHandle>;
using Int64AsIdAOSStorage = typename Int64AsIdAOSHandle::StorageTag;

using CellSetExplicit32Bit = vtkm::cont::CellSetExplicit<vtkm::cont::StorageTagBasic,
  vtkm::cont::StorageTagBasic, vtkm::cont::StorageTagBasic>;
using CellSetExplicit64Bit = vtkm::cont::CellSetExplicit<vtkm::cont::StorageTagBasic,
  Int64AsIdAOSStorage, Int64AsIdAOSStorage>;
using CellSetSingleType32Bit = vtkm::cont::CellSetSingleType<vtkm::cont::StorageTagBasic>;
using CellSetSingleType64Bit = vtkm::cont::CellSetSingleType<Int64AsIdAOSStorage>;
#endif // VTKM_USE_64BIT_IDS

//------------------------------------------------------------------------------
using CellListUnstructuredInVTK = vtkm::List< //
  CellSetExplicit32Bit,                       //
  CellSetExplicit64Bit,                       //
  CellSetSingleType32Bit,                     //
  CellSetSingleType64Bit,                     //
  vtkm::cont::CellSetExtrude                  //
  >;

using CellListUnstructuredOutVTK = vtkm::List<                     //
  vtkm::cont::CellSetExplicit<>,                                   //
  vtkm::cont::CellSetSingleType<>,                                 //
  CellSetExplicit32Bit,                                            //
  CellSetExplicit64Bit,                                            //
  CellSetSingleType32Bit,                                          //
  CellSetSingleType64Bit                                           //
  >;

//------------------------------------------------------------------------------
using CellListAllInVTK = vtkm::ListAppend<CellListStructuredInVTK, CellListUnstructuredInVTK>;
using CellListAllOutVTK = vtkm::ListAppend<CellListStructuredOutVTK, CellListUnstructuredOutVTK>;

#ifdef VTKM_ADD_XGC_DEFAULT_TYPES
using StorageListField = vtkm::ListAppend<
  vtkm::cont::StorageListCommon,
  vtkm::List<vtkm::cont::StorageTagXGCCoordinates>>;
#endif

} // end namespace tovtkm

#define VTKM_DEFAULT_TYPE_LIST ::tovtkm::FieldTypeInVTK
#define VTKM_DEFAULT_CELL_SET_LIST_STRUCTURED ::tovtkm::CellListStructuredInVTK
#define VTKM_DEFAULT_CELL_SET_LIST_UNSTRUCTURED ::tovtkm::CellListUnstructuredInVTK

#ifdef VTKM_ADD_XGC_DEFAULT_TYPES
#define VTKM_DEFAULT_STORAGE_LIST ::tovtkm::StorageListField
#endif

#endif //vtk_m_cont_internal_DefaultTypesVTK_h
