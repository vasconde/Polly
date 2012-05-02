#ifndef _ENZ_H_
#define _ENZ_H_

// C++ Standard Library //
#include <string>
#include <list>
#include <vector>

namespace BaseCoordinates{

  namespace Leaf{

    class ENZ{
    public:

      ENZ(double east, double north, double z, std::string id);
      
      ENZ(double east, double north, double z);

      ENZ();

      ~ENZ();

      std::string ID();
      
      void ID(std::string id);

      int E();

      void E(int e);
      
      int N();

      void N(int n);

      int Z();

      void Z(int z);
      
      int Dev_E();

      void Dev_E(int devE);

      int Dev_N();

      void Dev_N(int devN);

      int Dev_Z();

      void Dev_Z(int devZ);

      int Vel_E();

      void Vel_E(int velE);

      int Vel_N();

      void Vel_N(int velN);

      int Vel_Z();

      void Vel_Z(int velZ);

      int Dev_VE();

      void Dev_VE(int dev_VE);

      int Dev_VN();

      void Dev_VN(int dev_VN);

      int Dev_VP();

      void Dev_VP(int dev_VP);

      std::vector<std::string>* getInfoString();

      void setInfoString(std::vector<std::string>* infoString);

      std::vector<double>* getInfoDouble();

      void setInfoDouble(std::vector<double>* infoDouble);
      
      std::vector<int>* getInfoInt();

      void setInfoInt(std::vector<int>* infoInt);


    private:

      double m, p, h;

      double sig2_m, sig2_p, sig2_h;

      double vel_m, vel_p, vel_h;

      double sig2_Vm, sig2_Vp, sig2_Vh;

      std::vector<std::string>* infoString;

      std::vector<double>* infoDouble;

      std::vector<int>* infoInt;      

      std::string id;
    };
  }
}

#endif // _ENZ_H_
