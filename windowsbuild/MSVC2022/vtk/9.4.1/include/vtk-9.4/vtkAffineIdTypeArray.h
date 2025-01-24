// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkAffineIdTypeArray
 * @brief   affine implicit array of vtkIdType.
 *
 * vtkAffineIdTypeArray is an affine implicit array of values of type vtkIdType.
 * see vtkAffineArray, vtkAffineImplicitBackend
 *
 * This file is generated by vtkImplicitArrays.cmake
 */

#ifndef vtkAffineIdTypeArray_h
#define vtkAffineIdTypeArray_h

#include "vtkAffineArray.h" // Real Superclass
#include "vtkCommonCoreModule.h"     // For export macro
#include "vtkDataArray.h"

// Fake the superclass for the wrappers.
#ifndef __VTK_WRAP__
#define vtkDataArray vtkAffineArray<vtkIdType>
#endif
VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCORE_EXPORT vtkAffineIdTypeArray : public vtkDataArray
{
public:
  vtkImplicitArrayTypeMacro(vtkAffineIdTypeArray, vtkDataArray);
#ifndef __VTK_WRAP__
#undef vtkDataArray
#endif

  static vtkAffineIdTypeArray* New();
  static vtkAffineIdTypeArray* ExtendedNew();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // This macro expands to the set of method declarations that
  // make up the interface of vtkImplicitArray, which is ignored
  // by the wrappers.
#if defined(__VTK_WRAP__) || defined(__WRAP_GCCXML__)
  vtkCreateReadOnlyWrappedArrayInterface(vtkIdType);
#endif

  /**
   * A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
   */
  static vtkAffineIdTypeArray* FastDownCast(vtkAbstractArray* source)
  {
    return static_cast<vtkAffineIdTypeArray*>(Superclass::FastDownCast(source));
  }

  /**
   * Set the parameters for the affine backend.
   * slope is the unit variation and intercept is the value at 0.
   * Value at index is:
   *   value = slope * index + intercept
   */
  void ConstructBackend(vtkIdType slope, vtkIdType intercept);

protected:
  vtkAffineIdTypeArray();
  ~vtkAffineIdTypeArray() override;

private:
  typedef vtkAffineArray<vtkIdType> RealSuperclass;

  vtkAffineIdTypeArray(const vtkAffineIdTypeArray&) = delete;
  void operator=(const vtkAffineIdTypeArray&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkAffineIdTypeArray);

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: TYPEMACRO
