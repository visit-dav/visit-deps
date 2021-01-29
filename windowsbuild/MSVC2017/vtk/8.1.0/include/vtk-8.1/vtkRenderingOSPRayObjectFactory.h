/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkRenderingOSPRayObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkRenderingOSPRayObjectFactory_h
#define vtkRenderingOSPRayObjectFactory_h

#include "vtkRenderingOSPRayModule.h" // For export macro
#include "vtkObjectFactory.h"

class VTKRENDERINGOSPRAY_EXPORT vtkRenderingOSPRayObjectFactory : public vtkObjectFactory
{
public:
  static vtkRenderingOSPRayObjectFactory * New();
  vtkTypeMacro(vtkRenderingOSPRayObjectFactory, vtkObjectFactory)

  const char * GetDescription() override { return "vtkRenderingOSPRay factory overrides."; }

  const char * GetVTKSourceVersion() override;

  void PrintSelf(ostream &os, vtkIndent indent) override;

protected:
  vtkRenderingOSPRayObjectFactory();

private:
  vtkRenderingOSPRayObjectFactory(const vtkRenderingOSPRayObjectFactory&) = delete;
  void operator=(const vtkRenderingOSPRayObjectFactory&) = delete;
};

#endif // vtkRenderingOSPRayObjectFactory_h
