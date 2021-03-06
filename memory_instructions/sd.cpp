#include <stdio.h>

void sd (int rs1 , int rs2 , int * imm){

	//printf("check1\n");
	int imm64[64], memloc_addr[64];
	int byte_addr[3];
	int i = 0;
	for (i= 0; i < 12; ++i)
	{
		imm64[63-i] = imm[11-i];
	}
	i = 0;
	while(i < 52)
	{
		imm64[i] = imm[0];
		i++;
	}
	
	int immvalue = bin2dec(imm64);
	int rs1value = ubin2dec(Rreg[rs1]);
	uint64_t memlocation = immvalue + rs1value ;

	udec2binwr(memlocation, memloc_addr);
	std::cout << "SD TAKEN\n";

	for(i = 2; i >= 0; i--) 
	    byte_addr[i] = memloc_addr[i+61];

	for(i = 60; i >= 0; i--)
	    memloc_addr[i+3] = memloc_addr[i]; 

	for(i = 2; i >= 0; i--)
	    memloc_addr[i] = 0;

	uint64_t finalmemlocation = ubin2dec(memloc_addr);


	bool* currmem;
	currmem = Mem(finalmemlocation);
	std::cout << "FinalMemLoc : " << finalmemlocation << "\n";
	for(int m = 0 ; m < 64 ; ++m)
	{
	 std::cout << currmem[m];
	}
	std::cout << "\n";

	i=0;
	for (i= 0; i < 64; ++i)
	{
		currmem[63-i]=Rreg[rs2][63-i];
	}
	/*for (i= 0; i < 32; ++i)
	{
		printf("%d",currmem[31-i]);
	}*/

	fprintf(memout, "SD\t\t");
	fileprintmem(rs2, finalmemlocation, currmem);
}
