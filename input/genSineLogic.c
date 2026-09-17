/*
 * File: genSineLogic.c
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 15-Sep-2026 22:32:13
 */

/* Include Files */
#include "genSineLogic.h"
#include "abs.h"
#include "colon.h"
#include "genSineLogic_emxutil.h"
#include "genSineLogic_types.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * hack to allow memory size of t and x to grow
 *
 * Arguments    : double A
 *                double f
 *                double duration
 *                double Fs
 *                emxArray_real_T *t
 *                emxArray_real_T *x
 *                double *samples
 *                double *cycles
 * Return Type  : void
 */
void genSineLogic(double A, double f, double duration, double Fs,
                  emxArray_real_T *t, emxArray_real_T *x, double *samples,
                  double *cycles)
{
  __m128d r;
  emxArray_real_T *b_t;
  emxArray_real_T *r1;
  double dv[2];
  double d;
  double *b_t_data;
  double *r2;
  double *t_data;
  double *x_data;
  int b_loop_ub;
  int b_vectorUB;
  int i;
  int loop_ub;
  int scalarLB;
  int vectorUB;
  /*  Simple matlab function to generate Sine Wave */
  /*  We're using the time vector t to generate enough slots, one for each */
  /*  sample based on the frequency and duration */
  d = 1.0 / Fs;
  emxInit_real_T(&b_t, 2);
  t_data = b_t->data;
  if (rtIsNaN(d) || rtIsNaN(duration)) {
    vectorUB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    b_t->size[1] = 1;
    emxEnsureCapacity_real_T(b_t, vectorUB);
    t_data = b_t->data;
    t_data[0] = rtNaN;
  } else if ((d == 0.0) || ((duration > 0.0) && (d < 0.0)) ||
             ((duration < 0.0) && (d > 0.0))) {
    b_t->size[0] = 1;
    b_t->size[1] = 0;
  } else if (rtIsInf(duration) && rtIsInf(d)) {
    vectorUB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    b_t->size[1] = 1;
    emxEnsureCapacity_real_T(b_t, vectorUB);
    t_data = b_t->data;
    t_data[0] = rtNaN;
  } else if (rtIsInf(d)) {
    vectorUB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    b_t->size[1] = 1;
    emxEnsureCapacity_real_T(b_t, vectorUB);
    t_data = b_t->data;
    t_data[0] = 0.0;
  } else if (floor(d) == d) {
    vectorUB = b_t->size[0] * b_t->size[1];
    b_t->size[0] = 1;
    loop_ub = (int)(duration / d);
    b_t->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_t, vectorUB);
    t_data = b_t->data;
    vectorUB = ((loop_ub + 1) / 2) << 1;
    b_vectorUB = vectorUB - 2;
    for (i = 0; i <= b_vectorUB; i += 2) {
      dv[0] = i;
      dv[1] = i + 1;
      r = _mm_loadu_pd(&dv[0]);
      _mm_storeu_pd(&t_data[i], _mm_mul_pd(_mm_set1_pd(d), r));
    }
    for (i = vectorUB; i <= loop_ub; i++) {
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
  vectorUB = t->size[0] * t->size[1];
  t->size[0] = 1;
  t->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(t, vectorUB);
  b_t_data = t->data;
  /*  Generate the sine wave */
  d = 6.283185307179586 * f;
  emxInit_real_T(&t, 2);
  vectorUB = t->size[0] * t->size[1];
  t->size[0] = 1;
  t->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(t, vectorUB);
  x_data = t->data;
  scalarLB = (b_loop_ub / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&t_data[i]);
    _mm_storeu_pd(&b_t_data[i], r);
    _mm_storeu_pd(&x_data[i], _mm_mul_pd(_mm_set1_pd(d), r));
  }
  for (i = scalarLB; i < b_loop_ub; i++) {
    double b_d;
    b_d = t_data[i];
    b_t_data[i] = b_d;
    x_data[i] = d * b_d;
  }
  b_sin(t);
  loop_ub = t->size[1];
  vectorUB = t->size[0] * t->size[1];
  t->size[0] = 1;
  emxEnsureCapacity_real_T(t, vectorUB);
  x_data = t->data;
  vectorUB = (t->size[1] / 2) << 1;
  b_vectorUB = vectorUB - 2;
  for (i = 0; i <= b_vectorUB; i += 2) {
    _mm_storeu_pd(&x_data[i],
                  _mm_mul_pd(_mm_set1_pd(A), _mm_loadu_pd(&x_data[i])));
  }
  for (i = vectorUB; i < loop_ub; i++) {
    x_data[i] *= A;
  }
  emxInit_real_T(&r1, 2);
  vectorUB = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(r1, vectorUB);
  r2 = r1->data;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&r2[i], _mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&t_data[i])));
  }
  for (i = scalarLB; i < b_loop_ub; i++) {
    r2[i] = d * t_data[i];
  }
  emxFree_real_T(&b_t);
  b_sin(r1);
  r2 = r1->data;
  vectorUB = x->size[0] * x->size[1];
  x->size[0] = 1;
  loop_ub = r1->size[1];
  x->size[1] = r1->size[1];
  emxEnsureCapacity_real_T(x, vectorUB);
  b_t_data = x->data;
  vectorUB = (r1->size[1] / 2) << 1;
  b_vectorUB = vectorUB - 2;
  for (i = 0; i <= b_vectorUB; i += 2) {
    _mm_storeu_pd(&b_t_data[i],
                  _mm_mul_pd(_mm_set1_pd(A), _mm_loadu_pd(&r2[i])));
  }
  for (i = vectorUB; i < loop_ub; i++) {
    b_t_data[i] = A * r2[i];
  }
  /*  Normalize the wave to ensure it fits within the amplitude range */
  b_abs(t, r1);
  d = maximum(r1);
  emxFree_real_T(&r1);
  if (d > 0.0) {
    vectorUB = x->size[0] * x->size[1];
    x->size[0] = 1;
    loop_ub = t->size[1];
    x->size[1] = t->size[1];
    emxEnsureCapacity_real_T(x, vectorUB);
    b_t_data = x->data;
    vectorUB = (t->size[1] / 2) << 1;
    b_vectorUB = vectorUB - 2;
    for (i = 0; i <= b_vectorUB; i += 2) {
      _mm_storeu_pd(
          &b_t_data[i],
          _mm_mul_pd(_mm_set1_pd(A),
                     _mm_div_pd(_mm_loadu_pd(&x_data[i]), _mm_set1_pd(d))));
    }
    for (i = vectorUB; i < loop_ub; i++) {
      b_t_data[i] = A * (x_data[i] / d);
    }
  }
  emxFree_real_T(&t);
  /*  take samples from first to cycles for initial plotting */
  d = 2.0 * Fs / f;
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
 * File trailer for genSineLogic.c
 *
 * [EOF]
 */
