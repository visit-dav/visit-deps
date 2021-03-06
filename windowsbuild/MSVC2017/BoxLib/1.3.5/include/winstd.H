
#ifndef _WINSTD_H_
#define _WINSTD_H_

// This files 'fixes' MSVC 6 so that it is more like real C++.
#if defined(WIN32) && !defined(__MINGW32__)
// The STL and template classes in general will yield symbols greater
// than 256 chars, which are truncated; this suppresses the CL
// warning.
#pragma warning(disable:4786)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstddef>

typedef int mode_t;
typedef int pid_t;

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
//#undef max
//#undef min
#undef abs

// Place some globals in the standard namespace, where they belong
namespace std
{
template <class T> inline T min(const T& l, const T& r) { return (l<r)?l:r; }
template <class T> inline T max(const T& l, const T& r) { return (l<r)?r:l; }
template <class T> inline T abs(const T& r) { return (r<0)?-r:r; }

using ::pow;
using ::fabs;
using ::sqrt;
using ::exp;
using ::log;
using ::log10;
using ::sin;
using ::cos;
using ::tan;
using ::asin;
using ::acos;
using ::atan;
using ::sinh;
using ::cosh;
using ::tanh;
using ::floor;
using ::ceil;
using ::fmod;
using ::frexp;
using ::ldexp;
using ::modf;

using ::exit;
using ::abort;

using ::strerror;
using ::sprintf;

using ::size_t;
}
#endif
#endif

#if defined( BL_SUPERUX)
namespace std
{
template <class T> inline T abs(const T& r) { return (r<0)?-r:r; }
}
#endif
#if defined( BL_OSF1 )
namespace std
{
template <class T> inline T abs(const T& r) { return (r<0)?-r:r; }
}
#endif
#endif
