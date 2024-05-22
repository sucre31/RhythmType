#include "StatusWindow.h"

#include <string>
#include <Dxlib.h>
#include "Image.h"
#include "GameObject.h"

using namespace std;

StatusWindow::StatusWindow() {
	hp = 120;
	pp = 30;
	myX = 0;
	myY = 23;
	myNameLength = 0;
	frameCount = 0;
}

bool StatusWindow::update() {
	frameCount++;
	setTargetHP(playerCharacter->getHP());
	setTargetPP(playerCharacter->getPP());
	if (frameCount % 3 != 0) {
		calcPoint();
	}
	
	return true;
}

void StatusWindow::draw() const {
	if (playerCharacter->getIsActive()) {
			DrawRotaGraph(29 + myX, 117 + myY, 1.0, 0.0, Image::getIns()->getCharacterBattleImage(playerCharacter->getCharacterID()), TRUE, playerCharacter->getReverseFlag());		//�L�����N�^�[�̕`��
	}
	DrawGraph(0 + myX, 125 + myY, Image::getIns()->getWindowImage(), TRUE);
	drawHP();
	drawName();
}

/*!
@brief �C���X�^���X�����ꂽ��ɐ������w�肵�ă|�W�V����������
*/
void StatusWindow::setWindowPos(int No) {
	switch (No) {
	case 0:			//4�l
		myX = 0;
		break;
	case 1:			//3�l
		myX = 30;	
		break;
	case 2:			//4or2�l
		myX = 60;
		break;
	case 3:			//3or1�l
		myX = 90;
		break;
	case 4:			//4or2�l
		myX = 120;
		break;
	case 5:			//3�l
		myX = 150;
		break;
	case 6:			//4�l
		myX = 180;
		break;

	}
	myX += 40;
}

/*
@brief �L�����N�^�[�̃C���X�^���X���󂯎��
*/
void StatusWindow::setPlayerCharacterInstance(PlayerCharacter* playerCharacterInstance) {
	playerCharacter = playerCharacterInstance;
}

/*
@brief �L�����N�^�[����HP���󂯎��
*/
void StatusWindow::setTargetHP(int hpChara) {
	targetHP = hpChara;
}

/*
@brief �L�����N�^�[����PP���󂯎��
*/
void StatusWindow::setTargetPP(int ppChara) {
	targetPP = ppChara;
}

/*
@brief �L�����N�^�[����HP���󂯎��(����)
*/
void StatusWindow::setHP(int hpChara) {
	hp = hpChara * 8;
}

/*
@brief �L�����N�^�[����PP���󂯎��(����)
*/
void StatusWindow::setPP(int ppChara) {
	pp = ppChara * 8;
}

/*
@brief �L�����N�^�[���疼�O���󂯎��
*/
void StatusWindow::setName() {
	int i;
	for (i = 0; i < 6; i++) {
		myName[i] = playerCharacter->getName(i);
	}
	myNameLength = playerCharacter->getNameLength();
}

/*
@brief HP/PP��ڕW�l�ɋ߂Â��Ă���
*/
void StatusWindow::calcPoint() {
	if (hp / 8.0 < targetHP) {
		hp++;
	}
	else if (hp / 8.0 > targetHP) {
		hp--;
	}
	if (pp / 8.0 < targetPP) {
		pp++;
	}
	else if (pp / 8.0 > targetPP) {
		pp--;
	}
	if (hp < 0) {
		hp = 0;
	}
	if (pp < 0) {
		pp = 0;
	}
}

/*
@brief �L�����N�^�[�̖��O�ɑΉ�����X�v���C�g�ԍ���n��
@param charNum �������ڂ�
*/
int StatusWindow::getNameToSprite(int charNum) const {
	return myName[charNum];

	return 0;
}

/*!
@brief �h�������[���̃X�v���C�g�ԍ���HP����ݒ�
*/
int StatusWindow::getDumrollNum(int drumNum) const {
	int drumSpriteNum = 0;
	switch (drumNum) {			//HP��PP 3���ڂ���0�X�^�[�g��
	case 0:
		if ((((hp / 80) * 8) % 80 ) >= 72 && (hp % 80) >= 72) {
			drumSpriteNum = (((hp / 800) * 8) % 80) + (hp % 8);
			return drumSpriteNum;
		}
		else {
			drumSpriteNum = ((hp / 800) * 8) % 80;
		}
		return drumSpriteNum;
		break;
	case 1:
		if ((hp % 80) >= 72) {
			drumSpriteNum = (((hp / 80) * 8) % 80) + (hp % 8);
			return drumSpriteNum;
		}
		else {
			drumSpriteNum = ((hp / 80) * 8) % 80;
		}
		return drumSpriteNum;
		break;
	case 2:
		drumSpriteNum = hp % 80;
		return drumSpriteNum;
		break;
	case 3:
		if ((((pp / 80) * 8) % 80) >= 72 && (pp % 80) >= 72) {
			drumSpriteNum = (((pp / 800) * 8) % 80) + (pp % 8);
			return drumSpriteNum;
		}
		else {
			drumSpriteNum = ((pp / 800) * 8) % 80;
		}
		return drumSpriteNum;
		break;
	case 4:
		if ((pp % 80) >= 72) {
			drumSpriteNum = (((pp / 80) * 8) % 80) + (pp % 8);
			return drumSpriteNum;
		}
		drumSpriteNum = ((pp / 80) * 8) % 80;
		return drumSpriteNum;
		break;
	case 5:
		drumSpriteNum = pp % 80;
		return drumSpriteNum;
		break;
	}
	return 0;
}

void StatusWindow::drawHP() const {
	if (hp >= 800) DrawGraph(29 + myX, 137 + myY, Image::getIns()->getDrumroll()[getDumrollNum(0)], TRUE);
	if (hp >= 80) DrawGraph(37 + myX, 137 + myY, Image::getIns()->getDrumroll()[getDumrollNum(1)], TRUE);
	DrawGraph(45 + myX, 137 + myY, Image::getIns()->getDrumroll()[getDumrollNum(2)], TRUE);
	if (pp >= 800) DrawGraph(29 + myX, 147 + myY, Image::getIns()->getDrumroll()[getDumrollNum(3)], TRUE);
	if (pp >= 80) DrawGraph(37 + myX, 147 + myY, Image::getIns()->getDrumroll()[getDumrollNum(4)], TRUE);
	DrawGraph(45 + myX, 147 + myY, Image::getIns()->getDrumroll()[getDumrollNum(5)], TRUE);
}

void StatusWindow::drawName() const {
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", myName[0]);
	switch (myNameLength) {
	case 1:
		DrawGraph(28 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[0]], TRUE);
		break;
	case 2:
		DrawGraph(24 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[0]], TRUE);
		DrawGraph(31 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[1]], TRUE);
		break;
	case 3:
		DrawGraph(21 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[0]], TRUE);
		DrawGraph(28 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[1]], TRUE);
		DrawGraph(35 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[2]], TRUE);
		break;
	case 4:
		DrawGraph(17 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[0]], TRUE);
		DrawGraph(24 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[1]], TRUE);
		DrawGraph(31 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[2]], TRUE);
		DrawGraph(38 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[3]], TRUE);
		break;
	case 5:
		DrawGraph(14 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[0]], TRUE);
		DrawGraph(21 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[1]], TRUE);
		DrawGraph(28 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[2]], TRUE);
		DrawGraph(35 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[3]], TRUE);
		DrawGraph(42 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[4]], TRUE);
		break;
	case 6:
		DrawGraph(10 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[0]], TRUE);
		DrawGraph(17 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[1]], TRUE);
		DrawGraph(24 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[2]], TRUE);
		DrawGraph(31 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[3]], TRUE);
		DrawGraph(38 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[4]], TRUE);
		DrawGraph(45 + myX, 129 + myY, Image::getIns()->getCharacterKatakana()[myName[5]], TRUE);
	}
}