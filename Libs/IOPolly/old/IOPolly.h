/*
 * IOPolly
 * Classe especializada para entrada e saida
 * de dados
 *
 * FASE DE CRIACAO DA ESTRUTURA DE DADOS
 * AINDA MUITO EMBRIONARIA MAS JA FUNCIONA
 */

#ifndef _IOPOLLY_H_
#define _IOPOLLY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include <cstdlib>

#include "../SIUnits/SIUnits.h"
#include "../BaseCoordinates/Body/GeoCoord.h"
#include "../BaseCoordinates/Leafs/ENZ.h"

// ver union
class reading
{
 public:

  //construtores

  reading(BaseCoordinates::Leaf::ENZ *p_to, double horizontal_dir, 
	  double vertical_dir, double distance, double height);

  reading();

  //destrutor
  ~reading();

  BaseCoordinates::Leaf::ENZ *to;   //ponteiro para a visada
  
  double horizontal_dir;  //observacao azimutal
  double vertical_dir;    //observacao zenital
  double distance;        //distancia

  double height; // tripod height

 private:

};

class station
{
 public:

  //construtor e destrutor
  station();
  ~station();

  BaseCoordinates::Leaf::ENZ *from; //ponteiro para a estacao
 
  double height;

  double azimuth0; // PT - Rumo 0

  std::list <reading *> *readings;

 private:

};


class IOPolly
{
public:

  // lista com os estacionamentos que por sua vez
  // teem um lista com as leituras
  std::list<station *> *obs;

  //lista de estacoes de coordenads conhecidas - Control Stations
  //getInfoInt[0] -> 0 se Traverse Station; 1 se Control Station
  BaseCoordinates::Body::GeoCoord *TCStations;

  //construtor IOPolly
  IOPolly();

  //destrutor IOPolly
  ~IOPolly();

  //aloca memoria para o TCStations
  void new_TCStations ();

  //liberta memoria para o TCStations
  void delete_TCStations ();

  //aloca memoria para a lista de obs
  void new_obs ();

  //liberta memoria para a lista de obs
  void delete_obs ();

  // adiciona uma estacao ah lista obs
  void addStation (BaseCoordinates::Leaf::ENZ *p_from, double height);

  //adiciona uma leitura a uma estacao contida na lista obs
  void addReading (BaseCoordinates::Leaf::ENZ *p_from, 
		   BaseCoordinates::Leaf::ENZ *p_to, double horizontal_dir,
		   double vertical_dir, double distance, double height);

  //remove um estacao da lista obs
  void removeStation (std::string from);

  //remove uma leitura da lista de uma estacao que esta lista obs
  void removeReading (std::string from, std::string to);

  //carrega as coordenadas das estacoes a partir de um ficheiro de texto
  //aprox = 0 se as Traverse Stations nao tiverem coordenadas aproximadas
  //aprox = 1 caso contrario
  void StationsFromTextFile (std::string filePathCStations, 
			     std::string filePathTStations, 
			     int aprox);

  //carrega as observacoes a partir de um ficheiro de texto
  //angle_unit_type - 1 - rad; 2 - degree; 3 - gon
  void obsFromTextFile (std::string filePath, int angle_unit_type);

private:
  
  
};

// alocacao de memoria para a lista de estacoes
inline void IOPolly::new_TCStations ()
{
  TCStations = new BaseCoordinates::Body::GeoCoord();
}

// libertacao de memoria para a lista de estacoes
inline void IOPolly::delete_TCStations ()
{
  delete TCStations;
}

//aloca memoria para a lista de obs
inline void IOPolly::new_obs ()
{
  obs = new std::list<station *>();
}

//liberta memoria para a lista de obs
inline void IOPolly::delete_obs ()
{
  delete obs;
}

#endif // _IOPOLLY_H_
