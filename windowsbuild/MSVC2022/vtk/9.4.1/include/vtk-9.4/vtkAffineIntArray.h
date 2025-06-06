// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkAffineIntArray
 * @brief   affine implicit array of int.
 *
 * vtkAffineIntArray is an affine implicit array of values of type int.
 * see vtkAffineArray, vtkAffineImplicitBackend
 *
 * This file is generated by vtkImplicitArrays.cmake
 */

#ifndef vtkAffineIntArray_h
#define vtkAffineIntArray_h

#include "vtkAffineArray.h" // Real Superclass
#include "vtkCommonCoreModule.h"     // For export macro
#include "vtkDataArray.h"

// Fake the superclass for the wrappers.
#ifndef __VTK_WRAP__
#define vtkDataArray vtkAffineArray<int>
#endif
VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCORE_EXPORT vtkAffineIntArray : public vtkDataArray
{
public:
  vtkImplicitArrayTypeMacro(vtkAffineIntArray, vtkDataArray);
#ifndef __VTK_WRAP__
#undef vtkDataArray
#endif

  static vtkAffineIntArray* New();
  static vtkAffineIntArray* ExtendedNew();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // This macro expands to the set of method declarations that
  // make up the interface of vtkImplicitArray, which is ignored
  // by the wrappers.
#if defined(__VTK_WRAP__) || defined(__WRAP_GCCXML__)
  vtkCreateReadOnlyWrappedArrayInterface(int);
#endif

  /**
   * A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
   */
  static vtkAffineIntArray* FastDownCast(vtkAbstractArray* source)
  {
    return static_cast<vtkAffineIntArray*>(Superclass::FastDownCast(source));
  }

  /**
   * Set the parameters for the affine backend.
   * slope is the unit variation and intercept is the value at 0.
   * Value at index is:
   *   value = slope * index + intercept
   */
  void ConstructBackend(int slope, int intercept);

protected:
  vtkAffineIntArray();
  ~vtkAffineIntArray() override;

private:
  typedef vtkAffineArray<int> RealSuperclass;

  vtkAffineIntArray(const vtkAffineIntArray&) = delete;
  void operator=(const vtkAffineIntArray&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkAffineIntArray);

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: TYPEMACRO
