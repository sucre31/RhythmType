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
		DrawGraph((int)damageNumber[i]->x + 160, (int)damageNumber[i]->y, Image::getIns()->getBattleCharacter()[0], TRUE);
	}
}

void DamageBeat::addDamage(int valueOfDamage, int EnemyPosX, int EnemyPosY) {
	DamageCharacter* tmpDamage = new DamageCharacter();
	tmpDamage->damage = valueOfDamage;
	tmpDamage->x = EnemyPosX;
	tmpDamage->y = EnemyPosY + 80;
	tmpDamage->velY = -2.5;
	tmpDamage->velX = (GetRand(20) - 10) / 20.0;
	damageNumber.push_back(tmpDamage);
	numberOfDamage++;
}

void DamageBeat::calcDamagePos() {
	int i;
	for (i = 0; i < numberOfDamage; i++) {
		//d—Í‚ÌŽÀ‘•
		damageNumber[i]->velY += 0.08;
		//êŠ‚ÌXV
		damageNumber[i]->x += damageNumber[i]->velX;
		damageNumber[i]->y += damageNumber[i]->velY;
		if (damageNumber[i]->y > 180) {
			damageNumber.erase(damageNumber.begin() + i);
			numberOfDamage--;
		}
	}
}