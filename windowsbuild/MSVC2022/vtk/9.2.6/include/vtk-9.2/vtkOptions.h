/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOptions.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtkOptions_h
#define vtkOptions_h

/* Whether vtkIdType is a 64-bit integer type (or a 32-bit integer type).  */
#define VTK_USE_64BIT_IDS

/* Whether MTime should use a 64-bit integer type on 32 bit builds.  */
#define VTK_USE_64BIT_TIMESTAMPS

/* Whether VTK_FUTURE_CONST should be defined as const or nothing.  */
#define VTK_USE_FUTURE_CONST 0

#endif
