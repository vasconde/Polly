/*
 * IOPolly - Implentacao
 * Classe especializada para entrada e saida
 * de dados
 */

#include "IOPolly.h"

// adiciona uma estacao ah lista obs

void IOPolly::addStation (std::string from, double height)
{
  struct station s;

  s.from = from;
  s.height = height;

  obs.push_back(s);
}

//adiciona uma leitura a uma estacao contida na lista obs

void IOPolly::addReading (std::string from, std::string to, double horizontal_dir,
			  double vertical_dir, double distance, double height)
{
  struct reading r = {to, horizontal_dir, vertical_dir, distance, height};

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
//e converte as observacoes angulares para radianos
//angle_unit_type - 1 - rad; 2 - degree; 3 - gon

void IOPolly::obsFromTextFile (std::string filePath, int angle_unit_type)
{
  // The input file
  std::ifstream data_file (filePath.c_str());

  // testa a abertura do ficheiro
  if (!data_file.is_open()) 
    {
      std::cerr << "Error: Could not open " << filePath << "\n";
      exit (8); //faz parte da cstdlib
    }

  std::string current_line; // alberga cada linha do ficheiro
  
  double horizontal_dir, vertical_dir; // alberga os valores angulares convertidos para rad
  SIUnits *ang_conv = new SIUnits(); // responsavel pelas conversoes

  while(!data_file.eof())
    {
      std::getline(data_file, current_line); // recolhe a linha
      
      if (!current_line.empty()) // se n leu uma linha em branco
	{

	  std::vector<std::string> elements;  // linha nos seus elementos
	  
	  // faz o split ah string para elements
	  std::istringstream iss(current_line);	  
	  std::copy(std::istream_iterator<std::string>(iss),
		    std::istream_iterator<std::string>(),
		    std::back_inserter<std::vector<std::string> >(elements));


	  if(elements.size() == 2)
	    {
	      //cria uma estacao
	      addStation(elements[0], std::atof(elements[1].c_str()));
	    }
	  else if(elements.size() == 5)
	    {
	      //cria um reading
	      
	      switch(angle_unit_type) // conversao dos angulos
		{
		case 1:
		  horizontal_dir = std::atof(elements[1].c_str()); 
		  vertical_dir = std::atof(elements[2].c_str());
		  break;
		case 2:
		  horizontal_dir = ang_conv->degree2rad (std::atof(elements[1].c_str())); 
		  vertical_dir = ang_conv->degree2rad (std::atof(elements[2].c_str()));
		  break;
		case 3:
		  horizontal_dir = ang_conv->gon2rad (std::atof(elements[1].c_str())); 
		  vertical_dir = ang_conv->gon2rad (std::atof(elements[2].c_str()));
		  break;
		}
	      
	      addReading((*(--obs.end())).from, elements[0], horizontal_dir, 
			 vertical_dir, std::atof(elements[3].c_str()),
			 std::atof(elements[4].c_str()));
	    
	      
	    }

	}       
    }

  delete ang_conv;

  data_file.close();
}
