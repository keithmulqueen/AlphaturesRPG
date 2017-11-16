#include "Player.h"
#include "Portal.h"
#include <SDL_image.h>
#include <cmath>
#include <iostream>


Portal::Portal(SDL_Renderer *renderTarget, std::string filePath, int x, int y)
{
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

	//release unneeded surface
	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture, NULL, NULL, &cropRect.w, &cropRect.h);

	//Position on the map
	positionRect.x = x;
	positionRect.y = y;


	//PNG height and width of image
	frameWidth = positionRect.w = cropRect.w;
	frameHeight = positionRect.h = cropRect.h;

	//Centre of the image
	originX = frameWidth / 2;
	originY = frameWidth / 2;

	radius = 10;

}


Portal::~Portal()
{
	SDL_DestroyTexture(texture);
}

void Portal::Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect)
{
	SDL_Rect drawingRect = { (positionRect.x - cameraRect.x), (positionRect.y - cameraRect.y), positionRect.w, positionRect.h };
	SDL_RenderCopy(renderTarget, texture, &cropRect, &drawingRect);
}

bool Portal::IntersectsWith(Player &p)
{
	if (sqrt(pow(GetOriginX() - p.GetOriginX(), 2) + pow(GetOriginY() - p.GetOriginY(), 2)) >= radius + p.GetRadius())
	{
		//NO	
		SDL_SetTextureColorMod(texture, 255, 255, 255);
		return false;
	}

	//YES
	//Teleport to a new location
	SDL_SetTextureColorMod(texture, 0, 255, 0);
	return true;
}

int Portal::GetOriginX()
{
	return positionRect.x + originX;
}

int Portal::GetOriginY()
{
	return positionRect.y + originY;
}

int Portal::GetRadius()
{
	return radius;
}
