//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================

#ifndef vtk_m_source_Tangle_h
#define vtk_m_source_Tangle_h

#include <vtkm/source/Source.h>

namespace vtkm
{
namespace source
{
/**
 * @brief The Tangle source creates a uniform dataset.
 *
 * This class generates a predictable uniform grid dataset with an
 * interesting point field, which is useful for testing and
 * benchmarking.
 *
 * The Execute method creates a complete structured dataset of a
 * resolution specified in the constructor that is bounded by the
 * cube in the range [0,1] in each dimension. The dataset has a
 * point field named 'tangle' computed with the following formula
 *
 * x^4 - 5x^2 + y^4 - 5y^2 + z^4 - 5z^2
 *
**/
class VTKM_SOURCE_EXPORT Tangle final : public vtkm::source::Source
{
public:
  ///Construct a Tangle with Cell Dimensions
  VTKM_CONT
  Tangle(vtkm::Id3 dims)
    : Dims(dims)
  {
  }

private:
  vtkm::cont::DataSet DoExecute() const override;

  vtkm::Id3 Dims;
};
} //namespace source
} //namespace vtkm

#endif //vtk_m_source_Tangle_h
