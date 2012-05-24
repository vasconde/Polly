#ifndef _DProblem_H_
#define _DProblem_H_

// C++ Standard Library //
#include <string>
#include <list>
#include "../../IOPolly/IOPolly.h"

namespace GeoMathLib
{
  namespace Traverse
  {
    class DProblem
    {
    public:

      //Construtor
      DProblem(IOPolly *ioPolly);
   
      //Executa o processo de cálculo das aproximações inicias dos parâmetros
      void Run();
     
    private:

      IOPolly *ioPolly;
      
      void calcFixedAzimuth();
     
      void calcAzimith_0();
      
      void calcNextStatioENZ();

    };
  }
}
#endif // _DProblem_H_
