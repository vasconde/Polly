
#include "Data.h"

// Construtor
IOPolly::Data::Data()
{
  allocListPoints ();
  allocListStations ();
}

// Destrutor
IOPolly::Data::~Data()
{
  freeListPoints ();
  freeListStations ();
}


//retorna a station com um determinado ENZ
IOPolly::Station* IOPolly::Data::searchENZ (BaseCoordinates::Leaf::ENZ *p)
{
  
  std::list<Station *>::iterator j;
  
  for(j = stations->begin(); j != stations->end(); j++)
    {
      if( (*j)->getFrom() == p )
	return (*j);
    }
  
  return NULL;
  
}
