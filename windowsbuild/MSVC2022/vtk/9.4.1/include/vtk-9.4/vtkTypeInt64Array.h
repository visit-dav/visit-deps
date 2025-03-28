// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME vtkTypeInt64Array - dynamic, self-adjusting array of vtkTypeInt64
// .SECTION Description
// vtkTypeInt64Array is an array of values of type vtkTypeInt64.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int64 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeInt64Array_h
#define vtkTypeInt64Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_INT64 == VTK_LONG
# include "vtkLongArray.h"
# define vtkTypeArrayBase vtkLongArray
#elif VTK_TYPE_INT64 == VTK_LONG_LONG
# include "vtkLongLongArray.h"
# define vtkTypeArrayBase vtkLongLongArray
#endif


VTK_ABI_NAMESPACE_BEGIN

class VTKCOMMONCORE_EXPORT vtkTypeInt64Array : public vtkTypeArrayBase
{
public:
  static vtkTypeInt64Array* New();
  vtkTypeMacro(vtkTypeInt64Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeInt64Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeInt64Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeInt64Array();
  ~vtkTypeInt64Array() override;

private:
  vtkTypeInt64Array(const vtkTypeInt64Array&) = delete;
  void operator=(const vtkTypeInt64Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeInt64Array);

VTK_ABI_NAMESPACE_END

#undef vtkTypeArrayBase

#endif
/* VTK-HeaderTest-Exclude: INCLUDES */
