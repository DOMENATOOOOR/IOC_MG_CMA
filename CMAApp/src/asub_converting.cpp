#include<stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "alarm.h"
#include "dbDefs.h"
#include "dbAccess.h"
#include "dbConstLink.h"
#include "dbEvent.h"
#include "recGbl.h"
#include "devSup.h"
#include "cantProceed.h"
#include "menuYesNo.h"
#include <registryFunction.h>
#include <aSubRecord.h>
#include <epicsExport.h>

static long converting_from_coils_init(aSubRecord *prec){
        return 0;
}

static long converting_from_coils_process(aSubRecord *prec){

	if (!prec->a || !prec->b || !prec->vala || !prec->valb){
		return -1;
	}
	
	double target_v = (*(double *)prec->a + *(double *)prec->b) * 0.70710678;
	double target_h = (*(double *)prec->a - *(double *)prec->b) * 0.70710678;
	
	double current_v = *(double *)prec->vala;
	double current_h = *(double *)prec->valb;
	
 	/*if (fabs(target_v - current_v) < 1e-4 && 
	fabs(target_h - current_h) < 1e-4){
		return 0;
	}*/
	
        *(double *)prec->vala = target_v;
        *(double *)prec->valb = target_h;
        printf("[IOC] Conv From Coils -> V: %f, H: %f\n", target_v, target_h);
	return 0;
}


static long converting_to_coils_init(aSubRecord *prec){
        return 0;
}

static long converting_to_coils_process(aSubRecord *prec){
	
	if (!prec->a || !prec->b || !prec->vala || !prec->valb){
                return -1;
        }
	
	double target_c1 = (*(double *)prec->a + *(double *)prec->b) * 0.70710678;
	double target_c2 = (*(double *)prec->a - *(double *)prec->b) * 0.70710678;
	
	/*if (fabs(target_c1 - *(double *)prec->vala) < 1e-4 &&
        fabs(target_c2 - *(double *)prec->valb) < 1e-4){
                return 0;
        }*/

        *(double *)prec->vala = target_c1;
        *(double *)prec->valb = target_c2;
	printf("[IOC] Conv To Coils -> C1: %f, C2: %f\n", target_c1, target_c2);
        return 0;
}

epicsRegisterFunction(converting_from_coils_init);
epicsRegisterFunction(converting_from_coils_process);
epicsRegisterFunction(converting_to_coils_init);
epicsRegisterFunction(converting_to_coils_process);
