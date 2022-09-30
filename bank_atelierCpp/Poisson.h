#ifndef __Poisson_h
#define __Poisson_h

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

class Poisson {

public:
  static void init(int seed = 0) {
    srand(seed ? seed : getpid()); 
  }
  static double next(double moy = 1.0) {
    return -log(((double)rand()/RAND_MAX))*moy;
  }
};

#endif