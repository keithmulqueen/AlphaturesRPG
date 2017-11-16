#pragma once
#include <SDL.h>
#include<string>


class Portal
{
public:
	Portal(SDL_Renderer *renderTarget, std::string filePath, int x, int y);
	~Portal();

	void Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect);
	bool IntersectsWith(Player &p);

	SDL_Rect positionRect;

	int GetOriginX();
	int GetOriginY();
	int GetRadius();

private:

	SDL_Rect cropRect;
	SDL_Texture *texture;
	float moveSpeed;
	float frameCounter;
	int frameWidth;
	int frameHeight;
	bool isActive;
	int originX;
	int originY;
	int radius;
};
