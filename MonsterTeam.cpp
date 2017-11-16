#include "stdafx.h"
#include "MonsterTeam.h"
#include "Monster.h"
#include <vector>
#include <iostream>

MonsterTeam::MonsterTeam(int passed_activePlayer)
{
	activeplayer = passed_activePlayer;
	
	if (passed_activePlayer == 1)
	{
		blueHoodBoy = new Monster("Sprites/Character19.png", "Sprites/CharacterMode1.png", 2.5, 3.0, 0, 3, 2, 61, 300);
		starHairBoy = new Monster("Sprites/Character18.png", "Sprites/CharacterMode4.png", 2.5, 3.0, 0, 3, 2, 61, 300);
		
		myTeam.push_back(*blueHoodBoy);
		myTeam.push_back(*starHairBoy);
	}
	else if (passed_activePlayer == 2)
	{
		richGirl = new Monster("Sprites/Character19.png", "Sprites/CharacterMode1.png", 2.5, 3.0, 0, 3, 2, 61, 300);
		healingGaurdian = new Monster("Sprites/Character19.png", "Sprites/CharacterMode1.png", 2.5, 3.0, 0, 3, 2, 61, 300);

		myTeam.push_back(*richGirl);
		myTeam.push_back(*healingGaurdian);
	}
	else if (passed_activePlayer == 3)
	{
		schoolMainBoy = new Monster("Sprites/Character19.png", "Sprites/CharacterMode1.png", 2.5, 3.0, 0, 3, 2, 61, 300);

		myTeam.push_back(*schoolMainBoy);
	}

}


MonsterTeam::~MonsterTeam()
{

}

void MonsterTeam::joinTeam(Monster passed_newMonster)
{
	newMonster = passed_newMonster;

	//adds new Item to the end of the bag list
	myTeam.push_back(newMonster);

}

void MonsterTeam::removeFromTeam(int removeIndex)
{
	myTeam.erase(myTeam.begin() + removeIndex);
}

void MonsterTeam::viewTeam()
{

}

std::string MonsterTeam::getIconFromTeam(int indexNum)
{
	return myTeam.at(indexNum).GetIcon();
}

std::string MonsterTeam::getSpriteFromTeam(int indexNum)
{
	return myTeam.at(indexNum).GetSprite();
}

