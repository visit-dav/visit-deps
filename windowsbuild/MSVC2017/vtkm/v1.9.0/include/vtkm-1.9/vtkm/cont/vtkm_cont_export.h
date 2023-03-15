//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
#ifndef VTKM_CONT_EXPORT_H
#define VTKM_CONT_EXPORT_H

#if defined(_MSC_VER)
# if 1
    /* This is a static component and has no need for exports
       elf based static libraries are able to have hidden/default visibility
       controls on symbols so we should propagate this information in that
       use case
    */
#   define VTKM_CONT_EXPORT_DEFINE
#   define VTKM_CONT_IMPORT_DEFINE
#   define VTKM_CONT_NO_EXPORT_DEFINE
# else
#   define VTKM_CONT_EXPORT_DEFINE __declspec(dllexport)
#   define VTKM_CONT_IMPORT_DEFINE __declspec(dllimport)
#   define VTKM_CONT_NO_EXPORT_DEFINE
# endif
#else
#   define VTKM_CONT_EXPORT_DEFINE __attribute__((visibility("default")))
#   define VTKM_CONT_IMPORT_DEFINE __attribute__((visibility("default")))
#   define VTKM_CONT_NO_EXPORT_DEFINE __attribute__((visibility("hidden")))
#endif

#ifndef VTKM_CONT_EXPORT
# if defined(vtkm_cont_EXPORTS)
    /* We are building this library */
#   define VTKM_CONT_EXPORT VTKM_CONT_EXPORT_DEFINE
# else
    /* We are using this library */
#   define VTKM_CONT_EXPORT VTKM_CONT_IMPORT_DEFINE
# endif
#endif

#ifndef VTKM_CONT_TEMPLATE_EXPORT
# if defined(vtkm_cont_EXPORTS) && defined(_MSC_VER)
  /* Warning C4910 on windows state that extern explicit template can't be
     labeled with __declspec(dllexport). So that is why we use a new custom
     define. But when other modules ( e.g. rendering ) include this header
     we need them to see that the extern template is actually being imported.
  */
    /* We are building this library with MSVC */
#   define VTKM_CONT_TEMPLATE_EXPORT
# elif defined(vtkm_cont_EXPORTS)
    /* We are building this library */
#   define VTKM_CONT_TEMPLATE_EXPORT VTKM_CONT_EXPORT_DEFINE
# else
    /* We are using this library */
#   define VTKM_CONT_TEMPLATE_EXPORT VTKM_CONT_IMPORT_DEFINE
# endif
#endif

#ifndef VTKM_CONT_NO_EXPORT
  #define VTKM_CONT_NO_EXPORT VTKM_CONT_NO_EXPORT_DEFINE
#endif

#endif
