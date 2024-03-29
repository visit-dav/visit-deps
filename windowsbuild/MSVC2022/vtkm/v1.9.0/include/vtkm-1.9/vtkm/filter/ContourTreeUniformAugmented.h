//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
#ifndef vtk_m_filter_ContourTreeUniformAugmented_h
#define vtk_m_filter_ContourTreeUniformAugmented_h

#include <vtkm/Deprecated.h>
#include <vtkm/filter/scalar_topology/ContourTreeUniformAugmented.h>

namespace vtkm
{
namespace filter
{

VTKM_DEPRECATED(1.8,
                "Use vtkm/filter/scalar_topology/ContourTreeUniformAugmented.h instead of "
                "vtkm/filter/ContourTreeUniformAugmented.h.")
inline void ContourTreeUniformAugmented_deprecated() {}

inline void ContourTreeUniformAugmented_deprecated_warning()
{
  ContourTreeUniformAugmented_deprecated();
}

}
} // namespace vtkm::filter

#endif //vtk_m_filter_ContourTreeUniformAugmented_h
