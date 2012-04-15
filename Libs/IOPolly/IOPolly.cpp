/*
 * IOPolly - Implentacao
 * Classe especializada para entrada e saida
 * de dados
 */

#include "IOPolly.h"

void IOPolly::addStation (std::string from, double altura)
{
  struct station s;

  s.from = from;
  s.altura = altura;

  obs.push_back(s);
}

void IOPolly::addReading (std::string from, std::string to, double az,
			  double z, double dist, double altura)
{
  struct reading r = {to, az, z, dist, altura};

  std::list<struct station>::iterator i;
  for(i = obs.begin(); i != obs.end(); i++)
    {
      if(i->from == from)
	{
	  i->readings.push_back(r);
	  break;
	}
    }

}
