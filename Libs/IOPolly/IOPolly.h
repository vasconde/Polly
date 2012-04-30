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

// ver union
struct reading
{
  std::string to;   //nome da visada
  
  double horizontal_dir;  //observacao azimutal
  double vertical_dir;    //observacao zenital
  double distance;        //distancia

  double height; // tripod height
};

struct station
{

  std::string from; //nome da estacao
 
  double height;

  std::list <struct reading> readings;

};


class IOPolly
{
public:
  // lista com os estacionamentos que por sua vez
  // teem um lista com as leituras
  std::list<station> obs;

  // adiciona uma estacao ah lista obs
  void addStation (std::string from, double height);

  //adiciona uma leitura a uma estacao contida na lista obs
  void addReading (std::string from, std::string to, double horizontal_dir, 
		   double vertical_dir, double distance, double height);

  //remove um estacao da lista obs
  void removeStation (std::string from);

  //remove uma leitura da lista de uma estacao que esta lista obs
  void removeReading (std::string from, std::string to);

  //carrega as observacoes a partir de um ficheiro de texto
  //angle_unit_type - 1 - rad; 2 - degree; 3 - gon
  void obsFromTextFile (std::string filePath, int angle_unit_type);

private:
   
};



#endif // _IOPOLLY_H_
