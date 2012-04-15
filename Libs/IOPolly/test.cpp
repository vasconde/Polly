#include <iostream>

#include "IOPolly.h"

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

int main ()
{
  IOPolly *t = new IOPolly();

  struct station s1, s2;

  struct reading v1 = {"R1", 21,21,21, 22};
  struct reading v2 = {"R2", 23,23,23, 24};
  struct reading v3 = {"R3", 25,25,25, 26};

  t->addStation("V1", 0.98);
  t->addStation("V2", 0.87);
  t->addStation("V3", 0.88);

  t->addReading("V1", "R1", 21,21,21, 22);
  t->addReading("V1", "R2", 23,23,23, 24);
  t->addReading("V3", "R3", 25,25,25, 26);

  s1.readings.push_back(v1);
  s1.readings.push_back(v2);

  s2.readings.push_back(v3);

  

  printObs(t);

  delete t;

  return 0;
}
