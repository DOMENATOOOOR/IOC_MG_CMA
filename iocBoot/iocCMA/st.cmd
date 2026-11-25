#!../../bin/linux-x86_64/CMA

#- SPDX-FileCopyrightText: 2003 Argonne National Laboratory
#-
#- SPDX-License-Identifier: EPICS

#- You may have to change CMA to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"


## Register all support components
dbLoadDatabase "dbd/CMA.dbd"
CMA_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/coils.db", n_seq=1)
dbLoadRecords("db/coils.db", n_seq=2)
dbLoadRecords("db/coils.db", n_seq=3)
dbLoadRecords("db/coils.db", n_seq=4)
dbLoadRecords("db/coils.db", n_seq=5)
dbLoadRecords("db/coils.db", n_seq=6)
dbLoadRecords("db/coils.db", n_seq=7)
dbLoadRecords("db/coils.db", n_seq=8)
dbLoadRecords("db/coils.db", n_seq=9)
dbLoadRecords("db/coils.db", n_seq=10)
dbLoadRecords("db/coils.db", n_seq=11)
dbLoadRecords("db/coils.db", n_seq=12)
dbLoadRecords("db/coils.db", n_seq=13)
dbLoadRecords("db/coils.db", n_seq=14)
dbLoadRecords("db/coils.db", n_seq=15)
dbLoadRecords("db/coils.db", n_seq=16)
cd "${TOP}/iocBoot/${IOC}"
iocInit

