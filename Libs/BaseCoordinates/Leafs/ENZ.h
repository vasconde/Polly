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

      double E();

      void E(double e);
      
      double N();

      void N(double n);

      double Z();

      void Z(double z);
      
      double Dev_E();

      void Dev_E(double devE);

      double Dev_N();

      void Dev_N(double devN);

      double Dev_Z();

      void Dev_Z(double devZ);

      double Vel_E();

      void Vel_E(double velE);

      double Vel_N();

      void Vel_N(double velN);

      double Vel_Z();

      void Vel_Z(double velZ);

      double Dev_VE();

      void Dev_VE(double dev_VE);

      double Dev_VN();

      void Dev_VN(double dev_VN);

      double Dev_VP();

      void Dev_VP(double dev_VP);

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
