#ifndef _DProblem_H_
#define _DProblem_H_

// C++ Standard Library //
#include <string>
#include <list>
#include "../../../IOPolly/Data.h"
#include "../../../BaseCoordinates/Body/GeoCoord.h"
#include "../../../BaseCoordinates/Leafs/ENZ.h"

namespace GeoMathLib
{
  namespace Traverse
  {
    class DProblem
    {
    public:

      //Construtor
      DProblem(IOPolly::Data *ioPolly);
   
      //Executa o processo de cálculo das aproximações inicias dos parâmetros
      void Run();
     
    private:

      IOPolly::Data *ioPolly;
      
      //Calcula o Azimute fixo da poligonal
      void calcFixedAzimuth();
     
      //Calcula o R0 de cada estacionamento
      void calcAzimith_0();
      
      //Calcula as coordenadas do vértice seguinte
      void calcNextStatioENZ();

    };
  }
}
#endif // _DProblem_H_
