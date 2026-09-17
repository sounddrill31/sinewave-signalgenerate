/*
 * File: genChirpLogic.c
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 17-Sep-2026 09:12:10
 */

/* Include Files */
#include "genChirpLogic.h"
#include "abs.h"
#include "chirp.h"
#include "colon.h"
#include "genChirpLogic_emxutil.h"
#include "genChirpLogic_types.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * hack to allow memory size of t and x to grow
 *
 * Arguments    : double A
 *                double fStart
 *                double fEnd
 *                double duration
 *                double Fs
 *                emxArray_real_T *t
 *                emxArray_real_T *x
 *                double *samples
 *                double *cycles
 * Return Type  : void
 */
void genChirpLogic(double A, double fStart, double fEnd, double duration,
                   double Fs, emxArray_real_T *t, emxArray_real_T *x,
                   double *samples, double *cycles)
{
  emxArray_real_T *b_t;
  emxArray_real_T *b_x;
  double dv[2];
  double d;
  double *b_t_data;
  double *t_data;
  double *x_data;
  int b_loop_ub;
  int i;
  int loop_ub;
  int scalarLB;
  int vectorUB;
  /*  Simple matlab function to generate Chirp Wave */
  /*  We're using the time vector t to generate enough slots, one for each */
  /*  sample based on the duration */
  d = 1.0 / Fs;
  emxInit_real_T(&b_t, 2);
  t_data = b_t->data;
  if (rtIsNaN(d) || rtIsNaN(duration)) {
    scalarLB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    b_t->size[1] = 1;
    emxEnsureCapacity_real_T(b_t, scalarLB);
    t_data = b_t->data;
    t_data[0] = rtNaN;
  } else if ((d == 0.0) || ((duration > 0.0) && (d < 0.0)) ||
             ((duration < 0.0) && (d > 0.0))) {
    b_t->size[0] = 1;
    b_t->size[1] = 0;
  } else if (rtIsInf(duration) && rtIsInf(d)) {
    scalarLB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    b_t->size[1] = 1;
    emxEnsureCapacity_real_T(b_t, scalarLB);
    t_data = b_t->data;
    t_data[0] = rtNaN;
  } else if (rtIsInf(d)) {
    scalarLB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    b_t->size[1] = 1;
    emxEnsureCapacity_real_T(b_t, scalarLB);
    t_data = b_t->data;
    t_data[0] = 0.0;
  } else if (floor(d) == d) {
    scalarLB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    loop_ub = (int)(duration / d);
    b_t->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_t, scalarLB);
    t_data = b_t->data;
    scalarLB = ((loop_ub + 1) / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      __m128d r;
      dv[0] = i;
      dv[1] = i + 1;
      r = _mm_loadu_pd(&dv[0]);
      _mm_storeu_pd(&t_data[i], _mm_mul_pd(_mm_set1_pd(d), r));
    }
    for (i = scalarLB; i <= loop_ub; i++) {
      t_data[i] = d * (double)i;
    }
  } else {
    eml_float_colon(d, duration, b_t);
    t_data = b_t->data;
  }
  if (b_t->size[1] - 1 < 1) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = b_t->size[1] - 1;
  }
  scalarLB = t->size[0] * t->size[1];
  t->size[0] = 1;
  t->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(t, scalarLB);
  b_t_data = t->data;
  for (i = 0; i < b_loop_ub; i++) {
    b_t_data[i] = t_data[i];
  }
  /*  Generate a linear chirp. */
  /*  Frequency changes from fStart to fEnd over the duration. */
  emxInit_real_T(&b_x, 2);
  chirp(t, fStart, duration, fEnd, b_x);
  loop_ub = b_x->size[1];
  scalarLB = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  emxEnsureCapacity_real_T(b_x, scalarLB);
  x_data = b_x->data;
  scalarLB = (b_x->size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&x_data[i],
                  _mm_mul_pd(_mm_set1_pd(A), _mm_loadu_pd(&x_data[i])));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    x_data[i] *= A;
  }
  emxInit_real_T(&t, 2);
  scalarLB = t->size[0] * t->size[1];
  t->size[0] = 1;
  t->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(t, scalarLB);
  b_t_data = t->data;
  for (i = 0; i < b_loop_ub; i++) {
    b_t_data[i] = t_data[i];
  }
  chirp(t, fStart, duration, fEnd, b_t);
  t_data = b_t->data;
  emxFree_real_T(&t);
  scalarLB = x->size[0] * x->size[1];
  x->size[0] = 1;
  loop_ub = b_t->size[1];
  x->size[1] = b_t->size[1];
  emxEnsureCapacity_real_T(x, scalarLB);
  b_t_data = x->data;
  scalarLB = (b_t->size[1] / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&b_t_data[i],
                  _mm_mul_pd(_mm_set1_pd(A), _mm_loadu_pd(&t_data[i])));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    b_t_data[i] = A * t_data[i];
  }
  /*  Normalize the wave to ensure it fits within the amplitude range */
  b_abs(b_x, b_t);
  d = maximum(b_t);
  emxFree_real_T(&b_t);
  if (d > 0.0) {
    scalarLB = x->size[0] * x->size[1];
    x->size[0] = 1;
    loop_ub = b_x->size[1];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity_real_T(x, scalarLB);
    b_t_data = x->data;
    scalarLB = (b_x->size[1] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      _mm_storeu_pd(
          &b_t_data[i],
          _mm_mul_pd(_mm_set1_pd(A),
                     _mm_div_pd(_mm_loadu_pd(&x_data[i]), _mm_set1_pd(d))));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      b_t_data[i] = A * (x_data[i] / d);
    }
  }
  emxFree_real_T(&b_x);
  /*  Show approximately the first two seconds/cycles worth of samples. */
  /*  A chirp does not have one fixed frequency, so "cycles" is only */
  /*  an approximate plotting parameter here. */
  d = 2.0 * Fs / fmax(fStart, 1.0);
  if (fabs(d) < 4.503599627370496E+15) {
    if (d >= 0.5) {
      d = floor(d + 0.5);
    } else if (d > -0.5) {
      d *= 0.0;
    } else {
      d = ceil(d - 0.5);
    }
  }
  d = fmin(d, x->size[1]);
  *samples = d;
  *cycles = 2.0;
}

/*
 * File trailer for genChirpLogic.c
 *
 * [EOF]
 */
