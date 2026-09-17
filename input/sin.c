/*
 * File: sin.c
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 15-Sep-2026 22:32:13
 */

/* Include Files */
#include "sin.h"
#include "genSineLogic_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void b_sin(emxArray_real_T *x)
{
  double *x_data;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] = sin(x_data[k]);
  }
}

/*
 * File trailer for sin.c
 *
 * [EOF]
 */
