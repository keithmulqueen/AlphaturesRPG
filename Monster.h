#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Monster
{
public:
	Monster(std::string filePathSprite, std::string filePathIcon, float passed_health, float passed_damage, int passed_level, int passed_move, int passed_range, int passed_type, float passed_base);
	Monster();
	~Monster();

	void UpdateMonster(float experience_gain, float enemy_level);

	int GetDamage();
	int GetHealth();
	int GetMovement();
	int GetRange();
	int GetExperience();

	std::string GetIcon();
	std::string GetSprite();

	void SetRange(int passed_newRange);
	void SetMovement(int passed_newMovement);


private:
	std::string MonsterSprite;
	std::string MonsterIcon;

	float damage;
	float damage_mult;
	float health;
	float health_mult;
	float base_health;
	float currentLevel;
	int movement;
	int monsterType;
	int range;
	float experience;
};

