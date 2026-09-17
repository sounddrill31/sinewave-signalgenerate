/*
 * File: chirp.c
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

/* Include Files */
#include "chirp.h"
#include "genChirpLogic_emxutil.h"
#include "genChirpLogic_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *t
 *                double varargin_1
 *                double varargin_2
 *                double varargin_3
 *                emxArray_real_T *y
 * Return Type  : void
 */
void chirp(const emxArray_real_T *t, double varargin_1, double varargin_2,
           double varargin_3, emxArray_real_T *y)
{
  const double *t_data;
  double a;
  double *y_data;
  int k;
  int loop_ub;
  int nx;
  int vectorUB;
  t_data = t->data;
  a = (varargin_3 - varargin_1) * (1.0 / varargin_2) / 2.0;
  nx = y->size[0] * y->size[1];
  y->size[0] = 1;
  loop_ub = t->size[1];
  y->size[1] = t->size[1];
  emxEnsureCapacity_real_T(y, nx);
  y_data = y->data;
  nx = (t->size[1] / 2) << 1;
  vectorUB = nx - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    __m128d r;
    r = _mm_loadu_pd(&t_data[k]);
    _mm_storeu_pd(&y_data[k], _mm_mul_pd(r, r));
  }
  for (k = nx; k < loop_ub; k++) {
    double d;
    d = t_data[k];
    y_data[k] = d * d;
  }
  loop_ub = y->size[1];
  nx = y->size[0] * y->size[1];
  y->size[0] = 1;
  emxEnsureCapacity_real_T(y, nx);
  y_data = y->data;
  nx = (y->size[1] / 2) << 1;
  vectorUB = nx - 2;
  for (k = 0; k <= vectorUB; k += 2) {
    _mm_storeu_pd(&y_data[k],
                  _mm_mul_pd(_mm_set1_pd(6.283185307179586),
                             _mm_add_pd(_mm_mul_pd(_mm_set1_pd(a),
                                                   _mm_loadu_pd(&y_data[k])),
                                        _mm_mul_pd(_mm_set1_pd(varargin_1),
                                                   _mm_loadu_pd(&t_data[k])))));
  }
  for (k = nx; k < loop_ub; k++) {
    y_data[k] = 6.283185307179586 * (a * y_data[k] + varargin_1 * t_data[k]);
  }
  nx = y->size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = cos(y_data[k]);
  }
}

/*
 * File trailer for chirp.c
 *
 * [EOF]
 */
