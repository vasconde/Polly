
#include "Reading.h"

// Construtor
IOPolly::Reading::Reading(std::string id, BaseCoordinates::Leaf::ENZ *p_to, 
			  double h_dir, double v_dir, double dist, double height)
{
  this->id = id;
  this->to = p_to;
  this->h_dir = h_dir; 
  this->v_dir = v_dir; 
  this->dist = dist; 
  this->height = height;
  this->marker = false;
}

IOPolly::Reading::Reading()
{
  this->marker = false;
}

// Destrutor
IOPolly::Reading::~Reading()
{

}
