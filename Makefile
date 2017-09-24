# Begin Makefile
main: 	
	g++ -o imager main.cpp -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 
