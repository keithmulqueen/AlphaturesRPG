#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

class DialogueFeed
{
public:
	DialogueFeed(SDL_Renderer *renderTarget, int pass_screenWidth, int pass_screenHeight);
	~DialogueFeed();

	void Draw(SDL_Renderer *renderTarget);


	SDL_Rect cropRect2;

private:

	TTF_Font* DialogueFont;
	SDL_Color DialogueColor;

	SDL_Rect DialogueRect;

	SDL_Surface* DialogueMessage;
	SDL_Texture* DialogueTexture;
	SDL_Rect thisCrop;

	int screenHeight;
	int screenWidth;
};
