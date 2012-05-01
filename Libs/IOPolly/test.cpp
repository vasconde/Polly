#include <iostream>

#include "IOPolly.h"

// Rotina para imprimir a lista de observacoes
// Apenas sao apresentados os nomes das estacoes
// e das leituras (estas ultimas aparecem identadas)
void printObs (IOPolly *t)
{

  std::list<struct station>::iterator i;

  for(i = t->obs.begin(); i != t->obs.end(); i++)
    {
      std::cout << i->from << std::endl;

      std::list<struct reading>::iterator j;
      for(j = i->readings.begin(); j != i->readings.end(); j++)
	{
	  std::cout << "  " << j->to << std::endl;
	}
    }
}

//carregar os dados a partir de um ficheiro de texto
int main ()
{
  IOPolly *t = new IOPolly();

  t->obsFromTextFile ("dataFileTest.txt", 2); // 2 - degree

  t->StationsFromTextFile ("dataControl.txt", 
			   "dataTraverse.txt", 
			   1);

  printObs(t);

  delete t;

  return 0;
}

// carregar as estruturas uma a uma
int main_off ()
{
  IOPolly *t = new IOPolly();

  //stations
  t->addStation("V1", 0.98);
  t->addStation("V2", 0.87);
  t->addStation("V3", 0.88);

  //readings per stations
  t->addReading("V1", "R1", 21,21,21, 22);
  t->addReading("V1", "R2", 23,23,23, 24);
  t->addReading("V3", "R3", 25,25,25, 26);

  printObs(t); //before removed elements

  std::cout << "-----" << std::endl;

  t->removeStation ("V2");
  t->removeReading ("V1", "R2");

  printObs(t); //after removed element

  delete t;

  return 0;
}


