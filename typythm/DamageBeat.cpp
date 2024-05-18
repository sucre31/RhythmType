#include "DamageBeat.h"
#include <Dxlib.h>
#include "DamageCharacter.h"
#include "Image.h"

DamageBeat::DamageBeat() {
	numberOfDamage = 0;
}

bool DamageBeat::update() {
	calcDamagePos();
	return true;
}

void DamageBeat::draw() const {
	int i;
	for (i = 0; i < numberOfDamage; i++) {
		if (damageNumber[i]->damage < 100) {
			if (damageNumber[i]->damage < 10) {		//ダメージが1桁
				DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[damageNumber[i]->damage], TRUE);
			}
			else {									//ダメージが2桁
				DrawGraph((int)damageNumber[i]->x + 151, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage / 10) % 10], TRUE);
				DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage % 10)], TRUE);
			}
		}
		else {										//ダメージが3桁
			DrawGraph((int)damageNumber[i]->x + 142, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage / 100) % 10], TRUE);
			DrawGraph((int)damageNumber[i]->x + 151, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[(damageNumber[i]->damage / 10) % 10], TRUE);
			DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[damageNumber[i]->damage % 10], TRUE);
		}
	}
}

void DamageBeat::addDamage(int valueOfDamage, int EnemyPosX, int EnemyPosY) {
	DamageCharacter* tmpDamage = new DamageCharacter();
	if (valueOfDamage < 0) valueOfDamage = 0;
	tmpDamage->damage = valueOfDamage;
	tmpDamage->x = EnemyPosX;
	tmpDamage->y = EnemyPosY + 80;
	tmpDamage->velY = -2.5 + (GetRand(20) - 10) / 30.0;
	tmpDamage->velX = (GetRand(20) - 10) / 20.0;
	damageNumber.push_back(tmpDamage);
	numberOfDamage++;
}

void DamageBeat::calcDamagePos() {
	int i;
	for (i = 0; i < numberOfDamage; i++) {
		//重力の実装
		damageNumber[i]->velY += 0.08;
		//場所の更新
		damageNumber[i]->x += damageNumber[i]->velX;
		damageNumber[i]->y += damageNumber[i]->velY;
		if (damageNumber[i]->y > 180) {						//画面外に行ったらベクターから消去
			damageNumber.erase(damageNumber.begin() + i);
			numberOfDamage--;
		}
	}
}