#include "CImg.h"
#include <fstream>
#include <iostream>

using namespace cimg_library;

int main(int argc, char *argv[]) 
{
	CImg<unsigned char> img(256, 128, 1, 3);
	img.fill(32);
	
	const unsigned char white[] = {255, 255, 255};
	const unsigned char black[] = {0, 0, 0};

	std::ifstream file;
	
	if(argc > 1)
		file.open(argv[1], std::ios::binary | std::ios::in);

	char c;

	int bit = 0;

	if(argc > 1 && file.is_open())
		for(int x = 255; x > 0; x -= 8)
		{
			for(int y = 127; y >= 0; y--)
			{
				file.get(c);
				for(int z = 7; z >=0; z--)
				{
					int bit = ((c >> z) & 1);

					if(bit)
						img.draw_point((x - z), y, white);

				}
			}
		}
	else
	{
		if(argc < 2)
			std::cout << "Correct usage: imager filename.bin\n";
		else	
			std::cout << "File unable to be opened.\n";
	}
	
	file.close();
	img.save("image.bmp");	

	return 0;
}
