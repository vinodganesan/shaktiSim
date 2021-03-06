#include <stdio.h>

void sh (int rs1 , int rs2 , int * imm){

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
	std::cout << "SH TAKEN\n";

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
	int j = (4*byte_addr[0] + 2*byte_addr[1])*8; 

	i=0;
	for (i= 0; i < 16; ++i)
	{
		currmem[63-j-i]=Rreg[rs2][63-i];
	}

	fprintf(memout, "SH\t\t");
	fileprintmem(rs2, finalmemlocation, currmem);
}
