/*
 * File: _coder_genSineLogic_api.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 15-Sep-2026 22:32:13
 */

#ifndef _CODER_GENSINELOGIC_API_H
#define _CODER_GENSINELOGIC_API_H

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
void genSineLogic(real_T A, real_T f, real_T duration, real_T Fs,
                  emxArray_real_T *t, emxArray_real_T *x, real_T *samples,
                  real_T *cycles);

void genSineLogic_api(const mxArray *const prhs[4], int32_T nlhs,
                      const mxArray *plhs[4]);

void genSineLogic_atexit(void);

void genSineLogic_initialize(void);

void genSineLogic_terminate(void);

void genSineLogic_xil_shutdown(void);

void genSineLogic_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_genSineLogic_api.h
 *
 * [EOF]
 */
