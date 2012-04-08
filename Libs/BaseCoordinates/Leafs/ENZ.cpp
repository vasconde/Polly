
#include "ENZ.hpp"

BaseCoordinates::Leaf::ENZ::ENZ(double east, double north, double z, int id){
        
  m = east;
  p = north;
  h = z;
  this->id = id;
  infoDouble = new std::list<double>();
  infoString = new std::list<std::string>();
  infoInt = new std::list<int>();
}

BaseCoordinates::Leaf::ENZ::ENZ(double east, double north, double z){
  
  m = east;
  p = north;
  h = z;
  id = -1;
  infoDouble = new std::list<double>();
  infoString = new std::list<std::string>();
  infoInt = new std::list<int>();
}

BaseCoordinates::Leaf::ENZ::ENZ(){
  
  infoDouble = new std::list<double>();
  infoString = new std::list<std::string>();
  infoInt = new std::list<int>();
}

BaseCoordinates::Leaf::ENZ::~ENZ(){
  delete infoDouble;
  delete infoInt;
  delete infoString;
}

int BaseCoordinates::Leaf::ENZ::ID() {return id;}
      
void BaseCoordinates::Leaf::ENZ::ID(int id) {this->id = id;}

int BaseCoordinates::Leaf::ENZ::E(){return m;}

void BaseCoordinates::Leaf::ENZ::E(int e) {m = e;}

int BaseCoordinates::Leaf::ENZ::N(){return p;}

void BaseCoordinates::Leaf::ENZ::N(int n) {p = n;}

int BaseCoordinates::Leaf::ENZ::Z(){return h;}

void BaseCoordinates::Leaf::ENZ::Z(int z) {h = z;}
      
int BaseCoordinates::Leaf::ENZ::Dev_E(){return sig_m;}

void BaseCoordinates::Leaf::ENZ::Dev_E(int devE) {sig_m = devE;}

int BaseCoordinates::Leaf::ENZ::Dev_N(){return sig_p;}

void BaseCoordinates::Leaf::ENZ::Dev_N(int devN) {sig_p = devN;}

int BaseCoordinates::Leaf::ENZ::Dev_Z(){return sig_h;}

void BaseCoordinates::Leaf::ENZ::Dev_Z(int devZ) {sig_h = devZ;}

int BaseCoordinates::Leaf::ENZ::Vel_E(){return vel_m;}

void BaseCoordinates::Leaf::ENZ::Vel_E(int velE) {vel_m = velE;}

int BaseCoordinates::Leaf::ENZ::Vel_N(){return vel_p;}

void BaseCoordinates::Leaf::ENZ::Vel_N(int velN) {vel_p = velN;}

int BaseCoordinates::Leaf::ENZ::Vel_Z(){return vel_h;}

void BaseCoordinates::Leaf::ENZ::Vel_Z(int velZ) {vel_h = velZ;}

int BaseCoordinates::Leaf::ENZ::Dev_VE(){return sig_Vm;}

void BaseCoordinates::Leaf::ENZ::Dev_VE(int dev_VE) {sig_Vm = dev_VE;}

int BaseCoordinates::Leaf::ENZ::Dev_VN(){return sig_Vp;}

void BaseCoordinates::Leaf::ENZ::Dev_VN(int dev_VN) {sig_Vp = dev_VN;}

int BaseCoordinates::Leaf::ENZ::Dev_VP(){return sig_Vh;}

void BaseCoordinates::Leaf::ENZ::Dev_VP(int dev_VP) {sig_Vh = dev_VP;}


std::list<std::string>* BaseCoordinates::Leaf::ENZ::getInfoString(){return infoString;}

void BaseCoordinates::Leaf::ENZ::setInfoString(std::list<std::string>* infoString) {this->infoString = infoString;}

std::list<double>* BaseCoordinates::Leaf::ENZ::getInfoDouble(){return infoDouble;}

void BaseCoordinates::Leaf::ENZ::setInfoDouble(std::list<double>* infoDouble) {this->infoDouble = infoDouble;}
      
std::list<int>* BaseCoordinates::Leaf::ENZ::getInfoInt(){return infoInt;}

void BaseCoordinates::Leaf::ENZ::setInfoInt(std::list<int>* infoInt) {this->infoInt = infoInt;}
