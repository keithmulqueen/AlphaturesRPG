#include "stdafx.h"
#include "ClockDisplay.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <ctime>
#include <iostream>
#include <string>


ClockDisplay::ClockDisplay(SDL_Renderer *renderTarget, int pass_screenWidth, int pass_screenHeight)
{
	screenHeight = pass_screenHeight;
	screenWidth = pass_screenWidth;

	//Set the text font and size
	ClockDisplayFont = TTF_OpenFont("Fonts/Tandysoft.otf", 40);
	
	if (ClockDisplayFont == NULL)
	{
		std::cout << "Couldnt open the text!!!!!!!!!!!" << std::endl;
	}

	//Font color		
	ClockDisplayColor = { 255, 255, 255 };  // White

}

ClockDisplay::~ClockDisplay()
{
	SDL_DestroyTexture(ClockTexture);
}

void ClockDisplay::Draw(SDL_Renderer *renderTarget)
{
	//time_t now = time(0);
	//char* dt = ctime(&now);

	ClockMessage = TTF_RenderText_Solid(ClockDisplayFont, "11:36AM", ClockDisplayColor);

	ClockTexture = SDL_CreateTextureFromSurface(renderTarget, ClockMessage); //now you can convert it into a texture

	thisCrop.w = 0;
	thisCrop.h = 0;

	SDL_QueryTexture(ClockTexture, NULL, NULL, &thisCrop.w, &thisCrop.h);

	ClockDisplayRect = { ((screenWidth)-(screenWidth / 5)),	((screenHeight / 24) * 1),		(screenWidth / 5),	(screenHeight / 8) };

	SDL_RenderCopy(renderTarget, ClockTexture, NULL, &ClockDisplayRect);
	SDL_RenderPresent(renderTarget);

	SDL_FreeSurface(ClockMessage);

}
