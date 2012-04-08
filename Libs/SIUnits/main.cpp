#include <iostream>
#include <cmath>

#include "SIUnits.h"

int main ()
{
  SIUnits *u = new SIUnits();

  std::cout << u->rad2degree(M_PI) << std::endl;

  std::cout << u->degree2rad(180.0) << std::endl;

  delete u;

  return 0;
}
