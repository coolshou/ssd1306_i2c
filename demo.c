/******
Demo for ssd1306 i2c driver for  Raspberry Pi
******/
#include "demo.h"
#include "ssd1306_i2c.h"

#define EXIT_SUCCESS 0
/* ======================================================================
Function: usage
Purpose : display usage
Input 	: program name
Output	: -
Comments:
====================================================================== */
void usage( char * name)
{
	printf("%s\n", name );
	printf("Options are:\n");
	printf("  -c clear dieplay\n");
	printf("  -t <text> text to dieplay\n");
	printf("  -h this help\n");
}


int main(int argc, char *argv[]) {

	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
	// TODO: specify font size on command argment
	ssd1306_setTextSize(4);

    for (int i = 1; i < argc; i++) {

		if(strcmp(argv[i], "-h")==0) {
			usage(argv[0]);
			exit(EXIT_SUCCESS);
		}
		if(strcmp(argv[i], "-c")==0) {
			ssd1306_clearDisplay();
			ssd1306_display();
			exit(EXIT_SUCCESS);
		}
		if(strcmp(argv[i], "-t")==0) {
			char* text;
			if((i + 1) < argc) {
				//myDisplay.textDisplay(argv[i+1]);
				text = argv[i+1];
				i++;
			}
			printf("%s\n",text);
			ssd1306_clearDisplay();
			ssd1306_drawString(text);
			ssd1306_display();
		}
    }
/*
	ssd1306_display(); //Adafruit logo is visible
	ssd1306_clearDisplay();
	sleep(3);

	char* text = "This is demo for SSD1306 i2c driver for Raspberry Pi";
	ssd1306_drawString(text);
	ssd1306_display();
	delay(5000);

	ssd1306_dim(1);
	ssd1306_startscrollright(00,0xFF);
	delay(5000);

	ssd1306_clearDisplay();
	ssd1306_fillRect(10,10, 50, 20, WHITE);
	ssd1306_fillRect(80, 10, 130, 50, WHITE);
	ssd1306_display();
	* */
}
