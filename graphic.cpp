#include "graphic.h"

graphic::graphic(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
	SDL_WM_SetCaption("Pong", NULL);
}

SDL_Surface* graphic::loadImage(string filename){
	SDL_Surface* old=SDL_LoadBMP(filename.c_str());
	SDL_Surface* opt=SDL_DisplayFormat(old); 
	SDL_FreeSurface(old);
	return opt;
}

void graphic::applySurface(int x, int y, int w, int h, SDL_Surface* src, SDL_Surface*dest, int offsetx, int offsety){
	SDL_Rect offset;
	SDL_Rect clip;
	offset.x=offsetx;
	offset.y=offsety;
	clip.x=x;
	clip.y=y;
	clip.w=w;
	clip.h=h;
	SDL_BlitSurface(src, &clip, dest, &offset);
}

graphic::~graphic(){
//	SDL_FreeSurface();
	SDL_Quit();
}
