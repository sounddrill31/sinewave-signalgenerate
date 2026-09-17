/*
 * File: _coder_genChirpLogic_api.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

#ifndef _CODER_GENCHIRPLOGIC_API_H
#define _CODER_GENCHIRPLOGIC_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void genChirpLogic(real_T A, real_T fStart, real_T fEnd, real_T duration,
                   real_T Fs, emxArray_real_T *t, emxArray_real_T *x,
                   real_T *samples, real_T *cycles);

void genChirpLogic_api(const mxArray *const prhs[5], int32_T nlhs,
                       const mxArray *plhs[4]);

void genChirpLogic_atexit(void);

void genChirpLogic_initialize(void);

void genChirpLogic_terminate(void);

void genChirpLogic_xil_shutdown(void);

void genChirpLogic_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_genChirpLogic_api.h
 *
 * [EOF]
 */
