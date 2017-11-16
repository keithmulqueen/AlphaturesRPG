#pragma once
#include "ClockDisplay.h"
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
#include <ctime>

class Environment
{
public:
	Environment(SDL_Renderer *renderTarget, int passed_screenWidth, int passed_screenHeight, int passed_activePlayer);
	~Environment();

	void Update();
	void Draw(SDL_Renderer *renderTarget);
	void Intersects();

	float delta;
	int seperation;
	int seperation2;
	int currentTime;
	int prevTime;
	int activePlayer;
	int screenWidth;
	int screenHeight;
	int levelWidth;
	int levelHeight;
	SDL_Texture *BGtexture;

	bool isRunning;

	SDL_Rect cameraRect;

	const Uint8 *keyState;

	Portal* location1;
	NPC* npc1;
	Player* player1;
	Player* player2;

	std::string DialogueMessage;
	

	TTF_Font* DialogueFont;
	SDL_Color DialogueFontColor;

	SDL_Surface *DialogueSurface;
	SDL_Texture *DialogueTexture;
	SDL_Rect DialogueCrop;
	SDL_Rect DialogueRect;

private:



};

