// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkAffineUnsignedCharArray
 * @brief   affine implicit array of unsigned char.
 *
 * vtkAffineUnsignedCharArray is an affine implicit array of values of type unsigned char.
 * see vtkAffineArray, vtkAffineImplicitBackend
 *
 * This file is generated by vtkImplicitArrays.cmake
 */

#ifndef vtkAffineUnsignedCharArray_h
#define vtkAffineUnsignedCharArray_h

#include "vtkAffineArray.h" // Real Superclass
#include "vtkCommonCoreModule.h"     // For export macro
#include "vtkDataArray.h"

// Fake the superclass for the wrappers.
#ifndef __VTK_WRAP__
#define vtkDataArray vtkAffineArray<unsigned char>
#endif
VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCORE_EXPORT vtkAffineUnsignedCharArray : public vtkDataArray
{
public:
  vtkImplicitArrayTypeMacro(vtkAffineUnsignedCharArray, vtkDataArray);
#ifndef __VTK_WRAP__
#undef vtkDataArray
#endif

  static vtkAffineUnsignedCharArray* New();
  static vtkAffineUnsignedCharArray* ExtendedNew();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // This macro expands to the set of method declarations that
  // make up the interface of vtkImplicitArray, which is ignored
  // by the wrappers.
#if defined(__VTK_WRAP__) || defined(__WRAP_GCCXML__)
  vtkCreateReadOnlyWrappedArrayInterface(unsigned char);
#endif

  /**
   * A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
   */
  static vtkAffineUnsignedCharArray* FastDownCast(vtkAbstractArray* source)
  {
    return static_cast<vtkAffineUnsignedCharArray*>(Superclass::FastDownCast(source));
  }

  /**
   * Set the parameters for the affine backend.
   * slope is the unit variation and intercept is the value at 0.
   * Value at index is:
   *   value = slope * index + intercept
   */
  void ConstructBackend(unsigned char slope, unsigned char intercept);

protected:
  vtkAffineUnsignedCharArray();
  ~vtkAffineUnsignedCharArray() override;

private:
  typedef vtkAffineArray<unsigned char> RealSuperclass;

  vtkAffineUnsignedCharArray(const vtkAffineUnsignedCharArray&) = delete;
  void operator=(const vtkAffineUnsignedCharArray&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkAffineUnsignedCharArray);

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: TYPEMACRO
