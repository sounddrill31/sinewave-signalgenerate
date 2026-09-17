/*
 * File: genSineLogic_emxutil.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 15-Sep-2026 22:32:13
 */

#ifndef GENSINELOGIC_EMXUTIL_H
#define GENSINELOGIC_EMXUTIL_H

/* Include Files */
#include "genSineLogic_types.h"
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
 * File trailer for genSineLogic_emxutil.h
 *
 * [EOF]
 */
