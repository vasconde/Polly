/*
 * IOPolly
 * Classe especializada para entrada e saida
 * de dados
 *
 * FASE DE CRIACAO DA ESTRUTURA DE DADOS
 * AINDA MUITO EMBRIONARIA MAS JA FUNCIONA
 */

#ifndef _DATA_H_
#define _DATA_H_

#include "../BaseCoordinates/Leafs/ENZ.h"
#include "../BaseCoordinates/Body/GeoCoord.h"
#include "Reading.h"
#include "Station.h"

namespace IOPolly
{
  class Data
  {
  public:

    Data();
    ~Data();

    //metodos

    //aloca e liberta memoria para a lista de stations
    inline void allocListPoints ();
    inline void freeListPoints ();

    //aloca e liberta memoria para a lista de stations
    inline void allocListStations ();
    inline void freeListStations ();

    //adiciona uma nova station ah lista stations
    inline void addStation (Station *p_newStation);

    // GET & SET //

    //points
    inline BaseCoordinates::Body::GeoCoord * getPoints() const;
    inline void setPoints(BaseCoordinates::Body::GeoCoord * newval); 

    //stations
    inline std::list <Station *> * getStations() const;
    inline void setStations(std::list <Station *> * newval);

  private:

    //lista de pontoa de coordenads conhecidas - Control Stations
    //getInfoInt[0] -> 0 se Traverse Station; 1 se Control Station
    BaseCoordinates::Body::GeoCoord *points;

    std::list<Station *> *stations;

  };
  
  // alocacao de memoria para a lista de points
  inline void Data::allocListPoints ()
  {
    points = new BaseCoordinates::Body::GeoCoord();
  }
  
  // libertacao de memoria para a lista de points
  inline void Data::freeListPoints ()
  {
    delete points;
  }

  // alocacao de memoria para a lista de stations
  inline void Data::allocListStations ()
  {
    stations = new std::list <Station *>();
  }

  // libertacao de memoria para a lista de stations
  inline void Data::freeListStations ()
  {
    delete stations;
  }

  //adiciona um novo station a lista stations
  inline void Data::addStation (Station *p_newStation)
  {
    stations->push_back(p_newStation);
  }

  // * GET & SET * //

  //Points
  inline BaseCoordinates::Body::GeoCoord * Data::getPoints() const
  { return points; }

  inline void Data::setPoints(BaseCoordinates::Body::GeoCoord * newval)
  { 
    freeListPoints (); // liberta a memoria
    points = newval; 
  }

  //Stations
  inline std::list <Station *> * Data::getStations() const
  { return stations; }

  inline void Data::setStations(std::list <Station *> * newval)
  { 
    freeListStations (); // liberta a memoria
    stations = newval; 
  }
}

#endif // _DATA_H_
