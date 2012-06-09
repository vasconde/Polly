
#include "Station.h"

// Construtor
IOPolly::Station::Station()
{
  allocListReadings ();
}

IOPolly::Station::Station(BaseCoordinates::Leaf::ENZ *from, double height, 
			  double az0)
{
  this->from = from;
  this->height = height;
  this->az0 = az0;
  allocListReadings ();
}


IOPolly::Station::Station(BaseCoordinates::Leaf::ENZ *from, double height, 
		 double az0, std::list <Reading *> *readings)
{
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
