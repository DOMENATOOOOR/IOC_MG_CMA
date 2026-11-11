#!../../bin/darwin-aarch64/CMA

#- SPDX-FileCopyrightText: 2003 Argonne National Laboratory
#-
#- SPDX-License-Identifier: EPICS

#- You may have to change CMA to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

epicsEnvSet("EPICS_CA_ADDR_LIST", "127.0.0.1")
epicsEnvSet("EPICS_CA_AUTO_ADDR_LIST", "NO")
epicsEnvSet("EPICS_CAS_INTF_ADDR_LIST", "127.0.0.1")

## Register all support components
dbLoadDatabase "dbd/CMA.dbd"
CMA_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/coils.db", n_seq=1)
dbLoadRecords("db/sim_server.db")

cd "${TOP}/iocBoot/${IOC}"
iocInit

