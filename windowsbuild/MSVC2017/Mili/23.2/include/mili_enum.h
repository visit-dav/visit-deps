/*
 Copyright (c) 2016, Lawrence Livermore National Security, LLC.
 Produced at the Lawrence Livermore National Laboratory. Written
 by Kevin Durrenberger: durrenberger1@llnl.gov. CODE-OCEC-16-056.
 All rights reserved.

 This file is part of Mili. For details, see <URL describing code
 and how to download source>.

 Please also read this link-- Our Notice and GNU Lesser General
 Public License.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License (as published by
 the Free Software Foundation) version 2.1 dated February 1999.

 This program is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms
 and conditions of the GNU General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

 * Enumerated types for Mili.
 *
 *
 ************************************************************************
 * Modifications:
 *
 *  I. R. Corey - March 20, 2009: Added support for WIN32 for use with
 *                with Visit.
 *                See SCR #587.
 ************************************************************************
 */

#ifndef MILI_ENUM_H
#define MILI_ENUM_H


enum subrec_layout
{
RESULT_ORDERED,
OBJECT_ORDERED
};

/*****************************************************************
 * TAG( Control_function_type )
 *
 * Enumerations of db control functions exercised in the db open
 * control string.
 */
typedef enum
{
   CTL_ACCESS_MODE = 0,
   CTL_PRECISION_LIMIT,
   CTL_ENDIAN,
   QTY_CONTROL_FUNCTIONS /* Always last! */
} Control_function_type;


/*****************************************************************
 * TAG( Precision_limit_type )
 *
 * Enumerations of possible numeric precision limit constraints
 * (not all may be supported).
 */
typedef enum
{
   PREC_LIMIT_NULL = 0, /* Want zero to represent absence of specification. */
   PREC_LIMIT_SINGLE,
   PREC_LIMIT_DOUBLE,
   PREC_LIMIT_QUAD,
   PREC_LIMIT_NONE,
   QTY_PREC_LIMITS /* Always last! */
} Precision_limit_type;


/*****************************************************************
 * TAG( Endianness_type )
 *
 * Enumerations of endian format types.
 */
typedef enum
{
   MILI_BIG_ENDIAN = 1,
   MILI_LITTLE_ENDIAN,
   QTY_ENDIAN_TYPES /* Always last! */
} Endianness_type;


/*****************************************************************
 * TAG( Database_type )
 *
 * enumerations of database types mili/griz can handle.
 */
typedef enum
{
   MILI_DB_TYPE,
   TAURUS_DB_TYPE,
   SILO_DB_TYPE
} Database_type;


typedef enum
{
   STATE_COUNT = 1,
   BYTE_COUNT
} File_partition_scheme;


typedef enum
{
   UNDEFINED = 0,
   UNSTRUCTURED
} Mesh_type;


typedef enum
{
   DV_HEADERS,
   DV_SHORT,
   DV_LONG,
   DV_XTRA_LONG
} Dump_verbosity;


/*****************************************************************
 * TAG( Dir_entry_type )
 *
 * Enumeration of directory entry types.
 *
 * Additions cannot change the value of existing enumerations.
 *
 * ** Warning **
 *    Never add in the middle of the list - only at the end, BUT before
 *    QTY_DIR_ENTRY_TYPES!!!
 *
 */
typedef enum
{
   NODES,
   ELEM_CONNS,
   CLASS_IDENTS,
   STATE_VAR_DICT,
   STATE_REC_DATA,
   MILI_PARAM,
   APPLICATION_PARAM,
   CLASS_DEF,
   SURFACE_CONNS,

   /********************************
    *  Add here ->
    ********************************/

   TI_PARAM,

   /********************************
    *  QTY Must be the last item!!
    ********************************/
   QTY_DIR_ENTRY_TYPES

} Dir_entry_type;


/*****************************************************************
 * TAG( Db_object_status )
 *
 * Enumeration of possible states of certain db objects.
 */
typedef enum
{
   OBJ_OPEN = 0,
   OBJ_CLOSED,
   OBJ_EMPTY,
   OBJ_SAVED
} Db_object_status;


/*****************************************************************
 * TAG( Dir_entry_indices )
 *
 * Indices to the fields in a directory entry.  Additional
 * fields can be added but must be inserted immediately preceding
 * Qty_entry_fields and order of existing fields should not be
 * altered.
 */
enum Dir_entry_indices
{
   TYPE_IDX,                   /* Type of object in the family */
   MODIFIER1_IDX,              /* Object-specific information */
   MODIFIER2_IDX,              /* Object-specific information */
   STRING_QTY_IDX,             /* Quantity of associated strings */
   OFFSET_IDX,                 /* Location of object's first byte */
   LENGTH_IDX,                 /* Byte length of object */
   QTY_ENTRY_FIELDS
};


/*****************************************************************
 * TAG( File_dir_indices )
 *
 *
 */
enum File_dir_indices
{
   NAMES_LEN_IDX,              /* Qty of bytes occupied by null-term'd names */
   COMMIT_COUNT_IDX,           /* Number of commit that output this dir */
   QTY_ENTRIES_IDX,            /* Qty of entries in this directory */
   QTY_STATES_IDX,             /* Number of timesteps written thus far, only in mili file version 2*/
   QTY_DIR_HEADER_FIELDS
};


/*****************************************************************
 * TAG( Ident_entry_indices )
 *
 *
 */
enum Ident_entry_indices
{
   IDENT_SUPERCLASS_IDX,
   START_IDENT_IDX,
   STOP_IDENT_IDX,
   QTY_IDENT_ENTRY_FIELDS
};


/*****************************************************************
 * TAG( Conn_entry_indices )
 *
 *
 */
enum Conn_entry_indices
{
   CONN_SUPERCLASS_IDX,
   QTY_BLOCKS_IDX,
   QTY_CONN_HEADER_FIELDS
};


/*****************************************************************
 * TAG( Svar_header_indices )
 *
 *
 */
enum Svar_header_indices
{
   SVAR_QTY_INT_WORDS_IDX,
   SVAR_QTY_BYTES_IDX,
   QTY_SVAR_HEADER_FIELDS
};


/*****************************************************************
 * TAG( Srec_header_indices )
 *
 *
 */
enum Srec_header_indices
{
   SREC_ID_IDX,
   SREC_PARENT_MESH_ID_IDX,
   SREC_SIZE_BYTES_IDX,
   SREC_QTY_SUBRECS_IDX,
   QTY_SREC_HEADER_FIELDS
};


#ifdef OK
#undef OK
#endif

#ifdef NOT_OK
#undef NOT_OK
#endif


typedef enum
{
   OK     = 0,
   NOT_OK = 1,

   /* Return values 1-100 reserved for Fortran-API detected errors. */
   /* These values must also be explicitly assigned in mili_fparam.h! */
   TOO_MANY_SCALARS = 1,
   TOO_MANY_LIST_FIELDS = 2,

   /* Values above 100 for internal C-code returned values. */

   /* Reserve 101-120 for hash library. */
   ENTRY_EXISTS = 101,
   ENTRY_NOT_FOUND,
   HASH_TABLE_OVERFLOW,
   UNKNOWN_HASH_ACTION,
   VECTOR_REDECLARATION_ERROR,
   VARIABLE_AGG_TYPE_ERROR,

   BAD_FAMILY = 121,
   UNKNOWN_OS,
   UNKNOWN_PRECISION,
   OPEN_FAILED,
   FAMILY_NOT_FOUND,
   NO_MESH,
   NO_CLASS,
   NO_OBJECT_GROUP,
   OBJECT_RANGE_OVERLAP,
   OBJECT_RANGE_MERGE,  // 130
   OBJECT_RANGE_INSERT,
   OBJECT_RANGE_COLLAPSE,
   OBJECT_NOT_IN_MESH,
   NAME_CONFLICT,
   NO_MATCH,
   MESH_TYPE_CONFLICT,
   SUPERCLASS_CONFLICT,
   TOO_MANY_TYPES,
   UNKNOWN_FAMILY_FILE_TYPE,
   NOT_APPLICABLE,  // 140
   INVALID_SUFFIX_WIDTH,
   MEMBER_DELETE_FAILED,
   UNKNOWN_DATA_TYPE,
   INVALID_DATA_TYPE,
   INVALID_NAME,
   ORGANIZATION_READ_ONLY,
   UNKNOWN_ORGANIZATION,
   MISMATCHED_LIST_FIELD,
   UNKNOWN_ELEM_FMT,
   INVALID_DIMENSIONALITY, // 150
   LOCK_OPEN_FAILED,
   LOCK_EXISTS,
   LOCK_NAME_FAILED,
   BAD_ACCESS_TYPE,
   INCOMPATIBLE_BINARY_FORMAT,
   TOO_LATE,
   BAD_LOAD_READ,
   BAD_NAME_READ,
   SHORT_READ,
   SHORT_WRITE,  // 160
   NULL_POINTER,
   NOT_IN_FAMILY,
   UNKNOWN_PARTITION_SCHEME,
   SEEK_FAILED,
   INCOMPLETE_MESH_DEF,
   NOT_STRING_TYPE,
   INVALID_INDEX,
   INVALID_SREC_INDEX,
   INVALID_SUBREC_INDEX,
   INVALID_CLASS_OPERATION,  // 170
   INVALID_STATE,
   INVALID_RESULT,
   INVALID_TIME,
   MALFORMED_SUBSET,
   UNBOUND_NAME,
   INVALID_AGG_TYPE,
   UNKNOWN_QUERY_TYPE,
   ALLOC_FAILED,
   FAMILY_TRUNCATION_FAILED,
   NUM_TYPE_MISMATCH,  // 180
   STR_LEN_MISMATCH,
   INVALID_FILE_NAME_INDEX,
   INVALID_FILE_STATE_INDEX,
   CANNOT_MODIFY_OBJ,
   DIR_OPEN_FAILED,
   NO_SVARS,
   DIRECTORY_WRITE_CONFLICT,
   HEADER_WRITE_CONFLICT,
   BAD_CONTROL_STRING,
   MULTIPLE_HEADER_READ,  // 190
   MAPPED_OLD_HEADER,
   TAURUS_INCOMPLETE_GEOM,
   INVALID_CLASS_NAME,
   IOS_NO_VIABLE_BUFFER,
   IOS_ALLOC_FAILED,
   IOS_STR_DUP_FAILED,
   INVALID_SVAR_DATA,
   INVALID_DIR_ENTRY_DATA,
   TOO_MANY_MATERIALS,
   NO_MATERIALS,  // 200
   CORRUPTED_FILE,
   EPRINTF_FAILED,
   EFPRINTF_FAILED,
   ESPRINTF_FAILED,
   IOS_NO_CHAR_BUF,
   IOS_OUT_OF_SYNC,
   IOS_INVALID_DATA,
   BAD_HOST_NAME,
   BAD_SYSTEM_INFO,
   BAD_USER_ID,  // 210
   UNABLE_TO_FLUSH_FILE,
   UNABLE_TO_STAT_FILE,
   UNABLE_TO_CLOSE_FILE,
   OVERSIZED_SARRAY,
   FILE_FAMILY_NAME_MISMATCH,
   DIR_CLOSE_FAILED,
   DATA_PRECISION_MISMATCH,
   INVALID_SVAR_AGG_TYPE,
   CONN_LABEL_ID_MISMATCH,
   ZERO_SIZE_ERROR,  // 220
   TOO_MANY_LABELS,
   SVAR_VEC_ARRAY_ORG_MISMATCH,
   INVALID_VISIT_JSON_FILE,
   NO_A_FILE_FOR_STATEMAP,
   DIR_ZERO_COUNT,
   SUBRECORD_ALIGN_ERROR,
   STATE_NOT_INSTATIATED,
   INVALID_SR_OFFSET_UNDER,
   INVALID_SR_OFFSET_OVER, 
   MAP_FILE_CREATION_ERROR, //230
   TFILE_HEADER_VERSION_ERROR
   
} Return_value;


#define CHAR_HEADER_SIZE (16) /* Qty bytes in the "a" file character header. */
/*****************************************************************
 * TAG( Char_header_indices )
 *
 * Indices to the character header fields in the "A" file.
 * New indices can be added but must be inserted preceding
 * ADDL_FIELDS_IDX and order of existing fields should not be altered
 * or backward compatibility between the library and extant databases
 * will be eliminated.  If more than (CHAR_HEADER_SIZE - 1) indices
 * are required, additional header space can be allocated (in units
 * of four bytes) by making the header byte indexed by
 * ADDL_FIELDS_IDX non-zero.  I.e., the number of bytes reserved in
 * the "A" file for the header can be computed as:
 *      (CHAR_HEADER_SIZE + 4 * header[ADDL_FIELDS_IDX])
 */
enum Char_header_indices
{
   MILI_MAGIC_NUMBER_IDX = 0,    /* Mili database id, allow 4-bytes */
   HDR_VERSION_IDX = 4,          /* Header format version */
   DIR_VERSION_IDX = 5,          /* Directory format version index 5*/
   ENDIAN_IDX = 6,               /* Database endianness index 6*/
   PRECISION_LIMIT_IDX = 7,      /* Max precision of data written to family index 7 */
   ST_FILE_SUFFIX_WIDTH_IDX = 8, /* Numeric suffix width for state-data files index 8*/
   PARTITION_SCHEME_IDX = 9,    /* File partitioning scheme for family index 9*/
   /* Qty of additional 4-char fields following */
   ADDL_FIELDS_IDX = CHAR_HEADER_SIZE - 1
};


/*****************************************************************
 * TAG( Char_extension_indices )
 *
 * If header characters beyond the 16 provided above are ever
 * required (the value stored at location ADDL_FIELDS_IDX would be
 * non-zero), index them here.

enum Char_extension_indices
{
    FIRST_EXTENSION_CHAR_IDX = CHAR_HEADER_SIZE ...
};
 */

#endif
