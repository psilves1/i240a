#include "fns-compare.hh"

static double
linear(double n)
{
  enum { C = 10000 };
  return C*n;
}

static double
quadratic(double n){
  enum{C = 1000};
  return C*n*n;
}

static const bool isRegistered =
  register_fn(FnInfo("quadratic", quadratic));
