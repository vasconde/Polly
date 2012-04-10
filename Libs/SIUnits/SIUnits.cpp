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
  double aux; // para calculos intermedios

  // graus
  *D = (int)degree;
  
  // minutos
  if (degree >= 0)
    aux = (degree - *D) * 60;
  else
    aux = (-degree + *D) * 60;
  *M = (int)aux;

  // segundos
  aux = (aux - *M) * 60;
  *S = aux; 
}

// conversao de grados para graus decimal
double SIUnits::gon2degree (double gon)
{
  return gon * 180.0 / 200.0;
}

// conversao de graus decimais para grados
double SIUnits::degree2gon (double degree)
{
  return degree * 200.0 / 180.0;
}

// conversao de DMS para rad
double SIUnits::DMS2rad (double D, double M, double S)
{
  double degree = DMS2degree (D, M, S);

  return degree2rad (degree);
}
  
// conversao de rad para DMS
void SIUnits::rad2DMS (double rad, int *D, int *M, double *S)
{
  double degree = rad2degree (rad);

  degree2DMS (degree, D, M, S);
}

// conversao de grados para rad
double SIUnits::gon2rad (double gon)
{
  return gon * M_PI / 200.0;
}

// conversao de rad para grados
double SIUnits::rad2gon (double rad)
{
  return rad * 200.0 / M_PI;
}

// conversao de DMS para gon
double SIUnits::DMS2gon (double D, double M, double S)
{
  double degree = DMS2degree (D, M, S);

  return degree2gon (degree);
}
  
// conversao de gon para DMS
void SIUnits::gon2DMS (double gon, int *D, int *M, double *S)
{
  double degree = gon2degree (gon);
  
  degree2DMS (degree, D, M, S);
}
