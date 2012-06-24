

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

// IOPolly libs
#include "../BaseCoordinates/Leafs/ENZ.h"
#include "../BaseCoordinates/Body/GeoCoord.h"
#include "Reading.h"
#include "Station.h"

// C++ libs
#include <string>
#include <list>
#include <vector>

// C libs
#include <cassert>

namespace IOPolly
{
  class Data
  {
  public:

    Data();
    ~Data();

    //metodos

    //aloca e liberta memoria para a lista de stations
    inline void allocListTrigPoints ();
    inline void freeListTrigPoints ();

    //aloca e liberta memoria para a lista de stations
    inline void allocListStations ();
    inline void freeListStations ();

    //adiciona um novo ponto ah lista TrigPoints
    //info define se eh um ponto fixo:
    //info -> 0 se Traverse Station; 1 se Control Station
    inline BaseCoordinates::Leaf::ENZ * newTrigPoint 
      (std::string name, double e, double n, double z, int info);

    //adiciona uma station ah lista stations
    inline void addStation (Station *p_newStation);

    //cria e adiciona uma nova station ah lista stations
    inline Station* newStation (std::string id, BaseCoordinates::Leaf::ENZ *p,
				double height, double az0);

    //cria e adiciona uma nova reading ah lista de readigs de uma sation
    inline void newReading (std::string id, Station *s, BaseCoordinates::Leaf::ENZ *p,
			    double h_dir, double v_dir, double dist, 
			    double height);

    //retorna a station com um determinado ENZ
    // VC - deveria retornar uma lista de Station *
    Station* searchENZ (BaseCoordinates::Leaf::ENZ *p);

    // GET & SET for DATA attributes //

    //TrigPoints
    inline BaseCoordinates::Body::GeoCoord * getTrigPoints() const;
    inline void setTrigPoints(BaseCoordinates::Body::GeoCoord * newval); 

    //stations
    inline std::list <Station *> * getStations() const;
    inline void setStations(std::list <Station *> * newval);

    // GET & SET for STATION and READINGS attributes //

    // retorna os elementos das listas em funcao da posicao
    Station* getStation (unsigned int pos);
    Reading* getReading (unsigned int sPos, unsigned int rPos);

    // retorna a dimensao das listas
    unsigned int sizeStations ();
    unsigned int sizeReadings (unsigned pos);

    // retorna o id das estacoes e dos readings
    std::string getId (unsigned int pos);
    void setId (unsigned int pos, std::string newId);

    std::string getId (unsigned int sPos, unsigned int rPos);
    void setId (unsigned int sPos, unsigned int rPos, std::string newId);

    // From and To
    BaseCoordinates::Leaf::ENZ * getFrom (unsigned int pos);
    void setFrom (unsigned int pos, BaseCoordinates::Leaf::ENZ * newFrom);
    
    BaseCoordinates::Leaf::ENZ * getTo (unsigned int sPos, unsigned int rPos);
    void setTo (unsigned int sPos, unsigned int rPos,
		BaseCoordinates::Leaf::ENZ * newTo);

    // Height
    const double getHeight (unsigned int pos);
    void setHeight (unsigned int pos, const double& newval);
    
    const double getHeight (unsigned int sPos, unsigned int rPos);
    void setHeight (unsigned int sPos, unsigned int rPos, const double& newval);

    // az0 - Station
    const double getAz0 (unsigned int pos);
    void setAz0 (unsigned int pos, const double& newval);

    // readings - Station
    std::list <Reading *> * getReadings(unsigned int pos);
    void setReadings(unsigned int pos, std::list <Reading *> * newval);

    // h_dir - Reading
    double getH_dir(unsigned int sPos, unsigned int rPos);
    void setH_dir(unsigned int sPos, unsigned int rPos,
		  const double& newval);

    // v_dir - Reading
    double getV_dir(unsigned int sPos, unsigned int rPos);
    void setV_dir(unsigned int sPos, unsigned int rPos,
		  const double& newval);

    // dist - Reading
    double getDist(unsigned int sPos, unsigned int rPos);
    void setDist(unsigned int sPos, unsigned int rPos,
		 const double& newval);

    // posicao dado o id
    unsigned int getPos(std::string id);

    std::vector<unsigned int> getPos(std::string sId, std::string rId);

  private:

    //lista de pontoa de coordenads conhecidas - Control Stations
    //getInfoInt[0] -> 0 se Traverse Station; 1 se Control Station
    BaseCoordinates::Body::GeoCoord *trigPoints;

    std::list<Station *> *stations;

  };
  
  // alocacao de memoria para a lista de TrigPoints
  inline void Data::allocListTrigPoints ()
  {
    trigPoints = new BaseCoordinates::Body::GeoCoord();
  }
  
  // libertacao de memoria para a lista de TrigPoints
  inline void Data::freeListTrigPoints ()
  {
    delete trigPoints;
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

  //adiciona um novo ponto ah lista TrigPoints
  //info define se eh um ponto fixo:
  //info -> 0 se Traverse Station; 1 se Control Station
  inline BaseCoordinates::Leaf::ENZ * Data::newTrigPoint 
    (std::string name, double e, double n, double z, int info)
  {
    BaseCoordinates::Leaf::ENZ *p = new BaseCoordinates::Leaf::ENZ(e, n, z, name);
    
    p->getInfoInt()->push_back(info); //caso de ser uma control station
    
    trigPoints->addEnzPoint(p);

    return p;
  }

  //adiciona um novo station a lista stations
  inline void Data::addStation (Station *p_newStation)
  {
    stations->push_back(p_newStation);
  }

  //cria e adiciona uma nova station ah lista stations
  inline Station* Data::newStation (std::string id, BaseCoordinates::Leaf::ENZ *p, 
				double height, double az0)
  {
    //criacao da estacao 1 e respectivas leituras
    Station *s = new IOPolly::Station(id, p, height, az0);
    //adiciona ah lista
    addStation (s);

    return s;
  }

  //cria e adiciona uma nova reading ah lista de readigs de uma sation
  inline void Data::newReading (std::string id, Station *s, BaseCoordinates::Leaf::ENZ *p,
				double h_dir, double v_dir, double dist, 
				double height)
  {
    //criacao da reading e respectivas leituras
    Reading *r = new Reading(id, p, h_dir , v_dir, dist, height);
    //adiciona ah lista    
    s->addReading(r);
  }
  
  // * GET & SET for DATA attributes //

  //Trigpoints
  inline BaseCoordinates::Body::GeoCoord * Data::getTrigPoints() const
  { return trigPoints; }

  inline void Data::setTrigPoints(BaseCoordinates::Body::GeoCoord * newval)
  { 
    freeListTrigPoints (); // liberta a memoria
    trigPoints = newval; 
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
