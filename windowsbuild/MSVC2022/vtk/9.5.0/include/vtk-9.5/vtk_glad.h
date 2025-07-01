// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#ifndef vtk_glad_h
#define vtk_glad_h

/* Mobile device support. */
#define VTK_MODULE_vtkglad_GLES3 0

#if VTK_MODULE_vtkglad_GLES3
#include <GLES3/gl3.h>
#elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#include <OpenGLES/ES3/gl.h>
#else
#include <vtkglad/include/glad/gl.h>
#endif

/* some fixes for both ES 2 and 3 */
#if defined(GL_ES_VERSION_3_0) || defined(GL_ES_VERSION_2_0)
#define GL_BACK_LEFT GL_BACK
#define GL_BACK_RIGHT GL_BACK
#define GL_FRONT_LEFT GL_FRONT
#define GL_FRONT_RIGHT GL_FRONT

/* this sends all the data each time as opposed to allowing a subset */
#define glMultiDrawElements(mode, counts, type, indicies, primcount)                               \
  for (size_t eCount = 0; eCount < primcount; ++eCount)                                            \
  {                                                                                                \
    glDrawElements(mode, *(counts + eCount), type, (GLvoid*)(indicies[eCount]));                   \
  }
#endif

/*** deal with some GLES 3.0 specific issues ***/
#ifdef GL_ES_VERSION_3_0
#define GLAD_GL_ARB_vertex_array_object 1
#define GLAD_GL_ARB_instanced_arrays 1
#endif

#endif // vtk_glad_h
