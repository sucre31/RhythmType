#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Instrument.h"

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
	void setCharacterId(int Number);
	void setInstrumentNumber(int Number);
	void reverseCharacter();
	int getName(int charNum) const;
	int getHP() const;
	int getPP() const;
	int getNameLength() const;
	int getCharacterID() const { return characterID; }
	bool getIsActive() const { return isActive; }
	bool getReverseFlag() const { return reverseFlag; }
private:
	void playMainSoundNumberMem(int numberOfSound);
	void playSubSoundNumberMem(int numberOfSound);
	void reverseSub();
	bool isActive;
	int myName[6];
	int myHP;
	int myPP;
	int myTurn;
	int nameLength;
	int mainSoundNumber;
	int subSoundNumber;
	int characterID;
	bool reverseFlag;
	Enemy* enemyA;
	Enemy* enemyB;
	Enemy* enemyC;
	Enemy* enemyD;
	Enemy* enemyE;
	Instrument* myInstrument;
};

