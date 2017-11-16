#include "stdafx.h"
#include "DialogueFeed.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <ctime>
#include <iostream>
#include <string>


DialogueFeed::DialogueFeed(SDL_Renderer *renderTarget, int pass_screenWidth, int pass_screenHeight)
{
	screenHeight = pass_screenHeight;
	screenWidth = pass_screenWidth;

	//Set the text font and size
	DialogueFont = TTF_OpenFont("Fonts/Tandysoft.otf", 40);

	if (DialogueFont == NULL)
	{
		std::cout << "Couldnt open the text!!!!!!!!!!!" << std::endl;
	}

	//Font color		
	DialogueColor = { 255, 255, 255 };  // White

}

DialogueFeed::~DialogueFeed()
{
	SDL_DestroyTexture(DialogueTexture);
}

void DialogueFeed::Draw(SDL_Renderer *renderTarget)
{

	DialogueMessage = TTF_RenderText_Solid(DialogueFont, "Hi", DialogueColor);

	DialogueTexture = SDL_CreateTextureFromSurface(renderTarget, DialogueMessage); //now you can convert it into a texture

	SDL_QueryTexture(DialogueTexture, NULL, NULL, &thisCrop.w, &thisCrop.h);

	//Where to put the Clock Display
	DialogueRect = { ((screenWidth / 24)*1),	((screenHeight / 50) * 40),		(thisCrop.w),	(thisCrop.h) };

	//Adding to the Render
	SDL_RenderCopy(renderTarget, DialogueTexture, NULL, &DialogueRect);

	//Release Unneeded Message
	SDL_FreeSurface(DialogueMessage);

}
