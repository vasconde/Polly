#include "ENZ.hpp"

BaseCoordinates::Body::GeoCoord::GeoCoord(std::list<Leaf::ENZ> *listENZ){
  this->listENZ = listENZ;
}
BaseCoordinates::Body::GeoCoord::GeoCoord(){
  listENZ = new std::list<Leaf::ENZ>();
}
~BaseCoordinates::Body::GeoCoord::GeoCoord(){
  delete listENZ;
}

void addEnzPoint(Leaf::ENZ enzPt){
  try{
    listENZ->push_front(enzPt);
  }
  catch(std::bad_alloc& ba){
    std::cout << "addEnzPoint: O objeto BaseCoordinates::Body::GeoCoord::GeoCoord não contém nenhuma lista<EastingNorthing> declarada.";
  }
  catch(...){
    std::cout << "addEnzPoint: Erro diverso.";
  }
}

std::list<Leaf::ENZ>* getListENZ(){return listENZ;}
void setListENZ(std::list<Leaf::ENZ>* listENZ){this->listENZ = listENZ;}
