#include "CImg.h"
#include <fstream>
#include <iostream>

using namespace cimg_library;

int main(int argc, char *argv[]) 
{
	// Variable section

	CImg<unsigned char> image(256, 128, 1, 3);
	
	const unsigned char white[] = {255, 255, 255};
	const unsigned char black[] = {0, 0, 0};

	std::ifstream file;

	char c;

	int bit = 0;

	// Fill image with black	
	image.fill(32);

	// Check to see if argument has been passed
	// Open the file specfied by users argument	
	if(argc > 1)
		file.open(argv[1], std::ios::binary | std::ios::in);

	// Check to make sure there was an argument and that the file is open.
	// Starting from the bottom right corner the x and y loop will go through
	// in 8 pixel chunks. The z loop will iterate through those 8 pixel chunks
	// and draw white for bits that are 1.
	if(argc > 1 && file.is_open())
		for(int x = 255; x > 0; x -= 8)
		{
			for(int y = 127; y >= 0; y--)
			{
				// Get the next byte in the file
				file.get(c);
				for(int z = 7; z >=0; z--)
				{
					// Bitshift the byte and & the byte to get 
					// the current bit
					int bit = ((c >> z) & 1);

					// If the bit is 1 then draw white at our 
					// current location
					if(bit)
						image.draw_point((x - z), y, white);

				}
			}
		}
	else // Too few arguments or file is unable to be opened
	{
		if(argc < 2)
			std::cout << "Correct usage: imager filename.bin\n";
		else	
			std::cout << "File unable to be opened.\n";
	}

	// Close the file	
	file.close();
	// Output the image
	image.save("output.bmp");	

	return 0;
}
