#include "fact.hh"

unsigned fact(unsigned n) {
    if(n > 1){
        return n * fact(n-1);
    }
    return n;
  //return (n <= 1) ? n : n * fact(n - 1);
}
