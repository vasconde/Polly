#include <iostream>


#define WANT_STREAM                  // include.h will get stream fns
#define WANT_MATH                    // include.h will get math fns
                                     // newmatap.h will get include.h

#include "AjustLS.h"

#include "../../../newmat10/newmat.h"

#include "../../../newmat10/newmatap.h"                // need matrix applications

#include "../../../newmat10/newmatio.h"                // need matrix output routines

//#ifdef use_namespace
//using namespace NEWMAT;              // access NEWMAT namespace
//#endif

int main ()
{

  NEWMAT::Matrix A(5,5);
  NEWMAT::Matrix B(5,5);

  
  for (int i = 1; i <= 5; i++)
    {
      for(int j = 1; j <= 5; j++)
	{
	  A(i,j) = i*j;
	  B(i,j) = i*j;
	}
    } 

  NEWMAT::Matrix C = A * B;

  std::cout << A << std::endl;

  std::cout << C;

  //  std::cout << std::setw(10) << std::setprecision(5) << A;

  return 0;
}
