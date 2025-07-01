// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#ifndef vtkABINamespace_h
#define vtkABINamespace_h

#define VTK_HAS_ABI_NAMESPACE 0

#if !defined(VTK_NO_ABI_NAMESPACE) && VTK_HAS_ABI_NAMESPACE
// NOTE: VTK_ABI_NAMESPACE_NAME is only characters [a-zA-Z0-9_]+, so it is safe
// to use in the MANGLE macro beneath.  We use the VTK_ABI_NAMESPACE_MANGLE to
// mangle C symbols coming from VTK (e.g., extern "C" { void some_func(); }).
#define VTK_ABI_NAMESPACE_NAME 
#define VTK_ABI_NAMESPACE_MANGLE(x) _##x

#if defined(__cplusplus)
#define VTK_ABI_NAMESPACE_BEGIN 
#define VTK_ABI_NAMESPACE_END 
#else
#define VTK_ABI_NAMESPACE_BEGIN
#define VTK_ABI_NAMESPACE_END
#endif

#else

#define VTK_ABI_NAMESPACE_MANGLE(x) x
#define VTK_ABI_NAMESPACE_BEGIN
#define VTK_ABI_NAMESPACE_END

#endif // VTK_NO_ABI_NAMESPACE

#endif // vtkABINamespace_h
