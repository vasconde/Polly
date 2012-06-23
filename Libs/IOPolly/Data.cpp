
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

  // para o caso de um pedido impossivel
  assert(pos < stations->size());


  std::list<Station *>::iterator i;

  i = stations->begin();

  // avanca o iterador para a posicao pedida
  std::advance(i, pos);


  std::string id = (*i)->getId();

  return id;
}



void IOPolly::Data::setId (unsigned int pos, std::string newId)
{
  // para o caso de um pedido impossivel
  assert(pos < stations->size());

  std::list<Station *>::iterator i;

  i = stations->begin();

  // avanca o iterador para a posicao pedida
  std::advance(i, pos);

  // altera o id da station
  (*i)->setId(newId);
}

std::string IOPolly::Data::getId (unsigned int sPos, unsigned int rPos)
{

  /*** 1o - ir ate station na sPos ***/

  // para o caso de um pedido impossivel
  assert(sPos < stations->size());

  std::list<Station *>::iterator i;

  i = stations->begin();

  // avanca o iterador para a posicao pedida
  std::advance(i, sPos);

  // recolhe o ponteiro para readings
  std::list <Reading *> * r = (*i)->getReadings();

  /*** 2o - ir ate reading na rPos ***/

  // para o caso de um pedido impossivel
  assert(rPos < r->size());

  std::list<Reading *>::iterator j;

  j = r->begin();
  
  // avanca o iterador para a posicao pedida
  std::advance(j, rPos);

  std::string id = (*j)->getId();

  return id;
}

// void IOPolly::Data::setID (int sPos, int rPos, std::string newId)
// {

// }
