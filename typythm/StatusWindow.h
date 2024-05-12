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
	int hp, pp;			//�퓬����HP�͎��Ԃŏ����_�Ǘ������A������HP�����ɂ��A�����l�ɂȂ�����v���C���[�ɕԂ�
	int targetHP, targetPP;
	int myX, myY;		//�E�B���h�E�̃|�W�V�����𒲐�
	int myName[6];
	int myNameLength;
	int frameCount;
	void calcPoint();
	void drawHP() const;
	void drawName() const;
	//std::shared_ptr<PlayerCharacter> playerCharacter;
	PlayerCharacter* playerCharacter;
};

