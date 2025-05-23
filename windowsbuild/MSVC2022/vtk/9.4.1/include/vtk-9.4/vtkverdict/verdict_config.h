/*=========================================================================

  Module:    verdict_config.h.in

  Copyright 2003,2006,2019 National Technology & Engineering Solutions of Sandia, LLC (NTESS).
  Under the terms of Contract DE-NA0003525 with NTESS,
  the U.S. Government retains certain rights in this software.

  See LICENSE for details.

=========================================================================*/

/*! \file verdict_config.h
  \brief Configuration header file for verdict library that calculates metrics for finite elements.
    Also see: \ref index "Main Page" 
 *
 * This file is part of VERDICT
 *
 */

#ifndef __verdict_config_h
#define __verdict_config_h

#define VERDICT_VERSION 

#define BUILD_SHARED_LIBS
#ifdef BUILD_SHARED_LIBS
# define VERDICT_SHARED_LIB
#endif

/* #undef VERDICT_MANGLE */
#ifdef VERDICT_MANGLE
# define VERDICT_NAMESPACE 
#endif
                     
#endif  /* __verdict_config_h */
