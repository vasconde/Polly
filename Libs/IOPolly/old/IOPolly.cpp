/*
 * IOPolly - Implentacao
 * Classe especializada para entrada e saida
 * de dados
 *
 * PROBLEMA: eh necessario descobrir como fazer o delete dos geocoords
 * sem entrar em falha de segmentacao
 */

#include "IOPolly.h"

// INICIO READING CLASS

reading::reading(BaseCoordinates::Leaf::ENZ *p_to, double horizontal_dir, 
		 double vertical_dir, double distance, double height)
{
  this->to = p_to;
  this->horizontal_dir = horizontal_dir; 
  this->vertical_dir = vertical_dir; 
  this->distance = distance; 
  this->height = height;
}
  
reading::reading()
{

}

reading::~reading()
{

}

// FIM READING CLASS

// INICIO STATION CLASS

station::station()
{
  readings = new std::list <reading *>();
}

station::~station()
{
  delete readings;
}

// FIM STATION CLASS

// INICIO IOPOLLY CLASS

//construtor IOPolly
IOPolly::IOPolly()
{
  new_TCStations ();
  new_obs ();
}

//destrutor IOPolly
IOPolly::~IOPolly()
{
  delete_TCStations ();
  delete_obs ();
}

// adiciona uma estacao ah lista obs

void IOPolly::addStation (BaseCoordinates::Leaf::ENZ *p_from, double height)
{
  station *s = new station();

  s->from = p_from;
  s->height = height;

  obs->push_back(s);
}

//adiciona uma leitura a uma estacao contida na lista obs

void IOPolly::addReading (BaseCoordinates::Leaf::ENZ *p_from, 
			  BaseCoordinates::Leaf::ENZ *p_to, double horizontal_dir,
			  double vertical_dir, double distance, double height)
{

  reading *r = 
    new reading (p_to, horizontal_dir, vertical_dir, distance, height);

  std::list<station *>::iterator i;
  for(i = obs->begin(); i != obs->end(); i++)
    {
      if(i->from == p_from)
	{
	  i->readings->push_back(r);
	  break;
	}
    }

}

//remove um estacao da lista obs
void IOPolly::removeStation (std::string from)
{
  BaseCoordinates::Leaf::ENZ *p_from = TCStations->getEnzPoint(from);

  std::list<station *>::iterator i;

  for(i = obs->begin(); i != obs->end(); i++)
    {
      if(i->from == p_from)
	{
	  obs->erase(i);
	  break;
	}
    }

}

//remove uma leitura da lista de uma estacao que esta lista obs
//ISSUE: pode haver mais do que uma observacao com o mesmo from e to
void IOPolly::removeReading (std::string from, std::string to)
{

  BaseCoordinates::Leaf::ENZ *p_from = TCStations->getEnzPoint(from);
  BaseCoordinates::Leaf::ENZ *p_to = TCStations->getEnzPoint(to);

  std::list<station>::iterator i;

  for(i = obs->begin(); i != obs->end(); i++)
    {
      if(i->from == p_from)
	{
	  std::list<reading>::iterator j;
	  
	  for(j = i->readings->begin(); j != i->readings->end(); j++)
	    {
	      if(j->to == p_to)
		{
		  i->readings->erase(j);
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
	      addStation(TCStations->getEnzPoint(elements[0]), 
			 std::atof(elements[1].c_str()));
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
	      
	      addReading((*(--(obs->end()))).from,
			 TCStations->getEnzPoint(elements[0]), horizontal_dir, 
			 vertical_dir, std::atof(elements[3].c_str()),
			 std::atof(elements[4].c_str()));
	    
	      
	    }

	}       
    }

  delete ang_conv;

  data_file.close();
}

void IOPolly::StationsFromTextFile (std::string filePathCStations, 
				    std::string filePathTStations, 
				    int aprox)
{
  // The input Control Stations file 
  std::ifstream CStations_file (filePathCStations.c_str());

  // testa a abertura do ficheiro
  if (!CStations_file.is_open()) 
    {
      std::cerr << "Error: Could not open " << filePathCStations << "\n";
      exit (8); //faz parte da cstdlib
    }

  // The input Traverse Stations file
  std::ifstream TStations_file (filePathTStations.c_str());
  
  // testa a abertura do ficheiro
  if (!TStations_file.is_open()) 
    {
      std::cerr << "Error: Could not open " << filePathTStations << "\n";
      exit (8); //faz parte da cstdlib
    }

  std::string name;
  double E, N, Z;
  
  while(!CStations_file.eof())
    {    
      // esta condicao eh para evitar a dupla leitura no final
      if(CStations_file >> name >> E >> N >> Z)
	{
	  
	  BaseCoordinates::Leaf::ENZ *point = 
	    new BaseCoordinates::Leaf::ENZ(E, N, Z, name);
	  
	  point->getInfoInt()->push_back(1); //caso de ser uma control station

	  TCStations->addEnzPoint(point);
	}
    }

  while(!TStations_file.eof())
    {    
      if(aprox)
	{
	  // esta condicao eh para evitar a dupla leitura no final
	  if(TStations_file >> name >> E >> N >> Z)
	    {

	  
	      BaseCoordinates::Leaf::ENZ *point = 
		new BaseCoordinates::Leaf::ENZ(E, N, Z, name);

	      point->getInfoInt()->push_back(0); //caso de ser uma traverse station

	      TCStations->addEnzPoint(point);
	    }
	}
      else
	{
	  // esta condicao eh para evitar a dupla leitura no final
	  if(TStations_file >> name)
	    {	      
	      BaseCoordinates::Leaf::ENZ *point = 
		new BaseCoordinates::Leaf::ENZ(0.0, 0.0, 0.0, name);

	      point->getInfoInt()->push_back(0); //caso de ser uma traverse station

	      TCStations->addEnzPoint(point);
	    }
	}

    }

  CStations_file.close();
  
  TStations_file.close();
}
