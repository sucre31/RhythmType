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
			DrawRotaGraph(29 + myX, 117 + myY, 1.0, 0.0, Image::getIns()->getCharacterBattleImage(playerCharacter->getCharacterID()), TRUE, playerCharacter->getReverseFlag());		//キャラクターの描画
	}
	DrawGraph(0 + myX, 125 + myY, Image::getIns()->getWindowImage(), TRUE);
	drawHP();
	drawName();
}

/*!
@brief インスタンスが作られた後に数字を指定してポジションを決定
*/
void StatusWindow::setWindowPos(int No) {
	switch (No) {
	case 0:			//4人
		myX = 0;
		break;
	case 1:			//3人
		myX = 30;	
		break;
	case 2:			//4or2人
		myX = 60;
		break;
	case 3:			//3or1人
		myX = 90;
		break;
	case 4:			//4or2人
		myX = 120;
		break;
	case 5:			//3人
		myX = 150;
		break;
	case 6:			//4人
		myX = 180;
		break;

	}
	myX += 40;
}

/*
@brief キャラクターのインスタンスを受け取る
*/
void StatusWindow::setPlayerCharacterInstance(PlayerCharacter* playerCharacterInstance) {
	playerCharacter = playerCharacterInstance;
}

/*
@brief キャラクターからHPを受け取る
*/
void StatusWindow::setTargetHP(int hpChara) {
	targetHP = hpChara;
}

/*
@brief キャラクターからPPを受け取る
*/
void StatusWindow::setTargetPP(int ppChara) {
	targetPP = ppChara;
}

/*
@brief キャラクターからHPを受け取る(直接)
*/
void StatusWindow::setHP(int hpChara) {
	hp = hpChara * 8;
}

/*
@brief キャラクターからPPを受け取る(直接)
*/
void StatusWindow::setPP(int ppChara) {
	pp = ppChara * 8;
}

/*
@brief キャラクターから名前を受け取る
*/
void StatusWindow::setName() {
	int i;
	for (i = 0; i < 6; i++) {
		myName[i] = playerCharacter->getName(i);
	}
	myNameLength = playerCharacter->getNameLength();
}

/*
@brief HP/PPを目標値に近づけていく
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
@brief キャラクターの名前に対応するスプライト番号を渡す
@param charNum 何文字目か
*/
int StatusWindow::getNameToSprite(int charNum) const {
	return myName[charNum];

	return 0;
}

/*!
@brief ドラムロールのスプライト番号をHPから設定
*/
int StatusWindow::getDumrollNum(int drumNum) const {
	int drumSpriteNum = 0;
	switch (drumNum) {			//HP→PP 3桁目から0スタートで
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