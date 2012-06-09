
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
