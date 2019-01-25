#include <stdio.h>
#include "gfx2.h"


void drawSquare(double xCenter, double yCenter, double side)
{
	// calculate x, y coordinates of all corners... ulx means upper left x.. etc.
	double ulx = xCenter - side/2;
	double uly = yCenter - side/2;
	double llx = xCenter - side/2;
	double lly = yCenter + side/2;
	double urx = xCenter + side/2;
	double ury = yCenter - side/2;
	double lrx = xCenter + side/2;
	double lry = yCenter + side/2;
	
	gfx_line(ulx, uly, llx, lly);
	gfx_line(llx, lly, lrx, lry);
	gfx_line(lrx, lry, urx, ury);
	gfx_line(urx, ury, ulx, uly);

}


int main()
{
	int ysize = 300;
	int xsize = 300;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	//Change color to blue and create three new sized squares
	gfx_color(0,0,200);
	drawSquare(150, 150, 32);
	drawSquare(145, 150, 32);
	drawSquare(140, 150, 32);
	drawSquare(145, 100, 32);
	drawSquare(145, 200, 32);
	drawSquare(195, 150, 32);
	drawSquare(95, 150, 32);

	
	//Change color to red and create four new sized squares in all four corners of the program
	gfx_color(200, 0, 0);
	drawSquare(262, 262, 75);
	drawSquare(39, 39, 75);
	drawSquare(262, 39, 75);
	drawSquare(39, 262, 75);


	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
