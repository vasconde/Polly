
#include "Data.h"

// Construtor
IOPolly::Data::Data()
{
  allocListTrigPoints ();
  allocListStations ();
}

// Destrutor
IOPolly::Data::~Data()
{
  freeListTrigPoints ();
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

// From and To

BaseCoordinates::Leaf::ENZ * IOPolly::Data::getFrom (unsigned int pos)
{
  BaseCoordinates::Leaf::ENZ * from = getStation(pos)->getFrom();

  return from;
}

void IOPolly::Data::setFrom (unsigned int pos, 
			     BaseCoordinates::Leaf::ENZ * newFrom)
{
  getStation(pos)->setFrom(newFrom);
}
    
BaseCoordinates::Leaf::ENZ * IOPolly::Data::getTo (unsigned int sPos, 
						   unsigned int rPos)
{
  BaseCoordinates::Leaf::ENZ * to = getReading(sPos, rPos)->getTo();

  return to;
}

void IOPolly::Data::setTo (unsigned int sPos, unsigned int rPos,
			   BaseCoordinates::Leaf::ENZ * newTo)
{
  getReading (sPos, rPos)->setTo(newTo);
}

// Height
const double IOPolly::Data::getHeight (unsigned int pos)
{
  double height = getStation(pos)->getHeight();

  return height;
}

void IOPolly::Data::setHeight (unsigned int pos, const double& newval)
{
  getStation(pos)->setHeight(newval);
}
    
const double IOPolly::Data::getHeight (unsigned int sPos, unsigned int rPos)
{
  double height = getReading(sPos, rPos)->getHeight();

  return height;
}

void IOPolly::Data::setHeight (unsigned int sPos, unsigned int rPos, const double& newval)
{
  getReading (sPos, rPos)->setHeight(newval);
}

// az0 - Station
const double IOPolly::Data::getAz0 (unsigned int pos)
{
  double az0 = getStation(pos)->getAz0();

  return az0;
}

void IOPolly::Data::setAz0 (unsigned int pos, const double& newval)
{
  getStation(pos)->setAz0(newval);
}

// readings - Station

std::list <IOPolly::Reading *> * IOPolly::Data::getReadings(unsigned int pos)
{
  std::list <Reading *> * readings = getStation(pos)->getReadings();

  return readings;
}

void IOPolly::Data::setReadings(unsigned int pos,
				std::list <IOPolly::Reading *> * newval)
{
  getStation(pos)->setReadings(newval);
}

// h_dir - Reading
double IOPolly::Data::getH_dir(unsigned int sPos, unsigned int rPos)
{
  double h_dir = getReading(sPos, rPos)->getH_dir();

  return h_dir;
}

void IOPolly::Data::setH_dir(unsigned int sPos, unsigned int rPos,
			     const double& newval)
{
  getReading (sPos, rPos)->setH_dir(newval);
}

// v_dir - Reading
double IOPolly::Data::getV_dir(unsigned int sPos, unsigned int rPos)
{
  double v_dir = getReading(sPos, rPos)->getV_dir();

  return v_dir;
}

void IOPolly::Data::setV_dir(unsigned int sPos, unsigned int rPos,
			     const double& newval)
{
  getReading (sPos, rPos)->setV_dir(newval);
}

// dist - Reading
double IOPolly::Data::getDist(unsigned int sPos, unsigned int rPos)
{
  double dist = getReading(sPos, rPos)->getDist();

  return dist;
}

void IOPolly::Data::setDist(unsigned int sPos, unsigned int rPos,
			    const double& newval)
{
  getReading (sPos, rPos)->setDist(newval);
}

// posicao dado o id
unsigned int IOPolly::Data::getPos(std::string id)
{
  for(unsigned int i=0; i < sizeStations(); i++)
    {
      if(getStation(i)->getId() == id)
	return i;
    }
  return -1;
}

std::vector<unsigned int> IOPolly::Data::getPos(std::string sId, std::string rId)
{

  std::vector<unsigned int> pos(2);

  pos[0] = -1;
  pos[1] = -1;

  for(unsigned int i = 0; i < sizeStations(); i++)
    {
      if(getStation(i)->getId() == sId)
	{
	  for(unsigned int j = 0; j < sizeReadings(i); j++)
	    {
	      if(getReading(i,j)->getId() == rId)
		{
		    pos[0] = i;
		    pos[1] = j;
		}
	    }
	}
    }

  return pos;
}
