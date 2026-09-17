/*
 * File: genChirpLogic_types.h
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

#ifndef GENCHIRPLOGIC_TYPES_H
#define GENCHIRPLOGIC_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#endif
/*
 * File trailer for genChirpLogic_types.h
 *
 * [EOF]
 */
