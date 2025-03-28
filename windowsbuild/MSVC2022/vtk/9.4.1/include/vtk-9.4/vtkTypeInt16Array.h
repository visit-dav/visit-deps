// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME vtkTypeInt16Array - dynamic, self-adjusting array of vtkTypeInt16
// .SECTION Description
// vtkTypeInt16Array is an array of values of type vtkTypeInt16.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int16 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeInt16Array_h
#define vtkTypeInt16Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_INT16 == VTK_SHORT
# include "vtkShortArray.h"
# define vtkTypeArrayBase vtkShortArray
#endif


VTK_ABI_NAMESPACE_BEGIN

class VTKCOMMONCORE_EXPORT vtkTypeInt16Array : public vtkTypeArrayBase
{
public:
  static vtkTypeInt16Array* New();
  vtkTypeMacro(vtkTypeInt16Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeInt16Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeInt16Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeInt16Array();
  ~vtkTypeInt16Array() override;

private:
  vtkTypeInt16Array(const vtkTypeInt16Array&) = delete;
  void operator=(const vtkTypeInt16Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeInt16Array);

VTK_ABI_NAMESPACE_END

#undef vtkTypeArrayBase

#endif
/* VTK-HeaderTest-Exclude: INCLUDES */
