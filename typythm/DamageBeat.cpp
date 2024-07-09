#include <Dxlib.h>

#include "FpsControl.h"
#include "DamageBeat.h"
#include "DamageCharacter.h"
#include "Image.h"
#include "GameManager.h"

DamageBeat::DamageBeat() {
	numberOfDamage = 0;
}

bool DamageBeat::update() {
	calcDamagePos();
	if (GameManager::getIns()->getFpsIns()->isFrameChanged() && ShowDamageHit != 0) {
		ShowDamageHit++;
		if (ShowDamageHit == 7) {
			ShowDamageHit = 0;
		}
	}
	return true;
}

void DamageBeat::draw() const {
	int i;
	if (ShowDamageHit > 0) {
		DrawGraph(DamageHitPosX, DamageHitPosY, Image::getIns()->getHitImage()[((ShowDamageHit - 1) / 3) % 2], TRUE);
	}
	for (i = 0; i < numberOfDamage; i++) {
		if (damageNumber[i]->damage < 100) {
			if (damageNumber[i]->damage < 10) {		//�_���[�W��1��
				DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[damageNumber[i]->damage], TRUE);
			}
			else {									//�_���[�W��2��
				DrawGraph((int)damageNumber[i]->x + 151, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage / 10) % 10], TRUE);
				DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage % 10)], TRUE);
			}
		}
		else {										//�_���[�W��3��
			DrawGraph((int)damageNumber[i]->x + 142, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage / 100) % 10], TRUE);
			DrawGraph((int)damageNumber[i]->x + 151, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage / 10) % 10], TRUE);
			DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[damageNumber[i]->damage % 10], TRUE);
		}
	}
}

/*
@brief �_���[�W�̐��l�E���̓^�C�~���O���󂯎��C��������ɉ�ʕ\�����鐔���̓�����ݒ�D�q�b�g�G�t�F�N�g�������ŏ�����
@param isFast ���̓^�C�~���O�������̂��x���̂�
*/
void DamageBeat::addDamage(int valueOfDamage, bool isFast, int EnemyPosX, int EnemyPosY) {
	DamageCharacter* tmpDamage = new DamageCharacter();
	if (valueOfDamage < 0) valueOfDamage = 0;
	tmpDamage->damage = valueOfDamage;
	tmpDamage->x = EnemyPosX;
	tmpDamage->y = EnemyPosY + 80;
	tmpDamage->velY = -2.5 + (GetRand(20) - 10) / 30.0;
	if (isFast) {
		tmpDamage->velX = - (GetRand(5)) / 10.0 - (90 - valueOfDamage) / 180.0;
		tmpDamage->velX = - (90 - valueOfDamage) / 180.0;
	}
	else {
		tmpDamage->velX = GetRand(5) / 10.0 + (90 - valueOfDamage) / 180.0;
		tmpDamage->velX = (90 - valueOfDamage) / 180.0;
	}
	damageNumber.push_back(tmpDamage);
	numberOfDamage++;
	ShowDamageHit = 1;						//�q�b�g�G�t�F�N�g�̐ݒ�
	DamageHitPosX = EnemyPosX + (GetRand(20) - 10) + 151;
	DamageHitPosY = EnemyPosY + (GetRand(20) - 10) + 80;
}

void DamageBeat::calcDamagePos() {
	int i;
	if (GameManager::getIns()->getFpsIns()->isFrameChanged()) {
		for (i = 0; i < numberOfDamage; i++) {
			//�d�͂̎���
			damageNumber[i]->velY += 0.08;
			//�ꏊ�̍X�V
			damageNumber[i]->x += damageNumber[i]->velX;
			damageNumber[i]->y += damageNumber[i]->velY;
			if (damageNumber[i]->y > 180) {						//��ʊO�ɍs������x�N�^�[�������
				damageNumber.erase(damageNumber.begin() + i);
				numberOfDamage--;
			}
		}
	}
}