//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
#ifndef vtk_m_exec_ParametricCoordinates_h
#define vtk_m_exec_ParametricCoordinates_h

#include <vtkm/Assert.h>
#include <vtkm/CellShape.h>
#include <vtkm/VecAxisAlignedPointCoordinates.h>
#include <vtkm/exec/CellInterpolate.h>
#include <vtkm/exec/FunctorBase.h>
#include <vtkm/exec/internal/FastVec.h>
#include <vtkm/internal/Assume.h>

#include <lcl/lcl.h>

namespace vtkm
{
namespace exec
{

//-----------------------------------------------------------------------------
template <typename ParametricCoordType, typename CellShapeTag>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesCenter(
  vtkm::IdComponent numPoints,
  CellShapeTag,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  auto lclTag = typename vtkm::internal::CellShapeTagVtkmToVtkc<CellShapeTag>::Type{};

  pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
  if (numPoints != lclTag.numberOfPoints())
  {
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }

  return vtkm::internal::LclErrorToVtkmError(lcl::parametricCenter(lclTag, pcoords));
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesCenter(
  vtkm::IdComponent numPoints,
  vtkm::CellShapeTagEmpty,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
  if (numPoints != 0)
  {
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  return vtkm::ErrorCode::Success;
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesCenter(
  vtkm::IdComponent numPoints,
  vtkm::CellShapeTagVertex,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
  if (numPoints != 1)
  {
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  return vtkm::ErrorCode::Success;
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesCenter(
  vtkm::IdComponent numPoints,
  vtkm::CellShapeTagPolyLine,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  switch (numPoints)
  {
    case 1:
      return ParametricCoordinatesCenter(numPoints, vtkm::CellShapeTagVertex(), pcoords);
    case 2:
      return ParametricCoordinatesCenter(numPoints, vtkm::CellShapeTagLine(), pcoords);
  }
  pcoords[0] = 0.5;
  pcoords[1] = 0;
  pcoords[2] = 0;
  return vtkm::ErrorCode::Success;
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesCenter(
  vtkm::IdComponent numPoints,
  vtkm::CellShapeTagPolygon,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  if (numPoints < 1)
  {
    pcoords = { 0 };
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  switch (numPoints)
  {
    case 1:
      return ParametricCoordinatesCenter(numPoints, vtkm::CellShapeTagVertex(), pcoords);
    case 2:
      return ParametricCoordinatesCenter(numPoints, vtkm::CellShapeTagLine(), pcoords);
    default:
      pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
      return vtkm::internal::LclErrorToVtkmError(
        lcl::parametricCenter(lcl::Polygon(numPoints), pcoords));
  }
}

//-----------------------------------------------------------------------------
/// Returns the parametric center of the given cell shape with the given number
/// of points.
///
template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesCenter(
  vtkm::IdComponent numPoints,
  vtkm::CellShapeTagGeneric shape,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  vtkm::ErrorCode status;
  switch (shape.Id)
  {
    vtkmGenericCellShapeMacro(status =
                                ParametricCoordinatesCenter(numPoints, CellShapeTag(), pcoords));
    default:
      pcoords = { 0 };
      status = vtkm::ErrorCode::InvalidShapeId;
  }
  return status;
}

template <typename ParametricCoordType, typename CellShapeTag>
VTKM_DEPRECATED(1.6, "Signature changed to ParametricCoordinatesCenter(numPoints, shape, result).")
static inline VTKM_EXEC void ParametricCoordinatesCenter(vtkm::IdComponent numPoints,
                                                         vtkm::Vec<ParametricCoordType, 3>& pcoords,
                                                         CellShapeTag shape,
                                                         const vtkm::exec::FunctorBase& worklet)
{
  vtkm::ErrorCode status = ParametricCoordinatesCenter(numPoints, shape, pcoords);
  if (status != vtkm::ErrorCode::Success)
  {
    worklet.RaiseError(vtkm::ErrorString(status));
  }
}

/// Returns the parametric center of the given cell shape with the given number
/// of points.
///
template <typename CellShapeTag>
VTKM_DEPRECATED(1.6, "Signature changed to ParametricCoordinatesCenter(numPoints, shape, result).")
static inline VTKM_EXEC vtkm::Vec3f
  ParametricCoordinatesCenter(vtkm::IdComponent numPoints,
                              CellShapeTag shape,
                              const vtkm::exec::FunctorBase& worklet)
{
  vtkm::Vec3f pcoords(0.0f);
  vtkm::ErrorCode status = ParametricCoordinatesCenter(numPoints, shape, pcoords);
  if (status != vtkm::ErrorCode::Success)
  {
    worklet.RaiseError(vtkm::ErrorString(status));
  }
  return pcoords;
}

//-----------------------------------------------------------------------------
template <typename ParametricCoordType, typename CellShapeTag>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesPoint(
  vtkm::IdComponent numPoints,
  vtkm::IdComponent pointIndex,
  CellShapeTag,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  auto lclTag = typename vtkm::internal::CellShapeTagVtkmToVtkc<CellShapeTag>::Type{};

  if (numPoints != lclTag.numberOfPoints())
  {
    pcoords = { 0 };
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  if ((pointIndex < 0) || (pointIndex >= numPoints))
  {
    pcoords = { 0 };
    return vtkm::ErrorCode::InvalidPointId;
  }

  pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
  return vtkm::internal::LclErrorToVtkmError(lcl::parametricPoint(lclTag, pointIndex, pcoords));
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesPoint(
  vtkm::IdComponent,
  vtkm::IdComponent,
  vtkm::CellShapeTagEmpty,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  pcoords[0] = pcoords[1] = pcoords[2] = 0;
  return vtkm::ErrorCode::OperationOnEmptyCell;
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesPoint(
  vtkm::IdComponent numPoints,
  vtkm::IdComponent pointIndex,
  vtkm::CellShapeTagVertex,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
  if (numPoints != 1)
  {
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  if (pointIndex != 0)
  {
    return vtkm::ErrorCode::InvalidPointId;
  }
  return vtkm::ErrorCode::Success;
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesPoint(
  vtkm::IdComponent numPoints,
  vtkm::IdComponent pointIndex,
  vtkm::CellShapeTagPolyLine,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  if (numPoints < 1)
  {
    pcoords = { 0 };
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  switch (numPoints)
  {
    case 1:
      return ParametricCoordinatesPoint(numPoints, pointIndex, vtkm::CellShapeTagVertex(), pcoords);
    case 2:
      return ParametricCoordinatesPoint(numPoints, pointIndex, vtkm::CellShapeTagLine(), pcoords);
  }
  pcoords[0] =
    static_cast<ParametricCoordType>(pointIndex) / static_cast<ParametricCoordType>(numPoints - 1);
  pcoords[1] = 0;
  pcoords[2] = 0;
  return vtkm::ErrorCode::Success;
}

template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesPoint(
  vtkm::IdComponent numPoints,
  vtkm::IdComponent pointIndex,
  vtkm::CellShapeTagPolygon,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  switch (numPoints)
  {
    case 1:
      return ParametricCoordinatesPoint(numPoints, pointIndex, vtkm::CellShapeTagVertex(), pcoords);
    case 2:
      return ParametricCoordinatesPoint(numPoints, pointIndex, vtkm::CellShapeTagLine(), pcoords);
    default:
      pcoords = vtkm::TypeTraits<vtkm::Vec<ParametricCoordType, 3>>::ZeroInitialization();
      return vtkm::internal::LclErrorToVtkmError(
        lcl::parametricPoint(lcl::Polygon(numPoints), pointIndex, pcoords));
  }
}

//-----------------------------------------------------------------------------
/// Returns the parametric coordinate of a cell point of the given shape with
/// the given number of points.
///
template <typename ParametricCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesPoint(
  vtkm::IdComponent numPoints,
  vtkm::IdComponent pointIndex,
  vtkm::CellShapeTagGeneric shape,
  vtkm::Vec<ParametricCoordType, 3>& pcoords)
{
  vtkm::ErrorCode status;
  switch (shape.Id)
  {
    vtkmGenericCellShapeMacro(
      status = ParametricCoordinatesPoint(numPoints, pointIndex, CellShapeTag(), pcoords));
    default:
      pcoords[0] = pcoords[1] = pcoords[2] = 0;
      status = vtkm::ErrorCode::InvalidShapeId;
  }
  return status;
}

template <typename ParametricCoordType, typename CellShapeTag>
VTKM_DEPRECATED(
  1.6,
  "Signature changed to ParametricCoordinatesPoint(numPoints, pointIndex, shape, result).")
static inline VTKM_EXEC void ParametricCoordinatesPoint(vtkm::IdComponent numPoints,
                                                        vtkm::IdComponent pointIndex,
                                                        vtkm::Vec<ParametricCoordType, 3>& pcoords,
                                                        CellShapeTag shape,
                                                        const vtkm::exec::FunctorBase& worklet)
{
  vtkm::ErrorCode status = ParametricCoordinatesPoint(numPoints, pointIndex, shape, pcoords);
  if (status != vtkm::ErrorCode::Success)
  {
    worklet.RaiseError(vtkm::ErrorString(status));
  }
}

/// Returns the parametric coordinate of a cell point of the given shape with
/// the given number of points.
///
template <typename CellShapeTag>
VTKM_DEPRECATED(
  1.6,
  "Signature changed to ParametricCoordinatesPoint(numPoints, pointIndex, shape, result).")
static inline VTKM_EXEC vtkm::Vec3f
  ParametricCoordinatesPoint(vtkm::IdComponent numPoints,
                             vtkm::IdComponent pointIndex,
                             CellShapeTag shape,
                             const vtkm::exec::FunctorBase& worklet)
{
  vtkm::Vec3f pcoords;
  vtkm::ErrorCode status = ParametricCoordinatesPoint(numPoints, pointIndex, shape, pcoords);
  if (status != vtkm::ErrorCode::Success)
  {
    worklet.RaiseError(vtkm::ErrorString(status));
  }
  return pcoords;
}

//-----------------------------------------------------------------------------
namespace internal
{

template <typename LclCellShapeTag, typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinatesImpl(
  LclCellShapeTag tag,
  const WorldCoordVector& pointWCoords,
  const PCoordType& pcoords,
  typename WorldCoordVector::ComponentType& wcoords)
{
  return vtkm::internal::LclErrorToVtkmError(lcl::parametricToWorld(
    tag, lcl::makeFieldAccessorNestedSOA(pointWCoords, 3), pcoords, wcoords));
}

} // namespace internal

template <typename WorldCoordVector, typename PCoordType, typename CellShapeTag>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const WorldCoordVector& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  CellShapeTag shape,
  typename WorldCoordVector::ComponentType& result)
{
  auto numPoints = pointWCoords.GetNumberOfComponents();
  return internal::ParametricCoordinatesToWorldCoordinatesImpl(
    vtkm::internal::make_LclCellShapeTag(shape, numPoints), pointWCoords, pcoords, result);
}

template <typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const WorldCoordVector& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  vtkm::CellShapeTagEmpty empty,
  typename WorldCoordVector::ComponentType& result)
{
  return vtkm::exec::CellInterpolate(pointWCoords, pcoords, empty, result);
}

template <typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const WorldCoordVector& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  vtkm::CellShapeTagPolyLine polyLine,
  typename WorldCoordVector::ComponentType& result)
{
  return vtkm::exec::CellInterpolate(pointWCoords, pcoords, polyLine, result);
}

template <typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const WorldCoordVector& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  vtkm::CellShapeTagPolygon,
  typename WorldCoordVector::ComponentType& result)
{
  auto numPoints = pointWCoords.GetNumberOfComponents();
  switch (numPoints)
  {
    case 1:
      return ParametricCoordinatesToWorldCoordinates(
        pointWCoords, pcoords, vtkm::CellShapeTagVertex{}, result);
    case 2:
      return ParametricCoordinatesToWorldCoordinates(
        pointWCoords, pcoords, vtkm::CellShapeTagLine{}, result);
    default:
      return internal::ParametricCoordinatesToWorldCoordinatesImpl(
        lcl::Polygon(numPoints), pointWCoords, pcoords, result);
  }
}

template <typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const vtkm::VecAxisAlignedPointCoordinates<2>& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  vtkm::CellShapeTagQuad,
  typename WorldCoordVector::ComponentType& result)
{
  return internal::ParametricCoordinatesToWorldCoordinatesImpl(
    lcl::Pixel{}, pointWCoords, pcoords, result);
}

template <typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const vtkm::VecAxisAlignedPointCoordinates<3>& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  vtkm::CellShapeTagHexahedron,
  typename WorldCoordVector::ComponentType& result)
{
  return internal::ParametricCoordinatesToWorldCoordinatesImpl(
    lcl::Voxel{}, pointWCoords, pcoords, result);
}

//-----------------------------------------------------------------------------
/// Returns the world coordinate corresponding to the given parametric coordinate of a cell.
///
template <typename WorldCoordVector, typename PCoordType>
static inline VTKM_EXEC vtkm::ErrorCode ParametricCoordinatesToWorldCoordinates(
  const WorldCoordVector& pointWCoords,
  const vtkm::Vec<PCoordType, 3>& pcoords,
  vtkm::CellShapeTagGeneric shape,
  typename WorldCoordVector::ComponentType& result)
{
  vtkm::ErrorCode status;
  switch (shape.Id)
  {
    vtkmGenericCellShapeMacro(status = ParametricCoordinatesToWorldCoordinates(
                                pointWCoords, pcoords, CellShapeTag(), result));
    default:
      result = { 0 };
      status = vtkm::ErrorCode::InvalidShapeId;
  }
  return status;
}

template <typename WorldCoordVector, typename PCoordType, typename CellShapeTag>
VTKM_DEPRECATED(1.6,
                "Signature changed to "
                "ParametricCoordinatesToWorldCoordinates(pointWCoords, pcoords, shape, result).")
static inline VTKM_EXEC typename WorldCoordVector::ComponentType
  ParametricCoordinatesToWorldCoordinates(const WorldCoordVector& pointWCoords,
                                          const vtkm::Vec<PCoordType, 3>& pcoords,
                                          CellShapeTag shape,
                                          const vtkm::exec::FunctorBase& worklet)
{
  typename WorldCoordVector::ComponentType result;
  vtkm::ErrorCode status =
    ParametricCoordinatesToWorldCoordinates(pointWCoords, pcoords, shape, result);
  if (status != vtkm::ErrorCode::Success)
  {
    worklet.RaiseError(vtkm::ErrorString(status));
  }
  return result;
}

//-----------------------------------------------------------------------------
namespace internal
{

template <typename LclCellShapeTag, typename WorldCoordVector>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinatesImpl(
  LclCellShapeTag tag,
  const WorldCoordVector& pointWCoords,
  const typename WorldCoordVector::ComponentType& wcoords,
  typename WorldCoordVector::ComponentType& result)
{
  if (pointWCoords.GetNumberOfComponents() != tag.numberOfPoints())
  {
    result = { 0 };
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }

  result = vtkm::TypeTraits<typename WorldCoordVector::ComponentType>::ZeroInitialization();
  return vtkm::internal::LclErrorToVtkmError(
    lcl::worldToParametric(tag, lcl::makeFieldAccessorNestedSOA(pointWCoords, 3), wcoords, result));
}

} // namespace internal

template <typename WorldCoordVector, typename CellShapeTag>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const WorldCoordVector& pointWCoords,
  const typename WorldCoordVector::ComponentType& wcoords,
  CellShapeTag shape,
  typename WorldCoordVector::ComponentType& result)
{
  auto numPoints = pointWCoords.GetNumberOfComponents();
  return internal::WorldCoordinatesToParametricCoordinatesImpl(
    vtkm::internal::make_LclCellShapeTag(shape, numPoints), pointWCoords, wcoords, result);
}

template <typename WorldCoordVector>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const WorldCoordVector&,
  const typename WorldCoordVector::ComponentType&,
  vtkm::CellShapeTagEmpty,
  typename WorldCoordVector::ComponentType& result)
{
  result = { 0 };
  return vtkm::ErrorCode::OperationOnEmptyCell;
}

template <typename WorldCoordVector>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const WorldCoordVector& pointWCoords,
  const typename WorldCoordVector::ComponentType&,
  vtkm::CellShapeTagVertex,
  typename WorldCoordVector::ComponentType& result)
{
  if (pointWCoords.GetNumberOfComponents() != 1)
  {
    result = { 0 };
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }
  result = typename WorldCoordVector::ComponentType(0, 0, 0);
  return vtkm::ErrorCode::Success;
}

template <typename WorldCoordVector>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const WorldCoordVector& pointWCoords,
  const typename WorldCoordVector::ComponentType& wcoords,
  vtkm::CellShapeTagPolyLine,
  typename WorldCoordVector::ComponentType& result)
{
  vtkm::IdComponent numPoints = pointWCoords.GetNumberOfComponents();
  if (numPoints < 1)
  {
    result = { 0 };
    return vtkm::ErrorCode::InvalidNumberOfPoints;
  }

  if (numPoints == 1)
  {
    return WorldCoordinatesToParametricCoordinates(
      pointWCoords, wcoords, vtkm::CellShapeTagVertex(), result);
  }

  using Vector3 = typename WorldCoordVector::ComponentType;
  using T = typename Vector3::ComponentType;

  //Find the closest vertex to the point.
  vtkm::IdComponent idx = 0;
  Vector3 vec = pointWCoords[0] - wcoords;
  T minDistSq = vtkm::Dot(vec, vec);
  for (vtkm::IdComponent i = 1; i < numPoints; i++)
  {
    vec = pointWCoords[i] - wcoords;
    T d = vtkm::Dot(vec, vec);

    if (d < minDistSq)
    {
      idx = i;
      minDistSq = d;
    }
  }

  //Find the right segment, and the parameterization along that segment.
  //Closest to 0, so segment is (0,1)
  if (idx == 0)
  {
    idx = 1;
  }

  vtkm::Vec<Vector3, 2> line(pointWCoords[idx - 1], pointWCoords[idx]);
  Vector3 lpc;
  VTKM_RETURN_ON_ERROR(
    WorldCoordinatesToParametricCoordinates(line, wcoords, vtkm::CellShapeTagLine{}, lpc));

  //Segment param is [0,1] on that segment.
  //Map that onto the param for the entire segment.
  T dParam = static_cast<T>(1) / static_cast<T>(numPoints - 1);
  T polyLineParam = static_cast<T>(idx - 1) * dParam + lpc[0] * dParam;

  result = Vector3(polyLineParam, 0, 0);
  return vtkm::ErrorCode::Success;
}

template <typename WorldCoordVector>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const WorldCoordVector& pointWCoords,
  const typename WorldCoordVector::ComponentType& wcoords,
  vtkm::CellShapeTagPolygon,
  typename WorldCoordVector::ComponentType& result)
{
  auto numPoints = pointWCoords.GetNumberOfComponents();
  switch (numPoints)
  {
    case 1:
      return WorldCoordinatesToParametricCoordinates(
        pointWCoords, wcoords, vtkm::CellShapeTagVertex{}, result);
    case 2:
      return WorldCoordinatesToParametricCoordinates(
        pointWCoords, wcoords, vtkm::CellShapeTagLine{}, result);
    default:
      return internal::WorldCoordinatesToParametricCoordinatesImpl(
        lcl::Polygon(numPoints), pointWCoords, wcoords, result);
  }
}

static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const vtkm::VecAxisAlignedPointCoordinates<2>& pointWCoords,
  const vtkm::Vec3f& wcoords,
  vtkm::CellShapeTagQuad,
  vtkm::Vec3f& result)
{
  return internal::WorldCoordinatesToParametricCoordinatesImpl(
    lcl::Pixel{}, pointWCoords, wcoords, result);
}

static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const vtkm::VecAxisAlignedPointCoordinates<3>& pointWCoords,
  const vtkm::Vec3f& wcoords,
  vtkm::CellShapeTagHexahedron,
  vtkm::Vec3f& result)
{
  return internal::WorldCoordinatesToParametricCoordinatesImpl(
    lcl::Voxel{}, pointWCoords, wcoords, result);
}

//-----------------------------------------------------------------------------
/// Returns the world paramteric corresponding to the given world coordinate for a cell.
///
template <typename WorldCoordVector>
static inline VTKM_EXEC vtkm::ErrorCode WorldCoordinatesToParametricCoordinates(
  const WorldCoordVector& pointWCoords,
  const typename WorldCoordVector::ComponentType& wcoords,
  vtkm::CellShapeTagGeneric shape,
  typename WorldCoordVector::ComponentType& result)
{
  vtkm::ErrorCode status;
  switch (shape.Id)
  {
    vtkmGenericCellShapeMacro(status = WorldCoordinatesToParametricCoordinates(
                                pointWCoords, wcoords, CellShapeTag(), result));
    default:
      result = { 0 };
      status = vtkm::ErrorCode::InvalidShapeId;
  }
  return status;
}

template <typename WorldCoordVector, typename CellShapeTag>
VTKM_DEPRECATED(1.6,
                "Signature changed to "
                "WorldCoordinatesToParametricCoordinates(pointWCoords, wcoords, shape, result).")
static inline VTKM_EXEC typename WorldCoordVector::ComponentType
  WorldCoordinatesToParametricCoordinates(const WorldCoordVector& pointWCoords,
                                          const typename WorldCoordVector::ComponentType& wcoords,
                                          CellShapeTag shape,
                                          bool& success,
                                          const vtkm::exec::FunctorBase& worklet)
{
  typename WorldCoordVector::ComponentType result;
  vtkm::ErrorCode status =
    WorldCoordinatesToParametricCoordinates(pointWCoords, wcoords, shape, result);
  if (status != vtkm::ErrorCode::Success)
  {
    success = false;
    worklet.RaiseError(vtkm::ErrorString(status));
  }
  else
  {
    success = true;
  }
  return result;
}
}
} // namespace vtkm::exec

#endif //vtk_m_exec_ParametricCoordinates_h
