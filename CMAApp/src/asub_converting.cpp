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
	
	double c1 = *(double *)prec->a;
	double c2 = *(double *)prec->b;

	if (fabs(c1) > 10 || fabs(c2) > 10){
                return 0;
        }

	double cur_cx = *(double *)prec->c;
	double cur_cy = *(double *)prec->d;

	double new_cx = (c1 + c2) * 0.70710678;
	double new_cy = (c1 - c2) * 0.70710678;
	
	if (fabs(new_cx - cur_cx) < 1e-4 && fabs(new_cy - cur_cy) < 1e-4) {
		*(double *)prec->vala = cur_cx;
        	*(double *)prec->valb = cur_cy;
		return 0; 
	}
	
	*(double *)prec->vala = new_cx;
	*(double *)prec->valb = new_cy;

	printf("[IOC] Conv Set From Coils -> CX: %f, CY: %f\n", new_cx, new_cy);
	return 0;
	
}


static long converting_to_coils_init(aSubRecord *prec){
        return 0;
}

static long converting_to_coils_process(aSubRecord *prec){
	
	if (!prec->a || !prec->b || !prec->vala || !prec->valb){
                return -1;
        }
	double cx = *(double *)prec->a;
	double cy = *(double *)prec->b;
	
	double target_c1 = (cx + cy) * 0.70710678;
	double target_c2 = (cx - cy) * 0.70710678;
	
	if (fabs(target_c1) > 10 || fabs(target_c2) > 10){
		return 0;
	}
	
	*(double *)prec->valc = cx;
	*(double *)prec->vald = cy;
		
	if (fabs(target_c1 - *(double *)prec->vala) < 1e-4 &&
        fabs(target_c2 - *(double *)prec->valb) < 1e-4){
                return 0;
        }
	

        *(double *)prec->vala = target_c1;
        *(double *)prec->valb = target_c2;

	printf("[IOC] Conv To Coils -> C1: %f, C2: %f\n", target_c1, target_c2);
        return 0;
}

epicsRegisterFunction(converting_from_coils_init);
epicsRegisterFunction(converting_from_coils_process);
epicsRegisterFunction(converting_to_coils_init);
epicsRegisterFunction(converting_to_coils_process);
