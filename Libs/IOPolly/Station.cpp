
#include "Station.h"

// Construtor
IOPolly::Station::Station()
{
  allocListReadings ();
}

IOPolly::Station::Station(std::string id, BaseCoordinates::Leaf::ENZ *from, 
			  double height, double az0)
{
  this->id = id;
  this->from = from;
  this->height = height;
  this->az0 = az0;
  allocListReadings ();
}


IOPolly::Station::Station(std::string id, BaseCoordinates::Leaf::ENZ *from, 
			  double height, double az0, 
			  std::list <Reading *> *readings)
{
  this->id = id;
  this->from = from;
  this->height = height;
  this->az0 = az0;
  this->readings = readings;
}

// Destrutor
IOPolly::Station::~Station()
{
  freeListReadings ();
}
