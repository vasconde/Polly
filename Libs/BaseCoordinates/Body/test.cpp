#include <iostream>

#include "GeoCoord.h"
#include "../Leafs/ENZ.h"

int main ()
{
  BaseCoordinates::Body::GeoCoord *geo = new BaseCoordinates::Body::GeoCoord();

  BaseCoordinates::Leaf::ENZ *point = new BaseCoordinates::Leaf::ENZ(2, 3, 4, "1");

  geo->addEnzPoint(point);

  delete geo;

  return 0;
}
