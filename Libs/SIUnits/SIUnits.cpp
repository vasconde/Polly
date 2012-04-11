/*
 * SIUnits - Implentacao
 * Classe especializada para conversoes de unidades
 */

#include "SIUnits.h"

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
