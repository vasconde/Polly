
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

// * GET & SET for STATION and READINGS attributes //

IOPolly::Station* IOPolly::Data::getStation (unsigned int pos)
{

  assert(pos < stations->size());

  std::list<IOPolly::Station *>::iterator it;

  it = stations->begin();

  std::advance(it, pos);

  return *it;
}

IOPolly::Reading* IOPolly::Data::getReading (unsigned int sPos, unsigned int rPos)
{
  Station* s = getStation (sPos);
  
  std::list<IOPolly::Reading*>* r = s->getReadings();

  assert(rPos < r->size());

  std::list<IOPolly::Reading *>::iterator it;

  it = r->begin();

  std::advance(it, rPos);

  return *it;
}

unsigned int IOPolly::Data::sizeStations ()
{
  return stations->size();
}

unsigned int IOPolly::Data::sizeReadings (unsigned pos)
{
    Station* s = getStation (pos);
  
    std::list<IOPolly::Reading*>* r = s->getReadings();

    return r->size();
}

// Id

std::string IOPolly::Data::getId (unsigned int pos)
{
  std::string id = getStation(pos)->getId();

  return id;
}

void IOPolly::Data::setId (unsigned int pos, std::string newId)
{
  getStation(pos)->setId(newId);
}

std::string IOPolly::Data::getId (unsigned int sPos, unsigned int rPos)
{
  std::string id = getReading(sPos, rPos)->getId();

  return id;
}

void IOPolly::Data::setId (unsigned int sPos, unsigned int rPos, std::string newId)
{
  getReading (sPos, rPos)->setId(newId);
}
