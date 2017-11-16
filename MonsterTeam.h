#pragma once
#include "Monster.h"
#include <vector>

class MonsterTeam
{
public:
	MonsterTeam(int passed_activePlayer);
	~MonsterTeam();

	void joinTeam(Monster passed_newMonster);
	void removeFromTeam(int removeIndex);
	void viewTeam();
	std::string getIconFromTeam(int indexNum);
	std::string getSpriteFromTeam(int indexNum);
	
	std::vector< Monster > myTeam;

private:

	Monster newMonster;

	Monster *blueHoodBoy;
	Monster *starHairBoy;
	Monster *richGirl;
	Monster *healingGaurdian;
	Monster *schoolMainBoy;

	int activeplayer;

};