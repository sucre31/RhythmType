#pragma once
#include "Character.h"
#include "Enemy.h"

class PlayerCharacter : public Character
{
public:
	PlayerCharacter();
	~PlayerCharacter() = default;
	bool update() override;
	void draw() const override;
	void setHP(int HP);
	void setPP(int PP);
	void setName(int charNum, int charSpriteNum);
	void setMyTurn(int Number);
	void setEnemyInstance(int enemyNum, Enemy* enemyInstance);
	int getName(int charNum) const;
	int getHP() const;
	int getPP() const;
	int getNameLength() const;
private:
	void playMainSoundNumberMem(int numberOfSound);
	void playSubSoundNumberMem(int numberOfSound);
	void reverseSub();
	int myName[6];
	int myHP;
	int myPP;
	int myTurn;
	int nameLength;
	int mainSoundNumber;
	int subSoundNumber;
	Enemy* enemyA;
	Enemy* enemyB;
	Enemy* enemyC;
	Enemy* enemyD;
	Enemy* enemyE;
};

