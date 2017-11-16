#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

class ClockDisplay
{
public:
	ClockDisplay(SDL_Renderer *renderTarget, int pass_screenWidth, int pass_screenHeight);
	~ClockDisplay();

	void Draw(SDL_Renderer *renderTarget);


	SDL_Rect cropRect2;

private:

	TTF_Font* ClockDisplayFont;
	SDL_Color ClockDisplayColor;

	SDL_Rect ClockDisplayRect;
	
	SDL_Surface* ClockMessage;
	SDL_Texture* ClockTexture;
	SDL_Rect thisCrop;

	int screenHeight;
	int screenWidth;
};

