#ifndef _GeoCoord_H_
#define _GeoCoord_H_

// C++ Standard Library //
#include<ENZ.hpp>
#include<string>
#include<list>
#include<iostream>

namespace BaseCoordinates{

  namespace Body{

    class GeoCoord{

    public:      
      GeoCoord(std::list<Leaf::ENZ> *listENZ);

      GeoCoord();

      ~GeoCoord();

      void addEnzPoint(Leaf::ENZ enzPt);

      std::list<Leaf::ENZ>* getListENZ();

      void setListENZ(std::list<Leaf::ENZ>* listENZ);

    private:
      std::list<Leaf::ENZ> *listENZ;

      std::list<Leaf::ENZ>::iterator it; 
    };
  }
}
#endif // _GeoCoord_H_
