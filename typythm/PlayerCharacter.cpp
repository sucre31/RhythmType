#include <Dxlib.h>
#include "PlayerCharacter.h"
#include "Pad.h"
#include "Sound.h"
#include "GameManager.h"


PlayerCharacter::PlayerCharacter() {
	mainSoundNumber = 0;
	subSoundNumber = 0;
	myInstrument = new Instrument();
	reverseFlag = FALSE;
}

bool PlayerCharacter::update() {
	if (GameManager::getIns()->getTurn() % 4 == myTurn) {
		isActive = true;
		if (Pad::getIns()->get(ePad::up) >= 1) {
			myHP++;
		}
		if (Pad::getIns()->get(ePad::down) >= 1) {
			myHP--;
		}
		if (Pad::getIns()->get(ePad::A) == 1) {
			playMainSoundNumberMem(mainSoundNumber);
			setPP(mainSoundNumber);
			PlaySoundMem(Sound::getIns()->getBattleSE()[0], DX_PLAYTYPE_BACK);
			reverseCharacter();
			enemyC->reverse();
			mainSoundNumber++;
		}
		if (Pad::getIns()->get(ePad::left) == 1) {
			playSubSoundNumberMem(subSoundNumber);
			setPP(subSoundNumber);
			reverseCharacter();
			reverseSub();
			subSoundNumber++;
		}
		if (Pad::getIns()->get(ePad::R) == 1) {
			GameManager::getIns()->nextTurn();
			isActive = false;
		}
		//if (Pad::getIns()->get(ePad::L) == 1) {
		//	GameManager::getIns()->minusTurn();
		//	isActive = false;
		//}
		if (myHP < 0) {
			myHP = 0;
		}
	}
	return true;
}

void PlayerCharacter::draw() const {
}

void PlayerCharacter::reverseCharacter() {
	reverseFlag = !reverseFlag;
}


/*!
@brief キャラクターのHPを設定
*/
void PlayerCharacter::setHP(int HP){
	myHP = HP;
}

/*
@brief キャラクターのPPを設定
*/
void PlayerCharacter::setPP(int PP) {
	myPP = PP;
}

/*
@brief キャラクターの名前を設定
@param charNum 文字数
@param charSpriteNum スプライト番号
*/
void PlayerCharacter::setName(int charNum, int charSpriteNum) {
	myName[charNum] = charSpriteNum;
	nameLength = charNum + 1;
}

/*
@brief キャラクターの行動ターンを設定
@param charNum 文字数
*/
void PlayerCharacter::setMyTurn(int Number) {
	myTurn = Number;
}

void PlayerCharacter::setInstrumentNumber(int Number) {
	myInstrument->setMyInstrumentNumber(Number);
}

/*!
@brief 敵のインスタンスを取得
@param charNum 何体目?
@param enemyInstance 敵のインスタンス
*/
void PlayerCharacter::setEnemyInstance(int enemyNum, Enemy* enemyInstance) {
	switch (enemyNum) {
	case 0:
		enemyA = enemyInstance;
		break;
	case 1:
		enemyB = enemyInstance;
		break;
	case 2:
		enemyC = enemyInstance;
		break;
	case 3:
		enemyD = enemyInstance;
		break;
	case 4:
		enemyE = enemyInstance;
		break;
	default:
		break;
	}
}

void PlayerCharacter::setCharacterId(int Number) {
	characterID = Number;
}

/*!
@brief キャラクターの名前を取得
@param charNum 何文字目？
*/
int PlayerCharacter::getName(int charNum) const {
	if (charNum < 6 && charNum >= 0) {
		return myName[charNum];
	}
	else {
		return 0;
	}
}

/*!
@brief キャラクターの名前を取得
@param charNum 何文字目？
*/
int PlayerCharacter::getNameLength() const {
	return nameLength;
}

/*!
@brief キャラクターのHPを取得
*/
int PlayerCharacter::getHP() const {
	return myHP;
}

/*!
@brief キャラクターのPPを取得
*/
int PlayerCharacter::getPP() const {
	return myPP;
}

/*!
@brief メインの音を順番に並べる
*/
void PlayerCharacter::playMainSoundNumberMem(int numberOfSound) {
	myInstrument->playMainInstrument(numberOfSound);
}

void PlayerCharacter::playSubSoundNumberMem(int numberOfSound) {
	myInstrument->playSubInstrument(numberOfSound);
}

void PlayerCharacter::reverseSub() {
	switch (subSoundNumber % 4) {
	case 0:
		enemyA->reverse();
		break;
	case 1:
		enemyB->reverse();
		break;
	case 2:
		enemyD->reverse();
		break;
	case 3:
		enemyE->reverse();
		break;
	}
}

///*!
//@brief 引数に対応した音(メイン)をならす
//@param numberOfSound BPMに対応した音の番号 128でループ
//*/
//void playSoundNumberAMem(int numberOfBPM) {
//	int switchNumber = 0;
//	numberOfBPM = numberOfBPM % 128
//	if (numberOfBPM < 16) {
//		switchNumber = 0;
//	}
//	else if (numberOfBPM < 24) {
//		switchNumber = 1;
//	}
//	else if (numberOfBPM < 32) {
//		switchNumber = 2;
//	}
//	else if (numberOfBPM < 48) {
//		switchNumber = 0;
//	}
//	else if (numberOfBPM < 56) {
//		switchNumber = 1;
//	}
//	else if (numberOfBPM < 64) {
//		switchNumber = 2;
//	}
//	else if (numberOfBPM < 80) {
//		switchNumber = 4;
//	}
//	else if (numberOfBPM < 88) {
//		switchNumber = 5;
//	}
//	else if (numberOfBPM < 96) {
//		switchNumber = 6;
//	}
//	else if (numberOfBPM < 128) {
//		switchNumber = 6;
//	}
//
//	switch (numberOfBPM) {
//	default:
//		break;
//	case 0:
//		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[numberOfBPM], DX_PLAYTYPE_BACK);
//		break;
//	}
//}