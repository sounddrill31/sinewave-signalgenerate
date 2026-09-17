/*
 * File: genChirpLogic_emxutil.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

#ifndef GENCHIRPLOGIC_EMXUTIL_H
#define GENCHIRPLOGIC_EMXUTIL_H

/* Include Files */
#include "genChirpLogic_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for genChirpLogic_emxutil.h
 *
 * [EOF]
 */
