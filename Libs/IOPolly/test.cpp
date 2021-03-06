#include <iostream>
#include <list>

#include "../BaseCoordinates/Leafs/ENZ.h"

#include "Data.h"
#include "Station.h"
#include "Reading.h"

int main ()
{

  //Criacao da data
  
  IOPolly::Data *d = new IOPolly::Data();

  BaseCoordinates::Leaf::ENZ *p1 = d->newTrigPoint ("Ponto 1", 45.5, 78.4, 120.0, 1);
  BaseCoordinates::Leaf::ENZ *p2 = d->newTrigPoint ("Ponto 2", 21.5, 98.2, 124.1, 0);
  BaseCoordinates::Leaf::ENZ *p3 = d->newTrigPoint ("Ponto 3", 21.5, 98.2, 124.1, 0);

  
  IOPolly::Station *s1 = d->newStation("S1", p1, 1.45, 93.0);
  IOPolly::Station *s2 = d->newStation("S2", p2, 1.45, 93.0);

  d->newReading ("S1->R1", s1, p2, 23, 54, 56, 1.54);  
  d->newReading ("S1->R2", s1, p3, 23, 54, 56, 1.54);
  d->newReading ("S2->R1", s2, p1, 23, 54, 56, 1.54);

  // apresentacao dos elementos na consola

  d->setId(0,0,"vasco conde");
  std::cout << d->getId(0,0) << std::endl;

  for(unsigned int i = 0; i < d->sizeStations(); i++)
    {
      std::cout << d->getStation(i)->getFrom()->ID() << std::endl;

      for(unsigned int j = 0; j < d->sizeReadings(i); j++)
	{
	  std::cout << "  " << d->getReading(i,j)->getTo()->ID() << std::endl;
	}
    }

  std::cout << "* * * * * * * *" << std::endl;

  std::vector<unsigned int> v = d->getPos("S1","Sdd->R1"); //BUG - ver o q se passa

  std::cout << v[0] << " " << v[1] << std::endl;

  return 0;
}

// int main ()
// {

//   //Criacao da data
  
//   IOPolly::Data *d = new IOPolly::Data();

//   BaseCoordinates::Leaf::ENZ *p1 = d->newPoint ("Ponto 1", 45.5, 78.4, 120.0, 1);
//   BaseCoordinates::Leaf::ENZ *p2 = d->newPoint ("Ponto 2", 21.5, 98.2, 124.1, 0);
//   BaseCoordinates::Leaf::ENZ *p3 = d->newPoint ("Ponto 3", 21.5, 98.2, 124.1, 0);

  
//   IOPolly::Station *s1 = d->newStation("S1", p1, 1.45, 93.0);
//   IOPolly::Station *s2 = d->newStation("S2", p2, 1.45, 93.0);

//   d->newReading ("S1->R1", s1, p2, 23, 54, 56, 1.54);  
//   d->newReading ("S1->R2", s1, p3, 23, 54, 56, 1.54);
//   d->newReading ("S2->R1", s2, p3, 23, 54, 56, 1.54);  

//   d->setId(0, "ALO");

//   std::cout << d->getId(0) << std::endl;
//   std::cout << d->getId(1,0) << std::endl;
//   std::cout << d->getId(1) << std::endl;

//   std::cout << " * * * * * * * * " << std::endl;

//   std::list<IOPolly::Station *>::iterator j;

//   std::list<IOPolly::Reading *>::iterator k;

//   for(j = d->getStations()->begin(); j != d->getStations()->end(); j++)
//     {
//       std::cout << (*j)->getFrom()->ID() << std::endl;            

//       for(k = (*j)->getReadings()->begin(); k != (*j)->getReadings()->end(); k++)
// 	{
// 	  std::cout << "  " << (*k)->getTo()->ID() << std::endl;
// 	}
//     }  

//   return 0;
// }



// int main ()
// {
//   //criacao dos pontos
//   BaseCoordinates::Leaf::ENZ *p1 = new BaseCoordinates::Leaf::ENZ(23,22,4,"Ponto 1");

//   BaseCoordinates::Leaf::ENZ *p2 = new BaseCoordinates::Leaf::ENZ(56,25,8,"Ponto 2");
//   BaseCoordinates::Leaf::ENZ *p3 = new BaseCoordinates::Leaf::ENZ(43,24,8,"Ponto 3");
//   BaseCoordinates::Leaf::ENZ *p4 = new BaseCoordinates::Leaf::ENZ(76,23,9,"Ponto 4");

//   //criacao da estacao 1 e respectivas leituras
//   IOPolly::Station *s1 = new IOPolly::Station(p1, 1.50, 46);

//   IOPolly::Reading *r1_2 = new IOPolly::Reading(p2, 9.0 ,10.0, 13.4, 9.3);
//   IOPolly::Reading *r1_3 = new IOPolly::Reading(p3, 10.0 ,11.0, 14.4, 9.4);

//   s1->addReading(r1_2);
//   s1->addReading(r1_3);

//   //criacao da estacao 2 e respectivas leituras
//   IOPolly::Station *s2 = new IOPolly::Station(p2, 1.43, 180);

//   IOPolly::Reading *r2_4 = new IOPolly::Reading(p4, 11.0 ,12.0, 15.4, 9.5);
  
//   s2->addReading(r2_4);

//   //apresentacao dos resultados

//   //station 1

//   std::cout << s1->getFrom()->ID() << std::endl;

//   std::list<IOPolly::Reading *>::iterator i;

//   for(i = s1->getReadings()->begin(); i != s1->getReadings()->end(); i++)
//     {
//       std::cout << "  " << (*i)->getTo()->ID() << std::endl;
//     }

//   //station 2
//   std::cout << s2->getFrom()->ID() << std::endl;

//   for(i = s2->getReadings()->begin(); i != s2->getReadings()->end(); i++)
//     {
//       std::cout << "  " << (*i)->getTo()->ID() << std::endl;
//     }

//   //Criacao da data
  
//   IOPolly::Data *d = new IOPolly::Data();

//   d->addStation(s1);
//   d->addStation(s2);

//   // INICIO - UTILIZANDO APENAS A CLASSE DATA
  
//   IOPolly::Station *s3 = d->newStation(p4, 1.45, 93.0);

//   d->newReading (s3, p3, 23, 54, 56, 1.54);
  
//   // FIM - UTILIZANDO APENAS A CLASSE DATA

//   std::cout << " * * * * * * * * " << std::endl;

//   std::list<IOPolly::Station *>::iterator j;

//   std::list<IOPolly::Reading *>::iterator k;

//   for(j = d->getStations()->begin(); j != d->getStations()->end(); j++)
//     {
//       std::cout << (*j)->getFrom()->ID() << std::endl;            

//       for(k = (*j)->getReadings()->begin(); k != (*j)->getReadings()->end(); k++)
// 	{
// 	  std::cout << "  " << (*k)->getTo()->ID() << std::endl;
// 	}
//     }

//   std::cout << " * * * * * * * * " << std::endl;

//   IOPolly::Station * ss = d->searchENZ (p2);

//   if(ss != NULL)
//     std::cout << ss->getFrom()->ID() << std::endl;

//   //libertacao da memoria

//   delete p1;

//   delete p2;
//   delete p3;
//   delete p4;

//   delete s1;

//   delete r1_2;
//   delete r1_3;

//   delete s2;

//   delete r2_4;

//   delete d;

//   return 0;
// }


