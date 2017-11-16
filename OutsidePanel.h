#pragma once
#include <SDL.h>
#include "ClockDisplay.h"
#include "DialogueFeed.h"

class OutsidePanel
{
public:
	OutsidePanel(SDL_Renderer *renderTarget, int passed_screenWidth, int passed_screenHeight, int passed_activePlayer);
	~OutsidePanel();
	void Update(SDL_Renderer *renderTarget, int passed_activeplayer);

	SDL_Rect positionRect;

private:
	
	int activePlayer;
	int screenHeight;
	int screenWidth;

	SDL_Rect cropRect;

	ClockDisplay* clock;
	DialogueFeed* feed;

	SDL_Texture *texture1;
	SDL_Texture *texture2;
	SDL_Texture *texture3;

	SDL_Texture *textOptions;
	SDL_Texture *textEditTeam;
	SDL_Texture *textBag;
	SDL_Texture *textPedia;
	SDL_Texture *textSave;
	SDL_Texture *textQuit;

	SDL_Texture *textAChar1;
	SDL_Texture *textAChar2;
	SDL_Texture *textAChar3;
};

