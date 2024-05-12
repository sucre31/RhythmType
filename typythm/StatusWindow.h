#pragma once

#include <memory>
#include "GameObject.h"
#include "PlayerCharacter.h"


class StatusWindow : GameObject
{
public:
	StatusWindow();
	virtual ~StatusWindow() = default;
	bool update() override;
	void draw() const override;
	void setWindowPos(int No);
	void setPlayerCharacterInstance(PlayerCharacter* playerCharacterInstance);
	void setTargetHP(int hpChara);
	void setTargetPP(int ppChara);
	void setHP(int hpChara);
	void setPP(int ppChara);
	void setName();
	int getNameToSprite(int charNum) const;
	int getDumrollNum(int drumNum) const;
private:
	int hp, pp;			//戦闘中のHPは時間で小数点管理される、ここのHPを元にし、整数値になったらプレイヤーに返す
	int targetHP, targetPP;
	int myX, myY;		//ウィンドウのポジションを調整
	int myName[6];
	int myNameLength;
	int frameCount;
	void calcPoint();
	void drawHP() const;
	void drawName() const;
	//std::shared_ptr<PlayerCharacter> playerCharacter;
	PlayerCharacter* playerCharacter;
};

