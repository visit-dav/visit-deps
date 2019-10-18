/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOSPRayFollowerNode.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOSPRayFollowerNode
 * @brief   links vtkFollower to OSPRay
 *
 * Translates vtkFollower state into OSPRay rendering calls
*/

#ifndef vtkOSPRayFollowerNode_h
#define vtkOSPRayFollowerNode_h

#include "vtkOSPRayActorNode.h"

class VTKRENDERINGOSPRAY_EXPORT vtkOSPRayFollowerNode :
  public vtkOSPRayActorNode
{
public:
  static vtkOSPRayFollowerNode* New();
  vtkTypeMacro(vtkOSPRayFollowerNode, vtkOSPRayActorNode);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Overridden to take into account my renderables time, including
   * its associated camera
   */
  virtual vtkMTimeType GetMTime() override;

protected:
  vtkOSPRayFollowerNode();
  ~vtkOSPRayFollowerNode();

private:
  vtkOSPRayFollowerNode(const vtkOSPRayFollowerNode&) = delete;
  void operator=(const vtkOSPRayFollowerNode&) = delete;
};
#endif
