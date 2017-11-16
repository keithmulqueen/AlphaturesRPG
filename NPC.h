#pragma once
#include <SDL.h>
#include "Player.h"
#include<string>

class NPC
{
public:
	NPC(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY, std::string passed_Dialogue);
	~NPC();

	void Update(float delta, const Uint8 *keyState, int move);
	void Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect);
	bool IntersectsWith(Player &p);


	SDL_Rect positionRect;

	int GetOriginX();
	int GetOriginY();
	int GetRadius();

	std::string GetDialogue();

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
	int movementPattern;
	std::string Dialogue;

};
