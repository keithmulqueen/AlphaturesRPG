#include "stdafx.h"
#include "Player.h"
#include "NPC.h"
#include <SDL_image.h>
#include <cmath>
#include <iostream>


NPC::NPC(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY, std::string passed_Dialogue)
{
	SDL_Surface *surface = IMG_Load(filePath.c_str());

	Dialogue = passed_Dialogue;


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

	SDL_QueryTexture(texture, NULL, NULL, &cropRect.w, &cropRect.h);

	positionRect.x = x;
	positionRect.y = y;

	textureWidth = cropRect.w;

	cropRect.w /= framesX;
	cropRect.h /= framesY;

	frameWidth = positionRect.w = cropRect.w;
	frameHeight = positionRect.h = cropRect.h;

	originX = frameWidth / 2;
	originY = frameWidth / 2;

	radius = 5;

	isActive = false;


	moveSpeed = 200.0f;
}


NPC::~NPC()
{
	SDL_DestroyTexture(texture);
}

void NPC::Update(float delta, const Uint8 *keyState, int move)
{
	movementPattern = move;
	
	/*	isActive = true;

	if (keyState[keys[0]])
	{
	positionRect.y -= moveSpeed * delta;
	cropRect.y = frameHeight * 3;
	}
	else if (keyState[keys[1]])
	{
	positionRect.y += moveSpeed * delta;
	cropRect.y = frameHeight * 0;
	}
	else if (keyState[keys[2]])
	{
	positionRect.x -= moveSpeed * delta;
	cropRect.y = frameHeight * 1;
	}
	else if (keyState[keys[3]])
	{
	positionRect.x += moveSpeed * delta;
	cropRect.y = frameHeight * 2;
	}
	else
	{
	isActive = false;
	}

	if (isActive)
	{
	frameCounter += delta;

	if (frameCounter >= 0.25f)
	{

	if (cropRect.x >= (textureWidth / 4) * 3)
	{
	cropRect.x = 0;
	}

	else
	{
	cropRect.x += frameWidth;
	}

	frameCounter = 0;
	}

	}
	else
	{
	cropRect.x = frameWidth * 0;
	}
	*/
}

void NPC::Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect)
{
	SDL_Rect drawingRect = { (positionRect.x - cameraRect.x), (positionRect.y - cameraRect.y), positionRect.w, positionRect.h };
	SDL_RenderCopy(renderTarget, texture, &cropRect, &drawingRect);
}

bool NPC::IntersectsWith(Player &p)
{
	if (sqrt(pow(GetOriginX() - p.GetOriginX(), 2) + pow(GetOriginY() - p.GetOriginY(), 2)) >= radius + p.GetRadius())
	{
		SDL_SetTextureColorMod(texture, 255, 255, 255);
		return false;
	}

	SDL_SetTextureColorMod(texture, 255, 0, 0);
	return true;
}

int NPC::GetOriginX()
{
	return positionRect.x + originX;
}

int NPC::GetOriginY()
{
	return positionRect.y + originY;
}

int NPC::GetRadius()
{
	return radius;
}

std::string NPC::GetDialogue()
{
	return Dialogue;
}