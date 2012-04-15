/*
 * IOPolly - Implentacao
 * Classe especializada para entrada e saida
 * de dados
 */

#include "IOPolly.h"

// adiciona uma estacao ah lista obs
void IOPolly::addStation (std::string from, double altura)
{
  struct station s;

  s.from = from;
  s.altura = altura;

  obs.push_back(s);
}

//adiciona uma leitura a uma estacao contida na lista obs
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

//remove um estacao da lista obs
void IOPolly::removeStation (std::string from)
{
  std::list<struct station>::iterator i;
  
  for(i = obs.begin(); i != obs.end(); i++)
    {
      if(i->from == from)
	{
	  obs.erase(i);
	  break;
	}
    }

}

//remove uma leitura da lista de uma estacao que esta lista obs
//ISSUE: pode haver mais do que uma observacao com o mesmo from e to
void IOPolly::removeReading (std::string from, std::string to)
{
  std::list<struct station>::iterator i;

  for(i = obs.begin(); i != obs.end(); i++)
    {
      if(i->from == from)
	{
	  std::list<struct reading>::iterator j;
	  
	  for(j = i->readings.begin(); j != i->readings.end(); j++)
	    {
	      if(j->to == to)
		{
		  i->readings.erase(j);
		  break;
		}
	    }
	  break;
	}
    }  
}

//carrega as observacoes a partir de um ficheiro de texto
void IOPolly::obsFromTextFile (std::string filePath)
{
  // The input file
  std::ifstream data_file (filePath.c_str());

  // testa a abertura do ficheiro
  if (!data_file.is_open()) 
    {
      std::cerr << "Error: Could not open " << filePath << "\n";
      exit (8); //faz parte da cstdlib
    }

  data_file.close();
}
