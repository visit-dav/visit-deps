// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#ifndef vtkVersionQuick_h
#define vtkVersionQuick_h

/* Note: this file is deliberately both valid C and valid C++. */

#define VTK_MAJOR_VERSION 9
#define VTK_MINOR_VERSION 4
#define VTK_EPOCH_VERSION 1

#define VTK_VERSION_CHECK(major, minor, build)                                                     \
  (10000000000ULL * major + 100000000ULL * minor + build)
#define VTK_VERSION_NUMBER_QUICK                                                                   \
  VTK_VERSION_CHECK(VTK_MAJOR_VERSION, VTK_MINOR_VERSION, VTK_EPOCH_VERSION)

#endif
