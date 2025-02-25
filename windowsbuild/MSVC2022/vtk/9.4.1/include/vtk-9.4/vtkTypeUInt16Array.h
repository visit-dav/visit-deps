// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME vtkTypeUInt16Array - dynamic, self-adjusting array of vtkTypeUInt16
// .SECTION Description
// vtkTypeUInt16Array is an array of values of type vtkTypeUInt16.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt16 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeUInt16Array_h
#define vtkTypeUInt16Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_UINT16 == VTK_UNSIGNED_SHORT
# include "vtkUnsignedShortArray.h"
# define vtkTypeArrayBase vtkUnsignedShortArray
#endif


VTK_ABI_NAMESPACE_BEGIN

class VTKCOMMONCORE_EXPORT vtkTypeUInt16Array : public vtkTypeArrayBase
{
public:
  static vtkTypeUInt16Array* New();
  vtkTypeMacro(vtkTypeUInt16Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeUInt16Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeUInt16Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeUInt16Array();
  ~vtkTypeUInt16Array() override;

private:
  vtkTypeUInt16Array(const vtkTypeUInt16Array&) = delete;
  void operator=(const vtkTypeUInt16Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeUInt16Array);

VTK_ABI_NAMESPACE_END

#undef vtkTypeArrayBase

#endif
/* VTK-HeaderTest-Exclude: INCLUDES */
