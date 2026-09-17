/*
 * File: genChirpLogic_emxAPI.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

#ifndef GENCHIRPLOGIC_EMXAPI_H
#define GENCHIRPLOGIC_EMXAPI_H

/* Include Files */
#include "genChirpLogic_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);

extern emxArray_real_T *
emxCreateWrapperND_real_T(double *data, int numDimensions, const int *size);

extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows,
                                                int cols);

extern emxArray_real_T *emxCreate_real_T(int rows, int cols);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for genChirpLogic_emxAPI.h
 *
 * [EOF]
 */
