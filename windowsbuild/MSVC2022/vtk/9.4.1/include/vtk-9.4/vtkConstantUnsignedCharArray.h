// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkConstantUnsignedCharArray
 * @brief   constant implicit array of unsigned char.
 *
 * vtkConstantUnsignedCharArray is a constant implicit array of values of type unsigned char.
 * see vtkConstantArray, vtkConstantImplicitBackend
 *
 * This file is generated by vtkImplicitArrays.cmake
 */

#ifndef vtkConstantUnsignedCharArray_h
#define vtkConstantUnsignedCharArray_h

#include "vtkConstantArray.h" // Real Superclass
#include "vtkCommonCoreModule.h"     // For export macro
#include "vtkDataArray.h"

// Fake the superclass for the wrappers.
#ifndef __VTK_WRAP__
#define vtkDataArray vtkConstantArray<unsigned char>
#endif
VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCORE_EXPORT vtkConstantUnsignedCharArray : public vtkDataArray
{
public:
  vtkImplicitArrayTypeMacro(vtkConstantUnsignedCharArray, vtkDataArray);
#ifndef __VTK_WRAP__
#undef vtkDataArray
#endif

  // This macro expands to the set of method declarations that
  // make up the interface of vtkAOSDataArrayTemplate, which is ignored
  // by the wrappers.
#if defined(__VTK_WRAP__) || defined(__WRAP_GCCXML__)
  vtkCreateReadOnlyWrappedArrayInterface(unsigned char);
#endif

  static vtkConstantUnsignedCharArray* New();
  static vtkConstantUnsignedCharArray* ExtendedNew();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // This macro expands to the set of method declarations that
  // make up the interface of vtkImplicitArray, which is ignored
  // by the wrappers.

  /**
   * A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
   */
  static vtkConstantUnsignedCharArray* FastDownCast(vtkAbstractArray* source)
  {
    return static_cast<vtkConstantUnsignedCharArray*>(Superclass::FastDownCast(source));
  }

  /**
   * Set the constant value for this array.
   */
  void ConstructBackend(unsigned char value);

protected:
  vtkConstantUnsignedCharArray();
  ~vtkConstantUnsignedCharArray() override;

private:
  typedef vtkConstantArray<unsigned char> RealSuperclass;

  vtkConstantUnsignedCharArray(const vtkConstantUnsignedCharArray&) = delete;
  void operator=(const vtkConstantUnsignedCharArray&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkConstantUnsignedCharArray);

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: TYPEMACRO
