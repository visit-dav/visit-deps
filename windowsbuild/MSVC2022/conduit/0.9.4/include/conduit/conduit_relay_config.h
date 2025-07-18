// Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
// Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
// other details. No copyright assignment is required to contribute to Conduit.

//-----------------------------------------------------------------------------
///
/// file: conduit_relay_config.h
///
//-----------------------------------------------------------------------------

#ifndef CONDUIT_RELAY_CONFIG_H
#define CONDUIT_RELAY_CONFIG_H

//-----------------------------------------------------------------------------
//
// #define optional i/o features
//
//-----------------------------------------------------------------------------
/* #undef CONDUIT_RELAY_IO_ADIOS_ENABLED */

/* #undef CONDUIT_RELAY_IO_MPI_ADIOS_ENABLED */

#define CONDUIT_RELAY_IO_HDF5_ENABLED

/* #undef CONDUIT_RELAY_IO_H5ZZFP_ENABLED */

#define CONDUIT_RELAY_IO_SILO_ENABLED

/* #undef CONDUIT_RELAY_ZFP_ENABLED */

#define CONDUIT_RELAY_MPI_ENABLED

/* #undef CONDUIT_RELAY_WEBSERVER_ENABLED */

// this path points to the source dir
/* #define CONDUIT_RELAY_SOURCE_DIR  */

#endif



