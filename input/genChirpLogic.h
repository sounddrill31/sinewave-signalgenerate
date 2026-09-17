/*
 * File: genChirpLogic.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

#ifndef GENCHIRPLOGIC_H
#define GENCHIRPLOGIC_H

/* Include Files */
#include "genChirpLogic_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void genChirpLogic(double A, double fStart, double fEnd, double duration,
                          double Fs, emxArray_real_T *t, emxArray_real_T *x,
                          double *samples, double *cycles);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for genChirpLogic.h
 *
 * [EOF]
 */
