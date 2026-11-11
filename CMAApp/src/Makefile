# SPDX-FileCopyrightText: 2003 Argonne National Laboratory
#
# SPDX-License-Identifier: EPICS

TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = CMA
# CMA.dbd will be created and installed
DBD += CMA.dbd

# CMA.dbd will be made up from these files:
CMA_DBD += base.dbd

# Include dbd files from all support applications:
#CMA_DBD += asub_to_coils.dbd
#CMA_DBD += asub_from_coils.dbd
CMA_DBD += asub_converting.dbd

# Add all the support libraries needed by this IOC
#CMA_LIBS += xxx

# test_registerRecordDeviceDriver.cpp derives from test.dbd
CMA_SRCS += CMA_registerRecordDeviceDriver.cpp
#CMA_SRCS += asub_to_coils.cpp
#CMA_SRCS += asub_from_coils.cpp
CMA_SRCS += asub_converting.cpp
# Build the main IOC entry point on workstation OSs.
CMA_SRCS_DEFAULT += CMAMain.cpp
CMA_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#CMA_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
CMA_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

