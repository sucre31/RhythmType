#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Instrument.h"
#include "BeatManager.h"

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
	void setBeatManager(BeatManager* beatManagerInstance) { beatManager = beatManagerInstance; }
	void setCharacterId(int Number);
	void setInstrumentNumber(int Number);
	void reverseCharacter();
	int scoreCheck();
	int scoreCheckSub();
	int getName(int charNum) const;
	int getHP() const;
	int getPP() const;
	int getNameLength() const;
	int getCharacterID() const { return characterID; }
	bool getIsActive() const { return (isActive || alwaysActive); }
	bool getReverseFlag() const { return reverseFlag; }
private:
	void playMainSoundNumberMem(int numberOfSound);
	void playSubSoundNumberMem(int numberOfSound);
	void reverseSub();
	bool isActive;
	bool alwaysActive;
	int myName[6];
	int myHP;
	int myPP;
	int myTurn;
	int nameLength;
	int mainSoundNumber;
	int subSoundNumber;
	int characterID;
	int damage;
	bool reverseFlag;
	Enemy* enemyA;
	Enemy* enemyB;
	Enemy* enemyC;
	Enemy* enemyD;
	Enemy* enemyE;
	Instrument* myInstrument;
	BeatManager* beatManager;
};

