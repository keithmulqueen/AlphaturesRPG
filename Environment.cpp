#include "stdafx.h"
#include "Environment.h"
#include "SDL.h"
#include "Player.h"
#include "NPC.h"
#include "Portal.h"
#include "SDL_thread.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>
#include <ctime>
#include "ClockDisplay.h"

SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());


	if (surface == NULL)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);

		if (texture == NULL)
		{
			std::cout << "Error" << std::endl;
		}
	}

	SDL_FreeSurface(surface);

	return texture;
}

Environment::Environment(SDL_Renderer *renderTarget, int passed_screenWidth, int passed_screenHeight, int passed_activePlayer)
{
	currentTime = 0;
	prevTime = 0;
	activePlayer = passed_activePlayer;
	DialogueMessage = "";


	screenWidth = passed_screenWidth;
	screenHeight = passed_screenHeight;

	DialogueFont = TTF_OpenFont("Fonts/Tandysoft.otf", 20);
	DialogueFontColor = { 255, 255, 255 };  // White

	cameraRect = { 0, 0, screenWidth, screenHeight };

	isRunning = true;
	SDL_Event ev;

	//LOADING LOCATIONS
	location1 = new Portal(renderTarget, "Sprites/LOC1.png", 2200, 2200);

	if (activePlayer == 1)
	{
		//LOADING PLAYERS
		player1 = new Player(renderTarget, "Sprites/Character19.png", 2000, 2000, 4, 4);
		player2 = new Player(renderTarget, "Sprites/Character18.png", 2100, 2000, 4, 4);
	}
	else if (activePlayer == 2)
	{
		//LOADING PLAYERS
		player1 = new Player(renderTarget, "Sprites/Character4.png", 2000, 2000, 4, 4);
		player2 = new Player(renderTarget, "Sprites/Character3.png", 2100, 2000, 4, 4);
	}
	else
	{
		//LOADING PLAYERS
		player1 = new Player(renderTarget, "Sprites/Character5.png", 2000, 2000, 4, 4);
		player2 = new Player(renderTarget, "Sprites/Character7.png", 2100, 2000, 4, 4);
	}

	//LOADING NPC PLAYERS
	npc1 = new NPC(renderTarget, "Sprites/Character17.png", 2100, 2100, 4, 4, "Hello there! It is so nice to meet you!");

	BGtexture = LoadTexture("Sprites/TechnologyArea.png", renderTarget);
	SDL_QueryTexture(BGtexture, NULL, NULL, &levelWidth, &levelHeight);
}


Environment::~Environment()
{
	SDL_DestroyTexture(BGtexture);
	BGtexture = nullptr;

}

void Environment::Update()
{
	prevTime = currentTime;
	currentTime = SDL_GetTicks();
	
	delta = (currentTime - prevTime) / 1000.0f;
	keyState = SDL_GetKeyboardState(NULL);

	player1->Update(delta, keyState, *player2);
	player2->Update(delta, keyState, *player1);
	npc1->Update(delta, keyState, 1);

	cameraRect.x = player1->GetOriginX() - ((screenWidth*0.8) / 2);
	cameraRect.y = player1->GetOriginY() - ((screenHeight*0.8) / 2);

	if (cameraRect.x < 0)
	{
		cameraRect.x = 0;
	}
	if (cameraRect.y < 0)
	{
		cameraRect.y = 0;
	}

	if (cameraRect.x + cameraRect.w >= levelWidth)
	{
		cameraRect.x = levelWidth - screenWidth;
		;
	}
	if (cameraRect.y + cameraRect.h >= levelHeight)
	{
		cameraRect.y = levelHeight - screenHeight;
	}
}

void Environment::Draw(SDL_Renderer *renderTarget)
{
	(renderTarget);
	SDL_RenderCopy(renderTarget, BGtexture, &cameraRect, NULL);
	
	//DRAW LOCATIONS
	location1->Draw(renderTarget, cameraRect);

	//DRAW NPC CHARACTERS
	npc1->Draw(renderTarget, cameraRect);

	//DRAW PLAYERS
	player1->Draw(renderTarget, cameraRect);
	player2->Draw(renderTarget, cameraRect);

}

void Environment::Intersects()
{
	player1->IntersectsWith(*player2);
	location1->IntersectsWith(*player1);

	if (npc1->IntersectsWith(*player1) == true)
	{
		DialogueMessage = npc1->GetDialogue();
	}
	else
	{
		DialogueMessage = "";
	}
}
