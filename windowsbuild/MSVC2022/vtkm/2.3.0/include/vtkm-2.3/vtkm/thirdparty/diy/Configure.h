//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
#ifndef vtkm_diy_h
#define vtkm_diy_h

#include <vtkm/internal/Configure.h>

// Diy headers include windows.h. Use the following header file so that only the
// lean version of windows.h is included.
// (Without problematic macros like MIN, Max, GetMessage, etc)
#include <vtkm/internal/Windows.h>

/* Use the diy library configured for VTM-m. */
#define VTKM_USE_EXTERNAL_DIY 0

/* Need to provide a way to for Serialziation
 * specializations to be injected into the correct
 * namespace. This solves the issue while allowing
 * for VTK-m to support an internal and external diy
 * existing at the same time. */
#if(VTKM_USE_EXTERNAL_DIY)
# define mangled_diy_namespace diy
#else
# define mangled_diy_namespace vtkmdiy
#endif

#endif
