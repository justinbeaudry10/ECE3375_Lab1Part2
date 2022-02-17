#include "address_map_arm.h"
/* Your first program*/

volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE; // Switch address


void DisplayHex(int value)
{
	
	char lookUpTable[16];
	lookUpTable[0] = 0x3F;
	lookUpTable[1] = 0x06;
	lookUpTable[2] = 0x5B;
	lookUpTable[3] = 0x4F;
	lookUpTable[4] = 0x66;
	lookUpTable[5] = 0x6D;
	lookUpTable[6] = 0x7D;
	lookUpTable[7] = 0x07;
	lookUpTable[8] = 0x7F;
	lookUpTable[9] = 0x67;
	lookUpTable[10] = 0x77;
	lookUpTable[11] = 0x7C;
	lookUpTable[12] = 0x39;
	lookUpTable[12] = 0x5E;
	lookUpTable[14] = 0x79;
	lookUpTable[15] = 0x71;
	
	*HEX_ptr = lookUpTable[value];
	
}

int ReadSwitches(void)
{
	volatile int * SW_ptr = (int *)SW_BASE; // Switch address
	return(*(SW_ptr));
	
}
	
int main(void) {
	
	volatile int DELAY_LENGTH = 700000;
	volatile int status = 0;
	volatile int delay_count;
	
    while (1) 
	{
		if (status == 0)
		{
			status = 1;
			*(HEX_ptr) = 0x00;
		}
		else
		{
			status = 0;
			int switchPosition = ReadSwitches();
			DisplayHex(switchPosition);
		}

        for (delay_count = DELAY_LENGTH; delay_count != 0; --delay_count)
            ; // delay loop
    }
}
