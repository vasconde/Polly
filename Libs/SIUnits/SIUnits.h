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

// conversao de radianos para graus decimais
inline double SIUnits::rad2degree (double rad)
{
  return rad * 180.0/M_PI;
}

// conversao de graus decimais para radianos
inline double SIUnits::degree2rad (double degree)
{
  return degree * M_PI / 180.0;
}

// conversao de DMS para graus decimal
inline double SIUnits::DMS2degree (double D, double M, double S)
{
  return D >= 0 ? D + M / 60.0 + S / 3600.0 : D - M / 60.0 - S / 3600.0;
}

// conversao de grados para graus decimal
inline double SIUnits::gon2degree (double gon)
{
  return gon * 180.0 / 200.0;
}

// conversao de graus decimais para grados
inline double SIUnits::degree2gon (double degree)
{
  return degree * 200.0 / 180.0;
}

// conversao de DMS para rad
inline double SIUnits::DMS2rad (double D, double M, double S)
{
  return degree2rad (DMS2degree (D, M, S));
}
  
// conversao de rad para DMS
inline void SIUnits::rad2DMS (double rad, int *D, int *M, double *S)
{
  degree2DMS (rad2degree (rad), D, M, S);
}

// conversao de grados para rad
inline double SIUnits::gon2rad (double gon)
{
  return gon * M_PI / 200.0;
}

// conversao de rad para grados
inline double SIUnits::rad2gon (double rad)
{
  return rad * 200.0 / M_PI;
}

// conversao de DMS para gon
inline double SIUnits::DMS2gon (double D, double M, double S)
{
  return degree2gon (DMS2degree (D, M, S));
}
  
// conversao de gon para DMS
inline void SIUnits::gon2DMS (double gon, int *D, int *M, double *S)
{
  degree2DMS (gon2degree (gon), D, M, S);
}

#endif // _SIUNITS_H_
