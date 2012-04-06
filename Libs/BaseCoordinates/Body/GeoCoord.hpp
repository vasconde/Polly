#include<ENZ.hpp>
#include<string>
#include<list>
#include<iostream>

namespace BaseCoordinates{

  namespace Body{

    class GeoCoord{
    public:
      
      GeoCoord(std::list<Leaf::ENZ> *listENZ){

	this->listENZ = listENZ;
      }
      GeoCoord(){
	listENZ = new std::list<Leaf::ENZ>();
      }
      ~GeoCoord(){
	delete listENZ;
      }

      void addEnzPoint(Leaf::ENZ enzPt){
	try{
	  listENZ->push_front(enzPt);
	}
	catch(std::bad_alloc& ba){
	  std::cout << "addEnzPoint: O objeto GeoCoord não contém nenhuma lista<EastingNorthing> declarada.";
	}
	catch(...){
	  std::cout << "addEnzPoint: Erro diverso.";
	}
      }

      std::list<Leaf::ENZ>* getListENZ(){return listENZ;}
      void setListENZ(std::list<Leaf::ENZ>* listENZ){this->listENZ = listENZ;}
    private:

      std::list<Leaf::ENZ> *listENZ;
      std::list<Leaf::ENZ>::iterator it; 
    };
  }
}

