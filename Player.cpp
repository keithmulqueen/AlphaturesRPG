#include "Player.h"
#include <SDL_image.h>
#include <cmath>
#include <iostream>

Player::Player()
{

}

Player::Player(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY)
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

	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture, NULL, NULL, &cropRect.w, &cropRect.h);

	//Position on the map
	positionRect.x = x;
	positionRect.y = y;

	//PNG image slicing
	textureWidth = cropRect.w;

	//Dividing into how many slices?
	cropRect.w /= framesX;
	cropRect.h /= framesY;

	//PNG height and width of image
	frameWidth = positionRect.w = cropRect.w;
	frameHeight = positionRect.h = cropRect.h;

	//Centre of the image
	originX = frameWidth / 2;
	originY = frameWidth / 2;

	radius = 5;

	isActive = false;

	static int playerNumber = 0;
	playerNumber++;

	if (playerNumber == 1)
	{
		keys[0] = SDL_SCANCODE_UP;
		keys[1] = SDL_SCANCODE_DOWN;
		keys[2] = SDL_SCANCODE_LEFT;
		keys[3] = SDL_SCANCODE_RIGHT;
	}
	else
	{
		keys[0] = SDL_SCANCODE_W;
		keys[1] = SDL_SCANCODE_S;
		keys[2] = SDL_SCANCODE_A;
		keys[3] = SDL_SCANCODE_D;
		keys[4] = SDL_SCANCODE_F;
	}

	moveSpeed = 200.0f;
}


Player::~Player()
{
	SDL_DestroyTexture(texture);
}

void Player::Update(float delta, const Uint8 *keyState, Player &p)
{
	isActive = true;

	if (keyState[keys[0]]) //
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
	else if (keyState[keys[4]])
	{
		positionRect.x = p.GetOriginX() - (frameWidth/2);
		positionRect.y = p.GetOriginY() - (frameHeight/2);
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
}

void Player::Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect)
{
	SDL_Rect drawingRect = { (positionRect.x - cameraRect.x), (positionRect.y - cameraRect.y), positionRect.w, positionRect.h };
	SDL_RenderCopy(renderTarget, texture, &cropRect, &drawingRect);
}

bool Player::IntersectsWith(Player &p)
{
	if (sqrt(pow(GetOriginX() - p.GetOriginX(), 2) + pow(GetOriginY() - p.GetOriginY(), 2)) >= radius + p.GetRadius())
	{
		SDL_SetTextureColorMod(texture, 255, 255, 255);
		return false;
	}

	SDL_SetTextureColorMod(texture, 255, 0, 0);
	return true;
}

int Player::GetOriginX()
{
	return positionRect.x + originX;
}

int Player::GetOriginY()
{
	return positionRect.y + originY;
}

int Player::GetRadius()
{
	return radius;
}


int Player::IsSeperatedFrom(Player &player1)
{
	if ((GetOriginX() - player1.GetOriginX()) >= 300)
	{
		return 1; //RIGHT
	}
	
	else if ((GetOriginY() - player1.GetOriginY()) >= 300)
	{
		return 2; //UP
	}

	else if ((GetOriginX() - player1.GetOriginX()) <= -300)
	{
		return 3;//LEFT
	}

	else if ((GetOriginY() - player1.GetOriginY()) <= -300)
	{
		return 4;//DOWN
	}
	else
	{
		return 0;
	}

}