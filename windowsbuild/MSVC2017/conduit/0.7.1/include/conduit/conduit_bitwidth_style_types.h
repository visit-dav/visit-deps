// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_bitwidth_style_types.h
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_BITWIDTH_STYLE_TYPES_H
#define CONDUIT_BITWIDTH_STYLE_TYPES_H

#include "conduit_config.h"
#include <limits.h>

//-----------------------------------------------------------------------------
// byte len of native types
//-----------------------------------------------------------------------------

#define CONDUIT_SIZEOF_BYTE        1

#define CONDUIT_SIZEOF_CHAR        1
#define CONDUIT_SIZEOF_SHORT       2
#define CONDUIT_SIZEOF_INT         4
#define CONDUIT_SIZEOF_LONG        4
#define CONDUIT_SIZEOF_LONG_LONG   8

#define CONDUIT_SIZEOF_FLOAT       4
#define CONDUIT_SIZEOF_DOUBLE      8
#define CONDUIT_SIZEOF_LONG_DOUBLE 8

#define CONDUIT_SIZEOF_VOID_P      8

// defines that let us know if the compiler supports long long and long double
#define CONDUIT_HAS_LONG_LONG      1
#define CONDUIT_HAS_LONG_DOUBLE    1


// defines that let us know which types are used to support for our menu of
// bit-width style types
#define CONDUIT_USE_CHAR           1
#define CONDUIT_USE_SHORT          1
#define CONDUIT_USE_INT            1
/* #undef CONDUIT_USE_LONG */

#define CONDUIT_USE_FLOAT          1
#define CONDUIT_USE_DOUBLE         1

#define CONDUIT_USE_LONG_LONG      1
/* #undef CONDUIT_USE_LONG_DOUBLE */

//-----------------------------------------------------------------------------
// unsigned native types
//-----------------------------------------------------------------------------

typedef unsigned char       conduit_unsigned_char;
typedef unsigned short      conduit_unsigned_short;
typedef unsigned int        conduit_unsigned_int;
typedef unsigned long       conduit_unsigned_long;

#ifdef CONDUIT_HAS_LONG_LONG
typedef unsigned long long  conduit_unsigned_long_long;
#endif

//-----------------------------------------------------------------------------
// signed native types
//-----------------------------------------------------------------------------

typedef signed char         conduit_signed_char;
typedef signed short        conduit_signed_short;
typedef signed int          conduit_signed_int;
typedef signed long         conduit_signed_long;

#ifdef CONDUIT_HAS_LONG_LONG
typedef signed long long    conduit_signed_long_long;
#endif

//-----------------------------------------------------------------------------
// floating point native types
//-----------------------------------------------------------------------------

typedef float               conduit_float;
typedef double              conduit_double;

#if CONDUIT_SIZEOF_LONG_DOUBLE == CONDUIT_SIZEOF_DOUBLE
        typedef double conduit_long_double;
#else
#ifdef CONDUIT_HAS_LONG_DOUBLE
        typedef long double conduit_long_double;
#endif
#endif


//-----------------------------------------------------------------------------
//  signed vs unsigned determination
//-----------------------------------------------------------------------------

// --- char -- //
// char can be signed or unsigned
#ifndef CHAR_MIN
#error Bitwidth Style Types: native mapping requires CHAR_MIN def
#endif


#if (CHAR_MIN==0)
#define CONDUIT_CHAR_IS_UNSIGNED
#else
#define CONDUIT_CHAR_IS_SIGNED
#endif

// per standard, the rest of types w/o
// signed-ness should never be unsigned

// --- short -- //
#ifndef SHRT_MIN
#error Bitwidth Style Types: native mapping requires SHRT_MIN def
#endif

#if (SHRT_MIN==0)
#define CONDUIT_SHORT_IS_UNSIGNED
#else
#define CONDUIT_SHORT_IS_SIGNED
#endif

// --- int -- //
#ifndef INT_MIN
#error Bitwidth Style Types: native mapping requires INT_MIN def
#endif

#if (INT_MIN==0)
#define CONDUIT_INT_IS_UNSIGNED
#else
#define CONDUIT_INT_IS_SIGNED
#endif

// --- long -- //
#ifndef LONG_MIN
#error Bitwidth Style Types: native mapping requires LONG_MIN def
#endif

#if (LONG_MIN==0)
#define CONDUIT_LONG_IS_UNSIGNED
#else
#define CONDUIT_LONG_IS_SIGNED
#endif

// --- long long -- //
#ifdef CONDUIT_HAS_LONG_LONG

#ifndef LLONG_MIN
#error Bitwidth Style Types: native mapping requires LLONG_MIN def
#endif

#if (LLONG_MIN==0)
#define CONDUIT_LONG_LONG_IS_UNSIGNED
#else
#define CONDUIT_LONG_LONG_IS_SIGNED
#endif

#endif


#if defined(CONDUIT_CHAR_IS_UNSIGNED)
typedef conduit_unsigned_char conduit_char;
#else
typedef conduit_signed_char   conduit_char;
#endif

typedef conduit_signed_short  conduit_short;
typedef conduit_signed_int    conduit_int;
typedef conduit_signed_long   conduit_long;

#ifdef CONDUIT_HAS_LONG_LONG
typedef conduit_signed_long_long  conduit_long_long;
#endif

/*-----------------------------------------------------------------------------
/ conduit_datatype_type_id is an Enumeration used to describe the type
/ roles supported by conduit:
-----------------------------------------------------------------------------*/
typedef enum
{
    CONDUIT_EMPTY_ID  = 0,  // empty (default type)
    CONDUIT_OBJECT_ID = 1, // object
    CONDUIT_LIST_ID   = 2,   // list
    /* signed integer types */
    CONDUIT_INT8_ID  = 3,   // int8 and int8_array
    CONDUIT_INT16_ID = 4,  // int16 and int16_array
    CONDUIT_INT32_ID = 5,  // int32 and int32_array
    CONDUIT_INT64_ID = 6,  // int64 and int64_array
    /* unsigned integer types */
    CONDUIT_UINT8_ID  = 7,  // int8 and int8_array
    CONDUIT_UINT16_ID = 8, // uint16 and uint16_array
    CONDUIT_UINT32_ID = 9, // uint32 and uint32_array
    CONDUIT_UINT64_ID = 10, // uint64 and uint64_array
    /* floating point integer types */
    CONDUIT_FLOAT32_ID = 11, // float32 and float32_array
    CONDUIT_FLOAT64_ID = 12, // float64 and float64_array
    /* string  types */
    CONDUIT_CHAR8_STR_ID = 13 // char8 string (incore c-string)
} conduit_datatype_type_id;



//-----------------------------------------------------------------------------
// -- bitwidth style signed integer types --
//-----------------------------------------------------------------------------
typedef conduit_signed_char  conduit_int8;
typedef conduit_signed_short conduit_int16;
typedef conduit_signed_int conduit_int32;
typedef conduit_signed_long_long conduit_int64;

// string defs
#define CONDUIT_INT8_NATIVE_NAME  "signed char"
#define CONDUIT_INT16_NATIVE_NAME "signed short"
#define CONDUIT_INT32_NATIVE_NAME "signed int"
#define CONDUIT_INT64_NATIVE_NAME "signed long long"

//-----------------------------------------------------------------------------
// -- bitwidth style unsigned integer types --
//-----------------------------------------------------------------------------
typedef conduit_unsigned_char  conduit_uint8;
typedef conduit_unsigned_short conduit_uint16;
typedef conduit_unsigned_int conduit_uint32;
typedef conduit_unsigned_long_long conduit_uint64;

// string defs
#define CONDUIT_UINT8_NATIVE_NAME  "unsigned char"
#define CONDUIT_UINT16_NATIVE_NAME "unsigned short"
#define CONDUIT_UINT32_NATIVE_NAME "unsigned int"
#define CONDUIT_UINT64_NATIVE_NAME "unsigned long long"


//-----------------------------------------------------------------------------
// -- bitwidth style floating point types
//-----------------------------------------------------------------------------
typedef conduit_float conduit_float32;
typedef conduit_double conduit_float64;

// string defs
#define CONDUIT_FLOAT32_NATIVE_NAME "float"
#define CONDUIT_FLOAT64_NATIVE_NAME "double"


//-----------------------------------------------------------------------------
// -- c style signed integer type maps --
//-----------------------------------------------------------------------------
#define CONDUIT_NATIVE_SIGNED_CHAR  conduit_int8
#define CONDUIT_NATIVE_SIGNED_SHORT conduit_int16
#define CONDUIT_NATIVE_SIGNED_INT   conduit_int32
#define CONDUIT_NATIVE_SIGNED_LONG  conduit_int32
#if defined(CONDUIT_HAS_LONG_LONG)
#define CONDUIT_NATIVE_SIGNED_LONG_LONG  conduit_int64
#endif

#define CONDUIT_NATIVE_SIGNED_CHAR_ID  3
#define CONDUIT_NATIVE_SIGNED_SHORT_ID 4
#define CONDUIT_NATIVE_SIGNED_INT_ID   5
#define CONDUIT_NATIVE_SIGNED_LONG_ID  5
#if defined(CONDUIT_HAS_LONG_LONG)
#define CONDUIT_NATIVE_SIGNED_LONG_LONG_ID  6
#endif

//-----------------------------------------------------------------------------
// -- c style unsigned integer type maps --
//-----------------------------------------------------------------------------
#define CONDUIT_NATIVE_UNSIGNED_CHAR  conduit_uint8
#define CONDUIT_NATIVE_UNSIGNED_SHORT conduit_uint16
#define CONDUIT_NATIVE_UNSIGNED_INT   conduit_uint32
#define CONDUIT_NATIVE_UNSIGNED_LONG  conduit_uint32
#if defined(CONDUIT_HAS_LONG_LONG)
#define CONDUIT_NATIVE_UNSIGNED_LONG_LONG  conduit_uint64
#endif

#define CONDUIT_NATIVE_UNSIGNED_CHAR_ID  7
#define CONDUIT_NATIVE_UNSIGNED_SHORT_ID 8
#define CONDUIT_NATIVE_UNSIGNED_INT_ID   9
#define CONDUIT_NATIVE_UNSIGNED_LONG_ID  9
#if defined(CONDUIT_HAS_LONG_LONG)
#define CONDUIT_NATIVE_UNSIGNED_LONG_LONG_ID  10
#endif

//-----------------------------------------------------------------------------
// -- c style unsigned integer type maps --
//-----------------------------------------------------------------------------
#if defined(CONDUIT_CHAR_IS_UNSIGNED)
#define CONDUIT_NATIVE_CHAR  CONDUIT_NATIVE_UNSIGNED_CHAR
#else
#define CONDUIT_NATIVE_CHAR  CONDUIT_NATIVE_SIGNED_CHAR
#endif

#define CONDUIT_NATIVE_SHORT CONDUIT_NATIVE_SIGNED_SHORT
#define CONDUIT_NATIVE_INT   CONDUIT_NATIVE_SIGNED_INT
#define CONDUIT_NATIVE_LONG  CONDUIT_NATIVE_SIGNED_LONG
#if defined(CONDUIT_HAS_LONG_LONG)
#define CONDUIT_NATIVE_LONG_LONG  CONDUIT_NATIVE_SIGNED_LONG_LONG
#endif

#if defined(CONDUIT_CHAR_IS_UNSIGNED)
#define CONDUIT_NATIVE_CHAR_ID  CONDUIT_NATIVE_UNSIGNED_CHAR_ID
#else
#define CONDUIT_NATIVE_CHAR_ID  CONDUIT_NATIVE_SIGNED_CHAR_ID
#endif

#define CONDUIT_NATIVE_SHORT_ID CONDUIT_NATIVE_SIGNED_SHORT_ID
#define CONDUIT_NATIVE_INT_ID   CONDUIT_NATIVE_SIGNED_INT_ID
#define CONDUIT_NATIVE_LONG_ID  CONDUIT_NATIVE_SIGNED_LONG_ID
#if defined(CONDUIT_HAS_LONG_LONG)
#define CONDUIT_NATIVE_LONG_LONG_ID  6
#endif


//-----------------------------------------------------------------------------
// -- c style floating point type maps --
//-----------------------------------------------------------------------------
#define CONDUIT_NATIVE_FLOAT   conduit_float32
#define CONDUIT_NATIVE_DOUBLE  conduit_float64
#if defined(CONDUIT_USE_LONG_DOUBLE)
#define CONDUIT_NATIVE_LONG_DOUBLE  conduit_float64
#endif

#define CONDUIT_NATIVE_FLOAT_ID  11
#define CONDUIT_NATIVE_DOUBLE_ID  12
#if defined(CONDUIT_USE_LONG_DOUBLE)
#define CONDUIT_NATIVE_LONG_DOUBLE_ID  12
#endif


//-----------------------------------------------------------------------------
/// Index Types
//-----------------------------------------------------------------------------

/// index typedefs
typedef conduit_int32 conduit_index32_t;
typedef conduit_int64 conduit_index64_t;

/// use a 64-bit index, unless CONDUIT_INDEX_32 is defined.
#ifdef CONDUIT_INDEX_32
typedef conduit_index32_t conduit_index_t;
#else
typedef conduit_index64_t conduit_index_t;
#endif 

//-----------------------------------------------------------------------------
/// Bit-width type map sanity checks
//-----------------------------------------------------------------------------

//
// check that we were able to resolve all of the bitwidth style types we want
// to support

// signed int
#ifndef CONDUIT_INT8_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to int8
#endif

#ifndef CONDUIT_INT16_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to int16
#endif

#ifndef CONDUIT_INT32_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to int32
#endif

#ifndef CONDUIT_INT64_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to int64
#endif

// unsigned ints
#ifndef CONDUIT_UINT8_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to uint8
#endif

#ifndef CONDUIT_UINT16_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to uint16
#endif

#ifndef CONDUIT_UINT32_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to uint32
#endif

#ifndef CONDUIT_UINT64_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to uint64
#endif

// floating points numbers
#ifndef CONDUIT_FLOAT32_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to float32
#endif

#ifndef CONDUIT_FLOAT64_NATIVE_NAME
#error Bitwidth Style Types: no native type found that maps to float64
#endif

//-----------------------------------------------------------------------------
///End Bit-width type map sanity checks
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Native type map sanity checks
//-----------------------------------------------------------------------------

//
// check that we have a mapping for all base native types to conduit types
//

// native ints
#ifndef CONDUIT_NATIVE_CHAR
#error C-Style Types: no conduit type found that maps to char
#endif

#ifndef CONDUIT_NATIVE_SHORT
#error C-Style Types: no conduit type found that maps to short
#endif

#ifndef CONDUIT_NATIVE_INT
#error C-Style Types: no conduit type found that maps to int
#endif

#ifndef CONDUIT_NATIVE_LONG
#error C-Style Types: no conduit type found that maps to long
#endif

#if defined(CONDUIT_HAS_LONG_LONG)
#ifndef CONDUIT_NATIVE_LONG_LONG
#error C-Style Types: no conduit type found that maps to long long
#endif
#endif

// signed ints
#ifndef CONDUIT_NATIVE_SIGNED_CHAR
#error C-Style Types: no conduit type found that maps to signed char
#endif

#ifndef CONDUIT_NATIVE_SIGNED_SHORT
#error C-Style Types: no conduit type found that maps to signed short
#endif

#ifndef CONDUIT_NATIVE_SIGNED_INT
#error C-Style Types: no conduit type found that maps to signed int
#endif

#ifndef CONDUIT_NATIVE_SIGNED_LONG
#error C-Style Types: no conduit type found that maps to signed long
#endif

#if defined(CONDUIT_HAS_LONG_LONG)
#ifndef CONDUIT_NATIVE_SIGNED_LONG_LONG
#error C-Style Types: no conduit type found that maps to signed long long
#endif
#endif

// unsigned ints
#ifndef CONDUIT_NATIVE_UNSIGNED_CHAR
#error C-Style Types: no conduit type found that maps to unsigned char
#endif

#ifndef CONDUIT_NATIVE_UNSIGNED_SHORT
#error C-Style Types: no conduit type found that maps to unsigned short
#endif

#ifndef CONDUIT_NATIVE_UNSIGNED_INT
#error C-Style Types: no conduit type found that maps to unsigned int
#endif

#ifndef CONDUIT_NATIVE_UNSIGNED_LONG
#error C-Style Types: no conduit type found that maps to unsigned long
#endif

#if defined(CONDUIT_HAS_LONG_LONG)
#ifndef CONDUIT_NATIVE_UNSIGNED_LONG_LONG
#error C-Style Types: no conduit type found that maps to unsigned long long
#endif
#endif


// native ints
#ifndef CONDUIT_NATIVE_CHAR
#error C-Style Types: no conduit type found that maps to char
#endif

#ifndef CONDUIT_NATIVE_SHORT
#error C-Style Types: no conduit type found that maps to short
#endif

#ifndef CONDUIT_NATIVE_INT
#error C-Style Types: no conduit type found that maps to int
#endif

#ifndef CONDUIT_NATIVE_LONG
#error C-Style Types: no conduit type found that maps to long
#endif

#if defined(CONDUIT_HAS_LONG_LONG)
#ifndef CONDUIT_NATIVE_LONG_LONG
#error C-Style Types: no conduit type found that maps to long long
#endif
#endif

// floating points numbers
#ifndef CONDUIT_NATIVE_FLOAT
#error C-Style Types: no conduit type found that maps to float
#endif

#ifndef CONDUIT_NATIVE_DOUBLE
#error C-Style Types: no conduit type found that maps to double
#endif

//-----------------------------------------------------------------------------
///End Bit-width type map sanity checks
//-----------------------------------------------------------------------------


#endif

