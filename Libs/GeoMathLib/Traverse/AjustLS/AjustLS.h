/*
 * AjustLSxo
 * Classe especializada para executar o ajustamento da poligonal
 * segundo o metodo dos minimos quadrados
 */

#ifndef _AJUSTLS_H_
#define _AJUSTLS_H_

namespace GeoMathLib
{
  namespace Traverse
  {
    class AjustLS
    {
    public:
      AjustLS();
      ~AjustLS();

      void iteration();

    private:
    
    };

  }
}

#endif // _AJUSTLS_H_
