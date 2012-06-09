
#include "Reading.h"

// Construtor
IOPolly::Reading::Reading(BaseCoordinates::Leaf::ENZ *p_to, 
			  double h_dir, 
			  double v_dir, double dist, double height)
{
  this->to = p_to;
  this->h_dir = h_dir; 
  this->v_dir = v_dir; 
  this->dist = dist; 
  this->height = height;
}

IOPolly::Reading::Reading()
{

}

// Destrutor
IOPolly::Reading::~Reading()
{

}
