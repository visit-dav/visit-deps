/*
 * Include file for Mili (Mesh I/O Library).
 *
 */

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
 
************************************************************************
* Modifications:
*
*  I. R. Corey - April 4, 2006: Added new record type for time invarent
*                data (TI). This data will be written to a new file
*                trype and is not tied to a specific state.
*                See SCR #298.
*
*  I. R. Corey - October 10, 2006: Added new functions to get metadata
*                from non-state and TI files.
*
*  I. R. Corey - May 31, 2007: Increased max name length from 32 to
*                256.
*                See SCR #465.
*
*  I. R. Corey - August 16, 2007: Added field for TI vars to note if
*                nodal or element result.
*
*  I. R. Corey - October 24, 2007: Added element and nodal labels.
*                See SCR #418.
*
************************************************************************
*/



#ifndef MILI_H
#define MILI_H
/*The following is for bookkeeping only*/
#ifndef MILI_VERSION
#define MILI_REVISION_DATE ="09/30/2016:09:00";
#endif

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Famid;
#include "misc.h"
#include "mili_enum.h"

#ifndef MILI_VERSION
#define MILI_VERSION "V19_02"
#endif

#if defined(_WIN32) || defined(WIN32)
#define HAVEINT8
#else
#ifndef HAVEINT8
#if defined(__linux__) || defined(__unix__)
#define HAVEINT8
#endif
#endif
#endif

/**/
/* Need to improve this for all 64- and 32-bit OS cases. */
#ifdef HAVEINT8
#define LONGLONG long long
#if defined (_MSC_VER)
#define CLONGLONGCONST(c) c##i64
#else
#define CLONGLONGCONST(c) c##LL
#endif
#endif
#ifndef HAVEINT8
#define LONGLONG int
#define CLONGLONGCONST(c) c
#endif

#define TIMER 0
/*
 * Data types.
 */
#define M_STRING        (1)
#define M_FLOAT         (2)
#define M_FLOAT4        (3)
#define M_FLOAT8        (4)
#define M_INT           (5)
#define M_INT4          (6)
#define M_INT8          (7)

/*
 * Object superclasses.
 */
#define M_UNIT              (0)  /* Generic object, "node-free" */
#define M_NODE              (1)  /* 1 node */
#define M_TRUSS             (2)  /* 2 nodes */
#define M_BEAM              (3)  /* 3 nodes */
#define M_TRI               (4)  /* 3 nodes */
#define M_QUAD              (5)  /* 4 nodes */
#define M_TET               (6)  /* 4 nodes */
#define M_PYRAMID           (7)  /* 5 nodes */
#define M_WEDGE             (8)  /* 6 nodes */
#define M_HEX               (9)  /* 8 nodes */
#define M_MAT               (10) /* Class for material state variables */
#define M_MESH              (11) /* Class for global state variables */
#define M_SURFACE           (12) /* Class for surfaces */
#define M_PARTICLE          (13) /* Class for particles - 1 nodes */
#define M_TET10             (14) /* Class for 10 Node Tetrahedron */
#define M_QTY_SUPERCLASS    (15)

#define M_SHARED            (100) /* Used to identify multi-superclass objects for TI results */
#define M_ALL               (200)
#define M_INVALID_LABEL     -1
/* Make sure the following 2 static declarations are kept in sync with defines above. **/

static const int conn_words[M_QTY_SUPERCLASS] =
{
   0, 0, 4, 5, 5, 6, 6, 7, 8, 10, 0, 0, 0, 3, 12
};

static const int class_conns[M_QTY_SUPERCLASS] =
{
   0, 0, 2, 3, 3, 4, 4, 5, 6, 8, 0, 0, 0, 1, 10
};

/*
 * Mili database query types.
 *
 * Must be current with parameter definitions in mili_fparam.h!
 */
typedef enum
{
   QTY_STATES = 0,
   QTY_DIMENSIONS,
   QTY_MESHES,
   QTY_SREC_FMTS,
   QTY_SUBRECS,
   QTY_SUBREC_SVARS,
   QTY_SVARS,
   QTY_NODE_BLKS,
   QTY_NODES_IN_BLK,
   QTY_CLASS_IN_SCLASS,
   QTY_ELEM_CONN_DEFS,
   QTY_ELEMS_IN_DEF,
   SREC_FMT_ID,
   SERIES_SREC_FMTS,
   SUBREC_CLASS,
   SREC_MESH,
   CLASS_SUPERCLASS,
   STATE_TIME,
   SERIES_TIMES,
   MULTIPLE_TIMES,
   STATE_OF_TIME,
   NEXT_STATE_LOC,
   CLASS_EXISTS,
   LIB_VERSION,
   STATE_SIZE,
   QTY_FACETS_IN_SURFACE,
   TIME_OF_STATE,
   MESH_NAME
} Query_request_type;


/*
 * State data organization options.
 */
#define RESULT_ORDERED  (0)
#define OBJECT_ORDERED  (1)

/*
 * Categories of information in a Mili family.
 */
#define STATE_DATA      (0)
#define NON_STATE_DATA  (1)
#define TAURUS_DATA     (2)
#define TI_DATA         (10) /* New for time-invarient data */


/*
 * Formats for specifying element identifiers during connectivity definition.
 */
#define M_LIST_OBJ_FMT  (1)
#define M_BLOCK_OBJ_FMT (2)

/*
 * Miscellaneous limits
 */
#define M_MAX_NAME_LEN   (300) /* Longest name length */
#define M_MAX_ARRAY_DIMS (6)   /* Maximum number of array dimensions */
#define M_MAX_STRING_LEN (512) /* Maximum string length */

/*
 * Surface variable flag parameters
 */
#define PER_OBJECT (0)
#define PER_FACET  (1)


/*
 * Convenience type definitions
 */

typedef enum
{
   SCALAR,
   VECTOR,
   ARRAY,
   VEC_ARRAY,
   AGG_TYPE_CNT
} Aggregate_type;

/* State variable. */
typedef struct _state_variable
{
   char *short_name;
   char *long_name;
   int num_type;
   Aggregate_type agg_type;
   int rank;
   int *dims;
   int vec_size;
   char **components;
   char **component_titles;
} State_variable;

/* State subrecord. */
typedef struct _subrecord
{
   char *name;
   int organization;
   int qty_svars;
	int superclass;
   char **svar_names;
   char *class_name;
   int qty_objects;
   int qty_blocks;
   int *mo_blocks;
   int *surface_variable_flag;
} Subrecord;

/* Obj Group *
typedef struct _objgroup
{
   char   *group_name;

   int    numVertex;
   int    numLineSegs;
   int    numFaces;
   int    numPoints;

   float  **vertex;
   float  **normal;
   int    *vertex_id, *normal_id;

   int    *smoothing_group;
   int    **facesVertex;
   int    **linesVertex;
   int    **pointsVertex;
   int    *facesNormal;
} ObjGroup;
*/
/* Obj top-level *
typedef struct _objdef
{
   char *obj_name;
   int  num_groups;
   char **group_names;
   ObjGroup *groups;
} ObjDef;
*/
/* Mili version */
/* const char *mili_version; */

/*
                * *                                      * *
                * *   File family management routines.   * *
                * *                                      * *
*/
Return_value mc_writeMiliMetaData(Famid database_id);

/*
 * Family creation and access control
 */
Return_value
mc_quick_open(                   /* Create/open a file family. */
   char *root_name,       /* Root name for family */
   char *path,            /* Path to directory where family is/will be */
   char *mode,            /* Access mode */
   Famid *fam_id );       /* (output) Mili family identifier */

Return_value
mc_open(                   /* Create/open a file family. */
   char *root_name,       /* Root name for family */
   char *path,            /* Path to directory where family is/will be */
   char *mode,            /* Access mode */
   Famid *fam_id );       /* (output) Mili family identifier */

Return_value
mc_close(                  /* Close a file family. */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_partition_state_data(   /* Create a state data branch file partition. */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_restart_at_state(       /* Set family to overwrite at an existing state */
   Famid fam_id,          /* Mili family identifier */
   int file_suffix,       /* Index of state file where overwrite is to begin */
   int file_state_index );/* Index of state in file where overwrite begins */

Return_value
mc_restart_at_file(        /* Set family to overwrite at an existing file */
   Famid fam_id,          /* Mili family identifier */
   int fname_index );     /* Zero-based file index where overwrite begins */

Return_value
mc_delete_family(          /* Delete a Mili file family */
   char *root_name,       /* Root name for family */
   char *path );          /* Path to directory where family is/will be */

/*
 * Non-state named-parameter I/O
 */

Return_value
mc_wrt_scalar(             /* Write a named scalar to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of scalar */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

Return_value
mc_read_scalar(            /* Read a named scalar from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

Return_value
mc_wrt_array(              /* Write a named array to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of array */
   char *name,            /* Label of array */
   int order,             /* Number of array dimensions */
   int *dimensions,       /* Size of each dimension */
   void *data );          /* Array data */

Return_value
mc_read_param_array(       /* Read a named param array from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of param */
   void **value );        /* data */

Return_value
mc_read_param_array_len(   /* Read the length of a named param array from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of param */
   int *param_array_type, /* Returned param array type */
   int *param_array_len );/* Returned param array length */

Return_value
mc_wrt_string(             /* Write a named string to the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

Return_value
mc_read_string(            /* Read a named string from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

int
mc_get_next_famid(         /* Returns the next available file id number */
   void );

int
mc_get_app_parameter_count(
   Famid fam_id);

void 
mc_get_app_parameter_names(
	Famid fam_id, 
	char **names, 
	int in_size);

/*****************************************************************
 * Time Independent file functions:
 * Added May 2006 by I.R. Corey
 *****************************************************************
 */

/*
 * File TI enable/disable functions.
 */
void
mc_ti_disable_only( Famid fam_id ) ;

void
mc_ti_enable_only( Famid fam_id ) ;

void
mc_ti_enable(              /* Enable TI data capability */
   Famid fam_id );        /* Mili family identifier */

void
mc_ti_disable(             /* Disable TI data capability */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_ti_wrt_scalar(          /* Write a named scalar to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of scalar */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

Return_value
mc_ti_read_scalar(         /* Read a named scalar from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

Return_value
mc_ti_wrt_array(           /* Write a named array to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of array */
   char *name,            /* Label of array */
   int order,             /* Number of array dimensions */
   int *dimensions,       /* Size of each dimension */
   void *data );          /* Array data */

Return_value
mc_ti_read_array(          /* Read a named param array from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of param */
   void **value,          /* The data */
   int  *num_items );     /* Number of data items read */

Return_value
mc_ti_wrt_string(          /* Write a named string to the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

Return_value
mc_ti_read_string(         /* Read a named string from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

Return_value
mc_ti_set_class(           /* Define TI metadata */
   Famid  fam_id,         /* Mili family identifier */
   int    meshid,
   int    state,
   int    matid,
   char   *superclass,
   Bool_type meshvar,
   Bool_type nodal,
   char   *short_name,
   char   *long_name );

Return_value
mc_ti_def_class(           /* Define TI metadata */
   Famid  fam_id,         /* Mili family identifier */
   int    meshid,
   int    state,
   int    matid,
   char   *superclass,
   Bool_type meshvar,
   Bool_type nodal,
   char   *short_name,
   char   *long_name );

Return_value
mc_ti_undef_class(          /* Reset TI class data */
   Famid fam_id );         /* Mili family identifier */

Return_value
mc_ti_savedef_class(        /* Save TI class data */
   Famid fam_id );         /* Mili family identifier */

Return_value
mc_ti_restoredef_class(     /* Restore saved TI class data */
   Famid fam_id );         /* Mili family identifier */


Bool_type
mc_ti_check_if_data_found( /* Query if we found TI Data */
   Famid fam_id );        /* Mili family identifier */

void
mc_ti_data_found(          /* Set TI Data found flag to TRUE */
   Famid fam_id );        /* Mili family identifier */

void
mc_ti_data_not_found(      /* Set TI Data found flag to FALSE */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_ti_make_var_name(
   Famid  fam_id,         /* Mili family identifier */
   char *name,            /* Label of string */
   char *class_name,      /* The class for the identifier */
   char *new_name );      /* The neww expanded name */

Bool_type
mc_ti_verify_var_name(
   Famid  fam_id,         /* Mili family identifier */
   char *name );          /* TI variable name */

Bool_type
mc_ti_find_var_name(
   Famid  fam_id,         /* Mili family identifier */
   char *name,            /* TI variable name */
   char *class_name,      /* Mili class name */
   char **var_name );     /* Retured TI variable name */

Return_value
mc_ti_init_metadata(       /* Initialize Mili TI metadata */
   Famid fam);            /* Mili family identifier */

Return_value
mc_ti_get_metadata(        /* Read metadata from the TI file */
   Famid fam_id,          /* Mili family identifier */
   char *mili_version,    /* Library version string */
   char *host,            /* Host name */
   char *arch,            /* Arch name */
   char *timestamp,       /* File creation date and time */
   char *username,        /* User that created the Mili file */
   char *xmilics_version, /* Xmilics version that created this database if combined */
   char *code_name);      /* Name and version of the Physics code that created this database  */

Return_value
mc_ti_check_arch(          /* Read metadata from the TI file */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_ti_get_class(  /* Get attributes for a TI data field */
   Famid fam_id,
   int    meshid,
   char  *name,
   char  *class_name,
   int   *state,
   int   *matid,
   int   *superclass,
   Bool_type *isMeshvar,
   Bool_type *isNodal,
   int   *datatype,
   int   *datalength );

Return_value
mc_ti_get_data_attributes(  /* Get attributes for a TI data field */
   Famid fam_id,
   int    meshid,
   char  *name,
   char  *class_name,
   int   *state,
   int   *matid,
   int   *superclass,
   Bool_type *isMeshvar,
   Bool_type *isNodal,
   int   *datatype,
   int   *datalength );

Return_value
mc_ti_get_data_len(
   Famid fam_id,  /* Get len and type for a TI data field */
   char *name,
   int *datatype,
   int *datalength );

int
mc_ti_get_superclass_from_name(
   char *name ); /* Get the superclass for a TI data field */

int
mc_ti_get_material_from_name(
   char *name ); /* Get the material number for a TI data field */

Return_value
mc_ti_get_metadata_from_name(  /* Extract embedded metadata from a TI name */
   char  *name,
   char  *class_name,
   int   *meshid,
   int   *state,
   int   *matid,
   int   *superclass,
   Bool_type *isMeshvar,
   Bool_type *isNodal);

int
mc_ti_htable_search_wildcard( /* Search the TI hash table */
   int fid,                   /* Mili family identifier */
   int list_len,
   Bool_type allow_duplicates,
   char *key1,
   char *key2,
   char *key3,
   char **return_list );


/*
 * Mesh operations
 */
Return_value
mc_make_umesh(             /* Initialize a new unstructured mesh */
   Famid fam_id,          /* Mili family identifier */
   char *mesh_name,       /* Name of mesh */
   int dim,               /* Quantity of spatial dimensions in mesh */
   int *p_mesh_id );      /* (output) Destination for mesh ident */

Return_value
mc_def_class(              /* Define a new mesh oject class */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh class belongs to */
   int superclass,        /* Mesh object superclass */
   char *short_name,      /* Short name of new class */
   char *long_name );     /* Long name (title) of new class */

Return_value
mc_def_class_idents(       /* Define object identifiers for a class */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that objects belong to */
   char *class_name,      /* Name of class to which nodes belong */
   int start,             /* First object in sequence */
   int stop );            /* Last object in sequence */

Return_value
mc_def_nodes(              /* Define mesh node coordinates. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that nodes belong to */
   char *class_name,      /* Name of class to which nodes belong */
   int start_node,        /* First node in sequence */
   int stop_node,         /* Last node in sequence */
   float *coords );       /* Coordinates for each node in sequence */

Return_value
mc_def_node_labels(        /* Define mesh nodal labels. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int  qty,              /* Number of labels to write */
   int *labels );         /* Array of node labels */

Return_value
mc_def_conn_seq(           /* Define mesh element connectivities. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int start_el,          /* First element in sequence */
   int stop_el,           /* Last element in sequence */
   int *data );           /* Array of connectivities for each element */

Return_value
mc_def_conn_seq_labels(    /* Define mesh element connectivities with labels. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int start_el,          /* First element in sequence */
   int stop_el,           /* Last element in sequence */
   int *labels,           /* Element labels */
   int *data );           /* Array of connectivities for each element */

Return_value
mc_def_conn_arb(           /* Define mesh element connectivities. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int qty,               /* Quantity of elements listed */
   int *elem_ids,         /* Array of element identifiers */
   int *data );           /* Array of connectivities for each element */

Return_value
mc_def_conn_arb_labels(    /* Define mesh element connectivities with labels. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int qty,               /* Quantity of elements listed */
   int *elem_ids,         /* Array of element identifiers */
   int *labels,           /* Element labels */
   int *data );           /* Array of connectivities for each element */

Return_value
mc_def_seq_labels(        /* Define mesh element labels. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *short_name,      /* Name of class to which elements belong */
   int start_el,          /* First element in sequence */
   int stop_el,           /* Last element in sequence */
   int* labels);          /* Array of element labels */
   
Return_value
mc_def_conn_labels(        /* Define mesh element labels. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int  qty,              /* Number of labels to write */
	int* idents,           /* The array of object ids to assign the label to*/
   int *labels );         /* Array of element labels */

Return_value
mc_def_conn_surface(       /* Define surface node connectivities. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *short_name,      /* Short name of new class */
   int qty_of_facets,     /* Quantity of facets in surface */
   int *data,             /* Array of connectivities for each element */
   int *surface_id );     /* Surface ID established by this procedure */

Return_value
mc_load_nodes(             /* Read node coordinates into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class the nodes being loaded belong to */
   void *coords );        /* (output) Destination buffer for node coords */

Return_value
mc_get_node_label_info(    /* Get the info needed to load node labels. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *short_name,      /* Name of class the nodes being loaded belong to */
   int *num_blocks,       /* Number of material blocks */
   int *num_labels);      /* Number of node labels */

Return_value
mc_load_node_labels(       /* Read node labels into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class the nodes being loaded belong to */
   int  *num_blocks,      /* Number of material blocks */
   int  **block_range,    /* Start-Stop label number pair for each block */
   int *labels );         /* (output) Destination buffer for node labels */

int
mc_get_conn_count(         /* Returns the number of connecting nodes for a superclass. */
   int superclass );      /* Input superclass i.e. M_HEX or M_QUAD */

Return_value
mc_get_unique_node_count(  /* Returns the number unique nodes for a class */
   int *nodes,            /* List of all nodes - with duplicates */
   int qty,               /* Number of nodes in the list */
   int *count );          /* The returned number of unique nodes. */

Return_value
mc_load_conns(             /* Read element connectivities into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class elements being loaded belong to */
   int *conns,            /* (output) Destination buffer for element conn's */
   int *mats,             /* (output) Destination buffer for element mat's */
   int *parts );          /* (output) Destination buffer for elem part no's */

Return_value
mc_load_conn_labels(       /* Read element labels into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class the nodes being loaded belong to */
   int  qty,              /* Number of labels to load */
   int  *num_blocks,      /* Number of material blocks */
   int  **block_range,    /* Start-Stop label number pair for each block */
   int  *element_ids,     /* List of local element numbers for each label */
   int  *labels );        /* (output) Destination buffer for element labels */

Return_value
mc_load_surface(           /* Read surface connectivities into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh to which surface belongs */
   int surf,              /* Which surface of this name type */
   char *short_name,      /* (Short) Name of surface class to which nodal connectivities being loaded belong */
   void *conns );         /* (output) Destination buffer for element conn's */

Return_value
mc_get_mesh_id(           /* Find numeric ident associated with mesh name */
   Famid fam_id,          /* Mili family identifier */
   char *mesh_name,       /* Name of mesh */
   int *p_mesh_id );      /* (output) Destination for mesh ident */

Bool_type
mc_is_superclass(         /* Determines of a class name is a superclass */
   char *className );     /* Name of the superclass to test */

Bool_type
mc_is_particle_class( 
   Famid fam_id,
   char *class_name );

/*
 * State record definition
 */

Return_value
mc_def_svars(              /* Define multiple scalar state variables. */
   Famid fam_id,          /* Mili family identifier */
   int qty_svars,         /* Number of state variables defined */
   char *names,           /* Array of short names */
   int name_stride,       /* Spacing between start of each short name */
   char *titles,          /* Array of long names */
   int title_stride,      /* Spacing between start of each long name */
   int types[] );         /* Data type of each state variable */

Return_value
mc_def_vec_svar(           /* Define vector state variable. */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of array */
   int qty_fields,        /* Quantity of fields in vector */
   char *name,            /* Vector short name */
   char *title,           /* Vector long name */
   char **field_names,    /* Array of field short names */
   char **field_titles ); /* Array of field long names */

Return_value
mc_def_arr_svar(           /* Define single array state variable. */
   Famid fam_id,          /* Mili family identifier */
   int rank,              /* Number of array dimensions */
   int dims[],            /* Size of each dimension */
   char *name,            /* Array short name */
   char *title,           /* Array long name */
   int type );            /* Data type of array */

Return_value
mc_def_vec_arr_svar(       /* Define single list array state variable. */
   Famid fam_id,          /* Mili family identifier */
   int rank,              /* Number of array dimensions */
   int dims[],            /* Size of each dimension */
   char *name,            /* Array short name */
   char *title,           /* Array long name */
   int qty_fields,        /* Quantity of fields in vectors */
   char **field_names,    /* Array of field short names */
   char **field_titles,   /* Array of field long names */
   int type );            /* Data type of list array elements */

Return_value
mc_get_svar_def(           /* Copy state variable data to application struct */
   Famid fam_id,          /* Mili family identifier */
   char *svar_name,       /* State variable name */
   State_variable *p_svar ); /* (output) Application state variable struct */

Return_value
mc_get_svar_size(          /* Returns amount and type of data for svar on a class */
   Famid fam_id,          /* Mili family identifier */
   char *class_name,      /* Name of class state variable is associated with */
   char *var_name,        /* State variable name */
   int *num_blocks,       /* Returned number of mesh object blocks for svar */
   int *size,             /* Returned number of values associated with svar */
   int *type);            /* Returned data type of svar */

Return_value
mc_get_svar_mo_ids_on_class( /* Read and return mesh object blocks for specified class/var */
   Famid fam_id,          /* Mili family identifier */
   char *class_name,      /* Name of class state variable is associated with */
   char *svar_name,       /* State variable name */
   int *blocks);          /* Returned mesh object id blocks for svar */

Return_value
mc_get_svar_on_class(     /* Read and return results for specified class/var */
   Famid fam_id,          /* Mili family identifier */
   int state,             /* State number at which to read results */
   char *class_name,      /* Name of class state variable is associated with */
   char *svar_name,       /* State variable name */
   void *result);         /* Returned values for the state variable */

Return_value
mc_open_srec(              /* Create a state record format descriptor */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh which format belongs to */
   int *p_srec_id );      /* (output) Destination for state record ident */

Return_value
mc_close_srec(             /* Close a state record format descriptor */
   Famid fam_id,          /* Mili family identifier */
   int srec_id );         /* Ident of state record format descriptor */

Return_value
mc_def_subrec(            /* Define a state sub-record format */
   Famid fam_id,          /* Mili family identifier */
   int srec_id,           /* Ident of state record format descriptor */
   char *subrec_name,     /* Subrecord (binding) name */
   int data_org,          /* Data organization */
   int qty_svars,         /* Quantity of state variables bound to subrecord */
   char *svar_names,      /* Array of state variable short names */
   int name_stride,       /* Spacing between start of each short name */
   char *class_name,      /* Mesh object class name */
   int format,            /* Format of mesh objects passed in */
   int qty,               /* Number of objects or object blocks */
   int *mo_ids,           /* Array of objects or blocks making up subrecord */
   int *flag );           /* Array of surface variable "display flags":
                              PER_OBJECT or PER_FACET */

Return_value              
mc_get_subrec_cnt(        /* Get number of sub-records containing the names svar */
   Famid fam_id,          /* Mili family identifier */
   int staterec_id,       /* Ident of state record format descriptor */
   char *svar_name,       /* Name of svar to surch for */ 
   int *cnt );            /* Returned number of sub-records */

Return_value
mc_get_subrec_ids(        /* Get the id numbers for the sub-records that have var=svar_name */
   Famid fam_id,          /* Mili family identifier */
   int staterec_id,       /* Ident of state record format descriptor */
   char *svar_name,       /* Name of svar to surch for */ 
   int *cnt,              /* Number of sub-records located */
   int **ids );           /* List of sub-record ids (1-based) */

Return_value
mc_def_subrec_from_subrec( 
      Famid fam_id,        /* Mili family identifier */
      int srec_id,         /* Ident of state record format descriptor */
      Subrecord *in_subrec /* Subrecord from which we are creating the current sub_rec*/
);


Return_value
mc_get_subrec_def(         /* Copy subrecord data to application struct */
   Famid fam_id,          /* Mili family identifier */
   int srec_id,           /* Ident of state record format descriptor */
   int subrec_id,         /* Index of requested subrecord */
   Subrecord *p_subrec ); /* (output) application subrecord struct */

Return_value
mc_get_subrec_fields(     /* Gets all scalar fields from sub-record definition */
   Famid fam_id,          /* Mili family identifier */
   int staterec_id,       /* Ident of state record format descriptor */
   int sid, 
   char *name, 
   char *class_name, 
   int *qty_svars, 
   int *organization,
   int *qty_objects, 
   int *qty_blocks );

Return_value
mc_get_svars(           /* Gets all svars used in this database */
   Famid fam_id,        /* Mili family identifier */
   int staterec_id,     /* Ident of state record format descriptor */
   int *num_svars,      /* Total number of svars returned in svar_names */
   char ***svar_names ); /* List of svar names */

Return_value
mc_flush(                  /* Flush cached non-state data to disk */
   Famid fam_id,          /* Mili family identifier */
   int data_type );       /* Mili data category, state or non-state */

/*
 * State record I/O
 */

Return_value
mc_new_state(              /* Set family to receive data for a new state */
   Famid fam_id,          /* Mili family identifier */
   int srec_id,           /* State record definition ident for new state */
   float time,            /* Simulation time for new state */
   int *p_file_suffix,    /* Output - numeric suffix of file receiving state */
   int *p_file_st_index );/* Output - zero-based index of state within file */

Return_value
mc_end_state(              /* Tell mili that this is the end of state data to flush the last state map */
   Famid fam_id,           /* Mili family identifier*/
   int srec_id);            /* State record definition ident for state */
   
Return_value
mc_wrt_stream(             /* Write a sequential stream of state data words */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of words */
   int qty,               /* Quantity of words */
   void *data );          /* Data to be written to family */

Return_value
mc_wrt_subrec(             /* Write an indexed subset of a subrecord's data */
   Famid fam_id,          /* Mili family identifier */
   char *subrec_name,     /* Subrecord identifier for data being written */
   int start,             /* First lump (state vector or result array) index */
   int stop,              /* Last lump (state vector or result array) index */
   void *data );          /* Data (a sequence of lumps) to be written */

Return_value
mc_read_results(           /* Read state variables into result-ordered arrays */
   Famid fam_id,          /* Mili family identifier */
   int state,             /* State number at which to read results */
   int subrec_id,         /* Index of subrecord which has requested results */
   int qty,               /* Quantity of results requested */
   char **results,        /* Array of result names */
   void *data );          /* (output) Data buffer in which to write results */
/*
 * Miscellaneous
 */

Return_value
mc_query_family(           /* Request information about family contents */
   Famid fam_id,          /* Mili family identifier */
   int which,             /* Information type specifier */
   void *num_args,        /* Array of optional numerical arguments */
   char *char_args,       /* Array of characters for optional string args */
   void *p_info );        /* (output) Destination for requested info */
Return_value
mc_get_class_info_by_name( 
   Famid fam_id, 
	int *mesh_id, 
	const char *in_short_name,
	int *superclass, 
	int *class_index, 
	char *in_long_name,
   int *num_elems );
Return_value
mc_get_class_info(         /* Get object class name and size */
   Famid famid,           /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that class belongs to */
   int superclass,        /* Identifier of superclass parent of class */
   int class_index,       /* Unique index of requested class */
   char *short_name,      /* (output) Destination for short name of class */
   char *long_name,       /* (output) Destination for long name of class */
   int *object_qty );     /* (output) Destination for qty of class objects */

Return_value
mc_get_simple_class_info(  /* Get object class name and size */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that class belongs to */
   int superclass,        /* Identifier of superclass parent of class */
   int class_index,       /* Unique index of requested class */
   char *short_name,      /* (output) Destination for short name of class */
   char *long_name,       /* (output) Destination for long name of class */
   int *start_ident,      /* (output) Destination for class's first ident */
   int *stop_ident );     /* (output) Destination for class's last ident */

Return_value
mc_limit_states(           /* Set quantity of states per state-data file */
   Famid fam_id,          /* Mili family identifier */
   int states_per_file ); /* Quantity of states per family state-data file */

Return_value
mc_limit_filesize(         /* Set quantity of states per state-data file */
   Famid fam_id,          /* Mili family identifier */
   long filesize );       /* Requested filesize in bytes */

Return_value
mc_suffix_width(           /* Set suffix width for state-data filenames */
   Famid fam_id,          /* Mili family identifier */
   int suffix_width );    /* Min numeric suffix width for state-file names */

void
mc_print_error(            /* Print diagnostic message for error return */
   char *preamble,        /* Text to be prepended to ": <message>" */
   int error_return );    /* Value returned from function */

Return_value
mc_cleanse_subrec(         /* Free allocated memory in a Subrecord */
   Subrecord *p_subrec ); /* Pointer to Subrecord to clean */

Return_value
mc_cleanse_st_variable(    /* Free allocated memory in a State_variable */
   State_variable *p_svar ); /* Pointer to State_variable to clean */

Return_value
mc_set_buffer_qty(         /* Set input buffer quantity for subrecord(s) */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that class belongs to */
   char *class_name,      /* Mesh object class name */
   int buf_qty );         /* New qty of buffers for data of named class */

Return_value
mc_init_metadata(          /* Initialize Mili non-state metadata */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_get_metadata(           /* Read metadata from a Mili file */
   Famid fam_id,          /* Mili family identifier */
   char *mili_version,    /* Library version string */
   char *host,            /* Host name */
   char *arch,            /* Arch name */
   char *timestamp,       /* File creation date and time */
   char *xmilics_version);/* Xmilics version that created this database if combined */

Return_value
mc_countDomains(           /* Return number of domains for a file family */
   char *path,
   char *root,
   int *domCount );


/*****************************************************************
 * Time Independent file functions:
 * Added May 2006 by I.R. Corey
 *****************************************************************
 */

int
mc_htable_search_wildcard(    /* Search the standard hash table */
   int fid,                   /* Mili family identifier */
   int list_len,
   Bool_type allow_duplicates,
   char *key1,
   char *key2,
   char *key3,
   char **return_list );

int
mc_get_param_list(
   int fid,
   int *list_len,
   Bool_type ti_param,
   char **param_list );

int
mc_get_param_atributes(
   int fid,
   char *var_name,
   Bool_type ti_param,
   int *type,
   int *len );

/*
 * File locking enable/disable functions.
 */

void
mc_filelock_disable( void ) ;

void
mc_filelock_enable( void ) ;



/******************** Temporary ***********************/
/* Remove when new method to invoke mc_silo functions
 * is completed.
 */
int
mc_silo_open(              /* Create/open a file family. */
   char *root_name,       /* Root name for family */
   char *path,            /* Path to directory where family is/will be */
   char *mode,            /* Access mode */
   Famid *fam_id );       /* (output) Mili family identifier */

int
mc_silo_close(             /* Close a file family. */
   Famid fam_id );        /* Mili family identifier */

int
mc_silo_partition_state_data(   /* Create a state data branch file partition. */
   Famid fam_id );        /* Mili family identifier */

int
mc_silo_restart_at_state(  /* Set family to overwrite at an existing state */
   Famid fam_id,          /* Mili family identifier */
   int file_suffix,       /* Index of state file where overwrite is to begin */
   int file_state_index );/* Index of state in file where overwrite begins */

int
mc_silo_restart_at_file(   /* Set family to overwrite at an existing file */
   Famid fam_id,          /* Mili family identifier */
   int fname_index );     /* Zero-based file index where overwrite begins */

int
mc_silo_delete_family(     /* Delete a Mili file family */
   char *root_name,       /* Root name for family */
   char *path );          /* Path to directory where family is/will be */

/*
 * Non-state named-parameter I/O
 */

Return_value
mc_silo_wrt_scalar(        /* Write a named scalar to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of scalar */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

Return_value
mc_silo_read_scalar(       /* Read a named scalar from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

int
mc_silo_wrt_array(         /* Write a named array to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of array */
   char *name,            /* Label of array */
   int order,             /* Number of array dimensions */
   int *dimensions,       /* Size of each dimension */
   void *data );          /* Array data */

Return_value
mc_silo_read_param_array(  /* Read a named param array from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of param */
   void **value );        /* data */

Return_value
mc_silo_read_param_array_len(  /* Read length of a named param array from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name);           /* Label of param */

int
mc_silo_wrt_string(        /* Write a named string to the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

Return_value
mc_silo_read_string(       /* Read a named string from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */


/*****************************************************************
 * Time Independent file functions:
 * Added May 2006 by I.R. Corey
 *****************************************************************
 */

int
mc_silo_wrt_ti_scalar(     /* Write a named scalar to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of scalar */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

int
mc_silo_read_ti_scalar(    /* Read a named scalar from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of scalar */
   void *value );         /* Pointer to scalar */

int
mc_silo_wrt_ti_array(      /* Write a named array to the file family */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of array */
   char *name,            /* Label of array */
   int order,             /* Number of array dimensions */
   int *dimensions,       /* Size of each dimension */
   void *data );          /* Array data */

int
mc_silo_read_ti_array(     /* Read a named param array from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of param */
   void **value );        /* data */

int
mc_silo_wrt_ti_string(     /* Write a named string to the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

int
mc_silo_read_ti_string(    /* Read a named string from the file family */
   Famid fam_id,          /* Mili family identifier */
   char *name,            /* Label of string */
   char *value );         /* String data */

int
mc_silo_set_ti_class(      /* Define TI metadata */
   Famid  fam_id,         /* Mili family identifier */
   int    state,
   int    matid,
   char   *superclass,
   char   *short_name,
   char   *long_name );

int
mc_silo_undef_ti_class(     /* Reset TI class data */
   Famid fam_id );         /* Mili family identifier */


void
mc_silo_enable_ti(          /* Enable TI data capability */
   void );

void
mc_silo_disable_ti(         /* Disable TI data capability */
   void );

Bool_type
mc_silo_ti_check_if_data_found( /* Query if we found TI Data */
   Famid fam_id );

void
mc_silo_ti_data_found(          /* Query if we found TI Data */
   Famid fam_id );

void
mc_silo_make_ti_var_name(
   Famid  fam_id,         /* Mili family identifier */
   char *name,            /* Label of string */
   char *new_name );      /* The neww expanded name */


/*
 * Mesh operations
 */

int
mc_silo_make_umesh(        /* Initialize a new unstructured mesh */
   Famid fam_id,          /* Mili family identifier */
   char *mesh_name,       /* Name of mesh */
   int dim,               /* Quantity of spatial dimensions in mesh */
   int *p_mesh_id );      /* (output) Destination for mesh ident */

int
mc_silo_def_class(         /* Define a new mesh oject class */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh class belongs to */
   int superclass,        /* Mesh object superclass */
   char *short_name,      /* Short name of new class */
   char *long_name );     /* Long name (title) of new class */

int
mc_silo_def_class_idents(  /* Define object identifiers for a class */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that objects belong to */
   char *class_name,      /* Name of class to which nodes belong */
   int start,             /* First object in sequence */
   int stop );            /* Last object in sequence */

int
mc_silo_def_nodes(         /* Define mesh node coordinates. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that nodes belong to */
   char *class_name,      /* Name of class to which nodes belong */
   int start_node,        /* First node in sequence */
   int stop_node,         /* Last node in sequence */
   float *coords );       /* Coordinates for each node in sequence */

int
mc_silo_def_conn_seq(      /* Define mesh element connectivities. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int start_el,          /* First element in sequence */
   int stop_el,           /* Last element in sequence */
   int *data );           /* Array of connectivities for each element */

int
mc_silo_def_conn_seq_labels(  /* Define mesh element connectivities with element labels */
   Famid fam_id,             /* Mili family identifier */
   int mesh_id,              /* Ident of mesh that elements belong to */
   char *class_name,         /* Name of class to which elements belong */
   int start_el,             /* First element in sequence */
   int stop_el,              /* Last element in sequence */
   int *labels,              /* Element labels */
   int *data );              /* Array of connectivities for each element */

int
mc_silo_def_conn_arb(      /* Define mesh element connectivities. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class to which elements belong */
   int qty,               /* Quantity of elements listed */
   int *elem_ids,         /* Array of element identifiers */
   int *data );           /* Array of connectivities for each element */

int
mc_silo_def_conn_arb_labels( /* Define mesh element connectivities with labels */
   Famid fam_id,            /* Mili family identifier */
   int mesh_id,             /* Ident of mesh that elements belong to */
   char *class_name,        /* Name of class to which elements belong */
   int qty,                 /* Quantity of elements listed */
   int *elem_ids,           /* Array of element identifiers */
   int *labels,             /* Array of element labels */
   int *data );             /* Array of connectivities for each element */

int
mc_silo_def_conn_surface(  /* Define surface node connectivities. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *short_name,      /* Short name of new class */
   int qty_of_facets,     /* Quantity of facets in surface */
   int *data,             /* Array of connectivities for each element */
   int *surface_id );     /* Surface ID established by this procedure */

int
mc_silo_load_nodes(        /* Read node coordinates into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class the nodes being loaded belong to */
   void *coords );        /* (output) Destination buffer for node coords */

int
mc_silo_load_conns(        /* Read element connectivities into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that elements belong to */
   char *class_name,      /* Name of class elements being loaded belong to */
   int *conns,            /* (output) Destination buffer for element conn's */
   int *mats,             /* (output) Destination buffer for element mat's */
   int *parts );          /* (output) Destination buffer for elem part no's */

int
mc_silo_load_surface(      /* Read surface connectivities into memory. */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh to which surface belongs */
   int surf,              /* Which surface of this name type */
   char *short_name,      /* (Short) Name of surface class to which nodal connectivities being loaded belong */
   void *conns );         /* (output) Destination buffer for element conn's */

int
mc_silo_get_mesh_id(       /* Find numeric ident associated with mesh name */
   Famid fam_id,          /* Mili family identifier */
   char *mesh_name,       /* Name of mesh */
   int *p_mesh_id );      /* (output) Destination for mesh ident */

/*
 * State record definition
 */

int
mc_silo_def_svars(         /* Define multiple scalar state variables. */
   Famid fam_id,          /* Mili family identifier */
   int qty_svars,         /* Number of state variables defined */
   char *names,           /* Array of short names */
   int name_stride,       /* Spacing between start of each short name */
   char *titles,          /* Array of long names */
   int title_stride,      /* Spacing between start of each long name */
   int types[] );         /* Data type of each state variable */

int
mc_silo_def_vec_svar(      /* Define vector state variable. */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of array */
   int qty_fields,        /* Quantity of fields in vector */
   char *name,            /* Vector short name */
   char *title,           /* Vector long name */
   char **field_names,    /* Array of field short names */
   char **field_titles ); /* Array of field long names */

int
mc_silo_def_arr_svar(      /* Define single array state variable. */
   Famid fam_id,          /* Mili family identifier */
   int rank,              /* Number of array dimensions */
   int dims[],            /* Size of each dimension */
   char *name,            /* Array short name */
   char *title,           /* Array long name */
   int type );            /* Data type of array */

int
mc_silo_def_vec_arr_svar(  /* Define single list array state variable. */
   Famid fam_id,          /* Mili family identifier */
   int rank,              /* Number of array dimensions */
   int dims[],            /* Size of each dimension */
   char *name,            /* Array short name */
   char *title,           /* Array long name */
   int qty_fields,        /* Quantity of fields in vectors */
   char **field_names,    /* Array of field short names */
   char **field_titles,   /* Array of field long names */
   int type );            /* Data type of list array elements */

int
mc_silo_get_svar_def(      /* Copy state variable data to application struct */
   Famid fam_id,          /* Mili family identifier */
   char *svar_name,       /* State variable name */
   State_variable *p_svar ); /* (output) Application state variable struct */

int
mc_silo_open_srec(         /* Create a state record format descriptor */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh which format belongs to */
   int *p_srec_id );      /* (output) Destination for state record ident */

int
mc_silo_close_srec(        /* Close a state record format descriptor */
   Famid fam_id,          /* Mili family identifier */
   int srec_id );         /* Ident of state record format descriptor */

int
mc_silo_def_subrec(        /* Define a state sub-record format */
   Famid fam_id,          /* Mili family identifier */
   int srec_id,           /* Ident of state record format descriptor */
   char *subrec_name,     /* Subrecord (binding) name */
   int data_org,          /* Data organization */
   int qty_svars,         /* Quantity of state variables bound to subrecord */
   char *svar_names,      /* Array of state variable short names */
   int name_stride,       /* Spacing between start of each short name */
   char *class_name,      /* Mesh object class name */
   int format,            /* Format of mesh objects passed in */
   int qty,               /* Number of objects or object blocks */
   int *mo_ids,           /* Array of objects or blocks making up subrecord */
   int *flag );           /* Array of surface variable "display flags":
                              PER_OBJECT or PER_FACET */

int
mc_silo_get_subrec_def(    /* Copy subrecord data to application struct */
   Famid fam_id,          /* Mili family identifier */
   int srec_id,           /* Ident of state record format descriptor */
   int subrec_id,         /* Index of requested subrecord */
   Subrecord *p_subrec ); /* (output) application subrecord struct */

int
mc_silo_flush(             /* Flush cached non-state data to disk */
   Famid fam_id,          /* Mili family identifier */
   int data_type );       /* Mili data category, state or non-state */

/*
 * State record I/O
 */

int
mc_silo_new_state(         /* Set family to receive data for a new state */
   Famid fam_id,          /* Mili family identifier */
   int srec_id,           /* State record definition ident for new state */
   float time,            /* Simulation time for new state */
   int *p_file_suffix,    /* Output - numeric suffix of file receiving state */
   int *p_file_st_index );/* Output - zero-based index of state within file */

int
mc_silo_wrt_stream(        /* Write a sequential stream of state data words */
   Famid fam_id,          /* Mili family identifier */
   int type,              /* Data type of words */
   int qty,               /* Quantity of words */
   void *data );          /* Data to be written to family */

int
mc_silo_wrt_subrec(        /* Write an indexed subset of a subrecord's data */
   Famid fam_id,          /* Mili family identifier */
   char *subrec_name,     /* Subrecord identifier for data being written */
   int start,             /* First lump (state vector or result array) index */
   int stop,              /* Last lump (state vector or result array) index */
   void *data );          /* Data (a sequence of lumps) to be written */

int
mc_silo_read_results(      /* Read state variables into result-ordered arrays */
   Famid fam_id,          /* Mili family identifier */
   int state,             /* State number at which to read results */
   int subrec_id,         /* Index of subrecord which has requested results */
   int qty,               /* Quantity of results requested */
   char **results,        /* Array of result names */
   void *data );          /* (output) Data buffer in which to write results */
/*
 * Miscellaneous
 */

int
mc_silo_query_family(      /* Request information about family contents */
   Famid fam_id,          /* Mili family identifier */
   int which,             /* Information type specifier */
   void *num_args,        /* Array of optional numerical arguments */
   char *char_args,       /* Array of characters for optional string args */
   void *p_info );        /* (output) Destination for requested info */

int
mc_silo_get_class_info(    /* Get object class name and size */
   Famid famid,           /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that class belongs to */
   int superclass,        /* Identifier of superclass parent of class */
   int class_index,       /* Unique index of requested class */
   char *short_name,      /* (output) Destination for short name of class */
   char *long_name,       /* (output) Destination for long name of class */
   int *object_qty );     /* (output) Destination for qty of class objects */

int
mc_silo_get_simple_class_info(  /* Get object class name and size */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that class belongs to */
   int superclass,        /* Identifier of superclass parent of class */
   int class_index,       /* Unique index of requested class */
   char *short_name,      /* (output) Destination for short name of class */
   char *long_name,       /* (output) Destination for long name of class */
   int *start_ident,      /* (output) Destination for class's first ident */
   int *stop_ident );     /* (output) Destination for class's last ident */

int
mc_silo_limit_states(      /* Set quantity of states per state-data file */
   Famid fam_id,          /* Mili family identifier */
   int states_per_file ); /* Quantity of states per family state-data file */

int
mc_silo_limit_filesize(    /* Set quantity of states per state-data file */
   Famid fam_id,          /* Mili family identifier */
   int filesize );        /* Requested filesize */

int
mc_silo_suffix_width(      /* Set suffix width for state-data filenames */
   Famid fam_id,          /* Mili family identifier */
   int suffix_width );    /* Min numeric suffix width for state-file names */

void
mc_silo_print_error(       /* Print diagnostic message for error return */
   char *preamble,        /* Text to be prepended to ": <message>" */
   int error_return );    /* Value returned from function */

int
mc_silo_cleanse_subrec(    /* Free allocated memory in a Subrecord */
   Subrecord *p_subrec ); /* Pointer to Subrecord to clean */

int
mc_silo_cleanse_st_variable(  /* Free allocated memory in a State_variable */
   State_variable *p_svar ); /* Pointer to State_variable to clean */

int
mc_silo_set_buffer_qty(    /* Set input buffer quantity for subrecord(s) */
   Famid fam_id,          /* Mili family identifier */
   int mesh_id,           /* Ident of mesh that class belongs to */
   char *class_name,      /* Mesh object class name */
   int buf_qty );         /* New qty of buffers for data of named class */

void
mc_silo_init_metadata(     /* Initialize Mili non-state metadata */
   Famid fam_id );        /* Mili family identifier */

void
mc_silo_get_metadata(      /* Read metadata from a Mili file */
   Famid fam_id,          /* Mili family identifier */
   char *mili_version,    /* Library version string */
   char *host,            /* Host name */
   char *arch,            /* Arch name */
   char *timestamp);      /* File creation date and time */

void
mc_silo_ti_init_metadata(  /* Initialize Mili TI metadata */
   Famid fam);            /* Mili family identifier */

void
mc_silo_ti_get_metadata(   /* Read metadata from the TI file */
   Famid fam_id,          /* Mili family identifier */
   char *mili_version,    /* Library version string */
   char *host,            /* Host name */
   char *arch,            /* Arch name */
   char *timestamp,       /* File creation date and time */
   char *username);       /* User that created the Mili file */

int
mc_silo_ti_check_arch(     /* Read metadata from the TI file */
   Famid fam_id );        /* Mili family identifier */

Return_value
mc_silo_ti_get_data_attributes( /* Get attributes for a TI data field */
   Famid fam_id, int meshid,
   char  *name, char *this_class,
   int *state, int *matid,
   int *superclass,
   Bool_type *isMeshvar, Bool_type *isNodal,
   int   *datatype,
   int   *datalength );


/*
 * File locking enable/disable functions.
 */

void
mc_silo_filelocking_disable( void ) ;

void
mc_silo_filelocking_enable( void ) ;

/*
 * File TI enable/disable functions.
 */

void
mc_silo_ti_disable(  Famid fam_id ) ;

void
mc_silo_ti_enable(  Famid fam_id ) ;

void
mc_silo_ti_disable_only(  Famid fam_id ) ;

void
mc_silo_ti_enable_only(  Famid fam_id ) ;


/*****************************************************************
 * Mili Reader functions:
 * Added November 2008 by I.R. Corey
 *****************************************************************
 */

int
mc_calc_bytecount(
   int datatype,
   int size );

void
mc_blocks_to_list(  /* Converts block pair format to ids */
   int qty_blocks,  /* Block (pairs) input count */
   int *mo_blocks,  /* Block pair list (len=qty_blocks*2) */
   int *list_count, /* Number of ids returned in list */
   int *list,       /* Return ids */
   int decrement_indices ); /* Block pairs are in reverse order */

/***************************************************************/

/* New functions for global ids */

Return_value
mc_set_global_class_count(
Famid fam_id, 
char* name, 
int global_count);

Return_value
mc_get_global_class_count(
Famid fam_id, 
char* name, 
int *global_count);


Return_value
mc_get_local_class_count(
Famid fam_id, 
char* name, 
int *local_count);


Return_value
mc_def_conn_seq_labels_global_ids( 
Famid fam_id, 
int mesh_id, 
char *short_name,
int start_el, 
int stop_el, 
int *labels, 
int *data , 
int* global_ids);

Return_value
mc_def_seq_global_ids( 
Famid fam_id, 
int mesh_id, 
char *short_name,
int start_el, 
int stop_el,
int* global_ids);


Return_value
mc_def_conn_arb_labels_global_ids( 
Famid fam_id, 
int mesh_id, 
char *short_name,
int el_qty, 
int *elem_ids, 
int *labels, 
int *data , 
int *global_ids);

Return_value
mc_def_global_ids( 
Famid fam_id, 
int mesh_id, 
char *short_name,
int qty, 
int *idents, 
int *global_ids );

Return_value
mc_get_globals_and_locals(
Famid fam_id,
int mesh_id,
char* class_name ,
int *global_ids,
int *local_ids ,
int total_count);

/*
 *  Functions from util.c
 */
char *
mc_determine_naming( char *p_name , State_variable *p_sv);

/**
 *  Functions for writing Makemili files
 */
int 
mc_activate_visit_file(Famid fam_id, 
                       int on_off_switch);
int 
mc_update_global_times(Famid database_id);

int
mc_write_global_metadata(Famid database_id);

int 
mc_update_visit_file(Famid database_id);

Return_value
mc_write_mili_metadata(Famid database_id);
/******************** Temporary ***********************/

/*
 * For debugging.
 */
void
mc_set_hash_dump(          /* Dump hash tables when they're written to */
   int *compress_output );/* Ignore empty buckets on output if TRUE */

#endif
