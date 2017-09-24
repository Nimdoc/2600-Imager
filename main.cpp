#include "CImg.h"
#include <fstream>

using namespace cimg_library;

int main() 
{
	CImg<unsigned char> img(256, 128, 1, 3);
	img.fill(32);
	
	const unsigned char white[] = {255, 255, 255};
	const unsigned char black[] = {0, 0, 0};

	int bit_count = 0;

	//The amount of bits in 4096 bytes
	//And 4096 bytes is how much is in an atari 2600 cartridge
	const int bits = 32768;

	std::ifstream file("game.bin", std::ios::binary | std::ios::in);

	char c;

	int bit = 0;

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

	
	file.close();
	img.save("image.bmp");	

	return 0;
}
