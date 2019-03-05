/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOSPRayFollowerNode.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOSPRayFollowerNode.h"
#include "vtkCamera.h"
#include "vtkFollower.h"
#include "vtkObjectFactory.h"

//============================================================================
vtkStandardNewMacro(vtkOSPRayFollowerNode);

//----------------------------------------------------------------------------
vtkOSPRayFollowerNode::vtkOSPRayFollowerNode()
{
}

//----------------------------------------------------------------------------
vtkOSPRayFollowerNode::~vtkOSPRayFollowerNode()
{
}

//----------------------------------------------------------------------------
void vtkOSPRayFollowerNode::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//----------------------------------------------------------------------------
vtkMTimeType vtkOSPRayFollowerNode::GetMTime()
{
  vtkMTimeType mtime = this->Superclass::GetMTime();
  vtkCamera *cam = ((vtkFollower*)this->GetRenderable())->GetCamera();

  if (cam->GetMTime() > mtime)
  {
    mtime = cam->GetMTime();
  }

  return mtime;
}

