#include <Dxlib.h>
#include "PlayerCharacter.h"
#include "Pad.h"
#include "Sound.h"
#include "GameManager.h"


PlayerCharacter::PlayerCharacter() {
	mainSoundNumber = 0;
	subSoundNumber = 0;
	myInstrument = new Instrument();
	//myInstrument->setBeatManager(beatManager);
	reverseFlag = FALSE;
	alwaysActive = false;
	damage = 0;
}

bool PlayerCharacter::update() {
	if (GameManager::getIns()->getTurn() % 4 == myTurn) {
		isActive = true;
		scoreCheck();
		if (Pad::getIns()->get(ePad::up) >= 1) {
			myHP++;
		}
		if (Pad::getIns()->get(ePad::down) >= 1) {
			myHP--;
		}
		if (Pad::getIns()->get(ePad::A) == 1) {
			playMainSoundNumberMem(mainSoundNumber);
			setPP(mainSoundNumber);
			//PlaySoundMem(Sound::getIns()->getBattleSE()[0], DX_PLAYTYPE_BACK);
			reverseCharacter();
			damage = scoreCheck();
			if (damage == 80) PlaySoundMem(Sound::getIns()->getBattleSE()[2], DX_PLAYTYPE_BACK);
			enemyC->getDamage(damage);
			mainSoundNumber++;
		}
		if (Pad::getIns()->get(ePad::left) == 1) {
			playSubSoundNumberMem(subSoundNumber);
			setPP(subSoundNumber);
			reverseCharacter();
			damage = scoreCheckSub();
			reverseSub();
			subSoundNumber++;
		}
		if (Pad::getIns()->get(ePad::R) == 1) {
			GameManager::getIns()->nextTurn();
			PlaySoundMem(Sound::getIns()->getBattleSE()[1], DX_PLAYTYPE_BACK);
			isActive = false;
		}
		if (Pad::getIns()->get(ePad::change) == 1) {
			alwaysActive = !alwaysActive;
		}
		if (beatManager->isStepChanged() && Pad::getIns()->get(ePad::L) >= 1) {
			myInstrument->playWithStep(beatManager->getNumberOfStep(), 0);
			myInstrument->playWithStep(beatManager->getNumberOfStep(), 0);
		}
		//if (Pad::getIns()->get(ePad::L) == 1) {
		//	GameManager::getIns()->minusTurn();
		//	isActive = false;
		//}
		if (myHP < 0) {
			myHP = 0;
		}
	}
	else if (alwaysActive) {
		if(beatManager->isStepChanged()) myInstrument->playWithStep(beatManager->getNumberOfStep(), 0);
	}
	return true;
}

void PlayerCharacter::draw() const {
}

void PlayerCharacter::reverseCharacter() {
	reverseFlag = !reverseFlag;
}

/*!
@brief ���݂̃^�[�Q�b�g�ɂȂ�X�e�b�v�����v�Z���������Ń|�C���g�����炤
*/
int PlayerCharacter::scoreCheck() {
	int targetStep;
	int addNumber = 0, addValue = 0;
	bool isTargetDecide = false;
	targetStep = beatManager->getNumberOfStep();
	isTargetDecide = myInstrument->playWithStep(targetStep, 1);
	while (!isTargetDecide) {
		if (addNumber % 2 == 0) {
			addValue = (int)(addNumber / 2 + 1);
		}
		else {
			addValue = - (int)(addNumber / 2 + 1);
		}
		isTargetDecide = myInstrument->playWithStep(targetStep + addValue, 1);
		addNumber++;
		if (addNumber == 128) break;
	}

	return beatManager->checkNowScore(targetStep + addValue);
}

/*!
@brief ���݂̃^�[�Q�b�g�ɂȂ�X�e�b�v�����v�Z���������Ń|�C���g�����炤(�T�u�����p)
*/
int PlayerCharacter::scoreCheckSub() {
	int targetStep;
	int addNumber = 0, addValue = 0;
	bool isTargetDecide = false;
	targetStep = beatManager->getNumberOfStep();
	isTargetDecide = myInstrument->playWithStep(targetStep, 2);
	while (!isTargetDecide) {
		if (addNumber % 2 == 0) {
			addValue = (int)(addNumber / 2 + 1);
		}
		else {
			addValue = -(int)(addNumber / 2 + 1);
		}
		isTargetDecide = myInstrument->playWithStep(targetStep + addValue, 2);
		addNumber++;
		if (addNumber == 128) break;
	}

	return beatManager->checkNowScore(targetStep + addValue);
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
		enemyA->getDamage(damage);
		break;
	case 1:
		enemyB->getDamage(damage);
		break;
	case 2:
		enemyD->getDamage(damage);
		break;
	case 3:
		enemyE->getDamage(damage);
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