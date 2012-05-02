#include "GeoCoord.h"

BaseCoordinates::Body::GeoCoord::GeoCoord(std::list<BaseCoordinates::Leaf::ENZ* > *listENZ){
  this->listENZ = listENZ;
}
BaseCoordinates::Body::GeoCoord::GeoCoord(){
  listENZ = new std::list<BaseCoordinates::Leaf::ENZ* >();
}
BaseCoordinates::Body::GeoCoord::~GeoCoord(){
  delete listENZ;
}

//adiciona um objecto ENZ ao Geocoord
void BaseCoordinates::Body::GeoCoord::addEnzPoint(BaseCoordinates::Leaf::ENZ *enzPt){
  try{
    listENZ->push_front(enzPt);
  }
  catch(std::bad_alloc& ba){
    std::cout << "addEnzPoint: O objeto BaseCoordinates::Body::GeoCoord::GeoCoord não contém nenhuma lista<ENZ> declarada.";
  }
  catch(...){
    std::cout << "addEnzPoint: Erro diverso.";
  }
}

std::list<BaseCoordinates::Leaf::ENZ* >* BaseCoordinates::Body::GeoCoord::getListENZ(){return listENZ;}
void BaseCoordinates::Body::GeoCoord::setListENZ(std::list<BaseCoordinates::Leaf::ENZ* >* listENZ){this->listENZ = listENZ;}
