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

private:


};

#endif // _SIUNITS_H_
