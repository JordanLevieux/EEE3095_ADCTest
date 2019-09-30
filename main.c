#include <main.h>

int setup_gpio(void)
{
	printf("setting up...");
    //Set up wiring Pi
    wiringPiSetup();
    //setting up the buttons
	if(wiringPiSPISetup(SPI_CHAN, SPI_SPEED) == -1)
	{
		printf("YO YO YO it is broken");
	}
	printf("Ya ya setup it is finished\n");
    return 0;
}

int readADC()
{
	unsigned char buffer[3];
	buffer[0] = 1;
	buffer[1] = 0b10000000;//read from chan0
	wiringPiSPIDataRW(SPI_CHAN, buffer, 3);
	return((buffer[1]&2)<<8)+buffer[2];
}

int main()
{
	if(setup_gpio()==-1){
		printf("Yoo shem it is broken");
        return 0;
    int output = readADC();
    printf("Output: %d", output);
	return 0;
}
