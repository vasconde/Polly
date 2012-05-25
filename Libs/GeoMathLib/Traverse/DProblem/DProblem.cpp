#include "DProblem.h"

//Construtor
GeoMathLib::Traverse::DProblem::DProblem(IOPolly *ioPolly)
{
  this->ioPolly = ioPolly;
}
   
//Executa o processo de cálculo das aproximações inicias dos parâmetros
void Run()
{
  std::list<station>::iterator it;
  BaseCoordinates::Leaf::ENZ *Cst;
  for (it = ioPolly->obs->begin(); it !=ioPolly->obs->end(); it++)
    {
      if(it->from->getInfoInt() == 1) //==1 significa q é Estação FIXA
	{
	  
	}
    }
  
}
      
void calcFixedAzimuth()
{
  
}
     
void calcAzimith_0()
{
  
}
      
void calcNextStatioENZ()
{
  
}




