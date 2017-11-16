#include "stdafx.h"
#include "NPC.h"
#include "Environment.h"
#include "Player.h"
#include "Portal.h"
#include "OutsidePanel.h"
#include "ClockDisplay.h"
#include "SDL.h"
#include "SDL_thread.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <ctime>


int main(int argc, char *argv[])
{
	//Loading Variables
	//MAIN GAME CONSTRUCTOR
	SDL_Window *window = nullptr;
	SDL_Renderer *renderTarget = nullptr;

	int screenWidth = 1200;
	int screenHeight = 800;

	int activePlayer = 1;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	window = SDL_CreateWindow("Alphatures", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//LOADING ENVIRONMENT
	Environment environment1(renderTarget, screenWidth, screenHeight, activePlayer);

	//LOADING OUTSIDE PANEL
	OutsidePanel borderPanel(renderTarget, screenWidth, screenHeight, activePlayer);

	//LOADING CAMERA
	//ClockDisplay myClockDisplay();

	bool isRunning = true;
	SDL_Event ev;
	
	//GAME LOOP

	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}

		environment1.Update();
		
		//DRAW OBJECTS
		environment1.Draw(renderTarget);
		environment1.Intersects();

		//DRAW OUTSIDE PANEL
		borderPanel.Update(renderTarget, activePlayer);

		//FINAL FIXES TO RENDERING
		SDL_RenderPresent(renderTarget);

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderTarget);

	window = nullptr;
	renderTarget = nullptr;

	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

	return 0;
}

