/*
 * File: main.c
 *
 * MATLAB Coder version            : 26.1
 * C/C++ source code generated on  : 15-Sep-2026 22:32:13
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "genSineLogic.h"
#include "genSineLogic_emxAPI.h"
#include "genSineLogic_initialize.h"
#include "genSineLogic_terminate.h"
#include "genSineLogic_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  genSineLogic_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_genSineLogic();
  /* Terminate the application.
You do not need to do this more than one time. */
  genSineLogic_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_genSineLogic(void)
{
  emxArray_real_T *t;
  emxArray_real_T *x;
  double A_tmp;
  double cycles;
  double samples;
  /* Initialize function 'genSineLogic' input arguments. */
  A_tmp = argInit_real_T();
  /* Call the entry-point 'genSineLogic'. */
  emxInitArray_real_T(&t, 2);
  emxInitArray_real_T(&x, 2);
  genSineLogic(A_tmp, A_tmp, A_tmp, A_tmp, t, x, &samples, &cycles);
  emxDestroyArray_real_T(t);
  emxDestroyArray_real_T(x);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
