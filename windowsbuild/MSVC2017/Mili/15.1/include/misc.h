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
 
 * misc.h - Miscellaneous definitions.
 *
 *      Donald J. Dovey
 *      Lawrence Livermore National Laboratory
 *      Oct 24 1991
 *
 */

#ifndef MISC_H
#define MISC_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

/*
 * Uncomment next lines if debugging.
 */
/*
#define DEBUG
#define DEBUG_MEM
*/

/*****************************************************************
 * TAG( NEW NEW_N RENEW_N )
 *
 * Macros for allocating an object or a number of objects.
 */
#ifndef DEBUG_MEM
#define NEW(type,descr) ( (type *)calloc( 1, sizeof( type ) ) )
#define NEW_N(type,cnt,descr) ( (type *)calloc( (cnt), sizeof( type ) ) )
#define RENEW_N(type,old,cnt,add,descr) ( (type *)my_realloc( (void *) (old), \
                                          (cnt) * sizeof( type ),             \
                                          (add) * sizeof( type ),             \
                                          descr ) )
#define RENEWC_N(type,old,cnt,add,descr)                                      \
    ( (type *)mili_recalloc( (void *) (old),                                  \
                             (cnt) * sizeof( type ),                          \
                             (add) * sizeof( type ),                          \
                             descr ) )
#endif

#ifdef DEBUG_MEM
char *my_calloc();
#define NEW(type,descr) ( (type *)my_calloc( 1, sizeof( type ), descr ) )
#define NEW_N(type,cnt,descr) ( (type *)my_calloc( (cnt), sizeof( type ), \
                                descr ) )
#define RENEW_N(type,old,cnt,add,descr) ( (type *)my_realloc( (void *) (old), \
                                          (cnt) * sizeof( type ),             \
                                          (add) * sizeof( type ),             \
                                          descr ) )
#define RENEWC_N(type,old,cnt,add,descr)                                      \
    ( (type *)mili_recalloc( (void *) (old),                                  \
                             (cnt) * sizeof( type ),                          \
                             (add) * sizeof( type ),                          \
                             descr ) )
#endif

/*****************************************************************
 * TAG( Bool_type )
 *
 * A boolean value.
 */
typedef int Bool_type;

/*****************************************************************
 * TAG( TRUE FALSE )
 *
 * The boolean values of true and false.
 */
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#endif
