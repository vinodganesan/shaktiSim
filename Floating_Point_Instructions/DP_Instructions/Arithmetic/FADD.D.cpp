#include <stdio.h>
#include <sstream>
#include <iostream>

//int Freg[3][64] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

void faddd(int rd, int rs1 , int rs2, std::string rm)
{
  std::stringstream out1,out2,out3;
   for(int i=0;i<64;++i)
	{
	out1 << Freg[rs1][i];
	out2 << Freg[rs2][i];
	}
   std::string operand1(out1.str());
   std::string operand2(out2.str());
   double a1 = GetFloat64(operand1);
   double a2 = GetFloat64(operand2);
   getrounding(rm);
   double a3 = a1 + a2 ; 
   std::cout << a3;
   std::string operand3 = GetBinary64(a3);
	std::cout << operand3 << std::endl;
	for(int i = 0 ; i < 64 ; ++i)
	  Freg[rd][i] = operand3[i]-48;
	for(int i = 0 ; i < 64; ++i)
	  std:: cout << Freg[rd][i] ;
    	
}


/*int main()
{
int rd = 0, rs1 = 1, rs2 = 2;
FADDS(rd,rs1,rs2,3);
return 0;
} */

