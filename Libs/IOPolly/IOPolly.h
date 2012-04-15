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

#include <string>
#include <list>

// ver union
struct reading
{
  std::string to;   //visada

  //union ver 12.2

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
  std::list<station> obs;

  void addStation (std::string from, double altura);

  void addReading (std::string from, std::string to, double az,
		   double z, double dist, double altura);
private:
   
};



#endif // _IOPOLLY_H_
