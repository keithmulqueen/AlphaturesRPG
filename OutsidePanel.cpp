#include "stdafx.h"
#include "OutsidePanel.h"
#include "ClockDisplay.h"
#include "DialogueFeed.h"
#include "Monster.h"
#include "MonsterTeam.h"
#include <iostream>
#include <SDL_image.h>


OutsidePanel::OutsidePanel(SDL_Renderer *renderTarget, int passed_screenWidth, int passed_screenHeight, int passed_activePlayer)
{
	screenWidth = passed_screenWidth;
	screenHeight = passed_screenHeight;

	//Creating the Clock & Dialogue
	feed = new DialogueFeed(renderTarget, screenWidth, screenHeight);
	clock = new ClockDisplay(renderTarget, screenWidth, screenHeight);

	//Active Character Panel
	SDL_Surface *activeChar1 = IMG_Load("Sprites/CharacterMode1.png");
	SDL_Surface *activeChar2 = IMG_Load("Sprites/CharacterMode2.png");
	SDL_Surface *activeChar3 = IMG_Load("Sprites/CharacterMode3.png");

	if ((activeChar1 == NULL) || (activeChar2) == NULL || (activeChar3 == NULL))
	{
		std::cout << "Couldnt load active character visual" << std::endl;
	}
	else
	{
		textAChar1 = SDL_CreateTextureFromSurface(renderTarget, activeChar1);
		textAChar2 = SDL_CreateTextureFromSurface(renderTarget, activeChar2);
		textAChar3 = SDL_CreateTextureFromSurface(renderTarget, activeChar3);

		if ((textAChar1 == NULL) || (textAChar2) == NULL || (textAChar3 == NULL))
		{
			std::cout << "Couldnt transfer loaded images active character" << std::endl;
		}
	}











	//Border Word Sprites

	SDL_Surface *tabOptions = IMG_Load("Sprites/BOptions.png");
	SDL_Surface *tabEditTeam = IMG_Load("Sprites/BEditTeam.png");
	SDL_Surface *tabBag = IMG_Load("Sprites/BBag.png");
	SDL_Surface *tabPedia = IMG_Load("Sprites/BPedia.png");
	SDL_Surface *tabSave = IMG_Load("Sprites/BSave.png");
	SDL_Surface *tabQuit = IMG_Load("Sprites/BQuit.png");
	
	if ((tabOptions == NULL) || (tabEditTeam) == NULL || (tabPedia == NULL) || (tabQuit) == NULL || (tabSave == NULL) || (tabBag == NULL))
	{
		std::cout << "Couldnt load tab word" << std::endl;
	}
	else
	{
		textOptions = SDL_CreateTextureFromSurface(renderTarget, tabOptions);
		textEditTeam = SDL_CreateTextureFromSurface(renderTarget, tabEditTeam);
		textBag = SDL_CreateTextureFromSurface(renderTarget, tabBag);
		textPedia = SDL_CreateTextureFromSurface(renderTarget, tabPedia);
		textSave = SDL_CreateTextureFromSurface(renderTarget, tabSave);
		textQuit = SDL_CreateTextureFromSurface(renderTarget, tabQuit);

		if ((textOptions == NULL) || (textEditTeam) == NULL || (textPedia == NULL) || (textQuit) == NULL || (textSave == NULL) || (textBag == NULL))
		{
			std::cout << "Couldnt transfer loaded images into texture for screen words" << std::endl;
		}
	}

	//Border for 1st Players
	
	SDL_Surface *surface1 = IMG_Load("Sprites/Border3.png");

	if (surface1 == NULL)
	{
		std::cout << "Couldnt load border for Player1" << std::endl;
	}
	else
	{
		texture1 = SDL_CreateTextureFromSurface(renderTarget, surface1);

		if (texture1 == NULL)
		{
			std::cout << "Couldnt convert border for Player1" << std::endl;
		}
	}

	//Border for 2nd Players

	SDL_Surface *surface2 = IMG_Load("Sprites/Border3.png");

	if (surface2 == NULL)
	{
		std::cout << "Couldnt load border for Player2" << std::endl;
	}
	else
	{
		texture2 = SDL_CreateTextureFromSurface(renderTarget, surface2);

		if ((texture2 == NULL))
		{
			std::cout << "Couldnt convert border for Player2" << std::endl;
		}
	}

	//Border for 3rd Players

	SDL_Surface *surface3 = IMG_Load("Sprites/Border1.png");

	if ((surface3 == NULL))
	{
		std::cout << "Couldnt load border for Player3" << std::endl;
	}
	else
	{
		texture3 = SDL_CreateTextureFromSurface(renderTarget, surface3);

		if ((texture3 == NULL))
		{
			std::cout << "Couldnt convert border for Player3" << std::endl;
		}
	}

	//Deleting Original surfaces

	SDL_FreeSurface(surface1);
	SDL_FreeSurface(surface2);
	SDL_FreeSurface(surface3);

	SDL_FreeSurface(activeChar1);
	SDL_FreeSurface(activeChar2);
	SDL_FreeSurface(activeChar3);

	SDL_FreeSurface(tabBag);
	SDL_FreeSurface(tabEditTeam);
	SDL_FreeSurface(tabOptions); 
	SDL_FreeSurface(tabPedia);
	SDL_FreeSurface(tabQuit);
	SDL_FreeSurface(tabSave);


	SDL_QueryTexture(texture1, NULL, NULL, &cropRect.w, &cropRect.h);
	SDL_QueryTexture(texture2, NULL, NULL, &cropRect.w, &cropRect.h);
	SDL_QueryTexture(texture3, NULL, NULL, &cropRect.w, &cropRect.h);

	positionRect.x = 0;
	positionRect.y = 300;

}


OutsidePanel::~OutsidePanel()
{
	SDL_DestroyTexture(texture1);
	SDL_DestroyTexture(texture2);
	SDL_DestroyTexture(texture3);

	SDL_DestroyTexture(textSave);
	SDL_DestroyTexture(textBag);
	SDL_DestroyTexture(textPedia); 
	SDL_DestroyTexture(textEditTeam);
	SDL_DestroyTexture(textOptions);
	SDL_DestroyTexture(textQuit);

	SDL_DestroyTexture(textAChar1);
	SDL_DestroyTexture(textAChar2);
	SDL_DestroyTexture(textAChar3);

}

void OutsidePanel::Update(SDL_Renderer *renderTarget, int passed_activeplayer)
{
	//Update Changes to the Panel

	activePlayer = passed_activeplayer;

	//MonsterTeam Icons
	SDL_Surface *teamIcon1 = IMG_Load("Sprites/CharacterMode1.png");
	SDL_Surface *teamIcon2 = IMG_Load("Sprites/CharacterMode2.png");
	SDL_Surface *teamIcon3 = IMG_Load("Sprites/CharacterMode3.png");

	SDL_Texture *teamIconT1 = SDL_CreateTextureFromSurface(renderTarget, teamIcon1);
	SDL_Texture *teamIconT2 = SDL_CreateTextureFromSurface(renderTarget, teamIcon2);
	SDL_Texture *teamIconT3 = SDL_CreateTextureFromSurface(renderTarget, teamIcon3);

	SDL_FreeSurface(teamIcon1);
	SDL_FreeSurface(teamIcon2);
	SDL_FreeSurface(teamIcon3);

	SDL_Rect IconRect1 = { ((screenWidth / 120)*1	),	((screenHeight / 120) * 116),		(screenWidth / 12),	(screenWidth / 12) };
	SDL_Rect IconRect2 = { ((screenWidth / 120)*12.5),	((screenHeight / 120) * 116),		(screenWidth / 12),	(screenWidth / 12) };
	SDL_Rect IconRect3 = { ((screenWidth / 120)*24	),	((screenHeight / 120) * 116),		(screenWidth / 12),	(screenWidth / 12) };

	SDL_RenderCopy(renderTarget, teamIconT1, &cropRect, &IconRect1);
	SDL_RenderCopy(renderTarget, teamIconT2, &cropRect, &IconRect2);
	SDL_RenderCopy(renderTarget, teamIconT3, &cropRect, &IconRect3);





	//startX startY Width Height

	SDL_Rect drawingRect = { (0), (0), (screenWidth), (screenHeight) };

	SDL_Rect drawingRectOptions = { ((screenWidth)-(screenWidth / 5)),	((screenHeight/24)*8),		(screenWidth / 5),	(screenHeight / 16) };
	SDL_Rect drawingRectEditTeam = { ((screenWidth)-(screenWidth / 5)),	((screenHeight/24)*10),		(screenWidth / 5),	(screenHeight / 16) };
	SDL_Rect drawingRectBag = { ((screenWidth)-(screenWidth / 5)),		((screenHeight/24)*12),		(screenWidth / 5),	(screenHeight / 16) };
	SDL_Rect drawingRectSave = { ((screenWidth)-(screenWidth / 5)),		((screenHeight/24)*14),		(screenWidth / 5),	(screenHeight / 16) };
	SDL_Rect drawingRectPedia = { ((screenWidth)-(screenWidth / 5)),	((screenHeight/24)*16),		(screenWidth / 5),	(screenHeight / 16) };
	SDL_Rect drawingRectQuit = { ((screenWidth)-(screenWidth / 5)),		((screenHeight/24)*18),		(screenWidth / 5),	(screenHeight / 16) };

	SDL_Rect drawingRectChar1 = { ((screenWidth)-(screenWidth/5)),							((screenHeight / 24) * 5),		(screenWidth / 16),		(screenWidth / 16) };
	SDL_Rect drawingRectChar2 = { (((screenWidth)-(screenWidth/5)) + screenWidth/15),		((screenHeight / 24) * 5),		(screenWidth / 16),		(screenWidth / 16) };
	SDL_Rect drawingRectChar3 = { (((screenWidth)-(screenWidth/5)) + (screenWidth/15)*2),	((screenHeight / 24) * 5),		(screenWidth / 16),		(screenWidth / 16) };



	if (activePlayer == 1)
	{
		SDL_RenderCopy(renderTarget, texture1, &cropRect, &drawingRect);
	}
	else if (activePlayer == 2)
	{
		SDL_RenderCopy(renderTarget, texture2, &cropRect, &drawingRect);
	}
	else if (activePlayer == 3)
	{
		SDL_RenderCopy(renderTarget, texture3, &cropRect, &drawingRect);
	}

	SDL_RenderCopy(renderTarget, textBag, &cropRect, &drawingRectOptions);
	SDL_RenderCopy(renderTarget, textEditTeam, &cropRect, &drawingRectEditTeam);
	SDL_RenderCopy(renderTarget, textOptions, &cropRect, &drawingRectBag);
	SDL_RenderCopy(renderTarget, textPedia, &cropRect, &drawingRectSave);
	SDL_RenderCopy(renderTarget, textQuit, &cropRect, &drawingRectPedia);
	SDL_RenderCopy(renderTarget, textSave, &cropRect, &drawingRectQuit);

	SDL_RenderCopy(renderTarget, textBag, &cropRect, &drawingRectOptions);
	SDL_RenderCopy(renderTarget, textEditTeam, &cropRect, &drawingRectEditTeam);
	SDL_RenderCopy(renderTarget, textOptions, &cropRect, &drawingRectBag);

	SDL_RenderCopy(renderTarget, textAChar1, &cropRect, &drawingRectChar1);
	SDL_RenderCopy(renderTarget, textAChar2, &cropRect, &drawingRectChar2);
	SDL_RenderCopy(renderTarget, textAChar3, &cropRect, &drawingRectChar3);

	if (activePlayer == 1)
	{
		SDL_SetTextureColorMod(textAChar1, 153, 217, 234);
		SDL_SetTextureColorMod(textAChar2, 255, 255, 255);
		SDL_SetTextureColorMod(textAChar3, 255, 255, 255);
	}
	else if (activePlayer == 2)
	{
		SDL_SetTextureColorMod(textAChar1, 153, 217, 234);
		SDL_SetTextureColorMod(textAChar2, 255, 255, 255);
		SDL_SetTextureColorMod(textAChar3, 255, 255, 255);
	}
	else if (activePlayer == 3)
	{
		SDL_SetTextureColorMod(textAChar1, 153, 217, 234);
		SDL_SetTextureColorMod(textAChar2, 255, 255, 255);
		SDL_SetTextureColorMod(textAChar3, 255, 255, 255);
	}

	feed->Draw(renderTarget);
	clock->Draw(renderTarget);

}
