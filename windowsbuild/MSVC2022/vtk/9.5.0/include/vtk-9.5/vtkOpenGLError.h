// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#ifndef vtkOpenGLError_h
#define vtkOpenGLError_h

#include "vtkSetGet.h"
#include "vtk_glad.h"
#include <sstream>

#ifndef NDEBUG
// debug build.
/* #undef VTK_REPORT_OPENGL_ERRORS */
#else // NDEBUG
// release build
/* #undef VTK_REPORT_OPENGL_ERRORS_IN_RELEASE_BUILDS */
#if defined(VTK_REPORT_OPENGL_ERRORS_IN_RELEASE_BUILDS)
/* #undef VTK_REPORT_OPENGL_ERRORS */
#endif // defined(VTK_REPORT_OPENGL_ERRORS_IN_RELEASE_BUILDS)
#endif // NDEBUG

/**
 * The following functions can be used to detect and report, and/or
 * silently clear OpenGL error flags. These are not intended to be
 * used directly, instead use the following macros.
 *
 * vtkOpenGLClearErrorMacro() -- Silently clear OpenGL error flags.
 *
 * vtkOpenGLCheckErrorMacro(message) -- Check and clear OpenGL's error
 * flags. Report errors detected via vtkErrorMacro.
 *
 * vtkOpenGLStaticCheckErrorMacro(message) -- Check and clear OpenGL's
 * error flags. Report errors detected via vtkGenericWarningMacro.
 * This may be used in static methods and outside of vtkObjects.
 *
 * The intended usage pattern is to 1) call vtkOpenGLClearErrorMacro
 * at the top of, and 2) vtkOpenGLCheckErrorMacro at the bottom of
 * methods that make OpenGL calls.
 *
 * By calling vtkOpenGLClearErrorMacro at the top of a method that
 * makes OpenGL calls, you isolate the code and prevent it from
 * detecting any preceding errors. By calling vtkOpenGLCheckErrorMacro
 * at the bottom of the method you clear the error flags and report
 * any errors that have occurred in the method where they occurred.
 *
 * The macros maybe completely disabled via the CMakeLists variable
 * VTK_REPORT_OPENGL_ERRORS. Note that in that case error flags are
 * never cleared so that if an error occurs the flags will remain dirty
 * making it impossible for anyone else to use them reliably. Please
 * don't disable them with out a good reason.
 */

/**
 * Convert an OpenGL error code into a descriptive
 * string.
 */
VTK_ABI_NAMESPACE_BEGIN
inline
const char *vtkOpenGLStrError(unsigned int code)
{
  switch(static_cast<GLenum>(code))
  {
    case GL_NO_ERROR:
      return "No error";
    case GL_INVALID_ENUM:
      return "Invalid enum";
    case GL_INVALID_VALUE:
      return "Invalid value";
    case GL_INVALID_OPERATION:
      return "Invalid operation";
    case GL_OUT_OF_MEMORY:
      return "Out of memory";
#ifndef GL_ES_VERSION_3_0
    case GL_STACK_OVERFLOW:
      return "Stack overflow";
    case GL_STACK_UNDERFLOW:
      return "Stack underflow";
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      return "Invalid framebuffer operation";
#endif
  }
  return "Unknown error";
}

/**
 * Check for OpenGL errors. Error status is queried until
 * OpenGL reports no errors. The list of errors and their
 * descriptions are returned in the user supplied arrays.
 * User passes the size of the arrays as the first argument.
 * Error flags will still be cleared if the user arrays are
 * less than the number of errors.
 */
#if defined(VTK_REPORT_OPENGL_ERRORS)
inline
int vtkGetOpenGLErrors(
      int maxNum,
      unsigned int *errCode,
      const char **errDesc)
{
  int i = 0;
  GLenum code = glGetError();
  if (i < maxNum)
  {
    errCode[i] = static_cast<unsigned int>(code);
    errDesc[i] = vtkOpenGLStrError(code);
  }
  while (code != GL_NO_ERROR && i < maxNum)
  {
    i++;
    code = glGetError();
    if (i < maxNum)
    {
      errCode[i] = static_cast<unsigned int>(code);
      errDesc[i] = vtkOpenGLStrError(code);
    }
  }
  return i;
}
#else
inline
int vtkGetOpenGLErrors(
      int maxNum,
      unsigned int *errCode,
      const char **errDesc)
{
  (void)maxNum;
  (void)errCode;
  (void)errDesc;
  return 0;
}
#endif

/**
 * Send a set of errors collected by GetOpenGLErrors
 * to the give stream. The number of errors is obtained
 * in the return value of GetOpenGLErrors, while the max
 * errors gives the size of the error arrays.
 */
#if defined(VTK_REPORT_OPENGL_ERRORS)
inline
void vtkPrintOpenGLErrors(
      ostream &os,
      int maxErrors,
      int numErrors,
      unsigned int *errCode,
      const char **errDesc)
{
  os << numErrors << " OpenGL errors detected" << std::endl;
  for (int i=0; (i<numErrors)&&(i<maxErrors); ++i)
  {
    os << "  " <<  i << " : (" << errCode[i] << ") " << errDesc[i] << std::endl;
  }
  if (numErrors>maxErrors)
  {
    os
      << "More than " << maxErrors
      << " detected! The remainder are not reported"
      << std::endl;
  }
}
#else
inline
void vtkPrintOpenGLErrors(
      ostream &os,
      int maxErrors,
      int numErrors,
      unsigned int *errCode,
      const char **errDesc)
{
  (void)os;
  (void)maxErrors;
  (void)numErrors;
  (void)errCode;
  (void)errDesc;
}
#endif

/**
 * Errors are queried and reported via vtkGenericWarningMacro. An optional
 * header message can be appended to the stream. Returns true if no errors
 * were reported.
 */
#if defined(VTK_REPORT_OPENGL_ERRORS)
inline
bool vtkOpenGLCheckErrors(const char* headerMessage = "")
{
  const int maxNumErrors = 16;
  unsigned int errCode[maxNumErrors] = {0};
  const char* errDesc[maxNumErrors] = {nullptr};
  int numErrors = vtkGetOpenGLErrors(maxNumErrors, errCode, errDesc);
  if (numErrors > 0)
  {
    std::ostringstream oss;
    vtkPrintOpenGLErrors(oss, maxNumErrors, numErrors, errCode, errDesc);
    vtkGenericWarningMacro(<< headerMessage << oss.str());
    return false;
  }
  return true;
}
#else
inline
bool vtkOpenGLCheckErrors(const char* errorMessage = "")
{
  (void)errorMessage;
  return true;
}
#endif

/**
 * Clear OpenGL's error flags.
 */
#if defined(VTK_REPORT_OPENGL_ERRORS)
inline
void vtkClearOpenGLErrors(const unsigned int maxErrors = 16)
{
  GLenum glError;
  unsigned int i = 0;
  do
  {
    glError = glGetError();
    ++i;
  }
  while(i < maxErrors && glError != GL_NO_ERROR);
}
#else
inline
void vtkClearOpenGLErrors(const unsigned int maxErrors = 16)
{
  (void) maxErrors;
}
#endif

#if !defined(VTK_REPORT_OPENGL_ERRORS)
# define vtkOpenGLClearErrorMacro() do {} while (false)
# define vtkOpenGLCheckErrorMacro(message)
# define vtkOpenGLStaticCheckErrorMacro(message)
#else
#define vtkOpenGLClearErrorMacro()                                                                 \
  do                                                                                               \
  {                                                                                                \
    vtkClearOpenGLErrors(16);                                                                      \
  }                                                                                                \
  while (false)
# include <sstream> // for error macro
# define vtkOpenGLCheckErrorMacroImpl(ostr, message) \
do                                                   \
{                                                    \
  const int maxErrors = 16;                          \
  unsigned int errCode[maxErrors] = {0};             \
  const char *errDesc[maxErrors] = {nullptr};        \
                                                     \
  int numErrors                                      \
    = vtkGetOpenGLErrors(                            \
        maxErrors,                                   \
        errCode,                                     \
        errDesc);                                    \
                                                     \
  if (numErrors)                                     \
  {                                                  \
    std::ostringstream oss;                          \
    vtkPrintOpenGLErrors(                            \
          oss,                                       \
          maxErrors,                                 \
          numErrors,                                 \
          errCode,                                   \
          errDesc);                                  \
                                                     \
    ostr(<< message << " " << oss.str());            \
  }                                                  \
} while(false)
# define vtkOpenGLCheckErrorMacro(message) \
  vtkOpenGLCheckErrorMacroImpl(vtkErrorMacro, message)
# define vtkOpenGLStaticCheckErrorMacro(message) \
  vtkOpenGLCheckErrorMacroImpl(vtkGenericWarningMacro, message)
#endif

// Use this macro for fine grained error checking during
// debugging. It is removed for Release builds.
#ifdef NDEBUG
# define vtkOpenGLDebugClearErrorMacro()
# define vtkOpenGLDebugCheckErrorMacro(message)
#else
# define vtkOpenGLDebugClearErrorMacro() \
  vtkOpenGLClearErrorMacro()
# define vtkOpenGLDebugCheckErrorMacro(message) \
  vtkOpenGLStaticCheckErrorMacro(message)
#endif

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: vtkOpenGLError.h
