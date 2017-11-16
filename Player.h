#pragma once
#include <SDL.h>
#include<string>


class Player
{
public:
	Player();
	Player(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	~Player();

	void Update(float delta, const Uint8 *keyState, Player &p);
	void Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect);
	bool IntersectsWith(Player &p);

	int IsSeperatedFrom(Player &player1);

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
	int textureWidth;
	bool isActive;
	SDL_Scancode keys[4];
	int originX;
	int originY;
	int radius;
};

