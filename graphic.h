#include "SDL/SDL.h"
#include "string"
using namespace std;
#ifndef BALL_H
#define BALL_H

class graphic{
	public:
		graphic();
		SDL_Surface *loadImage(string filename);
		void applySurface(int x, int y, int w, int h, SDL_Surface* src, SDL_Surface*dest, int offsetx, int offsety);
		~graphic();
};
#endif
