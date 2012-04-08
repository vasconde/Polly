/*
 * SIUnits - Implentacao
 * Classe especializada para conversoes de unidades
 */

#include "SIUnits.h"


// conversao de radianos para graus decimais
double SIUnits::rad2degree (double rad)
{
  return rad * 180.0/M_PI;
}

// conversao de graus decimais para radianos
double SIUnits::degree2rad (double degree)
{
  return degree * M_PI / 180.0;
}

// conversao de DMS para graus decimal
double SIUnits::DMS2degree (double D, double M, double S)
{
  if(D >= 0)
    return D + M / 60.0 + S / 3600.0;
  else
    return D - M / 60.0 - S / 3600.0;
}

// conversao de degree para DMS
void SIUnits::degree2DMS (double degree, int *D, int *M, double *S)
{
  //*D = (int)degree;
  //*M = (int)(degree % 1) * 60;
  //*S = (((degree % 1) * 60) % 1) * 60;
}
