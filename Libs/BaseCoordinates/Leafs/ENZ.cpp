
#include "ENZ.h"

BaseCoordinates::Leaf::ENZ::ENZ(double east, double north, double z, std::string id){
        
  m = east;
  p = north;
  h = z;
  this->id = id;
  infoDouble = new std::vector<double>();
  infoString = new std::vector<std::string>();
  infoInt = new std::vector<int>();
}

BaseCoordinates::Leaf::ENZ::ENZ(double east, double north, double z){
  
  m = east;
  p = north;
  h = z;
  id = -1;
  infoDouble = new std::vector<double>();
  infoString = new std::vector<std::string>();
  infoInt = new std::vector<int>();
}

BaseCoordinates::Leaf::ENZ::ENZ(){
  
  infoDouble = new std::vector<double>();
  infoString = new std::vector<std::string>();
  infoInt = new std::vector<int>();
}

BaseCoordinates::Leaf::ENZ::~ENZ(){
  delete infoDouble;
  delete infoInt;
  delete infoString;
}

std::string BaseCoordinates::Leaf::ENZ::ID() {return id;}
      
void BaseCoordinates::Leaf::ENZ::ID(std::string id) {this->id = id;}

double BaseCoordinates::Leaf::ENZ::E(){return m;}

void BaseCoordinates::Leaf::ENZ::E(double e) {m = e;}

double BaseCoordinates::Leaf::ENZ::N(){return p;}

void BaseCoordinates::Leaf::ENZ::N(double n) {p = n;}

double BaseCoordinates::Leaf::ENZ::Z(){return h;}

void BaseCoordinates::Leaf::ENZ::Z(double z) {h = z;}
      
double BaseCoordinates::Leaf::ENZ::Dev_E(){return sig2_m;}

void BaseCoordinates::Leaf::ENZ::Dev_E(double devE) {sig2_m = devE;}

double BaseCoordinates::Leaf::ENZ::Dev_N(){return sig2_p;}

void BaseCoordinates::Leaf::ENZ::Dev_N(double devN) {sig2_p = devN;}

double BaseCoordinates::Leaf::ENZ::Dev_Z(){return sig2_h;}

void BaseCoordinates::Leaf::ENZ::Dev_Z(double devZ) {sig2_h = devZ;}

double BaseCoordinates::Leaf::ENZ::Vel_E(){return vel_m;}

void BaseCoordinates::Leaf::ENZ::Vel_E(double velE) {vel_m = velE;}

double BaseCoordinates::Leaf::ENZ::Vel_N(){return vel_p;}

void BaseCoordinates::Leaf::ENZ::Vel_N(double velN) {vel_p = velN;}

double BaseCoordinates::Leaf::ENZ::Vel_Z(){return vel_h;}

void BaseCoordinates::Leaf::ENZ::Vel_Z(double velZ) {vel_h = velZ;}

double BaseCoordinates::Leaf::ENZ::Dev_VE(){return sig2_Vm;}

void BaseCoordinates::Leaf::ENZ::Dev_VE(double dev_VE) {sig2_Vm = dev_VE;}

double BaseCoordinates::Leaf::ENZ::Dev_VN(){return sig2_Vp;}

void BaseCoordinates::Leaf::ENZ::Dev_VN(double dev_VN) {sig2_Vp = dev_VN;}

double BaseCoordinates::Leaf::ENZ::Dev_VP(){return sig2_Vh;}

void BaseCoordinates::Leaf::ENZ::Dev_VP(double dev_VP) {sig2_Vh = dev_VP;}


//lista strings com informação genérica
std::vector<std::string>* BaseCoordinates::Leaf::ENZ::getInfoString(){return infoString;}
void BaseCoordinates::Leaf::ENZ::setInfoString(std::vector<std::string>* infoString) {this->infoString = infoString;}

//lista de doubles com informação genérica
std::vector<double>* BaseCoordinates::Leaf::ENZ::getInfoDouble(){return infoDouble;}
void BaseCoordinates::Leaf::ENZ::setInfoDouble(std::vector<double>* infoDouble) {this->infoDouble = infoDouble;}
      
//lista de inteiros com infromação genérica
std::vector<int>* BaseCoordinates::Leaf::ENZ::getInfoInt(){return infoInt;}
void BaseCoordinates::Leaf::ENZ::setInfoInt(std::vector<int>* infoInt) {this->infoInt = infoInt;}
