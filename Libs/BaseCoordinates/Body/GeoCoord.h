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
      GeoCoord(std::list<BaseCoordinates::Leaf::ENZ> *listENZ);

      GeoCoord();

      ~GeoCoord();

      void addEnzPoint(BaseCoordinates::Leaf::ENZ enzPt);

      std::list<BaseCoordinates::Leaf::ENZ>* getListENZ();

      void setListENZ(std::list<BaseCoordinates::Leaf::ENZ>* listENZ);

    private:
      std::list<BaseCoordinates::Leaf::ENZ>* listENZ;	

      std::list<BaseCoordinates::Leaf::ENZ>::iterator it;
    };
  }
}
#endif // _GeoCoord_H_
