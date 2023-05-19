#ifndef H5PART_EXPORTS_H
#define H5PART_EXPORTS_H

// Added by Kathleen Bonnell, LLNL, to produce a DLL H5Part library.

#ifdef _WIN32
  #ifdef H5PARTDLL_EXPORTS
    #define H5PART_API __declspec(dllexport)
  #else
    #define H5PART_API __declspec(dllimport)
  #endif
#else
  #define H5PART_API 
#endif

#endif

