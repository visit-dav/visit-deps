# Copyright (c) Lawrence Livermore National Security, LLC and other Conduit
# Project developers. See top-level LICENSE AND COPYRIGHT files for dates and
# other details. No copyright assignment is required to contribute to Conduit.

###############################################################################
# file: conduit_config.mk
###############################################################################
#
# A CMake-generated Make include file Defines the following Make variables:
#
######
#  CONDUIT_INCLUDE_FLAGS
#  CONDUIT_LIB_FLAGS
#  CONDUIT_MPI_LIB_FLAGS
######
#
# For us in another Makefile build system
############################################################################

CONDUIT_DIR = C:\\A_Visit\\GIT\\visit-deps\\windowsbuild\\MSVC2017\\conduit\\0.8.2

CONDUIT_EXTRA_LIB_FLAGS = 

CONDUIT_USE_CXX11 = TRUE
CONDUIT_USE_FMT = TRUE

CONDUIT_SILO_DIR  = 
CONDUIT_ADIOS_DIR = 
CONDUIT_ZFP_DIR   = 

CONDUIT_METIS_DIR    = 
CONDUIT_PARMETIS_DIR = 


# hdf5 info, including tpls
CONDUIT_HDF5_DIR  = C:/A_Visit/GIT/visit-deps/windowsbuild/MSVC2017/hdf5/1.8.19
CONDUIT_HDF5_EXTRA_INCLUDE_FLAGS = 
CONDUIT_HDF5_EXTRA_LIB_FLAGS     =  

CONDUIT_LINK_RPATH = -Wl,-rpath,$(CONDUIT_DIR)/lib

# two steps are used b/c there are commas in the linker commands
# which will undermine parsing of the makefile
CONDUIT_SILO_RPATH_FLAGS_VALUE  = -Wl,-rpath,$(CONDUIT_SILO_DIR)/lib
CONDUIT_HDF5_RPATH_FLAGS_VALUE  = -Wl,-rpath,$(CONDUIT_HDF5_DIR)/lib
CONDUIT_ADIOS_RPATH_FLAGS_VALUE = -Wl,-rpath,$(CONDUIT_ADIOS_DIR)/lib
CONDUIT_ZFP_RPATH_FLAGS_VALUE   = -Wl,-rpath,$(CONDUIT_ZFP_DIR)/lib
CONDUIT_METIS_RPATH_FLAGS_VALUE = -Wl,-rpath,$(CONDUIT_METIS_DIR)/lib
CONDUIT_PARMETIS_RPATH_FLAGS_VALUE = -Wl,-rpath,$(CONDUIT_PARMETIS_DIR)/lib

CONDUIT_LINK_RPATH += $(if $(CONDUIT_SILO_DIR), $(CONDUIT_SILO_RPATH_FLAGS_VALUE))
CONDUIT_LINK_RPATH += $(if $(CONDUIT_HDF5_DIR), $(CONDUIT_HDF5_RPATH_FLAGS_VALUE))
CONDUIT_LINK_RPATH += $(if $(CONDUIT_ADIOS_DIR), $(CONDUIT_ADIOS_RPATH_FLAGS_VALUE))
CONDUIT_LINK_RPATH += $(if $(CONDUIT_ZFP_DIR), $(CONDUIT_ZFP_RPATH_FLAGS_VALUE))
CONDUIT_LINK_RPATH += $(if $(CONDUIT_METIS_DIR), $(CONDUIT_METIS_RPATH_FLAGS_VALUE))
CONDUIT_LINK_RPATH += $(if $(CONDUIT_PARMETIS_DIR), $(CONDUIT_PARMETIS_RPATH_FLAGS_VALUE))


#################
# Include Flags
#################
CONDUIT_INCLUDE_FLAGS  = -I $(CONDUIT_DIR)/include/conduit
CONDUIT_INCLUDE_FLAGS += -I $(CONDUIT_DIR)/include

CONDUIT_INCLUDE_FLAGS += $(if $(CONDUIT_ADIOS_DIR),-I$(CONDUIT_ADIOS_DIR)/include)

CONDUIT_INCLUDE_FLAGS += $(if $(CONDUIT_SILO_DIR),-I$(CONDUIT_SILO_DIR)/include)

CONDUIT_INCLUDE_FLAGS += $(if $(CONDUIT_HDF5_DIR),-I$(CONDUIT_HDF5_DIR)/include)
CONDUIT_INCLUDE_FLAGS += $(if $(CONDUIT_HDF5_DIR),$(CONDUIT_HDF5_EXTRA_INCLUDE_FLAGS))

CONDUIT_INCLUDE_FLAGS += $(if $(CONDUIT_ZFP_DIR),-I$(CONDUIT_ZFP_DIR)/include)

# Note: parmetis headers are not exposed in our api

#################
# Linking Flags
#################

###################################################
# ADIOS
#################
CONDUIT_ADIOS_LIB_FLAGS = $(if $(CONDUIT_ADIOS_DIR),)
CONDUIT_ADIOS_MPI_LIB_FLAGS = $(if $(CONDUIT_ADIOS_DIR),)


##########
# Silo
##########
CONDUIT_SILO_LIB_FLAGS = $(if $(CONDUIT_SILO_DIR),-L $(CONDUIT_SILO_DIR)/lib -lsiloh5)


##########
# HDF5
##########
CONDUIT_HDF5_LIB_FLAGS  = $(if $(CONDUIT_HDF5_DIR),-L $(CONDUIT_HDF5_DIR)/lib -lhdf5)
CONDUIT_HDF5_LIB_FLAGS += $(if $(CONDUIT_HDF5_DIR),$(CONDUIT_HDF5_EXTRA_LIB_FLAGS))

##########
# ZFP
##########
CONDUIT_ZFP_LIB_FLAGS  = $(if $(CONDUIT_ZFP_DIR),-L $(CONDUIT_ZFP_DIR)/lib -lzfp)

##########
# PARMETIS
##########
CONDUIT_METIS_LIB_FLAGS  = $(if $(CONDUIT_METIS_DIR),-L $(CONDUIT_METIS_DIR)/lib -lmetis)
CONDUIT_PARMETIS_LIB_FLAGS  = $(if $(CONDUIT_PARMETIS_DIR),-L $(CONDUIT_PARMETIS_DIR)/lib -lparmetis)


##########
# Conduit
##########
# All conduit libs, without MPI
CONDUIT_LIB_FLAGS = -L $(CONDUIT_DIR)/lib \
                    -lconduit_blueprint \
                    -lconduit_relay \
                    -lconduit $(CONDUIT_ADIOS_LIB_FLAGS) $(CONDUIT_SILO_LIB_FLAGS) $(CONDUIT_HDF5_LIB_FLAGS) $(CONDUIT_ZFP_LIB_FLAGS) $(CONDUIT_EXTRA_LIB_FLAGS)

# All conduit libs, with MPI
CONDUIT_MPI_LIB_FLAGS = -L $(CONDUIT_DIR)/lib \
                        -lconduit_relay_mpi_io \
                        -lconduit_relay_mpi \
                        -lconduit_blueprint_mpi \
                        -lconduit_blueprint \
                        -lconduit_relay \
                        -lconduit $(CONDUIT_ADIOS_MPI_LIB_FLAGS) $(CONDUIT_SILO_LIB_FLAGS) $(CONDUIT_HDF5_LIB_FLAGS) $(CONDUIT_ZFP_LIB_FLAGS) $(CONDUIT_METIS_LIB_FLAGS) $(CONDUIT_PARMETIS_LIB_FLAGS) $(CONDUIT_EXTRA_LIB_FLAGS)
