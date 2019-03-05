//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2014-2018, Lawrence Livermore National Security, LLC.
// 
// Produced at the Lawrence Livermore National Laboratory
// 
// LLNL-CODE-666778
// 
// All rights reserved.
// 
// This file is part of Conduit. 
// 
// For details, see: http://software.llnl.gov/conduit/.
// 
// Please also read conduit/LICENSE
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice, 
//   this list of conditions and the disclaimer below.
// 
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the disclaimer (as noted below) in the
//   documentation and/or other materials provided with the distribution.
// 
// * Neither the name of the LLNS/LLNL nor the names of its contributors may
//   be used to endorse or promote products derived from this software without
//   specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
// LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//-----------------------------------------------------------------------------
///
/// file: Bitwidth_Style_Types.hpp
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_BITWIDTH_STYLE_TYPES_H
#define CONDUIT_BITWIDTH_STYLE_TYPES_H

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
// native types
//-----------------------------------------------------------------------------

typedef signed char         conduit_byte;
typedef unsigned char       conduit_ubyte;
typedef unsigned short      conduit_ushort;
typedef unsigned int        conduit_uint;
typedef unsigned long       conduit_ulong;

#ifdef CONDUIT_HAS_LONG_LONG
typedef unsigned long long  conduit_ulong_long;
#endif

typedef char                conduit_char;
typedef short               conduit_short;
typedef int                 conduit_int;
typedef long                conduit_long;

#ifdef CONDUIT_HAS_LONG_LONG
typedef long long           conduit_long_long;
#endif

typedef float               conduit_float;
typedef double              conduit_double;

#if CONDUIT_SIZEOF_LONG_DOUBLE == CONDUIT_SIZEOF_DOUBLE
        typedef double conduit_long_double;
#else
#ifdef CONDUIT_HAS_LONG_DOUBLE
        typedef long double conduit_long_double;
#endif
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
typedef conduit_byte  conduit_int8;
typedef conduit_short conduit_int16;
typedef conduit_int conduit_int32;
typedef conduit_long_long conduit_int64;

// string defs
#define CONDUIT_INT8_NATIVE_NAME  "char"
#define CONDUIT_INT16_NATIVE_NAME "short"
#define CONDUIT_INT32_NATIVE_NAME "int"
#define CONDUIT_INT64_NATIVE_NAME "long long"

//-----------------------------------------------------------------------------
// -- bitwidth style unsigned integer types --
//-----------------------------------------------------------------------------
typedef conduit_ubyte  conduit_uint8;
typedef conduit_ushort conduit_uint16;
typedef conduit_uint conduit_uint32;
typedef conduit_ulong_long conduit_uint64;

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
#define CONDUIT_NATIVE_CHAR  conduit_int8
#define CONDUIT_NATIVE_SHORT conduit_int16
#define CONDUIT_NATIVE_INT   conduit_int32
#define CONDUIT_NATIVE_LONG  conduit_int32
#if defined(CONDUIT_USE_LONG_LONG)
#define CONDUIT_NATIVE_LONG_LONG  conduit_int64
#endif

#define CONDUIT_NATIVE_CHAR_ID  3
#define CONDUIT_NATIVE_SHORT_ID 4
#define CONDUIT_NATIVE_INT_ID   5
#define CONDUIT_NATIVE_LONG_ID  5
#if defined(CONDUIT_USE_LONG_LONG)
#define CONDUIT_NATIVE_LONG_LONG_ID  6
#endif

//-----------------------------------------------------------------------------
// -- c style unsigned integer type maps --
//-----------------------------------------------------------------------------
#define CONDUIT_NATIVE_UNSIGNED_CHAR  conduit_uint8
#define CONDUIT_NATIVE_UNSIGNED_SHORT conduit_uint16
#define CONDUIT_NATIVE_UNSIGNED_INT   conduit_uint32
#define CONDUIT_NATIVE_UNSIGNED_LONG  conduit_uint32
#if defined(CONDUIT_USE_LONG_LONG)
#define CONDUIT_NATIVE_UNSIGNED_LONG_LONG  conduit_uint64
#endif

#define CONDUIT_NATIVE_UNSIGNED_CHAR_ID  7
#define CONDUIT_NATIVE_UNSIGNED_SHORT_ID 8
#define CONDUIT_NATIVE_UNSIGNED_INT_ID   9
#define CONDUIT_NATIVE_UNSIGNED_LONG_ID  9
#if defined(CONDUIT_USE_LONG_LONG)
#define CONDUIT_NATIVE_UNSIGNED_LONG_LONG_ID  10
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

// signed ints
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

