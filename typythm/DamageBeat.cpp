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

/*
@brief ダメージの数値・入力タイミングを受け取り，それを元に画面表示する数字の動きを設定．ヒットエフェクトもここで初期化
@param isFast 入力タイミングが速いのか遅いのか
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
	ShowDamageHit = 1;						//ヒットエフェクトの設定
	DamageHitPosX = EnemyPosX + (GetRand(20) - 10) + 151;
	DamageHitPosY = EnemyPosY + (GetRand(20) - 10) + 80;
}

void DamageBeat::calcDamagePos() {
	int i;
	if (GameManager::getIns()->getFpsIns()->isFrameChanged()) {
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
}