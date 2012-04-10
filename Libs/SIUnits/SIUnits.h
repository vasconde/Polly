/*
 * SIUnits
 * Classe especializada para conversoes de unidades
 */

#ifndef _SIUNITS_H_
#define _SIUNITS_H_

// C Standard Library //
#include <cmath>


class SIUnits
{
public:

  //DEGREE
  // conversao de radianos para graus decimais
  double rad2degree (double rad);

  // conversao de graus decimais para radianos
  double degree2rad (double degree);

  // conversao de DMS para graus decimal
  double DMS2degree (double D, double M, double S);
  
  // conversao de graus decimal para DMS
  void degree2DMS (double degree, int *D, int *M, double *S);

  // conversao de grados para graus decimal
  double gon2degree (double gon);

  // conversao de graus decimais para grados
  double degree2gon (double degree);

  // RAD
  // conversao de DMS para rad
  double DMS2rad (double D, double M, double S);
  
  // conversao de rad para DMS
  void rad2DMS (double rad, int *D, int *M, double *S);

  // conversao de grados para rad
  double gon2rad (double gon);

  // conversao de rad para grados
  double rad2gon (double rad);

  // GON
  // conversao de DMS para gon
  double DMS2gon (double D, double M, double S);
  
  // conversao de gon para DMS
  void gon2DMS (double gon, int *D, int *M, double *S);

private:


};

#endif // _SIUNITS_H_
