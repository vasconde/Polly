/*
 * IOPolly
 * Classe especializada para entrada e saida
 * de dados
 *
 * FASE DE CRIACAO DA ESTRUTURA DE DADOS
 * AINDA MUITO EMBRIONARIA MAS JA FUNCIONA
 */

#ifndef _READING_H_
#define _READING_H_

#include "../BaseCoordinates/Leafs/ENZ.h"

namespace IOPolly
{
  class Reading
  {
  public:

    //construtores

    Reading(BaseCoordinates::Leaf::ENZ *p_to, double h_dir, 
	    double v_dir, double dist, double height);

    Reading();

    //destrutor
    ~Reading();

    //metodos//

    inline BaseCoordinates::Leaf::ENZ * getTo() const;
    inline void setTo(BaseCoordinates::Leaf::ENZ * newval);

    inline const double& getH_dir() const;
    inline void setH_dir(const double& newval);

    inline const double& getV_dir() const;
    inline void setV_dir(const double& newval);

    inline const double& getDist() const;
    inline void setDist(const double& newval);

    inline const double& getHeight() const;
    inline void setHeight(const double& newval);

  private:
        
    //atributos//

    BaseCoordinates::Leaf::ENZ *to;   //ponteiro para a visada
  
    double h_dir;  //observacao azimutal
    double v_dir;    //observacao zenital
    double dist;        //distancia

    double height; // tripod height

  };

  inline BaseCoordinates::Leaf::ENZ * Reading::getTo() const { return to; };
  inline void Reading::setTo(BaseCoordinates::Leaf::ENZ * newval) { to = newval; };

  inline const double& Reading::getH_dir() const { return h_dir; }		
  inline void Reading::setH_dir(const double& newval) { h_dir = newval; }

  inline const double& Reading::getV_dir() const { return v_dir; }		
  inline void Reading::setV_dir(const double& newval) { v_dir = newval; }

  inline const double& Reading::getDist() const { return dist; }		
  inline void Reading::setDist(const double& newval) { dist = newval; }

  inline const double& Reading::getHeight() const { return height; }		
  inline void Reading::setHeight(const double& newval) { height = newval; }
}

#endif // _READING_H_