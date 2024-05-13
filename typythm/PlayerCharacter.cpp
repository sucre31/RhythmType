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
@brief �L�����N�^�[��HP��ݒ�
*/
void PlayerCharacter::setHP(int HP){
	myHP = HP;
}

/*
@brief �L�����N�^�[��PP��ݒ�
*/
void PlayerCharacter::setPP(int PP) {
	myPP = PP;
}

/*
@brief �L�����N�^�[�̖��O��ݒ�
@param charNum ������
@param charSpriteNum �X�v���C�g�ԍ�
*/
void PlayerCharacter::setName(int charNum, int charSpriteNum) {
	myName[charNum] = charSpriteNum;
	nameLength = charNum + 1;
}

/*
@brief �L�����N�^�[�̍s���^�[����ݒ�
@param charNum ������
*/
void PlayerCharacter::setMyTurn(int Number) {
	myTurn = Number;
}

void PlayerCharacter::setInstrumentNumber(int Number) {
	myInstrument->setMyInstrumentNumber(Number);
}

/*!
@brief �G�̃C���X�^���X���擾
@param charNum ���̖�?
@param enemyInstance �G�̃C���X�^���X
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
@brief �L�����N�^�[�̖��O���擾
@param charNum �������ځH
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
@brief �L�����N�^�[�̖��O���擾
@param charNum �������ځH
*/
int PlayerCharacter::getNameLength() const {
	return nameLength;
}

/*!
@brief �L�����N�^�[��HP���擾
*/
int PlayerCharacter::getHP() const {
	return myHP;
}

/*!
@brief �L�����N�^�[��PP���擾
*/
int PlayerCharacter::getPP() const {
	return myPP;
}

/*!
@brief ���C���̉������Ԃɕ��ׂ�
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
//@brief �����ɑΉ�������(���C��)���Ȃ炷
//@param numberOfSound BPM�ɑΉ��������̔ԍ� 128�Ń��[�v
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