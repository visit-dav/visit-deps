/*
Copyright (C) 1994-2016 Lawrence Livermore National Security, LLC.
LLNL-CODE-425250.
All rights reserved.

This file is part of Silo. For details, see silo.llnl.gov.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the disclaimer below.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the disclaimer (as noted
     below) in the documentation and/or other materials provided with
     the distribution.
   * Neither the name of the LLNS/LLNL nor the names of its
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

THIS SOFTWARE  IS PROVIDED BY  THE COPYRIGHT HOLDERS  AND CONTRIBUTORS
"AS  IS" AND  ANY EXPRESS  OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT
LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A  PARTICULAR  PURPOSE ARE  DISCLAIMED.  IN  NO  EVENT SHALL  LAWRENCE
LIVERMORE  NATIONAL SECURITY, LLC,  THE U.S.  DEPARTMENT OF  ENERGY OR
CONTRIBUTORS BE LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR  CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT  LIMITED TO,
PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS  OF USE,  DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER  IN CONTRACT, STRICT LIABILITY,  OR TORT (INCLUDING
NEGLIGENCE OR  OTHERWISE) ARISING IN  ANY WAY OUT  OF THE USE  OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

This work was produced at Lawrence Livermore National Laboratory under
Contract No.  DE-AC52-07NA27344 with the DOE.

Neither the  United States Government nor  Lawrence Livermore National
Security, LLC nor any of  their employees, makes any warranty, express
or  implied,  or  assumes  any  liability or  responsibility  for  the
accuracy, completeness,  or usefulness of  any information, apparatus,
product, or  process disclosed, or  represents that its use  would not
infringe privately-owned rights.

Any reference herein to  any specific commercial products, process, or
services by trade name,  trademark, manufacturer or otherwise does not
necessarily  constitute or imply  its endorsement,  recommendation, or
favoring  by  the  United  States  Government  or  Lawrence  Livermore
National Security,  LLC. The views  and opinions of  authors expressed
herein do not necessarily state  or reflect those of the United States
Government or Lawrence Livermore National Security, LLC, and shall not
be used for advertising or product endorsement purposes.
*/

/*
 * SILO Public header file.
 *
 * This header file defines public constants and public prototypes.
 * Before including this file, the application should define
 * which file formats will be used.
 *
 * WARNING: The `#define' statements in this file are used when
 *      generating the Fortran include file `silo.inc'.  Any
 *     such symbol that should not be an integer parameter
 *     in the Fortran include file should have the text 
 *     `NO_FORTRAN_DEFINE' on the same line.  #define statements
 *     that define macros (or any value not beginning with
 *     one of [a-zA-Z0-9_]) are ignored.
 */
#ifndef SILO_H
#define SILO_H

#include <stdio.h> /* for FILE* datatype for filters */

#include <silo_exports.h>

/* Why these Void Const Pointer (VCP) typedefs? (see below)... */
typedef void const *                 DBVCP1_t; /* single level array */
typedef void const *                 DBVCP2_t; /* double level array */
typedef void const *                 DBVCP3_t; /* triple level array */

/* And not these...
typedef void const *                 DBVCP1_t;    single level array
typedef void const * const *         DBVCP2_t;    double level array
typedef void const * const * const * DBVCP3_t;    triple level array

Ideally, the later typedefs would be used in the Silo API wherever a caller
needs to pass a single, double or triple level array of arbitrary type.

However, for multi-level arrays (e.g. more than a single star*), if the caller
doesn't explicitly cast a non-void pointer to the exact type including the
const qualifiers, the later definitions create obscure and non-intuitive compiler
warnings for C callers and outright errors for C++ callers.

Basically, as counter-intuitive as it sounds neither C nor C++ compilers can handle
passing something like a 'double **' as an argument to a function expecting a
'void const * const *'.

A good reference on this issue for C is http://c-faq.com/ansi/constmismatch.html
A good reference for C++ is
http://www.embedded.com/electronics-blogs/programming-pointers/4025641/Qualifiers-in-multilevel-pointers

Therefore, we introduce the DBVCPX_t typedefs, where 'X' is 1, 2 or 3, to
indicate the number of levels in the array the Silo library is expecting the
caller to pass. Even though the typedef resolves to a 'void const *' for all
X, the underlying implementation will wind up treating it as a 'void const *' for
X=1 (e.g. DBVCP1_t), a 'void const * const *' for X=2 (e.g. DBVCP2_t), etc.

*/

/* For the char-specific case of a constant array of strings, to facilitate explicit casts */
typedef char const * const *         DBCAS_t;

#ifndef FALSE
#define FALSE   0
#endif
#ifndef TRUE
#define TRUE    1
#endif

/* Major release number of silo library. */
#define _SILO_VERS_MAJ_4
#ifdef _SILO_VERS_MAJ_
#define SILO_VERS_MAJ 0 /* NO_FORTRAN_DEFINE */
#else
#define SILO_VERS_MAJ 4
#endif

/* Minor release number of silo library. Can be empty. */
#define _SILO_VERS_MIN_11
#ifdef _SILO_VERS_MIN_
#define SILO_VERS_MIN 0 /* NO_FORTRAN_DEFINE */
#else
#define SILO_VERS_MIN 11
#endif

/* Patch release number of silo library.  Can be empty. */
#define _SILO_VERS_PAT_
#ifdef _SILO_VERS_PAT_
#define SILO_VERS_PAT 0 /* NO_FORTRAN_DEFINE */
#else
#define SILO_VERS_PAT 
#endif

/* Pre-release release number of silo library.  Can be empty. */
#define _SILO_VERS_PRE_
#ifdef _SILO_VERS_PRE_
#define SILO_VERS_PRE 0 /* NO_FORTRAN_DEFINE */
#else
#define SILO_VERS_PRE 
#endif

/* The symbol Silo uses to enforce link-time
   header/object version compatibility */
#define SILO_VERS_TAG Silo_version_4_11

/* Useful macro for comparing Silo versions (and DB_ alias) */
#define SILO_VERSION_GE(Maj,Min,Pat)  \
        (((SILO_VERS_MAJ==Maj) && (SILO_VERS_MIN==Min) && (SILO_VERS_PAT>=Pat)) || \
         ((SILO_VERS_MAJ==Maj) && (SILO_VERS_MIN>Min)) || \
         (SILO_VERS_MAJ>Maj))
#define DB_VERSION_GE(Maj,Min,Pat) SILO_VERSION_GE(Maj,Min,Pat)

/*-------------------------------------------------------------------------
 * Drivers.  This is a list of every driver that a user could use.  Not all of
 * them are necessarily compiled into the library.  However, users are free
 * to try without getting compilation errors.  They are listed here so that
 * silo.h doesn't have to be generated every time the library is recompiled.
 *--------------------------------------------------------------------------*/
#define DB_NETCDF 0
#define DB_PDB 2 /* PDB Lite */
#define DB_TAURUS 3
#define DB_UNKNOWN 5
#define DB_DEBUG 6
#define DB_HDF5X 7
#define DB_PDBP 1 /* PDB Proper */

/* DO NOT USE. Obsoleted ways of specifying different HDF5 vfds */
#define DB_HDF5_SEC2_OBSOLETE 0x100
#define DB_HDF5_STDIO_OBSOLETE 0x200
#define DB_HDF5_CORE_OBSOLETE 0x300
#define DB_HDF5_MPIO_OBSOLETE 0x400
#define DB_HDF5_MPIOP_OBSOLETE 0x500

/* symbols for various HDF5 vfds */
#define DB_H5VFD_DEFAULT 0
#define DB_H5VFD_SEC2    1
#define DB_H5VFD_STDIO   2
#define DB_H5VFD_CORE    3
#define DB_H5VFD_LOG     4
#define DB_H5VFD_SPLIT   5
#define DB_H5VFD_DIRECT  6
#define DB_H5VFD_FAMILY  7
#define DB_H5VFD_MPIO    8
#define DB_H5VFD_MPIP    9
#define DB_H5VFD_SILO    10
#define DB_H5VFD_FIC     11 /* File Image in Core */

/* Macro for defining various HDF5 vfds as 'type' arg in create/open.
   The 11 bit shift is to avoid possible collision with older versions
   of Silo header file where VFDs where specified in bits 8-11. Their
   obsoleted values are listed above. */ 
#define DB_HDF5_OPTS(OptsId) (DB_HDF5X|((OptsId&0x3F)<<11))

/* Monikers for default file options sets */
/* We just make the default options sets the same as the vfd is */
#define DB_FILE_OPTS_H5_DEFAULT_DEFAULT DB_H5VFD_DEFAULT 
#define DB_FILE_OPTS_H5_DEFAULT_SEC2    DB_H5VFD_SEC2 
#define DB_FILE_OPTS_H5_DEFAULT_STDIO   DB_H5VFD_STDIO 
#define DB_FILE_OPTS_H5_DEFAULT_CORE    DB_H5VFD_CORE 
#define DB_FILE_OPTS_H5_DEFAULT_LOG     DB_H5VFD_LOG 
#define DB_FILE_OPTS_H5_DEFAULT_SPLIT   DB_H5VFD_SPLIT 
#define DB_FILE_OPTS_H5_DEFAULT_DIRECT  DB_H5VFD_DIRECT 
#define DB_FILE_OPTS_H5_DEFAULT_FAMILY  DB_H5VFD_FAMILY 
#define DB_FILE_OPTS_H5_DEFAULT_MPIO    DB_H5VFD_MPIO
#define DB_FILE_OPTS_H5_DEFAULT_MPIP    DB_H5VFD_MPIP
#define DB_FILE_OPTS_H5_DEFAULT_SILO    DB_H5VFD_SILO 
#define DB_FILE_OPTS_LAST DB_FILE_OPTS_H5_DEFAULT_SILO
/* note: no possible *default* settings for DB_H5VFD_FIC */

/* Various default HDF5 driver options. Users can define their own
   sets of options using DBRegisterFileOptionsSets(). */
#define DB_HDF5 DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_DEFAULT)
#define DB_HDF5_SEC2 DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_SEC2)
#define DB_HDF5_STDIO DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_STDIO)
#define DB_HDF5_CORE DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_CORE)
#define DB_HDF5_LOG DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_LOG)
#define DB_HDF5_SPLIT DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_SPLIT)
#define DB_HDF5_DIRECT DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_DIRECT)
#define DB_HDF5_FAMILY DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_FAMILY)
#define DB_HDF5_MPIO DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_MPIO)
#define DB_HDF5_MPIOP DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_MPIP)
#define DB_HDF5_MPIP DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_MPIP)
#define DB_HDF5_SILO DB_HDF5_OPTS(DB_FILE_OPTS_H5_DEFAULT_SILO)

/*-------------------------------------------------------------------------
 * Other library-wide constants.
 *-------------------------------------------------------------------------*/
#define DB_NFILES       256         /*Max simultaneously open files */
#define DB_NFILTERS     32          /*Number of filters defined */

/*-------------------------------------------------------------------------
 * Constants.  All of these constants are always defined in the application.
 * Each group of constants defined here are small integers used as an index
 * into an array.  Many of the groups have a total count of items in the
 * group that will be used for array allocation and error checking--don't
 * forget to increment the value when adding a new item to a constant group.
 *-------------------------------------------------------------------------
 */

/* The following identifiers are for use with the DBDataReadMask() call.  They
 * specify what portions of the data beyond the metadata is allocated
 * and read.  Note that since these values are only necessary when reading
 * and since the Fortran interface is primarily a write interface, it is not
 * necessary for these symbols to appear in the silo.inc file. However, the
 * reason they DO NOT APPEAR there inspite of the fact that DO NOT HAVE the
 * 'NO_FORTRAN_DEFINE' text appearing on each line is that the mkinc script
 * requires an underscore in the symbol name for it to appear in silo.inc. */
#define DBAll                     0xffffffffffffffffULL
#define DBNone                    0x0000000000000000ULL
#define DBCalc                    0x0000000000000001ULL
#define DBMatMatnos               0x0000000000000002ULL
#define DBMatMatlist              0x0000000000000004ULL
#define DBMatMixList              0x0000000000000008ULL
#define DBCurveArrays             0x0000000000000010ULL
#define DBPMCoords                0x0000000000000020ULL
#define DBPVData                  0x0000000000000040ULL
#define DBQMCoords                0x0000000000000080ULL
#define DBQVData                  0x0000000000000100ULL
#define DBUMCoords                0x0000000000000200ULL
#define DBUMFacelist              0x0000000000000400ULL
#define DBUMZonelist              0x0000000000000800ULL
#define DBUVData                  0x0000000000001000ULL
#define DBFacelistInfo            0x0000000000002000ULL
#define DBZonelistInfo            0x0000000000004000ULL
#define DBMatMatnames             0x0000000000008000ULL
#define DBUMGlobNodeNo            0x0000000000010000ULL
#define DBZonelistGlobZoneNo      0x0000000000020000ULL
#define DBMatMatcolors            0x0000000000040000ULL
#define DBCSGMBoundaryInfo        0x0000000000080000ULL
#define DBCSGMZonelist            0x0000000000100000ULL
#define DBCSGMBoundaryNames       0x0000000000200000ULL
#define DBCSGVData                0x0000000000400000ULL
#define DBCSGZonelistZoneNames    0x0000000000800000ULL
#define DBCSGZonelistRegNames     0x0000000001000000ULL
#define DBMMADJNodelists          0x0000000002000000ULL
#define DBMMADJZonelists          0x0000000004000000ULL
#define DBPMGlobNodeNo            0x0000000008000000ULL
#define DBPMGhostNodeLabels       0x0000000010000000ULL
#define DBQMGhostNodeLabels       0x0000000020000000ULL
#define DBQMGhostZoneLabels       0x0000000040000000ULL
#define DBUMGhostNodeLabels       0x0000000080000000ULL
#define DBZonelistGhostZoneLabels 0x0000000100000000ULL
#define DBMBNamesAndTypes         0x0000000200000000ULL
#define DBMBOptions               0x0000000400000000ULL

/* Definitions for COORD_TYPE */
/* Placed before DBObjectType enum because the
   DB_QUAD_CURV and DB_QUAD_RECT symbols are
   sometimes used as DBObjectType */

#define  DB_COLLINEAR           130
#define  DB_NONCOLLINEAR        131
#define  DB_QUAD_RECT           DB_COLLINEAR
#define  DB_QUAD_CURV           DB_NONCOLLINEAR

#ifdef __cplusplus
extern "C" {
#endif

/* Objects that can be stored in a data file */
typedef enum {
    DB_INVALID_OBJECT= -1,       /*causes enum to be signed, do not remove,
                                   space before minus sign necessary for lint*/
    DB_QUADRECT = DB_QUAD_RECT,
    DB_QUADCURV = DB_QUAD_CURV,
    DB_QUADMESH=500,
    DB_QUADVAR=501,
    DB_UCDMESH=510,
    DB_UCDVAR=511,
    DB_MULTIMESH=520,
    DB_MULTIVAR=521,
    DB_MULTIMAT=522,
    DB_MULTIMATSPECIES=523,
    DB_MULTIBLOCKMESH=DB_MULTIMESH,
    DB_MULTIBLOCKVAR=DB_MULTIVAR,
    DB_MULTIMESHADJ=524,
    DB_MATERIAL=530,
    DB_MATSPECIES=531,
    DB_FACELIST=550,
    DB_ZONELIST=551,
    DB_EDGELIST=552,
    DB_PHZONELIST=553,
    DB_CSGZONELIST=554,
    DB_CSGMESH=555,
    DB_CSGVAR=556,
    DB_CURVE=560,
    DB_DEFVARS=565,
    DB_POINTMESH=570,
    DB_POINTVAR=571,
    DB_ARRAY=580,
    DB_DIR=600,
    DB_SYMLINK=601,
    DB_VARIABLE=610,
    DB_MRGTREE=611,
    DB_GROUPELMAP=612,
    DB_MRGVAR=613,
    DB_USERDEF=700
} DBObjectType;

/* Data types */
typedef enum {
    DB_INT=16,
    DB_SHORT=17,
    DB_LONG=18,
    DB_FLOAT=19,
    DB_DOUBLE=20,
    DB_CHAR=21,
    DB_LONG_LONG=22,
    DB_NOTYPE=25           /*unknown type */
} DBdatatype;

/* Flags for DBCreate */
#define         DB_CLOBBER      0
#define         DB_NOCLOBBER    1

/* Flags for DBOpen */
#define         DB_READ         1
#define         DB_APPEND       2

/* Target machine for DBCreate */
#define         DB_LOCAL        0
#define         DB_SUN3         10
#define         DB_SUN4         11
#define         DB_SGI          12
#define         DB_RS6000       13
#define         DB_CRAY         14
#define         DB_INTEL        15

/* Options */
#define DBOPT_FIRST             260
#define DBOPT_ALIGN             260
#define DBOPT_COORDSYS          262
#define DBOPT_CYCLE             263
#define DBOPT_FACETYPE          264
#define DBOPT_HI_OFFSET         265
#define DBOPT_LO_OFFSET         266
#define DBOPT_LABEL             267
#define DBOPT_XLABEL            268
#define DBOPT_YLABEL            269
#define DBOPT_ZLABEL            270
#define DBOPT_MAJORORDER        271
#define DBOPT_NSPACE            272
#define DBOPT_ORIGIN            273
#define DBOPT_PLANAR            274
#define DBOPT_TIME              275
#define DBOPT_UNITS             276
#define DBOPT_XUNITS            277
#define DBOPT_YUNITS            278
#define DBOPT_ZUNITS            279
#define DBOPT_DTIME             280
#define DBOPT_USESPECMF         281
#define DBOPT_XVARNAME          282
#define DBOPT_YVARNAME          283
#define DBOPT_ZVARNAME          284
#define DBOPT_ASCII_LABEL       285
#define DBOPT_MATNOS            286
#define DBOPT_NMATNOS           287
#define DBOPT_MATNAME           288
#define DBOPT_NMAT              289
#define DBOPT_NMATSPEC          290
#define DBOPT_BASEINDEX         291 /* quad meshes for node and zone */
#define DBOPT_ZONENUM           292 /* ucd meshes for zone */
#define DBOPT_NODENUM           293 /* ucd/point meshes for node */
#define DBOPT_BLOCKORIGIN       294
#define DBOPT_GROUPNUM          295
#define DBOPT_GROUPORIGIN       296
#define DBOPT_NGROUPS           297
#define DBOPT_MATNAMES          298
#define DBOPT_EXTENTS_SIZE      299
#define DBOPT_EXTENTS           300
#define DBOPT_MATCOUNTS         301
#define DBOPT_MATLISTS          302
#define DBOPT_MIXLENS           303
#define DBOPT_ZONECOUNTS        304
#define DBOPT_HAS_EXTERNAL_ZONES 305
#define DBOPT_PHZONELIST        306
#define DBOPT_MATCOLORS         307
#define DBOPT_BNDNAMES          308
#define DBOPT_REGNAMES          309
#define DBOPT_ZONENAMES         310
#define DBOPT_HIDE_FROM_GUI     311
#define DBOPT_TOPO_DIM          312 /* TOPOlogical DIMension */
#define DBOPT_REFERENCE         313 /* reference object */
#define DBOPT_GROUPINGS_SIZE    314 /* size of grouping array */
#define DBOPT_GROUPINGS         315 /* groupings array */
#define DBOPT_GROUPINGNAMES     316 /* array of size determined by 
                                       number of groups of names of groups. */
#define DBOPT_ALLOWMAT0         317 /* Turn off material numer "0" warnings*/
#define DBOPT_MRGTREE_NAME      318
#define DBOPT_REGION_PNAMES     319
#define DBOPT_TENSOR_RANK       320
#define DBOPT_MMESH_NAME        321
#define DBOPT_TV_CONNECTIVITY   322
#define DBOPT_DISJOINT_MODE     323
#define DBOPT_MRGV_ONAMES       324
#define DBOPT_MRGV_RNAMES       325
#define DBOPT_SPECNAMES         326
#define DBOPT_SPECCOLORS        327
#define DBOPT_LLONGNZNUM        328
#define DBOPT_CONSERVED         329
#define DBOPT_EXTENSIVE         330
#define DBOPT_MB_FILE_NS        331
#define DBOPT_MB_BLOCK_NS       332
#define DBOPT_MB_BLOCK_TYPE     333
#define DBOPT_MB_EMPTY_LIST     334
#define DBOPT_MB_EMPTY_COUNT    335
#define DBOPT_MB_REPR_BLOCK_IDX 336
#define DBOPT_MISSING_VALUE     337
#define DBOPT_ALT_ZONENUM_VARS  338
#define DBOPT_ALT_NODENUM_VARS  339
#define DBOPT_GHOST_NODE_LABELS 340
#define DBOPT_GHOST_ZONE_LABELS 341
#define DBOPT_LAST              499 

/* Options relating to virtual file drivers */
#define DBOPT_H5_FIRST              500
#define DBOPT_H5_VFD                500
#define DBOPT_H5_RAW_FILE_OPTS      501
#define DBOPT_H5_RAW_EXTENSION      502
#define DBOPT_H5_META_FILE_OPTS     503
#define DBOPT_H5_META_EXTENSION     504
#define DBOPT_H5_CORE_ALLOC_INC     505
#define DBOPT_H5_CORE_NO_BACK_STORE 506
#define DBOPT_H5_META_BLOCK_SIZE    507
#define DBOPT_H5_SMALL_RAW_SIZE     508
#define DBOPT_H5_ALIGN_MIN          509
#define DBOPT_H5_ALIGN_VAL          510
#define DBOPT_H5_DIRECT_MEM_ALIGN   511
#define DBOPT_H5_DIRECT_BLOCK_SIZE  512
#define DBOPT_H5_DIRECT_BUF_SIZE    513
#define DBOPT_H5_LOG_NAME           514
#define DBOPT_H5_LOG_BUF_SIZE       515
#define DBOPT_H5_MPIO_COMM          516
#define DBOPT_H5_MPIO_INFO          517
#define DBOPT_H5_MPIP_NO_GPFS_HINTS 518
#define DBOPT_H5_SIEVE_BUF_SIZE     519
#define DBOPT_H5_CACHE_NELMTS       520
#define DBOPT_H5_CACHE_NBYTES       521
#define DBOPT_H5_CACHE_POLICY       522
#define DBOPT_H5_FAM_SIZE           523
#define DBOPT_H5_FAM_FILE_OPTS      524
#define DBOPT_H5_USER_DRIVER_ID     525
#define DBOPT_H5_USER_DRIVER_INFO   526
#define DBOPT_H5_SILO_BLOCK_SIZE    527
#define DBOPT_H5_SILO_BLOCK_COUNT   528
#define DBOPT_H5_SILO_LOG_STATS     529
#define DBOPT_H5_SILO_USE_DIRECT    530
#define DBOPT_H5_FIC_SIZE           531
#define DBOPT_H5_FIC_BUF            532
#define DBOPT_H5_FCPL_HID_T         533
#define DBOPT_H5_FAPL_HID_T         534
#define DBOPT_H5_LAST               599

/* Error trapping method */
#define         DB_TOP          0 /*default--API traps  */
#define         DB_NONE         1 /*no errors trapped  */
#define         DB_ALL          2 /*all levels trap (traceback) */
#define         DB_ABORT        3 /*abort() is called  */
#define         DB_SUSPEND      4 /*suspend error reporting temporarily */
#define         DB_RESUME       5 /*resume normal error reporting */
#define         DB_ALL_AND_DRVR 6 /*DB_ALL + driver error reporting */

/* Errors */
#define     E_NOERROR   0       /*No error   */
#define     E_BADFTYPE  1       /*Bad file type   */
#define     E_NOTIMP    2       /*Callback not implemented */
#define     E_NOFILE    3       /*No data file specified    */
#define     E_INTERNAL  5       /*Internal error        */
#define     E_NOMEM     6       /*Not enough memory     */
#define     E_BADARGS   7       /*Bad argument to function  */
#define     E_CALLFAIL  8       /*Low-level function failure    */
#define     E_NOTFOUND  9       /*Object not found      */
#define     E_TAURSTATE 10      /*Taurus: database state error  */
#define     E_MSERVER   11      /*SDX: too many connections */
#define     E_PROTO     12      /*SDX: protocol error       */
#define     E_NOTDIR    13      /*Not a directory       */
#define     E_MAXOPEN   14      /*Too many open files  */
#define     E_NOTFILTER 15      /*Filter(s) not found  */
#define     E_MAXFILTERS    16  /*Too many filters  */
#define     E_FEXIST    17      /*File already exists  */
#define     E_FILEISDIR 18      /*File is actually a directory */
#define     E_FILENOREAD    19  /*File lacks read permission. */
#define     E_SYSTEMERR 20      /*System level error occured. */
#define     E_FILENOWRITE 21    /*File lacks write permission. */
#define     E_INVALIDNAME 22    /* Variable name is invalid */
#define     E_NOOVERWRITE 23    /*Overwrite not permitted */
#define     E_CHECKSUM  24      /*Checksum failed */
#define     E_COMPRESSION  25   /*Compression failed */
#define     E_GRABBED   26      /*Low level driver enabled */
#define     E_NOTREG    27      /*The dbfile pointer is not resitered. */
#define     E_CONCURRENT 28     /*File is opened multiply and not all read-only. */
#define     E_DRVRCANTOPEN 29   /*Driver cannot open the file. */
#define     E_BADOPTCLASS 30    /*Optlist contains options for wrong class */
#define     E_NOTENABLEDINBUILD 31 /*feature not enabled in this build */
#define     E_MAXFILEOPTSETS 32 /*Too many file options sets */
#define     E_NOHDF5 33         /*HDF5 driver not available */
#define     E_EMPTYOBJECT 34    /*Empty object not currently permitted*/
#define     E_OBJBUFFULL  35    /*No more temp. buffer space for object */
#define     E_NOSILOHDF5 36     /*Not HDF5 silo produced by silo */
#define     E_NERRORS   50

/* Definitions for MAJOR_ORDER */
#define  DB_ROWMAJOR            0
#define  DB_COLMAJOR            1

/* Definitions for CENTERING */
#define  DB_NOTCENT             0
#define  DB_NODECENT            110
#define  DB_ZONECENT            111
#define  DB_FACECENT            112
#define  DB_BNDCENT             113 /* for CSG meshes only */
#define  DB_EDGECENT            114
#define  DB_BLOCKCENT           115 /* for 'block-centered' data on multimeshs */

/* Definitions for COORD_SYSTEM */
#define  DB_CARTESIAN           120
#define  DB_CYLINDRICAL         121 /* x,r;  y,theta;  z,height; 2D variant is eqiv. to poloar */
#define  DB_SPHERICAL           122 /* x,r;  y,theta;  z,phi;  2D variant is equiv. to polar */
#define  DB_NUMERICAL           123
#define  DB_OTHER               124

/* Definitions for ZONE FACE_TYPE */
#define  DB_RECTILINEAR         100
#define  DB_CURVILINEAR         101

/* Definitions for PLANAR */
#define  DB_AREA                140
#define  DB_VOLUME              141

/* Definitions for flag values */
#define DB_ON                    1000
#define DB_OFF                  -1000

/* Definitions for disjoint flag */
#define DB_ABUTTING              142
#define DB_FLOATING              143

/* Definitions for derived variable types */
#define DB_VARTYPE_SCALAR               200
#define DB_VARTYPE_VECTOR               201
#define DB_VARTYPE_TENSOR               202
#define DB_VARTYPE_SYMTENSOR            203
#define DB_VARTYPE_ARRAY                204
#define DB_VARTYPE_MATERIAL             205
#define DB_VARTYPE_SPECIES              206
#define DB_VARTYPE_LABEL                207

/* Definitions for ghost labels */
#define DB_GHOSTTYPE_NOGHOST ((char)0x00)
#define DB_GHOSTTYPE_INTDUP ((char)0x01)

/* Definitions for compatability mode */
#define DB_MAX_COMPATABILITY            0
#define DB_MAX_PERFORMANCE              1

/* Definitions for CSG boundary types 
   Designed so low-order 16 bits are unused.

   The last few characters of the symbol are intended
   to indicate the representational form of the surface type

   G = generalized form  (n values, depends on surface type)
   P = point (3 values, x,y,z in 3D, 2 values in 2D x,y)
   N = normal (3 values, Nx,Ny,Nz in 3D, 2 values in 2D Nx,Ny)
   R = radius (1 value)
   A = angle (1 value in degrees)
   L = length (1 value)
   X = x-intercept (1 value)
   Y = y-intercept (1 value)
   Z = z-intercept (1 value)
   K = arbitrary integer
   F = planar face defined by point-normal pair (6 values)
   */
#define DBCSG_QUADRIC_G         0x01000000
#define DBCSG_SPHERE_PR         0x02010000
#define DBCSG_ELLIPSOID_PRRR    0x02020000
#define DBCSG_PLANE_G           0x03000000
#define DBCSG_PLANE_X           0x03010000
#define DBCSG_PLANE_Y           0x03020000
#define DBCSG_PLANE_Z           0x03030000
#define DBCSG_PLANE_PN          0x03040000
#define DBCSG_PLANE_PPP         0x03050000
#define DBCSG_CYLINDER_PNLR     0x04000000
#define DBCSG_CYLINDER_PPR      0x04010000
#define DBCSG_BOX_XYZXYZ        0x05000000
#define DBCSG_CONE_PNLA         0x06000000
#define DBCSG_CONE_PPA          0x06010000
#define DBCSG_POLYHEDRON_KF     0x07000000
#define DBCSG_HEX_6F            0x07010000
#define DBCSG_TET_4F            0x07020000
#define DBCSG_PYRAMID_5F        0x07030000
#define DBCSG_PRISM_5F          0x07040000

/* Definitions for 2D CSG boundary types */
#define DBCSG_QUADRATIC_G       0x08000000
#define DBCSG_CIRCLE_PR         0x09000000
#define DBCSG_ELLIPSE_PRR       0x09010000
#define DBCSG_LINE_G            0x0A000000
#define DBCSG_LINE_X            0x0A010000
#define DBCSG_LINE_Y            0x0A020000
#define DBCSG_LINE_PN           0x0A030000
#define DBCSG_LINE_PP           0x0A040000
#define DBCSG_BOX_XYXY          0x0B000000
#define DBCSG_ANGLE_PNLA        0x0C000000
#define DBCSG_ANGLE_PPA         0x0C010000
#define DBCSG_POLYGON_KP        0x0D000000
#define DBCSG_TRI_3P            0x0D010000
#define DBCSG_QUAD_4P           0x0D020000

/* Definitions for CSG Region operators */
#define DBCSG_INNER             0x7F000000
#define DBCSG_OUTER             0x7F010000
#define DBCSG_ON                0x7F020000
#define DBCSG_UNION             0x7F030000
#define DBCSG_INTERSECT         0x7F040000
#define DBCSG_DIFF              0x7F050000
#define DBCSG_COMPLIMENT        0x7F060000
#define DBCSG_XFORM             0x7F070000
#define DBCSG_SWEEP             0x7F080000

/* definitions for MRG Tree traversal flags */
#define DB_PREORDER             0x00000001
#define DB_POSTORDER            0x00000002
#define DB_FROMCWR              0x00000004

/* Miscellaneous constants */
#define     DB_F77NULL  (-99)   /*Fortran NULL pointer      */
#define     DB_F77NULLSTRING  "NULLSTRING"  /* FORTRAN STRING */

/* Mode constants for partial I/O operations */
#define DB_PARTIO_POINTS 0x1
#define DB_PARTIO_HSLABS 0x2

/*-------------------------------------------------------------------------
 * Index selection macros
 *-------------------------------------------------------------------------
 */
#define I4D(s,i,j,k,l) (l)*s[3]+(k)*s[2]+(j)*s[1]+(i)*s[0]
#define I3D(s,i,j,k)   (k)*s[2]+(j)*s[1]+(i)*s[0]
#define I2D(s,i,j)     (j)*s[1]+(i)*s[0]

/* Note we should not use MAX_DOUBLE here as its definition could be different
   from one machine to the next. We need something that is a constant across
   all machines we will operate on. And, yes, it means this particular number
   cannot be used for any real data values or for the missing data value. I
   think the risk of problems is minimal. Also, we want a zero in the file
   to represent the fact that a missing value is NOT SET. Nonetheless, we
   want Silo clients to be able to specify that zero represents the missing
   value. So, we adjust the interpretation of missing values on write and 
   on read to/from the file. On write, NOT_SET in mem gets mapped to zero in
   the file and zero in mem gets mapped to NOT_SET in the file. On read, this
   mapping is reversed. */
#define DB_MISSING_VALUE_NOT_SET ((double)1.0e+308)

/* End-of-args for terminating some varargs lists */
#define DB_EOA ((void*)0)

/*-------------------------------------------------------------------------
 * Structures (just the public parts).
 *-------------------------------------------------------------------------
 */

/*
 * Database table of contents for the current directory only.
 */
typedef struct DBtoc_ {

    char         **curve_names;
    int            ncurve;

    char         **multimesh_names;
    int            nmultimesh;

    char         **multimeshadj_names;
    int            nmultimeshadj;

    char         **multivar_names;
    int            nmultivar;

    char         **multimat_names;
    int            nmultimat;

    char         **multimatspecies_names;
    int            nmultimatspecies;

    char         **csgmesh_names;
    int            ncsgmesh;

    char         **csgvar_names;
    int            ncsgvar;

    char         **defvars_names;
    int            ndefvars;

    char         **qmesh_names;
    int            nqmesh;

    char         **qvar_names;
    int            nqvar;

    char         **ucdmesh_names;
    int            nucdmesh;

    char         **ucdvar_names;
    int            nucdvar;

    char         **ptmesh_names;
    int            nptmesh;

    char         **ptvar_names;
    int            nptvar;

    char         **mat_names;
    int            nmat;

    char         **matspecies_names;
    int            nmatspecies;

    char         **var_names;
    int            nvar;

    char         **obj_names;
    int            nobj;

    char         **dir_names;
    int            ndir;

    char         **array_names;
    int            narray;

    char         **mrgtree_names;
    int            nmrgtree;

    char         **groupelmap_names;
    int            ngroupelmap;

    char         **mrgvar_names;
    int            nmrgvar;

    char         **symlink_target_names;
    int            nsymlink;
    char         **symlink_names; /* copies of other members; never free'd */

} DBtoc;
#define DB_NOBJ_TYPES  25

/*----------------------------------------------------------------------------
 * Database Curve Object
 *--------------------------------------------------------------------------
 */
typedef struct DBcurve_ {
/*----------- X vs. Y (Curve) Data -----------*/
    int            id;          /* Identifier for this object */
    int            datatype;    /* Datatype for x and y (float, double) */
    int            origin;      /* '0' or '1' */
    char          *title;       /* Title for curve */
    char          *xvarname;    /* Name of domain (x) variable */
    char          *yvarname;    /* Name of range  (y) variable */
    char          *xlabel;      /* Label for x-axis */
    char          *ylabel;      /* Label for y-axis */
    char          *xunits;      /* Units for domain */
    char          *yunits;      /* Units for range  */
    void          *x;           /* Domain values for curve */
    void          *y;           /* Range  values for curve */
    int            npts;        /* Number of points in curve */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char          *reference;   /* Label to reference object */
    int            coord_sys;   /* To indicate other coordinate systems */
    double         missing_value; /* Value to indicate var data is invalid/missing */
} DBcurve;

typedef struct DBdefvars_ {
    int            ndefs;       /* number of definitions */
    char         **names;       /* [ndefs] derived variable names */
    int           *types;       /* [ndefs] derived variable types */
    char         **defns;       /* [ndefs] derived variable definitions */
    int        *guihides;       /* [ndefs] flags to hide from
                                   post-processor's GUI */
} DBdefvars;

typedef struct DBpointmesh_ {
/*----------- Point Mesh -----------*/
    int            id;          /* Identifier for this object */
    int            block_no;    /* Block number for this mesh */
    int            group_no;    /* Block group number for this mesh */
    char          *name;        /* Name associated with this mesh */
    int            cycle;       /* Problem cycle number */
    char          *units[3];    /* Units for each axis */
    char          *labels[3];   /* Labels for each axis */
    char          *title;       /* Title for curve */

    void          *coords[3];   /* Coordinate values */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
   /*
    * The following two fields really only contain 3 elements.  However, silo
    * contains a bug in PJ_ReadVariable() as called by DBGetPointmesh() which
    * can cause three doubles to be stored there instead of three floats.
    */
    float          min_extents[6];  /* Min mesh extents [ndims] */
    float          max_extents[6];  /* Max mesh extents [ndims] */

    int            datatype;    /* Datatype for coords (float, double) */
    int            ndims;       /* Number of computational dimensions */
    int            nels;        /* Number of elements in mesh */
    int            origin;      /* '0' or '1' */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    void          *gnodeno;     /* global node ids */
    char          *mrgtree_name; /* optional name of assoc. mrgtree object */
    int            gnznodtype;  /* datatype for global node/zone ids */
    char          *ghost_node_labels;
    char         **alt_nodenum_vars; 
} DBpointmesh;

/*----------------------------------------------------------------------------
 * Multi-Block Mesh Object
 *--------------------------------------------------------------------------
 */
typedef struct DBmultimesh_ {
/*----------- Multi-Block Mesh -----------*/
    int            id;          /* Identifier for this object */
    int            nblocks;     /* Number of blocks in mesh */
    int            ngroups;     /* Number of block groups in mesh */
    int           *meshids;     /* Array of mesh-ids which comprise mesh */
    char         **meshnames;   /* Array of mesh-names for meshids */
    int           *meshtypes;   /* Array of mesh-type indicators [nblocks] */
    int           *dirids;      /* Array of directory ID's which contain blk */
    int            blockorigin; /* Origin (0 or 1) of block numbers */
    int            grouporigin; /* Origin (0 or 1) of group numbers */
    int            extentssize; /* size of each extent tuple */
    double        *extents;     /* min/max extents of coords of each block */
    int           *zonecounts;  /* array of zone counts for each block */
    int           *has_external_zones;  /* external flags for each block */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    int            lgroupings;  /* size of groupings array */
    int            *groupings;  /* Array of mesh-ids, group-ids, and counts */
    char          **groupnames; /* Array of group-names for groupings  */
    char          *mrgtree_name;/* optional name of assoc. mrgtree object */
    int            tv_connectivity;
    int            disjoint_mode;
    int            topo_dim;    /* Topological dimension; max of all blocks. */ 
    char          *file_ns;     /* namescheme for files (in lieu of meshnames) */
    char          *block_ns;    /* namescheme for block objects (in lieu of meshnames) */
    int            block_type;  /* constant block type for all blocks (in lieu of meshtypes) */
    int           *empty_list;  /* list of empty block #'s (option for namescheme) */
    int            empty_cnt;   /* size of empty list */
    int            repr_block_idx; /* index of a 'representative' block */
    char         **alt_nodenum_vars; 
    char         **alt_zonenum_vars; 
    char          *meshnames_alloc; /* original alloc of meshnames as string list */
} DBmultimesh;

/*----------------------------------------------------------------------------
 * Multi-Block Mesh Adjacency Object
 *--------------------------------------------------------------------------
 */
typedef struct DBmultimeshadj_ {
/*----------- Multi-Block Mesh Adjacency -----------*/
    int            nblocks;     /* Number of blocks in mesh */
    int            blockorigin; /* Origin (0 or 1) of block numbers */
    int           *meshtypes;   /* Array of mesh-type indicators [nblocks] */
    int           *nneighbors;  /* Array [nblocks] neighbor counts */

    int           lneighbors;
    int           *neighbors;   /* Array [lneighbors] neighbor block numbers */
    int           *back;        /* Array [lneighbors] neighbor block back */

    int            totlnodelists;
    int           *lnodelists;  /* Array [lneighbors] of node counts shared */
    int          **nodelists;   /* Array [lneighbors] nodelists shared */

    int            totlzonelists;
    int           *lzonelists;  /* Array [lneighbors] of zone counts adjacent */
    int          **zonelists;   /* Array [lneighbors] zonelists adjacent */
} DBmultimeshadj;

/*----------------------------------------------------------------------------
 * Multi-Block Variable Object
 *--------------------------------------------------------------------------
 */
typedef struct DBmultivar_ {
/*----------- Multi-Block Variable -----------*/
    int            id;          /* Identifier for this object  */
    int            nvars;       /* Number of variables   */
    int            ngroups;     /* Number of block groups in mesh */
    char         **varnames;    /* Variable names   */
    int           *vartypes;    /* variable types   */
    int            blockorigin; /* Origin (0 or 1) of block numbers */
    int            grouporigin; /* Origin (0 or 1) of group numbers */
    int            extentssize; /* size of each extent tuple */
    double        *extents;     /* min/max extents of each block */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char         **region_pnames;
    char          *mmesh_name;
    int            tensor_rank;    /* DB_VARTYPE_XXX */
    int            conserved;   /* indicates if the variable should be conserved
                                   under various operations such as interp. */
    int            extensive;   /* indicates if the variable reprsents an extensiv
                                   physical property (as opposed to intensive) */
    char          *file_ns;     /* namescheme for files (in lieu of meshnames) */
    char          *block_ns;    /* namescheme for block objects (in lieu of meshnames) */
    int            block_type;  /* constant block type for all blocks (in lieu of meshtypes) */
    int           *empty_list;  /* list of empty block #'s (option for namescheme) */
    int            empty_cnt;   /* size of empty list */
    int            repr_block_idx; /* index of a 'representative' block */
    double         missing_value; /* Value to indicate var data is invalid/missing */
    char          *varnames_alloc; /* original alloc of varnames as string list */
} DBmultivar;

/*-------------------------------------------------------------------------
 * Multi-material
 *-------------------------------------------------------------------------
 */
typedef struct DBmultimat_ {
    int            id;          /* Identifier for this object  */
    int            nmats;       /* Number of materials   */
    int            ngroups;     /* Number of block groups in mesh */
    char         **matnames;    /* names of constiuent DBmaterial objects */
    int            blockorigin; /* Origin (0 or 1) of block numbers */
    int            grouporigin; /* Origin (0 or 1) of group numbers */
    int           *mixlens;     /* array of mixlen values in each mat */
    int           *matcounts;   /* counts of unique materials in each block */
    int           *matlists;    /* list of materials in each block */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    int            nmatnos;     /* global number of materials over all pieces */
    int           *matnos;      /* global list of material numbers */
    char         **matcolors;   /* optional colors for materials */
    char         **material_names; /* optional names of the materials */
    int            allowmat0;   /* Flag to allow material "0" */
    char          *mmesh_name;
    char          *file_ns;     /* namescheme for files (in lieu of meshnames) */
    char          *block_ns;    /* namescheme for block objects (in lieu of meshnames) */
    int           *empty_list;  /* list of empty block #'s (option for namescheme) */
    int            empty_cnt;   /* size of empty list */
    int            repr_block_idx; /* index of a 'representative' block */
    char          *matnames_alloc; /* original alloc of matnames as string list */
} DBmultimat;

/*-------------------------------------------------------------------------
 * Multi-species
 *-------------------------------------------------------------------------
 */
typedef struct DBmultimatspecies_ {
    int            id;          /* Identifier for this object  */
    int            nspec;       /* Number of species   */
    int            ngroups;     /* Number of block groups in mesh */
    char         **specnames;   /* Species object names   */    
    int            blockorigin; /* Origin (0 or 1) of block numbers */
    int            grouporigin; /* Origin (0 or 1) of group numbers */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    int            nmat;        /* equiv. to nmatnos of a DBmultimat */
    int           *nmatspec;    /* equiv. to matnos of a DBmultimat */
    char         **species_names; /* optional names of the species */
    char         **speccolors;  /* optional colors for species */
    char          *file_ns;     /* namescheme for files (in lieu of meshnames) */
    char          *block_ns;    /* namescheme for block objects (in lieu of meshnames) */
    int           *empty_list;  /* list of empty block #'s (option for namescheme) */
    int            empty_cnt;   /* size of empty list */
    int            repr_block_idx; /* index of a 'representative' block */
    char          *specnames_alloc; /* original alloc of matnames as string list */
} DBmultimatspecies;

/*----------------------------------------------------------------------
 *  Definitions for the FaceList, ZoneList, and EdgeList structures
 *  used for describing UCD meshes.
 *----------------------------------------------------------------------
 */

#define DB_ZONETYPE_BEAM        10

#define DB_ZONETYPE_POLYGON     20
#define DB_ZONETYPE_TRIANGLE    23
#define DB_ZONETYPE_QUAD        24

#define DB_ZONETYPE_POLYHEDRON  30
#define DB_ZONETYPE_TET         34
#define DB_ZONETYPE_PYRAMID     35
#define DB_ZONETYPE_PRISM       36
#define DB_ZONETYPE_HEX         38

typedef struct DBzonelist_ {
    int            ndims;       /* Number of dimensions (2,3) */
    int            nzones;      /* Number of zones in list */
    int            nshapes;     /* Number of zone shapes */
    int           *shapecnt;    /* [nshapes] occurences of each shape */
    int           *shapesize;   /* [nshapes] Number of nodes per shape */
    int           *shapetype;   /* [nshapes] Type of shape */
    int           *nodelist;    /* Sequent lst of nodes which comprise zones */
    int            lnodelist;   /* Number of nodes in nodelist */
    int            origin;      /* '0' or '1' */
    int            min_index;   /* Index of first real zone */
    int            max_index;   /* Index of last real zone */

/*--------- Optional zone attributes ---------*/
    int           *zoneno;      /* [nzones] zone number of each zone */
    void          *gzoneno;     /* [nzones] global zone number of each zone */
    int            gnznodtype;  /* datatype for global node/zone ids */
    char          *ghost_zone_labels;
    char         **alt_zonenum_vars; 
} DBzonelist;

typedef struct DBphzonelist_ {
    int            nfaces;      /* Number of faces in facelist (aka "facetable") */
    int           *nodecnt;     /* Count of nodes in each face */
    int            lnodelist;   /* Length of nodelist used to construct faces */
    int           *nodelist;    /* List of nodes used in all faces */
    char          *extface;     /* boolean flag indicating if a face is external */
    int            nzones;      /* Number of zones in this zonelist */
    int           *facecnt;     /* Count of faces in each zone */
    int            lfacelist;   /* Length of facelist used to construct zones */
    int           *facelist;    /* List of faces used in all zones */
    int            origin;      /* '0' or '1' */
    int            lo_offset;   /* Index of first non-ghost zone */
    int            hi_offset;   /* Index of last non-ghost zone */

/*--------- Optional zone attributes ---------*/
    int           *zoneno;      /* [nzones] zone number of each zone */
    void          *gzoneno;     /* [nzones] global zone number of each zone */
    int            gnznodtype;  /* datatype for global node/zone ids */
    char          *ghost_zone_labels;
    char         **alt_zonenum_vars; 
} DBphzonelist;

typedef struct DBfacelist_ {
/*----------- Required components ------------*/
    int            ndims;       /* Number of dimensions (2,3) */
    int            nfaces;      /* Number of faces in list */
    int            origin;      /* '0' or '1' */
    int           *nodelist;    /* Sequent list of nodes comprise faces */
    int            lnodelist;   /* Number of nodes in nodelist */

/*----------- 3D components ------------------*/
    int            nshapes;     /* Number of face shapes */
    int           *shapecnt;    /* [nshapes] Num of occurences of each shape */
    int           *shapesize;   /* [nshapes] Number of nodes per shape */

/*----------- Optional type component---------*/
    int            ntypes;      /* Number of face types */
    int           *typelist;    /* [ntypes] Type ID for each type */
    int           *types;       /* [nfaces] Type info for each face */

/*--------- Optional node attributes ---------*/
    int           *nodeno;      /* [lnodelist] node number of each node */

/*----------- Optional zone-reference component---------*/
    int           *zoneno;      /* [nfaces] Zone number for each face */
} DBfacelist;

typedef struct DBedgelist_ {
    int            ndims;       /* Number of dimensions (2,3) */
    int            nedges;      /* Number of edges */
    int           *edge_beg;    /* [nedges] */
    int           *edge_end;    /* [nedges] */
    int            origin;      /* '0' or '1' */
} DBedgelist;

typedef struct DBquadmesh_ {
/*----------- Quad Mesh -----------*/
    int            id;          /* Identifier for this object */
    int            block_no;    /* Block number for this mesh */
    int            group_no;    /* Block group number for this mesh */
    char          *name;        /* Name associated with mesh */
    int            cycle;       /* Problem cycle number */
    int            coord_sys;   /* Cartesian, cylindrical, spherical */
    int            major_order; /* 1 indicates row-major for multi-d arrays */
    int            stride[3];   /* Offsets to adjacent elements  */
    int            coordtype;   /* Coord array type: collinear,
                                 * non-collinear */
    int            facetype;    /* Zone face type: rect, curv */
    int            planar;      /* Sentinel: zones represent area or volume? */

    void          *coords[3];   /* Mesh node coordinate ptrs [ndims] */
    int            datatype;    /* Type of coordinate arrays (double,float) */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
   /*
    * The following two fields really only contain 3 elements.  However, silo
    * contains a bug in PJ_ReadVariable() as called by DBGetQuadmesh() which
    * can cause three doubles to be stored there instead of three floats.
    */
    float          min_extents[6];  /* Min mesh extents [ndims] */
    float          max_extents[6];  /* Max mesh extents [ndims] */

    char          *labels[3];   /* Label associated with each dimension */
    char          *units[3];    /* Units for variable, e.g, 'mm/ms' */
    int            ndims;       /* Number of computational dimensions */
    int            nspace;      /* Number of physical dimensions */
    int            nnodes;      /* Total number of nodes */

    int            dims[3];     /* Number of nodes per dimension */
    int            origin;      /* '0' or '1' */
    int            min_index[3];   /* Index in each dimension of 1st
                                    * non-phoney */
    int            max_index[3];   /* Index in each dimension of last
                                    * non-phoney */
    int            base_index[3];  /* Lowest real i,j,k value for this block */
    int            start_index[3]; /* i,j,k values corresponding to original
                                    * mesh */
    int            size_index[3];  /* Number of nodes per dimension for 
                                    * original mesh */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char          *mrgtree_name; /* optional name of assoc. mrgtree object */
    char          *ghost_node_labels;
    char          *ghost_zone_labels;
    char         **alt_nodenum_vars; 
    char         **alt_zonenum_vars; 
} DBquadmesh;

typedef struct DBucdmesh_ {
/*----------- Unstructured Cell Data (UCD) Mesh -----------*/
    int            id;          /* Identifier for this object */
    int            block_no;    /* Block number for this mesh */
    int            group_no;    /* Block group number for this mesh */
    char          *name;        /* Name associated with mesh */
    int            cycle;       /* Problem cycle number */
    int            coord_sys;   /* Coordinate system */
    int            topo_dim;    /* Topological dimension. */ 
    char          *units[3];    /* Units for variable, e.g, 'mm/ms' */
    char          *labels[3];   /* Label associated with each dimension */

    void          *coords[3];   /* Mesh node coordinates */
    int            datatype;    /* Type of coordinate arrays (double,float) */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
   /*
    * The following two fields really only contain 3 elements.  However, silo
    * contains a bug in PJ_ReadVariable() as called by DBGetUcdmesh() which
    * can cause three doubles to be stored there instead of three floats.
    */
    float          min_extents[6];  /* Min mesh extents [ndims] */
    float          max_extents[6];  /* Max mesh extents [ndims] */

    int            ndims;       /* Number of computational dimensions */
    int            nnodes;      /* Total number of nodes */
    int            origin;      /* '0' or '1' */

    DBfacelist    *faces;       /* Data structure describing mesh faces */
    DBzonelist    *zones;       /* Data structure describing mesh zones */
    DBedgelist    *edges;       /* Data struct describing mesh edges
                                 * (option) */

/*--------- Optional node attributes ---------*/
    void          *gnodeno;     /* [nnodes] global node number of each node */

/*--------- Optional zone attributes ---------*/
    int           *nodeno;      /* [nnodes] node number of each node */

/*--------- Optional polyhedral zonelist ---------*/
    DBphzonelist  *phzones;     /* Data structure describing mesh zones */

    int            guihide;     /* Flag to hide from post-processor's GUI */
    char          *mrgtree_name; /* optional name of assoc. mrgtree object */
    int            tv_connectivity;
    int            disjoint_mode;
    int            gnznodtype;  /* datatype for global node/zone ids */
    char          *ghost_node_labels;
    char         **alt_nodenum_vars; 
} DBucdmesh;

/*----------------------------------------------------------------------------
 * Database Mesh-Variable Object
 *---------------------------------------------------------------------------
 */
typedef struct DBquadvar_ {
/*----------- Quad Variable -----------*/
    int            id;          /* Identifier for this object */
    char          *name;        /* Name of variable */
    char          *units;       /* Units for variable, e.g, 'mm/ms' */
    char          *label;       /* Label (perhaps for editing purposes) */
    int            cycle;       /* Problem cycle number */
    int            meshid;      /* Identifier for associated mesh (Deprecated Sep2005) */

    void         **vals;        /* Array of pointers to data arrays */
    int            datatype;    /* Type of data pointed to by 'val' */
    int            nels;        /* Number of elements in each array */
    int            nvals;       /* Number of arrays pointed to by 'vals' */
    int            ndims;       /* Rank of variable */
    int            dims[3];     /* Number of elements in each dimension */

    int            major_order; /* 1 indicates row-major for multi-d arrays */
    int            stride[3];   /* Offsets to adjacent elements  */
    int            min_index[3];  /* Index in each dimension of 1st
                                   * non-phoney */
    int            max_index[3];  /* Index in each dimension of last
                                   * non-phoney */
    int            origin;      /* '0' or '1' */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
   /*
    * The following field really only contains 3 elements.  However, silo
    * contains a bug in PJ_ReadVariable() as called by DBGetQuadvar() which
    * can cause three doubles to be stored there instead of three floats.
    */
    float          align[6];    /* Centering and alignment per dimension */

    void         **mixvals;     /* nvals ptrs to data arrays for mixed zones */
    int            mixlen;      /* Num of elmts in each mixed zone data
                                 * array */

    int            use_specmf;  /* Flag indicating whether to apply species
                                 * mass fractions to the variable. */

    int            ascii_labels;/* Treat variable values as ASCII values
                                   by rounding to the nearest integer in
                                   the range [0, 255] */
    char          *meshname;    /* Name of associated mesh */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char         **region_pnames;
    int            conserved;   /* indicates if the variable should be conserved
                                   under various operations such as interp. */
    int            extensive;   /* indicates if the variable reprsents an extensiv
                                   physical property (as opposed to intensive) */
    int            centering;   /* explicit centering knowledge; should agree
                                   with alignment. */
    double         missing_value; /* Value to indicate var data is invalid/missing */
} DBquadvar;

typedef struct DBucdvar_ {
/*----------- Unstructured Cell Data (UCD) Variable -----------*/
    int            id;          /* Identifier for this object */
    char          *name;        /* Name of variable */
    int            cycle;       /* Problem cycle number */
    char          *units;       /* Units for variable, e.g, 'mm/ms' */
    char          *label;       /* Label (perhaps for editing purposes) */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
    int            meshid;      /* Identifier for associated mesh (Deprecated Sep2005) */

    void         **vals;        /* Array of pointers to data arrays */
    int            datatype;    /* Type of data pointed to by 'vals' */
    int            nels;        /* Number of elements in each array */
    int            nvals;       /* Number of arrays pointed to by 'vals' */
    int            ndims;       /* Rank of variable */
    int            origin;      /* '0' or '1' */

    int            centering;   /* Centering within mesh (nodal or zonal) */
    void         **mixvals;     /* nvals ptrs to data arrays for mixed zones */
    int            mixlen;      /* Num of elmts in each mixed zone data
                                 * array */

    int            use_specmf;  /* Flag indicating whether to apply species
                                 * mass fractions to the variable. */
    int            ascii_labels;/* Treat variable values as ASCII values
                                   by rounding to the nearest integer in
                                   the range [0, 255] */
    char          *meshname;    /* Name of associated mesh */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char         **region_pnames;
    int            conserved;   /* indicates if the variable should be conserved
                                   under various operations such as interp. */
    int            extensive;   /* indicates if the variable reprsents an extensiv
                                   physical property (as opposed to intensive) */
    double         missing_value; /* Value to indicate var data is invalid/missing */
} DBucdvar;

typedef struct DBmeshvar_ {
/*----------- Generic Mesh-Data Variable -----------*/
    int            id;          /* Identifier for this object */
    char          *name;        /* Name of variable */
    char          *units;       /* Units for variable, e.g, 'mm/ms' */
    char          *label;       /* Label (perhaps for editing purposes) */
    int            cycle;       /* Problem cycle number */
    int            meshid;      /* Identifier for associated mesh (Deprecated Sep2005) */

    void         **vals;        /* Array of pointers to data arrays */
    int            datatype;    /* Type of data pointed to by 'val' */
    int            nels;        /* Number of elements in each array */
    int            nvals;       /* Number of arrays pointed to by 'vals' */
    int            nspace;      /* Spatial rank of variable */
    int            ndims;       /* Rank of 'vals' array(s) (computatnl rank) */

    int            origin;      /* '0' or '1' */
    int            centering;   /* Centering within mesh (nodal,zonal,other) */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
   /*
    * The following field really only contains 3 elements.  However, silo
    * contains a bug in PJ_ReadVariable() as called by DBGetPointvar() which
    * can cause three doubles to be stored there instead of three floats.
    */
    float          align[6];    /* Alignmnt per dimension if
                                 * centering==other */

    /* Stuff for multi-dimensional arrays (ndims > 1) */
    int            dims[3];     /* Number of elements in each dimension */
    int            major_order; /* 1 indicates row-major for multi-d arrays */
    int            stride[3];   /* Offsets to adjacent elements  */
   /*
    * The following two fields really only contain 3 elements.  However, silo
    * contains a bug in PJ_ReadVariable() as called by DBGetUcdmesh() which
    * can cause three doubles to be stored there instead of three floats.
    */
    int            min_index[6];  /* Index in each dimension of 1st
                                   * non-phoney */
    int            max_index[6];  /* Index in each dimension of last
                                    non-phoney */

    int            ascii_labels;/* Treat variable values as ASCII values
                                   by rounding to the nearest integer in
                                   the range [0, 255] */
    char          *meshname;      /* Name of associated mesh */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char         **region_pnames;
    int            conserved;   /* indicates if the variable should be conserved
                                   under various operations such as interp. */
    int            extensive;   /* indicates if the variable reprsents an extensiv
                                   physical property (as opposed to intensive) */
    double         missing_value; /* Value to indicate var data is invalid/missing */
} DBmeshvar;
typedef DBmeshvar DBpointvar; /* better named alias for pointvar */

typedef struct DBmaterial_ {
/*----------- Material Information -----------*/
    int            id;          /* Identifier */
    char          *name;        /* Name of this material information block */
    int            ndims;       /* Rank of 'matlist' variable */
    int            origin;      /* '0' or '1' */
    int            dims[3];     /* Number of elements in each dimension */
    int            major_order; /* 1 indicates row-major for multi-d arrays */
    int            stride[3];   /* Offsets to adjacent elements in matlist */

    int            nmat;        /* Number of materials */
    int           *matnos;      /* Array [nmat] of valid material numbers */
    char         **matnames;    /* Array of material names   */
    int           *matlist;     /* Array[nzone] w/ mat. number or mix index */
    int            mixlen;      /* Length of mixed data arrays (mix_xxx) */
    int            datatype;    /* Type of volume-fractions (double,float) */
    void          *mix_vf;      /* Array [mixlen] of volume fractions */
    int           *mix_next;    /* Array [mixlen] of mixed data indeces */
    int           *mix_mat;     /* Array [mixlen] of material numbers */
    int           *mix_zone;    /* Array [mixlen] of back pointers to mesh */

    char         **matcolors;   /* Array of material colors */
    char          *meshname;    /* Name of associated mesh */
    int            allowmat0;   /* Flag to allow material "0" */
    int            guihide;     /* Flag to hide from post-processor's GUI */
} DBmaterial;

typedef struct DBmatspecies_ {
/*----------- Species Information -----------*/
    int            id;          /* Identifier */
    char          *name;        /* Name of this matspecies information block */
    char          *matname;     /* Name of material object with which the
                                 * material species object is associated. */
    int            nmat;        /* Number of materials */
    int           *nmatspec;    /* Array of lngth nmat of the num of material
                                 * species associated with each material. */
    int            ndims;       /* Rank of 'speclist' variable */
    int            dims[3];     /* Number of elements in each dimension of the
                                 * 'speclist' variable. */
    int            major_order; /* 1 indicates row-major for multi-d arrays */
    int            stride[3];   /* Offsts to adjacent elmts in 'speclist'  */

    int            nspecies_mf; /* Total number of species mass fractions. */
    void          *species_mf;  /* Array of length nspecies_mf of mass
                                 * frations of the material species. */
    int           *speclist;    /* Zone array of dimensions described by ndims
                                 * and dims.  Each element of the array is an
                                 * index into one of the species mass fraction
                                 * arrays.  A positive value is the index in
                                 * the species_mf array of the mass fractions
                                 * of the clean zone's material species:
                                 * species_mf[speclist[i]] is the mass fraction
                                 * of the first species of material matlist[i]
                                 * in zone i. A negative value means that the
                                 * zone is a mixed zone and that the array
                                 * mix_speclist contains the index to the
                                 * species mas fractions: -speclist[i] is the
                                 * index in the 'mix_speclist' array for zone
                                 * i. */
    int            mixlen;      /* Length of 'mix_speclist' array. */
    int           *mix_speclist;  /* Array of lgth mixlen of 1-orig indices
                                   * into the 'species_mf' array.
                                   * species_mf[mix_speclist[j]] is the index
                                   * in array species_mf' of the first of the
                                   * mass fractions for material
                                   * mix_mat[j]. */

    int            datatype;    /* Datatype of mass fraction data. */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char         **specnames;   /* Array of species names; length is sum of nmatspec   */
    char         **speccolors;  /* Array of species colors; length is sum of nmatspec */
} DBmatspecies;

typedef struct DBcsgzonelist_ {
/*----------- CSG Zonelist -----------*/
    int            nregs;       /* Number of regions in regionlist */
    int            origin;      /* '0' or '1' */

    int           *typeflags;   /* [nregs] type info about each region */
    int           *leftids;     /* [nregs] left operand region refs */
    int           *rightids;    /* [nregs] right operand region refs */
    void          *xform;       /* [lxforms] transformation coefficients */
    int            lxform;      /* length of xforms array */
    int            datatype;    /* type of data in xforms array */

    int            nzones;      /* number of zones */
    int           *zonelist;    /* [nzones] region ids (complete regions) */
    int            min_index;   /* Index of first real zone */
    int            max_index;   /* Index of last real zone */

/*--------- Optional zone attributes ---------*/
    char         **regnames;   /* [nregs] names of each region */
    char         **zonenames;  /* [nzones] names of each zone */
    char         **alt_zonenum_vars; 
} DBcsgzonelist;

typedef struct DBcsgmesh_ {
/*----------- CSG Mesh -----------*/
    int            block_no;    /* Block number for this mesh */
    int            group_no;    /* Block group number for this mesh */
    char          *name;        /* Name associated with mesh */
    int            cycle;       /* Problem cycle number */
    char          *units[3];    /* Units for variable, e.g, 'mm/ms' */
    char          *labels[3];   /* Label associated with each dimension */

    int            nbounds;     /* Total number of boundaries */
    int           *typeflags;   /* nbounds boundary type info flags */
    int           *bndids;      /* optional, nbounds explicit ids */

    void          *coeffs;      /* coefficients in the representation of
                                   each boundary */
    int            lcoeffs;     /* length of coeffs array */
    int           *coeffidx;    /* array of nbounds offsets into coeffs
                                   for each boundary's coefficients */
    int            datatype;    /* data type of coeffs data */

    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */
    double         min_extents[3];  /* Min mesh extents [ndims] */
    double         max_extents[3];  /* Max mesh extents [ndims] */

    int            ndims;       /* Number of spatial & topological dimensions */
    int            origin;      /* '0' or '1' */

    DBcsgzonelist *zones;       /* Data structure describing mesh zones */

/*--------- Optional boundary attributes ---------*/
    char         **bndnames;     /* [nbounds] boundary names */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char          *mrgtree_name; /* optional name of assoc. mrgtree object */
    int            tv_connectivity;
    int            disjoint_mode;
    char         **alt_nodenum_vars; 
} DBcsgmesh;

typedef struct DBcsgvar_ {
/*----------- CSG Variable -----------*/
    char          *name;        /* Name of variable */
    int            cycle;       /* Problem cycle number */
    char          *units;       /* Units for variable, e.g, 'mm/ms' */
    char          *label;       /* Label (perhaps for editing purposes) */
    float          time;        /* Problem time */
    double         dtime;       /* Problem time, double data type */

    void         **vals;        /* Array of pointers to data arrays */
    int            datatype;    /* Type of data pointed to by 'vals' */
    int            nels;        /* Number of elements in each array */
    int            nvals;       /* Number of arrays pointed to by 'vals' */

    int            centering;   /* Centering within mesh (nodal or zonal) */

    int            use_specmf;  /* Flag indicating whether to apply species
                                 * mass fractions to the variable. */
    int            ascii_labels;/* Treat variable values as ASCII values
                                   by rounding to the nearest integer in
                                   the range [0, 255] */
    char          *meshname;    /* Name of associated mesh */
    int            guihide;     /* Flag to hide from post-processor's GUI */
    char         **region_pnames;
    int            conserved;   /* indicates if the variable should be conserved
                                   under various operations such as interp. */
    int            extensive;   /* indicates if the variable reprsents an extensiv
                                   physical property (as opposed to intensive) */
    double         missing_value; /* Value to indicate var data is invalid/missing */
} DBcsgvar;

/*-------------------------------------------------------------------------
 * A compound array is an array whose elements are simple arrays. A simple
 * array is an array whose elements are all of the same primitive data
 * type: float, double, integer, long...  All of the simple arrays of
 * a compound array have elements of the same data type.
 *-------------------------------------------------------------------------
 */
typedef struct DBcompoundarray_ {
    int            id;          /*identifier of the compound array */
    char          *name;        /*name of te compound array  */
    char         **elemnames;   /*names of the simple array elements */
    int           *elemlengths; /*lengths of the simple arrays  */
    int            nelems;      /*number of simple arrays  */
    void          *values;      /*simple array values   */
    int            nvalues;     /*sum reduction of `elemlengths' vector */
    int            datatype;    /*simple array element data type */
} DBcompoundarray;

typedef struct DBoptlist_ {

    int           *options;     /* Vector of option identifiers */
    void         **values;      /* Vector of pointers to option values */
    int            numopts;     /* Number of options defined */
    int            maxopts;     /* Total length of option/value arrays */

} DBoptlist;

#define DB_MAX_H5_OBJ_VALS 64
typedef struct DBobject_ {

    char          *name;
    char          *type;        /* Type of group/object */
    char         **comp_names;  /* Array of component names */
    char         **pdb_names;   /* Array of internal (PDB) variable names */
    int            ncomponents; /* Number of components */
    int            maxcomponents;  /* Max number of components */

    /* fields below are a hack for HDF5 driver to handle
       customization of 'standard' objects */
    char           h5_vals[DB_MAX_H5_OBJ_VALS*3*sizeof(double)];
    int            h5_offs[DB_MAX_H5_OBJ_VALS];
    int            h5_sizes[DB_MAX_H5_OBJ_VALS];
    int            h5_types[DB_MAX_H5_OBJ_VALS];
    char          *h5_names[DB_MAX_H5_OBJ_VALS];
} DBobject;

typedef struct _DBmrgtnode {
    char *name;
    int  narray;
    char **names;
    int type_info_bits;
    int max_children;
    char *maps_name;
    int nsegs;
    int *seg_ids;
    int *seg_lens;
    int *seg_types;
    int num_children;
    struct _DBmrgtnode **children;

    /* internal stuff to support updates, i/o, etc. */
    int walk_order;
    struct _DBmrgtnode  *parent;
} DBmrgtnode;

typedef void (*DBmrgwalkcb)(DBmrgtnode const *tnode, int nat_node_num, void *data);

typedef struct _DBmrgtree {
    char *name;
    char *src_mesh_name;
    int src_mesh_type;
    int type_info_bits;
    int num_nodes;
    DBmrgtnode *root;
    DBmrgtnode *cwr;

    char **mrgvar_onames;
    char **mrgvar_rnames;
} DBmrgtree;

typedef struct _DBmrgvar {
    char *name;
    char *mrgt_name;
    int ncomps;
    char **compnames;
    int nregns;
    char **reg_pnames;
    int datatype;
    void **data;
} DBmrgvar ;

typedef struct _DBgroupelmap {
    char *name;
    int num_segments;
    int *groupel_types;
    int *segment_lengths;
    int *segment_ids;
    int **segment_data;
    void **segment_fracs;
    int fracs_data_type;
} DBgroupelmap;

#if !defined(DB_MAX_EXPNS) /* NO_FORTRAN_DEFINE */
#define DB_MAX_EXPNS 32 /* NO_FORTRAN_DEFINE */
#endif

typedef struct _DBnamescheme
{
    char *fmt;              /* orig. format string */
    char const **fmtptrs;   /* ptrs into first (printf) part of fmt for each conversion spec. */
    int fmtlen;             /* len of first part of fmt */
    int ncspecs;            /* # of conversion specs in first part of fmt */
    char delim;             /* delimiter char used for parts of fmt */
    int nembed;             /* number of last embedded namescheme encountered (used in eval process) */
    struct _DBnamescheme *embedns[DB_MAX_EXPNS]; /* ptrs to copies of embedded nameschemes */
    int arralloc;           /* flag indicating if Silo allocated the arrays or not */
    int narrefs;            /* number of array refs in conversion specs */
    char **arrnames;        /* array names used by array refs */
    void **arrvals;         /* pointer to actual array data assoc. with each name */
    int  *arrsizes;         /* size of each array (only needed for deallocating external arrays of strings) */
    char **exprstrs;        /* expressions to be evaluated for each conv. spec. */
} DBnamescheme;

typedef struct _DBmemfile_bufinfo
{
    void *buf;
    size_t size;
    size_t used;
} DBmemfile_bufinfo;

typedef struct DBfile *___DUMMY_TYPE;  /* Satisfy ANSI scope rules */

/*
 * All file formats are now anonymous except for the public properties
 * and public methods.
 */
typedef struct DBfile_pub {

    /* Public Properties */
    char          *name;        /*name of file    */
    int            type;        /*file type    */
    DBtoc         *toc;         /*table of contents   */
    int            dirid;       /*directory ID    */
    int            fileid;      /*unique file id [0,DB_NFILES-1] */
    int            pathok;      /*driver handles paths in names */
    int            Grab;        /*drive has access to low-level interface */
    void          *GrabId;      /*pointer to low-level driver descriptor */
    char          *file_lib_version; /* version of lib file was created with */
    /* we use pointer to struct here to avoid having to include private type
       information in the public header file */
    struct SILO_Globals_t *file_scope_globals;

    /* Public Methods */
    int            (*close)(struct DBfile *);
    int            (*exist)(struct DBfile *, char const *);
    int            (*newtoc)(struct DBfile *);
    DBObjectType   (*inqvartype)(struct DBfile *, char const *);
    int            (*uninstall)(struct DBfile *);
    DBobject      *(*g_obj)(struct DBfile *, char const *);
    int            (*c_obj)(struct DBfile *, DBobject const *, int);
    int            (*w_obj)(struct DBfile *, DBobject const *, int);
    void          *(*g_comp)(struct DBfile *, char const *, char const *);
    int            (*g_comptyp)(struct DBfile *, char const *, char const *);
    int            (*w_comp)(struct DBfile *, DBobject *, char const *, char const *,
                       char const *, void const *, int, long const *);
    int            (*write) (struct DBfile *, char const *, void const *, int const *, int, int);
    int            (*writeslice)(struct DBfile *, char const *array_name, void const *data,
                       int datatype, int const *offsets, int const *lens, int const *stides,
                       int const *dims, int ndim);
    int            (*g_dir)(struct DBfile *, char *);
    int            (*mkdir)(struct DBfile *, char const *);
    int            (*cd)(struct DBfile *, char const *);
    int            (*r_var)(struct DBfile *, char const *, void *);
    int            (*module)(struct DBfile *, FILE *);
    int            (*r_varslice)(struct DBfile *, char const *, int const *, int const *, int const *,
                       int, void *);
    int            (*g_compnames)(struct DBfile *, char const *, char ***, char ***);
    DBcompoundarray *(*g_ca)(struct DBfile *, char const *);
    DBcurve       *(*g_cu)(struct DBfile *, char const *);
    DBdefvars     *(*g_defv)(struct DBfile *, char const *);
    DBmaterial    *(*g_ma)(struct DBfile *, char const *);
    DBmatspecies  *(*g_ms)(struct DBfile *, char const *);
    DBmultimesh   *(*g_mm)(struct DBfile *, char const *);
    DBmultivar    *(*g_mv)(struct DBfile *, char const *);
    DBmultimat    *(*g_mt)(struct DBfile *, char const *);
    DBmultimatspecies *(*g_mms)(struct DBfile *, char const *);
    DBpointmesh   *(*g_pm)(struct DBfile *, char const *);
    DBmeshvar     *(*g_pv)(struct DBfile *, char const *);
    DBquadmesh    *(*g_qm)(struct DBfile *, char const *);
    DBquadvar     *(*g_qv)(struct DBfile *, char const *);
    DBucdmesh     *(*g_um)(struct DBfile *, char const *);
    DBucdvar      *(*g_uv)(struct DBfile *, char const *);
    DBfacelist    *(*g_fl)(struct DBfile *, char const *);
    DBzonelist    *(*g_zl)(struct DBfile *, char const *);
    void          *(*g_var)(struct DBfile *, char const *);
    int            (*g_varbl)(struct DBfile *, char const *);  /*byte length */
    int            (*g_varlen)(struct DBfile *, char const *);  /*nelems */
    int            (*g_vardims)(struct DBfile*, char const *, int, int *); /*dims*/
    int            (*g_vartype)(struct DBfile *, char const *);
    int            (*i_meshname)(struct DBfile *, char const *, char *);
    int            (*i_meshtype)(struct DBfile *, char const *);
    int            (*p_ca)(struct DBfile *dbfile, char const *name, char const * const *elemnames,
                       int const *elemlens, int nelems, void const *values, int nvalues,
                       int datatype, DBoptlist const *);
    int            (*p_cu)(struct DBfile *dbfile, char const *name, void const *xvals,
                       void const *yvals, int datatype, int npts, DBoptlist const *opts);
    int            (*p_defv)(struct DBfile *dbfile, char const *name, int ndefs,
                       char const * const *names, int const *types, char const * const *defns,
                       DBoptlist const * const *opts);
    int            (*p_fl)(struct DBfile *dbfile, char const *name, int nfaces, int ndims,
                       int const *nodelist, int lnodelist, int origin, int const *zoneno,
                       int const *shapesize, int const *shapecnt, int nshapes, int const *types,
                       int const *typelist, int ntypes);
    int            (*p_ma)(struct DBfile *dbfile, char const *name, char const *meshname,
                       int nmat, int const *matnos, int const *matlist, int const *dims,
                       int ndims, int const *mix_next, int const *mix_mat, int const *mix_zone,
                       DBVCP1_t mix_vf, int mixlen, int datatype, DBoptlist const *);
    int            (*p_ms)(struct DBfile *, char const *, char const *, int, int const *, int const *,
                       int const *, int, int, DBVCP1_t, int const *, int, int, DBoptlist const *);
    int            (*p_mm)(struct DBfile *, char const *, int, char const * const *, int const *,
                       DBoptlist const *);
    int            (*p_mv)(struct DBfile *, char const *, int, char const * const *, int const *,
                       DBoptlist const *);
    int            (*p_mt)(struct DBfile *, char const *, int, char const * const *, DBoptlist const *);
    int            (*p_mms)(struct DBfile *, char const *, int, char const * const *, DBoptlist const *);
    int            (*p_pm)(struct DBfile *, char const *, int, DBVCP2_t, int, int, DBoptlist const *);
    int            (*p_pv)(struct DBfile *, char const *, char const *, int, DBVCP2_t, int,
                       int, DBoptlist const *);
    int            (*p_qm)(struct DBfile *, char const *, char const * const *, DBVCP2_t, int const *,
                       int, int, int, DBoptlist const *);
    int            (*p_qv)(struct DBfile *, char const *, char const *, int, char const * const *, DBVCP2_t,
                       int const *, int, DBVCP2_t, int, int, int, DBoptlist const *);
    int            (*p_um)(struct DBfile *, char const *, int, char const * const *, DBVCP2_t,
                       int, int, char const *, char const *, int, DBoptlist const *);
    int            (*p_sm)(struct DBfile *, char const *, char const *,
                       int, char const *, char const *, DBoptlist const *);
    int            (*p_uv)(struct DBfile *, char const *, char const *, int, char const * const *,
                       DBVCP2_t, int, DBVCP2_t, int, int, int, DBoptlist const *);
    int            (*p_zl)(struct DBfile *, char const *, int, int, int const *, int, int,
                       int const *, int const *, int);
    int            (*p_zl2)(struct DBfile *, char const *, int, int, int const *, int, int,
                       int, int, int const *, int const *, int const *, int, DBoptlist const *);
    DBphzonelist  *(*g_phzl)(struct DBfile *, char const *);
    int            (*p_phzl)(struct DBfile *, char const *, int, int const *, int, int const *,
                       char const *, int, int const *, int, int const *, int, int, int, DBoptlist const *);
    int            (*p_csgzl)(struct DBfile *, char const *, int, int const *, int const *,
                       int const *, void const *, int, int, int, int const *, DBoptlist const *);
    DBcsgzonelist *(*g_csgzl)(struct DBfile *, char const *);
    int            (*p_csgm)(struct DBfile *, char const *, int, int, int const *, int const *,
                       void const *, int, int, double const *, char const *, DBoptlist const *);
    DBcsgmesh     *(*g_csgm)(struct DBfile *, char const *);
    int            (*p_csgv)(struct DBfile *, char const *, char const *, int,
                       char const * const *, void const * const *, int, int, int, DBoptlist const *);
    DBcsgvar      *(*g_csgv)(struct DBfile *, char const *);
    DBmultimeshadj *(*g_mmadj)(struct DBfile *, char const *, int, int const *);
    int            (*p_mmadj)(struct DBfile *, char const *, int, int const *, int const *,
                       int const *, int const *, int const *, int const * const *, int const *,
                       int const * const *, DBoptlist const *optlist);
    int            (*p_mrgt)(struct DBfile *dbfile, char const *name, char const *mesh_name,
                       DBmrgtree const *tree, DBoptlist const *opts);
    DBmrgtree     *(*g_mrgt)(struct DBfile *, char const *name);
    int            (*p_grplm)(struct DBfile *dbfile, char const *map_name, int num_segments,
                       int const *groupel_types, int const *segment_lengths, int const *segment_ids,
		       int const * const *segment_data, void const * const *segment_fracs,
                       int fracs_data_type, DBoptlist const *opts);
    DBgroupelmap  *(*g_grplm)(struct DBfile *dbfile, char const *name);
    int            (*p_mrgv)(struct DBfile *dbfile, char const *name, char const *mrgt_name,
                       int ncomps, char const * const *compnames, int nregns,
                       char const * const *reg_pnames, int datatype, void const * const *data,
                       DBoptlist const *opts);
    DBmrgvar      *(*g_mrgv)(struct DBfile *dbfile, char const *name);
    int            (*free_z)(struct DBfile *, char const *);
    int            (*cpdir)(struct DBfile *, char const *, struct DBfile *, char const *);
    int            (*sort_obo)(struct DBfile *dbfile, int nobjs, char const *const *obj_names, int *ranks);
    int            (*flush)(struct DBfile *);
    int            (*r_varvals)(struct DBfile *, char const *, int, int, int, void const *, void **, int*, int*);
    int            (*g_varblf)(struct DBfile *, char const *);  /*byte length in file */
    int            (*cpnobjs)(int, struct DBfile *, char const * const *, struct DBfile *, char const * const *);
    int            (*mksymlink)(struct DBfile *, char const *, char const *);
    int            (*g_symlink)(struct DBfile *, char const *, char *);
} DBfile_pub;

typedef struct DBfile {
    DBfile_pub     pub;
    /*private part follows per device driver */
} DBfile;

typedef void (*DBErrFunc_t)(char *);

/*-------------------------------------------------------------------------
 * Public global variables.
 *-------------------------------------------------------------------------
 */
SILO_API extern int     DBDebugAPI;      /*file desc for debug messages, or zero */
SILO_API extern int     db_errno;        /*error number of last error */
SILO_API extern char    db_errfunc[];    /*name of erring function */

#ifndef DB_MAIN
SILO_API extern DBfile *(*DBOpenCB[])(char const *, int, int);
SILO_API extern DBfile *(*DBCreateCB[])(char const *, int, int, int, char const *);
SILO_API extern int     (*DBFSingleCB[])(int);
#endif

#define SILO_VSTRING_NAME "_silolibinfo"
#define SILO_VSTRING PACKAGE_VERSION
SILO_API extern int SILO_VERS_TAG;
#define SiloCheckVersion SILO_VERS_TAG = 1

/* define versions of Silo this version is backward ABI compatible with */
SILO_API extern int Silo_version_4_10;

/*
 * SILO API FUNCTIONS 
 */

/* Error handling and other global library behavior */
SILO_API extern void                   DBShowErrors(int, DBErrFunc_t);
SILO_API extern DBErrFunc_t            DBErrfunc(void);
SILO_API extern int                    DBErrlvl(void);
SILO_API extern char const *           DBErrString(void);   /* last error string */
SILO_API extern char const *           DBErrFuncname(void); /* last error'ing function */
SILO_API extern int                    DBErrno(void);       /* last error number */
/* Designed to prevent accidental use of old interface by forcing a human readable compile time error */
#define DBSetDataReadMask(A) ,DBSetDataReadMask_is_replaced_with_DBSetDataReadMask2_using_unsigned_long_long
#define DBGetDataReadMask() ,DBGetDataReadMask_is_replaced_with_DBGetDataReadMask2_using_unsigned_long_long
SILO_API extern unsigned long long     DBSetDataReadMask2(unsigned long long);
SILO_API extern unsigned long long     DBGetDataReadMask2(void);
SILO_API extern unsigned long long     DBSetDataReadMask2File(DBfile *f, unsigned long long);
SILO_API extern unsigned long long     DBGetDataReadMask2File(DBfile *f);
SILO_API extern char *                 DBGetDatatypeString(int datatype);
SILO_API extern int                    DBSetAllowOverwrites(int allow);
SILO_API extern int                    DBGetAllowOverwrites(void);
SILO_API extern int                    DBSetAllowOverwritesFile(DBfile *f, int allow);
SILO_API extern int                    DBGetAllowOverwritesFile(DBfile *f);
SILO_API extern int                    DBSetAllowEmptyObjects(int allow);
SILO_API extern int                    DBGetAllowEmptyObjects(void);
SILO_API extern int                    DBSetAllowEmptyObjectsFile(DBfile *f, int allow);
SILO_API extern int                    DBGetAllowEmptyObjectsFile(DBfile *f);
SILO_API extern int                    DBSetEnableChecksums(int enable);
SILO_API extern int                    DBGetEnableChecksums(void);
SILO_API extern int                    DBSetEnableChecksumsFile(DBfile *f, int enable);
SILO_API extern int                    DBGetEnableChecksumsFile(DBfile *f);
SILO_API extern void                   DBSetCompression(char const *);
SILO_API extern char const *           DBGetCompression(void);
SILO_API extern void                   DBSetCompressionFile(DBfile *f, char const *);
SILO_API extern char const *           DBGetCompressionFile(DBfile *f);
SILO_API extern int                    DBSetFriendlyHDF5Names(int enable);
SILO_API extern int                    DBGetFriendlyHDF5Names(void);
SILO_API extern int                    DBSetFriendlyHDF5NamesFile(DBfile *f, int enable);
SILO_API extern int                    DBGetFriendlyHDF5NamesFile(DBfile *f);
SILO_API extern int                    DBSetDeprecateWarnings(int max);
SILO_API extern int                    DBGetDeprecateWarnings(void);
SILO_API extern int                    DBSetDeprecateWarningsFile(DBfile *f, int max);
SILO_API extern int                    DBGetDeprecateWarningsFile(DBfile *f);
SILO_API extern int                    DBSetAllowLongStrComponents(int allow);
SILO_API extern int                    DBGetAllowLongStrComponents(void);
SILO_API extern int                    DBSetAllowLongStrComponentsFile(DBfile *f, int allow);
SILO_API extern int                    DBGetAllowLongStrComponentsFile(DBfile *f);

SILO_API extern int const *            DBSetUnknownDriverPriorities(int const *);
SILO_API extern int const *            DBGetUnknownDriverPriorities();
SILO_API extern int                    DBRegisterFileOptionsSet(DBoptlist const *opts);
SILO_API extern int                    DBUnregisterFileOptionsSet(int opts_set_id);
SILO_API extern void                   DBUnregisterAllFileOptionsSets();
SILO_API extern char const *           DBVersion(void);
SILO_API extern int                    DBVersionDigits(int *Maj, int *Min, int *Pat, int *Pre);
SILO_API extern int                    DBVersionGE(int Maj, int Min, int Pat);
SILO_API extern int                    DBVariableNameValid(char const *s);
SILO_API extern int                    DBForceSingle(int);
SILO_API extern DBfile *               DBOpenReal(char const *name, int dbtype, int mode);
SILO_API extern DBfile *               DBCreateReal(char const *name, int mode, int targ, char const *info, int dbtype);
SILO_API extern int                    DBInqFileReal(char const *name);
/* 
 * The above functions are the 'Real' implementations of their macro counterparts (below).
 * These are the functions by which client code first gets into Silo. They are separated
 * out because they do a link-time header/library version check for us. It works because
 * we don't advertise the 'Real' functions and instead encourage clients to use the macro
 * counterparts (below). The macros wind up creating a reference to the Silo vesion tag
 * which is resolved only when the client is linked with a library that defines the
 * associated version symbol.
 */
#define DBOpen(NM, DR, MD)            (SiloCheckVersion, DBOpenReal(NM, DR, MD))
#define DBCreate(NM, MD, TG, NF, DR)  (SiloCheckVersion, DBCreateReal(NM, MD, TG, NF, DR))
#define DBInqFile(NM)                 (SiloCheckVersion, DBInqFileReal(NM))
SILO_API extern int                    DBFlush(DBfile *);
SILO_API extern int                    DBClose(DBfile *);
SILO_API extern DBtoc *                DBGetToc(DBfile *);
SILO_API extern int                    DBNewToc(DBfile *);
SILO_API extern int                    DBLs(DBfile *_dbfile, char const *cl_args, char *list[], int *nlist);
SILO_API extern void *                 DBGrabDriver(DBfile *);
SILO_API extern int                    DBUngrabDriver(DBfile *, void const *);
SILO_API extern int                    DBGetDriverType(DBfile const *);
SILO_API extern int                    DBGetDriverTypeFromPath(char const *);
SILO_API extern int                    DBVersionGEFileVersion(DBfile const *dbfile);
SILO_API extern char const *           DBFileName(DBfile const *dbfile);
SILO_API extern char const *           DBFileVersion(DBfile const *dbfile);
SILO_API extern int                    DBFileVersionDigits(DBfile const *dbfile, int *Maj, int *Min, int *Pat, int *Pre);
SILO_API extern int                    DBFileVersionGE(DBfile const *dbfile, int Maj, int Min, int Pat);
SILO_API extern int                    DBGetDir(DBfile *, char *);
SILO_API extern int                    DBSetDir(DBfile *, char const *);
#define DBMkdir DBMkDir
SILO_API extern int                    DBMkDir(DBfile *, char const *);
SILO_API extern int                    DBMkDirP(DBfile *, char const *);
SILO_API extern int                    DBCpDir(DBfile *srcFile, char const *srcDir,
                                           DBfile *dstFile, char const *dstDir);
SILO_API extern int                    DBCp(char const *opts, DBfile *srcFile, DBfile *dstFile, ...);
SILO_API extern int                    DBCpListedObject(int nobjs,
                                           DBfile *srcFile, char const * const *srcObjectList,
                                           DBfile *dstFile, char const * const *dstObjectList);
SILO_API extern int                    DBGetSymlink(DBfile *db, char const *in_candidate_link, char *out_target);
SILO_API extern char const *           DBIsSymlink(DBtoc const *toc, char const *toc_entry);
SILO_API extern int                    DBMkSymlink(DBfile *db, char const *target, char const *link);
SILO_API extern int                    DBGuessHasFriendlyHDF5Names(DBfile *f);
SILO_API extern int                    DBInqVarExists(DBfile *, char const *);
SILO_API extern int                    DBUninstall(DBfile *);
SILO_API extern int                    DBFreeCompressionResources(DBfile *dbfile, char const *meshname);
SILO_API extern int                    DBSortObjectsByOffset(DBfile *, int nobjs, char const * const *obj_names, int *ranks);
SILO_API extern int                    DBFilters(DBfile *, FILE *);
SILO_API extern int                    DBFilterRegistration(char const *, int (*init) (DBfile *, char *),
                                           int (*open) (DBfile *, char *));
SILO_API extern int                    DBInqFileHasObjects(DBfile *);

/* Object Allocation, Free and IsEmpty functions */
SILO_API extern DBcompoundarray *      DBAllocCompoundarray(void);
SILO_API extern DBcurve *              DBAllocCurve(void);
SILO_API extern DBdefvars *            DBAllocDefvars(int);
SILO_API extern DBmultimesh *          DBAllocMultimesh(int);
SILO_API extern DBmultimeshadj *       DBAllocMultimeshadj(int);
SILO_API extern DBmultivar *           DBAllocMultivar(int);
SILO_API extern DBmultimat *           DBAllocMultimat(int);
SILO_API extern DBmultimatspecies *    DBAllocMultimatspecies(int);
SILO_API extern DBcsgmesh *            DBAllocCsgmesh(void);
SILO_API extern DBquadmesh *           DBAllocQuadmesh(void);
SILO_API extern DBpointmesh *          DBAllocPointmesh(void);
SILO_API extern DBmeshvar *            DBAllocMeshvar(void);
SILO_API extern DBucdmesh *            DBAllocUcdmesh(void);
SILO_API extern DBcsgvar *             DBAllocCsgvar(void);
SILO_API extern DBquadvar *            DBAllocQuadvar(void);
SILO_API extern DBucdvar *             DBAllocUcdvar(void);
SILO_API extern DBzonelist *           DBAllocZonelist(void);
SILO_API extern DBphzonelist *         DBAllocPHZonelist(void);
SILO_API extern DBcsgzonelist *        DBAllocCSGZonelist(void);
SILO_API extern DBedgelist *           DBAllocEdgelist(void);
SILO_API extern DBfacelist *           DBAllocFacelist(void);
SILO_API extern DBmaterial *           DBAllocMaterial(void);
SILO_API extern DBmatspecies *         DBAllocMatspecies(void);
SILO_API extern DBnamescheme *         DBAllocNamescheme(void);
SILO_API extern DBgroupelmap *         DBAllocGroupelmap(int, DBdatatype);

SILO_API extern void                   DBFreeMatspecies(DBmatspecies *);
SILO_API extern void                   DBFreeMaterial(DBmaterial *);
SILO_API extern void                   DBFreeFacelist(DBfacelist *);
SILO_API extern void                   DBFreeEdgelist(DBedgelist *);
SILO_API extern void                   DBFreeZonelist(DBzonelist *);
SILO_API extern void                   DBFreePHZonelist(DBphzonelist *);
SILO_API extern void                   DBFreeCSGZonelist(DBcsgzonelist *);
SILO_API extern void                   DBResetUcdvar(DBucdvar *);
SILO_API extern void                   DBFreeUcdvar(DBucdvar *);
SILO_API extern void                   DBResetQuadvar(DBquadvar *);
SILO_API extern void                   DBFreeCsgvar(DBcsgvar *);
SILO_API extern void                   DBFreeQuadvar(DBquadvar *);
SILO_API extern void                   DBFreeUcdmesh(DBucdmesh *);
SILO_API extern void                   DBFreeMeshvar(DBmeshvar *);
SILO_API extern void                   DBFreePointvar(DBpointvar *);
SILO_API extern void                   DBFreePointmesh(DBpointmesh *);
SILO_API extern void                   DBFreeQuadmesh(DBquadmesh *);
SILO_API extern void                   DBFreeCsgmesh(DBcsgmesh *);
SILO_API extern void                   DBFreeDefvars(DBdefvars*);
SILO_API extern void                   DBFreeMultimesh(DBmultimesh *);
SILO_API extern void                   DBFreeMultimeshadj(DBmultimeshadj *);
SILO_API extern void                   DBFreeMultivar(DBmultivar *);
SILO_API extern void                   DBFreeMultimat(DBmultimat *);
SILO_API extern void                   DBFreeMultimatspecies(DBmultimatspecies *);
SILO_API extern void                   DBFreeCompoundarray(DBcompoundarray *);
SILO_API extern void                   DBFreeCurve(DBcurve *);
SILO_API extern void                   DBFreeNamescheme(DBnamescheme *);
SILO_API extern void                   DBFreeMrgvar(DBmrgvar *mrgv);
SILO_API extern void                   DBFreeMrgtree(DBmrgtree *tree);
SILO_API extern void                   DBFreeGroupelmap(DBgroupelmap *map);

SILO_API extern int                    DBIsEmptyCurve(DBcurve const *curve);
SILO_API extern int                    DBIsEmptyPointmesh(DBpointmesh const *msh);
SILO_API extern int                    DBIsEmptyPointvar(DBpointvar const *var);
SILO_API extern int                    DBIsEmptyMeshvar(DBmeshvar const *var);
SILO_API extern int                    DBIsEmptyQuadmesh(DBquadmesh const *msh);
SILO_API extern int                    DBIsEmptyQuadvar(DBquadvar const *var);
SILO_API extern int                    DBIsEmptyUcdmesh(DBucdmesh const *msh);
SILO_API extern int                    DBIsEmptyFacelist(DBfacelist const *fl);
SILO_API extern int                    DBIsEmptyZonelist(DBzonelist const *zl);
SILO_API extern int                    DBIsEmptyPHZonelist(DBphzonelist const *zl);
SILO_API extern int                    DBIsEmptyUcdvar(DBucdvar const *var);
SILO_API extern int                    DBIsEmptyCsgmesh(DBcsgmesh const *msh);
SILO_API extern int                    DBIsEmptyCSGZonelist(DBcsgzonelist const *zl);
SILO_API extern int                    DBIsEmptyCsgvar(DBcsgvar const *var);
SILO_API extern int                    DBIsEmptyMaterial(DBmaterial const *mat);
SILO_API extern int                    DBIsEmptyMatspecies(DBmatspecies const *spec);
SILO_API extern int                    DBIsEmptyMultimesh(DBmultimesh const *mmesh);
SILO_API extern int                    DBIsEmptyMultivar(DBmultivar const *mvar);
SILO_API extern int                    DBIsEmptyMultimat(DBmultimat const *mmat);
SILO_API extern int                    DBIsEmptyMultimatspecies(DBmultimatspecies const *mspec);

/* User-defined (generic) Data and Object functions */
SILO_API extern int                    DBGetObjtypeTag(char const *);
SILO_API extern DBobject *             DBMakeObject(char const *, int, int);
SILO_API extern int                    DBFreeObject(DBobject *);
SILO_API extern int                    DBClearObject(DBobject *);
SILO_API extern int                    DBAddVarComponent(DBobject *, char const *, char const *);
SILO_API extern int                    DBAddIntComponent(DBobject *, char const *, int);
SILO_API extern int                    DBAddIntNComponent(DBobject *, char const *, int, int const *);
SILO_API extern int                    DBAddFltComponent(DBobject *, char const *, double);
SILO_API extern int                    DBAddFltNComponent(DBobject *, char const *, int, double const *);
SILO_API extern int                    DBAddDblComponent(DBobject *, char const *, double);
SILO_API extern int                    DBAddDblNComponent(DBobject *, char const *, int, double const *);
SILO_API extern int                    DBAddStrComponent(DBobject *, char const *, char const *);
SILO_API extern int                    DBGetComponentNames(DBfile *, char const *, char ***, char ***);
SILO_API extern DBobject *             DBGetObject(DBfile *, char const *);
SILO_API extern int                    DBChangeObject(DBfile *, DBobject const *);
SILO_API extern int                    DBWriteObject(DBfile *, DBobject const *, int);
SILO_API extern void *                 DBGetComponent(DBfile *, char const *, char const *);
SILO_API extern int                    DBGetComponentType(DBfile *, char const *, char const *);
SILO_API extern int                    DBWriteComponent(DBfile *, DBobject *, char const *, char const *, char const *,
                                           void const *, int, long const *);
SILO_API extern int                    DBWrite(DBfile *, char const *, void const *, int const *, int, int);
SILO_API extern int                    DBWriteSlice(DBfile *dbfile, char const *array_name,
                                           void const * data, int datatype, int const *offsets,
                                           int const *lengths, int const *strides, int const *dims,
                                           int ndims);
SILO_API extern int                    DBRead(DBfile *, char const *, void *);
SILO_API extern int                    DBReadVar(DBfile *, char const *, void *);
SILO_API extern int                    DBReadVarSlice(DBfile *, char const *, int const *, int const *, int const *, int, void *);
SILO_API extern int                    DBReadVarVals(DBfile *, char const *, int mode, int nvals, int ndims,
                                           void const *indices, void **vals, int *ncomps, int *nitems);
SILO_API extern DBcompoundarray *      DBGetCompoundarray(DBfile *, char const *);
SILO_API extern int                    DBInqCompoundarray(DBfile *, char const *, char ***, int **, int *, int *, int *);
SILO_API extern void *                 DBGetVar(DBfile *, char const *);
SILO_API extern int                    DBGetVarByteLength(DBfile *, char const *);
SILO_API extern int                    DBGetVarByteLengthInFile(DBfile *, char const *);
SILO_API extern int                    DBGetVarLength(DBfile *, char const *);
SILO_API extern int                    DBGetVarDims(DBfile *, char const *, int, int *);
SILO_API extern int                    DBGetVarType(DBfile *, char const *);
SILO_API extern DBObjectType           DBInqVarType(DBfile *, char const *);

/* Curve, Mesh, Variable and Material functions */
SILO_API extern DBcurve *              DBGetCurve(DBfile *, char const *);
SILO_API extern DBdefvars *            DBGetDefvars(DBfile *, char const *);
SILO_API extern DBmaterial *           DBGetMaterial(DBfile *, char const *);
SILO_API extern DBmatspecies *         DBGetMatspecies(DBfile *, char const *);
SILO_API extern DBpointmesh *          DBGetPointmesh(DBfile *, char const *);
SILO_API extern DBmeshvar *            DBGetPointvar(DBfile *, char const *);
SILO_API extern DBquadmesh *           DBGetQuadmesh(DBfile *, char const *);
SILO_API extern DBquadvar *            DBGetQuadvar(DBfile *, char const *);
SILO_API extern DBucdmesh *            DBGetUcdmesh(DBfile *, char const *);
SILO_API extern DBucdvar *             DBGetUcdvar(DBfile *, char const *);
SILO_API extern DBcsgmesh *            DBGetCsgmesh(DBfile *, char const *);
SILO_API extern DBcsgvar *             DBGetCsgvar(DBfile *, char const *);
SILO_API extern DBcsgzonelist *        DBGetCSGZonelist(DBfile *, char const *);
SILO_API extern DBfacelist *           DBGetFacelist(DBfile *, char const *);
SILO_API extern DBzonelist *           DBGetZonelist(DBfile *, char const *);
SILO_API extern DBphzonelist *         DBGetPHZonelist(DBfile *, char const *);
SILO_API extern int                    DBInqMeshname(DBfile *, char const *, char *);
SILO_API extern int                    DBInqMeshtype(DBfile *, char const *);
SILO_API extern int                    DBPutCompoundarray(DBfile *dbfile, char const *name, char const * const *elemnames,
                                           int const *elemlens, int nelems, void const *values, int nvalues, int datatype,
                                           DBoptlist const *);
SILO_API extern int                    DBPutCurve(DBfile *dbfile, char const * name, void const * xvals,
                                           void const * yvals, int datatype, int npts, DBoptlist const * opts);
SILO_API extern int                    DBPutDefvars(DBfile *dbfile, char const *name, int, char const * const *names, 
                                           int const *types, char const * const *defns, DBoptlist const * const *opts);
SILO_API extern int                    DBPutFacelist(DBfile *dbfile, char const *, int nfaces, int ndims, int const *nodelist,
                                           int lnodelist, int origin, int const *zoneno, int const *shapesize,
                                           int const *shapecnt, int nshapes, int const *types, int const *typelist, int ntypes);
SILO_API extern int                    DBPutMaterial(DBfile *dbfile, char const *name, char const *meshname, int nmat,
                                           int const *matnos, int const *matlist, int const *dims, int ndims,
                                           int const *mix_next, int const *mix_mat, int const *mix_zone, DBVCP1_t mix_vf,
                                           int mixlen, int datatype, DBoptlist const *opts);
SILO_API extern int                    DBPutMatspecies(struct DBfile *dbfile, char const *name, char const *matnam,
                                           int nmat, int const *nmatspec, int const *speclist, int const *dims,
                                           int ndims, int nspecies_mf, DBVCP1_t species_mf, int const *mix_speclist,
                                           int mixlen, int datatype, DBoptlist const *optlist);
SILO_API extern int                    DBPutPointmesh(DBfile *, char const *, int, DBVCP2_t, int, int, DBoptlist const *);
SILO_API extern int                    DBPutPointvar(DBfile *, char const *, char const *, int, DBVCP2_t, int, int,
                                           DBoptlist const *);
SILO_API extern int                    DBPutPointvar1(DBfile *, char const *, char const *, DBVCP1_t, int, int,
                                           DBoptlist const *);
SILO_API extern int                    DBPutQuadmesh(DBfile *, char const *, char const * const *, DBVCP2_t, int const *, int,
                                           int, int, DBoptlist const *);
SILO_API extern int                    DBPutQuadvar(DBfile *, char const *, char const *, int, char const * const *, DBVCP2_t,
                                           int const *, int, DBVCP2_t, int, int, int, DBoptlist const *);
SILO_API extern int                    DBPutQuadvar1(DBfile *, char const *, char const *, DBVCP1_t, int const *, int,
                                           DBVCP1_t, int, int, int, DBoptlist const *);
SILO_API extern int                    DBPutUcdmesh(DBfile *, char const *, int, char const * const *, DBVCP2_t, int,
                                           int, char const *, char const *, int, DBoptlist const *);
SILO_API extern int                    DBPutUcdsubmesh(DBfile *, char const *, char const *, int,
                                           char const *, char const *, DBoptlist const *);
SILO_API extern int                    DBPutUcdvar(DBfile *, char const *, char const *, int, char const * const *, DBVCP2_t,
                                           int, DBVCP2_t, int, int, int, DBoptlist const *);
SILO_API extern int                    DBPutUcdvar1(DBfile *, char const *, char const *, DBVCP1_t, int, DBVCP1_t,
                                           int, int, int, DBoptlist const *);
SILO_API extern int                    DBPutZonelist(DBfile *, char const *, int, int, int const *, int, int,
                                           int const *, int const *, int);
SILO_API extern int                    DBPutZonelist2(DBfile *, char const *, int, int, int const *, int, int,
                                           int, int, int const *, int const *, int const *, int, DBoptlist const *);
SILO_API extern int                    DBPutPHZonelist(DBfile *, char const *, int, int const *, int, int const *, char const *,
                                           int, int const *, int, int const *, int, int, int, DBoptlist const *);
SILO_API extern int                    DBPutCsgmesh(DBfile *, char const *, int, int, int const *, int const *,
                                           void const *, int, int, double const *, char const *, DBoptlist const *);
SILO_API extern int                    DBPutCSGZonelist(DBfile *, char const *, int, int const *,
                                           int const *, int const *, void const *, int, int, int, int const *,
                                           DBoptlist const *);
SILO_API extern int                    DBPutCsgvar(DBfile *, char const *, char const *, int, char const * const *,
                                           DBVCP2_t, int, int, int, DBoptlist const *);

/* Part Assemblies, AMR, Slide Surfaces, Nodesets and Other Arbitrary Mesh Subsets */
SILO_API extern void                   DBPrintMrgtree(DBmrgtnode *tnode, int walk_order, void *data);
SILO_API extern void                   DBLinearizeMrgtree(DBmrgtnode *tnode, int walk_order, void *data);
SILO_API extern void                   DBWalkMrgtree(DBmrgtree const *tree, DBmrgwalkcb cb, void *wdata, int traversal_order);
SILO_API extern DBmrgtree *            DBMakeMrgtree(int source_mesh_type, int mrgtree_info, int max_root_descendents,
                                           DBoptlist *opts);
SILO_API extern int                    DBAddRegion(DBmrgtree *tree, char const *region_name, int type_info_bits,
                                           int max_descendents, char const *maps_name, int nsegs, int const *seg_ids,
                                           int const *seg_sizes, int const *seg_types, DBoptlist const *opts);
SILO_API extern int                    DBAddRegionArray(DBmrgtree *tree, int nregn, char const * const *regn_names,
                                           int type_info_bits, char const *maps_name, int nsegs, int const *seg_ids,
                                           int const *seg_sizes, int const *seg_types, DBoptlist const *opts);
SILO_API extern int                    DBSetCwr(DBmrgtree *tree, char const *path);
SILO_API extern char const *           DBGetCwr(DBmrgtree *tree);
SILO_API extern int                    DBPutMrgtree(DBfile *dbfile, char const *mrg_tree_name, char const *mesh_name,
                                           DBmrgtree const *tree, DBoptlist const *opts);
SILO_API extern int                    DBPutMrgvar(DBfile *dbfile, char const *name, char const *mrgt_name,
			                   int ncomps, char const * const *compnames, int nregns,
                                           char const * const *reg_pnames, int datatype, DBVCP2_t data,
                                           DBoptlist const *opts);
SILO_API extern int                    DBPutGroupelmap(DBfile *dbfile, char const *map_name, int num_segments,
                                           int const *groupel_types, int const *segment_lengths, int const *segment_ids,
                                           int const * const *segment_data, DBVCP2_t segment_fracs,
                                           int fracs_data_type, DBoptlist const *opts);
SILO_API extern DBmrgtree *            DBGetMrgtree(DBfile *dbfile, char const *mrg_tree_name);
SILO_API extern DBgroupelmap *         DBGetGroupelmap(DBfile *dbfile, char const *name);
SILO_API extern DBmrgvar *             DBGetMrgvar(DBfile *dbfile, char const *name);
SILO_API extern DBnamescheme *         DBMakeNamescheme(char const *fmt, ...);
SILO_API extern char const *           DBGetName(DBnamescheme const *ns, int natnum);
SILO_API int                           DBGetIndex(DBnamescheme const *ns, int natnum);
SILO_API extern char const *           DBSPrintf(char const *fmt, ...);

/* Multi-block objects and parallel I/O */
SILO_API extern DBmultimesh *          DBGetMultimesh(DBfile *, char const *);
SILO_API extern DBmultimeshadj *       DBGetMultimeshadj(DBfile *, char const *, int, int const *);
SILO_API extern DBmultivar *           DBGetMultivar(DBfile *, char const *);
SILO_API extern DBmultimat *           DBGetMultimat(DBfile *, char const *);
SILO_API extern DBmultimatspecies *    DBGetMultimatspecies(DBfile *, char const *);
SILO_API extern int                    DBPutMultimesh(DBfile *, char const *, int, char const * const *, int const *,
                                           DBoptlist const *);
SILO_API extern int                    DBPutMultimeshadj(DBfile *, char const *, int, int const *, int const *,
                                           int const *, int const *, int const *, int const * const *, int const *,
                                           int const * const *, DBoptlist const *optlist);
SILO_API extern int                    DBPutMultivar(DBfile *, char const *, int, char const * const *, int const *,
                                           DBoptlist const *);
SILO_API extern int                    DBPutMultimat(DBfile *, char const *, int, char const * const *, DBoptlist const *);
SILO_API extern int                    DBPutMultimatspecies(DBfile *, char const *, int, char const * const *, DBoptlist const *);

/* Option lists */
SILO_API extern DBoptlist *            DBMakeOptlist(int);
SILO_API extern int                    DBClearOptlist(DBoptlist *);
SILO_API extern int                    DBFreeOptlist(DBoptlist *);
SILO_API extern int                    DBAddOption(DBoptlist *, int, void *);
SILO_API extern void *                 DBGetOption(DBoptlist const *, int);
SILO_API extern int                    DBClearOption(DBoptlist *, int);

/* Calculational and Utility methods */
SILO_API extern int                    DBAnnotateUcdmesh(DBucdmesh *);
SILO_API extern DBfacelist *           DBCalcExternalFacelist(int *, int, int, int *, int *, int, int *, int);
SILO_API extern DBfacelist *           DBCalcExternalFacelist2(int *, int, int, int, int, int *, int *, int *, int, int *, int);
SILO_API extern char *                 DBJoinPath(char const *, char const *);
SILO_API extern void                   DBStringArrayToStringList(char const * const *strArray, int n, char **strList, int *m);
SILO_API extern char **                DBStringListToStringArray(char const *strList, int *n, int skipSemicolonAtIndexZero);
SILO_API extern void                   DBFreeStringArray(char **strArray, int n);
SILO_API extern int                    DBIsDifferentDouble(double a, double b, double abstol, double reltol, double reltol_eps);
SILO_API extern int                    DBIsDifferentLongLong(long long a, long long b, double abstol, double reltol, double reltol_eps);
SILO_API extern int                    DBCalcDenseArraysFromMaterial(DBmaterial const *mat, int datatype, int *narrs, void ***vfracs);
SILO_API extern DBmaterial            *DBCalcMaterialFromDenseArrays(int narrs, int ndims, int const *dims, int const *matnos, int dtype, DBVCP2_t const vfracs);

/* Fortran interface functions */
SILO_API extern void *                 DBFortranAccessPointer(int value);
SILO_API extern int                    DBFortranAllocPointer(void *pointer);
SILO_API extern void                   DBFortranRemovePointer(int value);
SILO_API extern char *                 _db_safe_strdup(const char *);

#ifdef __cplusplus
}
#endif

#undef NO_FORTRAN_DEFINE
#endif /* !SILO_H */
