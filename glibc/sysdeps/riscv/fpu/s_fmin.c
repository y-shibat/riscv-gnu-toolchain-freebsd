#include <math.h>

double __fmin (double x, double y)
{
#ifdef __riscv_soft_float
  if (isnan(x))
      return y;
  if (isnan(y))
      return x;
  return (x < y) ? x : y;
#else
  double res;
  asm ("fmin.d %0, %1, %2" : "=f"(res) : "f"(x), "f"(y));
  return res;
#endif
}
weak_alias (__fmin, fmin)
