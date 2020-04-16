#include "fact.hh"

unsigned fact(unsigned n) {
  return (n <= 1) ? n : n * fact(n - 1);
}
