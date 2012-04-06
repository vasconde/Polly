#include<string>
#include<list>
namespace BaseCoordinates{

  namespace Leaf{

    class ENZ{
    public:

      ENZ(double east, double north, double z, int id){
        
            m = east;
            p = north;
            h = z;
            this->id = id;
            infoDouble = new std::list<double>();
	    infoString = new std::list<std::string>();
	    infoInt = new std::list<int>();
        }
      
      ENZ(double east, double north, double z){
        
            m = east;
            p = north;
            h = z;
            id = -1;
            infoDouble = new std::list<double>();
	    infoString = new std::list<std::string>();
	    infoInt = new std::list<int>();
      }

      ENZ(){

	infoDouble = new std::list<double>();
	infoString = new std::list<std::string>();
	infoInt = new std::list<int>();
      }

      ~ENZ(){
	delete infoDouble;
	delete infoInt;
	delete infoString;
      }

      int ID() {return id;}
      void ID(int id) {this->id = id;}

      int E(){return m;}
      void E(int e) {m = e;}
      int N(){return p;}
      void N(int n) {p = n;}
      int Z(){return h;}
      void Z(int z) {h = z;}
      
      int Dev_E(){return sig_m;}
      void Dev_E(int devE) {sig_m = devE;}
      int Dev_N(){return sig_p;}
      void Dev_N(int devN) {sig_p = devN;}
      int Dev_Z(){return sig_h;}
      void Dev_Z(int devZ) {sig_h = devZ;}

      int Vel_E(){return vel_m;}
      void Vel_E(int velE) {vel_m = velE;}
      int Vel_N(){return vel_p;}
      void Vel_N(int velN) {vel_p = velN;}
      int Vel_Z(){return vel_h;}
      void Vel_Z(int velZ) {vel_h = velZ;}

      int Dev_VE(){return sig_Vm;}
      void Dev_VE(int dev_VE) {sig_Vm = dev_VE;}
      int Dev_VN(){return sig_Vp;}
      void Dev_VN(int dev_VN) {sig_Vp = dev_VN;}
      int Dev_VP(){return sig_Vh;}
      void Dev_VP(int dev_VP) {sig_Vh = dev_VP;}

      std::list<std::string>* getInfoString(){return infoString;}
      void setInfoString(std::list<std::string>* infoString) {this->infoString = infoString;}

      std::list<double>* getInfoDouble(){return infoDouble;}
      void setInfoDouble(std::list<double>* infoDouble) {this->infoDouble = infoDouble;}
      
      std::list<int>* getInfoInt(){return infoInt;}
      void setInfoInt(std::list<int>* infoInt) {this->infoInt = infoInt;}


    private:
      double m, p, h;
      double sig_m, sig_p, sig_h;
      double vel_m, vel_p, vel_h;
      double sig_Vm, sig_Vp, sig_Vh;
      std::list<std::string>* infoString;
      std::list<double>* infoDouble;
      std::list<int>* infoInt;      
      int id;
    };
  }
}






