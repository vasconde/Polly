#include <iostream>

#include "GeoCoord.h"
#include "../Leafs/ENZ.h"

int main ()
{
  BaseCoordinates::Body::GeoCoord *geo = new BaseCoordinates::Body::GeoCoord();

  BaseCoordinates::Leaf::ENZ *point = new BaseCoordinates::Leaf::ENZ(2, 3, 4, "1");

  geo->addEnzPoint(point);

  BaseCoordinates::Leaf::ENZ *point2 = new BaseCoordinates::Leaf::ENZ(6, 6, 6, "2");

  geo->addEnzPoint(point2);

  std::cout << geo->getEnzPoint("2")->E() << std::endl;

  delete geo;

  return 0;
}
