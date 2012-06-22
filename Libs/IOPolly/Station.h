/*
 * IOPolly
 * Classe especializada para entrada e saida
 * de dados
 *
 * FASE DE CRIACAO DA ESTRUTURA DE DADOS
 * AINDA MUITO EMBRIONARIA MAS JA FUNCIONA
 */

#ifndef _STATION_H_
#define _STATION_H_

#include <list>

#include "Reading.h"
#include "../BaseCoordinates/Leafs/ENZ.h"

namespace IOPolly
{
  class Station
  {
  public:
    
    // construtor basico
    // eh alocada uma lista readings vazia
    Station();

    // construtor com preenchimento dos atributos
    // eh alocada uma lista readings vazia
    Station(std::string id, BaseCoordinates::Leaf::ENZ *from, double height, 
	    double az0);

    // construtor com preenchimento dos atributos
    // NAO eh alocada uma lista readings vazia
    Station(std::string id, BaseCoordinates::Leaf::ENZ *from, double height, 
	    double az0, std::list <Reading *> *readings);

    // destrutor
    ~Station();


    // *** METODOS ***

    //aloca e liberta memoria para a lista de readings
    inline void allocListReadings ();
    inline void freeListReadings ();


    //adiciona uma nova reading ah lista readings
    inline void addReading (Reading *p_newReading);

    // GET & SET //

    // id
    inline std::string getId();
    inline void setId(std::string newval);

    // from
    inline BaseCoordinates::Leaf::ENZ * getFrom() const;
    inline void setFrom(BaseCoordinates::Leaf::ENZ * newval);

    // height
    inline const double& getHeight() const;
    inline void setHeight(const double& newval);

    //az0
    inline const double& getAz0() const;
    inline void setAz0(const double& newval);

    //readings
    inline std::list <Reading *> * getReadings() const;
    inline void setReadings(std::list <Reading *> * newval);

  private:

    // atributos //

    std::string id; // identificador unico

    BaseCoordinates::Leaf::ENZ *from; //ponteiro para a estacao
 
    double height;

    double az0; // PT - Rumo 0

    std::list <Reading *> *readings;


  };

  inline void Station::allocListReadings ()
  {
    readings = new std::list <Reading *>();
  }

  inline void Station::freeListReadings ()
  {
    delete readings;
  }

  //GET & SET

  // id
  inline std::string Station::getId() 
  { return id; }
  
  inline void Station::setId(std::string newval)
  { id = newval; }

  // from
  inline BaseCoordinates::Leaf::ENZ * Station::getFrom() const 
  { return from; }
  
  inline void Station::setFrom(BaseCoordinates::Leaf::ENZ * newval) 
  { from = newval; }

  // height
  inline const double& Station::getHeight() const
  { return height; }

  inline void Station::setHeight(const double& newval)
  { height = newval; }
  
  //az0
  inline const double& Station::getAz0() const
  { return az0; }

  inline void Station::setAz0(const double& newval)
  { az0 = newval; }

  //Readings
  inline std::list <Reading *> * Station::getReadings() const
  { return readings; }

  inline void Station::setReadings(std::list <Reading *> * newval)
  { 
    freeListReadings (); // liberta a memoria
    readings = newval; 
  }

  //adiciona um novo reading a lista readings
  inline void Station::addReading (Reading *p_newReading)
  {
    readings->push_back(p_newReading);
  }

}

#endif // _STATION_H_
