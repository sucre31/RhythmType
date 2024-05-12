#include <Dxlib.h>
#include "PlayerCharacter.h"
#include "Pad.h"
#include "Sound.h"
#include "GameManeger.h"


PlayerCharacter::PlayerCharacter() {
	mainSoundNumber = 0;
	subSoundNumber = 0;
}

bool PlayerCharacter::update() {
	if (GameManeger::getIns()->getTurn() % 4 == myTurn) {
		if (Pad::getIns()->get(ePad::up) == 1) {
			myHP++;
		}
		if (Pad::getIns()->get(ePad::down) == 1) {
			myHP--;
		}
		if (Pad::getIns()->get(ePad::A) == 1) {
			playMainSoundNumberMem(mainSoundNumber);
			enemyC->reverse();
			mainSoundNumber++;
		}
		if (Pad::getIns()->get(ePad::left) == 1) {
			playSubSoundNumberMem(subSoundNumber);
			reverseSub();
			subSoundNumber++;
		}
		if (myHP < 0) {
			myHP = 0;
		}
	}
	return true;
}

void PlayerCharacter::draw() const {
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
	numberOfSound = numberOfSound % 12;
	switch (numberOfSound) {
	case 0:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[0], DX_PLAYTYPE_BACK);
		break;
	case 1:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[1], DX_PLAYTYPE_BACK);
		break;
	case 2:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[2], DX_PLAYTYPE_BACK);
		break;
	case 3:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[0], DX_PLAYTYPE_BACK);
		break;
	case 4:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[1], DX_PLAYTYPE_BACK);
		break;
	case 5:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[2], DX_PLAYTYPE_BACK);
		break;
	case 6:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[3], DX_PLAYTYPE_BACK);
		break;
	case 7:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[4], DX_PLAYTYPE_BACK);
		break;
	case 8:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[5], DX_PLAYTYPE_BACK);
		break;
	case 9:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[6], DX_PLAYTYPE_BACK);
		break;
	case 10:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[0], DX_PLAYTYPE_BACK);
		break;
	case 11:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[7], DX_PLAYTYPE_BACK);
		break;
	}
}

void PlayerCharacter::playSubSoundNumberMem(int numberOfSound) {
	numberOfSound = numberOfSound % 28;
	switch (numberOfSound) {
	case 0:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[8], DX_PLAYTYPE_BACK);
		break;
	case 1:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[9], DX_PLAYTYPE_BACK);
		break;
	case 2:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[10], DX_PLAYTYPE_BACK);
		break;
	case 3:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[11], DX_PLAYTYPE_BACK);
		break;
	case 4:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[12], DX_PLAYTYPE_BACK);
		break;
	case 5:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[13], DX_PLAYTYPE_BACK);
		break;
	case 6:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[14], DX_PLAYTYPE_BACK);
		break;
	case 7:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[15], DX_PLAYTYPE_BACK);
		break;
	case 8:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[16], DX_PLAYTYPE_BACK);
		break;
	case 9:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[17], DX_PLAYTYPE_BACK);
		break;
	case 10:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[18], DX_PLAYTYPE_BACK);
		break;
	case 11:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[19], DX_PLAYTYPE_BACK);
		break;
	case 12:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[20], DX_PLAYTYPE_BACK);
		break;
	case 13:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[21], DX_PLAYTYPE_BACK);
		break;
	case 14:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[22], DX_PLAYTYPE_BACK);
		break;
	case 15:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[23], DX_PLAYTYPE_BACK);
		break;
	case 16:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[8], DX_PLAYTYPE_BACK);
		break;
	case 17:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[9], DX_PLAYTYPE_BACK);
		break;
	case 18:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[10], DX_PLAYTYPE_BACK);
		break;
	case 19:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[11], DX_PLAYTYPE_BACK);
		break;
	case 20:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[12], DX_PLAYTYPE_BACK);
		break;
	case 21:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[13], DX_PLAYTYPE_BACK);
		break;
	case 22:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[14], DX_PLAYTYPE_BACK);
		break;
	case 23:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[15], DX_PLAYTYPE_BACK);
		break;
	case 24:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[16], DX_PLAYTYPE_BACK);
		break;
	case 25:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[17], DX_PLAYTYPE_BACK);
		break;
	case 26:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[18], DX_PLAYTYPE_BACK);
		break;
	case 27:
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[19], DX_PLAYTYPE_BACK);
		break;
	}
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