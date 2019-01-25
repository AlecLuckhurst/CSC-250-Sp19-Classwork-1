/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
// #include directive finds the name file and "includes" all the text file
// right at this location in your program, BEFORE the compiler actual builds the program
// commands starting with # are called "preprocessor compiler directives"
#include "gfx2.h"
// angle brackets around an include filename mean it is provided by the system
// the compiler "should" know where to find
// filenamne in quotes (with no path) just means a file in the current directory or folder


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

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.
	gfx_line(100,100,200,100);
	gfx_line(200,100,150,150);
	gfx_line(150,150,100,100);

	gfx_color(0,0,200);
	drawSquare(150, 150, 32);
	drawSquare(145, 150, 32);
	drawSquare(140, 150, 32);

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
