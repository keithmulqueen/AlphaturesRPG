#include "stdafx.h"
#include "Monster.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <iostream>


Monster::Monster(std::string filePathSprite, std::string filePathIcon, float passed_health, float passed_damage, int passed_level, int passed_move, int passed_range, int passed_type, float passed_base)
{
	//health mult and damage mult <=5.00

	MonsterSprite =	filePathSprite;
	MonsterIcon = filePathIcon;

	health_mult = passed_health;
	base_health = passed_base;
	damage_mult = passed_damage;
	range =	passed_range;
	movement = passed_move;
	monsterType = passed_type;
	currentLevel = passed_level;
	experience = (currentLevel * 1000);

}

Monster::Monster()
{

}


Monster::~Monster()
{

}

void Monster::UpdateMonster(float enemy_experience_gain, float enemy_level)
{
	health = (base_health + ((currentLevel * health_mult) * 0.95));
	damage = ((damage_mult * 10) + ((currentLevel * damage_mult) * 0.75));

	experience = (experience)+((enemy_level / (currentLevel + 1))*enemy_experience_gain);

	for (int i = 0; (i * 1000) <= experience; i++) 
	{
		currentLevel = i;
	}

}

int Monster::GetDamage()
{
	return static_cast<int>(damage);
}

int Monster::GetHealth()
{
	return static_cast<int>(health);
}

int Monster::GetMovement()
{
	return static_cast<int>(range);
}

int Monster::GetRange()
{
	return static_cast<int>(range);
}

int Monster::GetExperience()
{
	return (((movement + range)+3)*50);
}

void Monster::SetRange(int passed_newRange)
{
	range = passed_newRange;
}

void Monster::SetMovement(int passed_newMovement)
{
	movement = passed_newMovement;
}

std::string Monster::GetIcon()
{
	return MonsterIcon;
}

std::string Monster::GetSprite()
{
	return MonsterSprite;
}