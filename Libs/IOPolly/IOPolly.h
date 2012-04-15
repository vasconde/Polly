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

#include <cstdlib>

// ver union
struct reading
{
  std::string to;   //visada

  double az;   //observacao azimutal
  double z;    //observacao zenital
  double dist; //distancia

  double altura;
};

struct station
{
  std::string from;
  
  double altura;

  std::list <struct reading> readings;
};


class IOPolly
{
public:
  // lista com os estacionamentos que por sua vez
  // teem um lista com as leituras
  std::list<station> obs;

  // adiciona uma estacao ah lista obs
  void addStation (std::string from, double altura);

  //adiciona uma leitura a uma estacao contida na lista obs
  void addReading (std::string from, std::string to, double az,
		   double z, double dist, double altura);
 
  //remove um estacao da lista obs
  void removeStation (std::string from);

  //remove uma leitura da lista de uma estacao que esta lista obs
  void removeReading (std::string from, std::string to);

  //carrega as observacoes a partir de um ficheiro de texto
  void obsFromTextFile (std::string filePath);

private:
   
};



#endif // _IOPOLLY_H_
