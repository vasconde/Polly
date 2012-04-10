#include <iostream>
#include <cmath>

#include "SIUnits.h"

int main ()
{
  SIUnits *u = new SIUnits();

  //Degree
  std::cout << u->rad2degree(M_PI) << std::endl;

  std::cout << u->degree2rad(180.0) << std::endl;

  int D, M;
  double S;
  double degree = u->DMS2degree(-90,59,20);

  std::cout << degree << std::endl;

  std::cout << (int)degree << std::endl;
  
  u->degree2DMS(degree, &D, &M, &S);

  std::cout << D << " " << M << " " << S << std::endl;


  std::cout << u->gon2degree(100.0) << std::endl;

  std::cout << u->degree2gon(90.0) << std::endl;

  //Rad
  double rad = u->DMS2rad (180, 0, 0);
  
  std::cout << rad << std::endl;
  
  u->rad2DMS (rad, &D, &M, &S);

  std::cout << D << " " << M << " " << S << std::endl;

  std::cout << u->gon2rad(100.0) << std::endl;

  std::cout << u->rad2gon(3.14159/2) << std::endl;

  //GON
  double gon = u->DMS2gon (-95, 34, 02);

  std::cout << gon << std::endl;

  u->gon2DMS (gon, &D, &M, &S);

  std::cout << D << " " << M << " " << S << std::endl;  

  delete u;

  return 0;
}
