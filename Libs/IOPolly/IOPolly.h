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

  std::string to;   //nome da visada
  
  double horizontal_dir;  //observacao azimutal
  double vertical_dir;    //observacao zenital
  double distance;        //distancia

  double height; // tripod height


  //construtores

  reading(std::string to, double horizontal_dir, 
	  double vertical_dir, double distance, double height);
  reading();

 private:

};

class station
{
 public:

  std::string from; //nome da estacao
 
  double height;

  std::list <struct reading> readings;

  station(); // construtor

 private:

};


class IOPolly
{
public:

  // lista com os estacionamentos que por sua vez
  // teem um lista com as leituras
  std::list<station> obs;

  //lista de estacoes de coordenads conhecidas - Control Stations
  //getInfoInt[0] -> 0 se Traverse Station; 1 se Control Station
  BaseCoordinates::Body::GeoCoord *TCStations;

  //construtor IOPolly
  IOPolly();

  //destrutor IOPolly
  ~IOPolly();

  // adiciona uma estacao ah lista obs
  void addStation (std::string from, double height);

  //adiciona uma leitura a uma estacao contida na lista obs
  void addReading (std::string from, std::string to, double horizontal_dir, 
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



#endif // _IOPOLLY_H_
