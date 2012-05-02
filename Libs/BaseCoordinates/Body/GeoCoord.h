#ifndef _GeoCoord_H_
#define _GeoCoord_H_

// C++ Standard Library //
#include<string>
#include<list>
#include<iostream>

// Polly Library
#include "../Leafs/ENZ.h"

namespace BaseCoordinates{

  namespace Body{

    class GeoCoord{

    public:      
      GeoCoord(std::list<BaseCoordinates::Leaf::ENZ* > *listENZ);

      GeoCoord();

      ~GeoCoord();

      //adiciona um ponteiro para ENZ
      void addEnzPoint(BaseCoordinates::Leaf::ENZ *enzPt);

      //procura pelo ID e devolve *ENZ 
      BaseCoordinates::Leaf::ENZ* getEnzPoint(std::string id);

      //procura pelas coordenadas e devolve *ENZ
      BaseCoordinates::Leaf::ENZ* getEnzPoint(double e, double n, double z);
      
      //remove ENZ através do ID
      void removeEnzPoint(std::string id);

      //remove ENZ através de coordenadas
      void removeEnzPoint(double e, double n, double z);

      //devolve a lista de *ENZ
      std::list<BaseCoordinates::Leaf::ENZ* >* getListENZ();

      void setListENZ(std::list<BaseCoordinates::Leaf::ENZ* >* listENZ);

    private:
      std::list<BaseCoordinates::Leaf::ENZ* >* listENZ;	

      std::list<BaseCoordinates::Leaf::ENZ* >::iterator it;
    };
  }
}
#endif // _GeoCoord_H_
