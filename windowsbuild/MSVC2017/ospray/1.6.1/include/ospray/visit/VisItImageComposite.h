// ======================================================================== //
// Copyright Qi WU                                                          //
//   Scientific Computing and Image Institution                             //
//   University of Utah                                                     //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //
// this file will be installed so can expose new functions to the users

#pragma once
#ifdef _WIN32
#  ifdef ospray_module_visit_common_EXPORTS
#    define OSPRAY_MODULE_VISIT_COMMON_INTERFACE __declspec(dllexport)
#  else
#    define OSPRAY_MODULE_VISIT_COMMON_INTERFACE __declspec(dllimport)
#  endif
#else
#  define OSPRAY_MODULE_VISIT_COMMON_INTERFACE OSPRAY_SDK_INTERFACE
#endif
namespace ospray {
namespace visit {
  
  extern "C" OSPRAY_MODULE_VISIT_COMMON_INTERFACE void Experiment();
  extern "C" OSPRAY_MODULE_VISIT_COMMON_INTERFACE void CompositeBackground(int*, int*, int, int, float *,
				      unsigned char *, float *,
				      unsigned char *&);
  extern "C" OSPRAY_MODULE_VISIT_COMMON_INTERFACE void BlendFrontToBack(const int   *blendExtents,
				   const int   *srcExtents,
				   const float *srcImage,
				   const int   *dstExtents,
				   float      *&dstImage);
  extern "C" OSPRAY_MODULE_VISIT_COMMON_INTERFACE void BlendBackToFront(const int   *blendExtents,
				   const int   *srcExtents,
				   const float *srcImage,
				   const int   *dstExtents,
				   float      *&dstImage);
};
};
