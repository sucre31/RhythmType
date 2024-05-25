#include <Dxlib.h>
#include "Enemy.h"
#include "Image.h"
#include "Pad.h"
#include "Define.h"
#include "Sound.h"
#include "GameManager.h"

Enemy::Enemy(int x, int y) {
	myX = x;
	myY = y;
	HP = 1000;
	myID = 1;
	alive = true;
	count = 0;
	BeatedMoveX = 0;
	reverseFlag = false;
	isBeated = false;
	damageBeat = new DamageBeat();
	getSize();
	screen = MakeScreen(enemyImageX,enemyImageY, TRUE);
}

bool Enemy::update() {
	if (isBeated) {
		if (GameManager::getIns()->getFpsIns()->isFrameChanged()) {
			BeatedMoveX = (int)(5 * sin(Define::PI * (frameFromBeatTime / 4.0)));

			if (frameFromBeatTime == 16) {
				BeatedMoveX = 0;
				isBeated = false;
				frameFromBeatTime = 0;
			}
			else {
				frameFromBeatTime++;
			}
		}
	}

	if (HP < 0 && alive) {
		alive = false;
		PlaySoundMem(Sound::getIns()->getBattleSE()[3], DX_PLAYTYPE_BACK);
	}
	damageBeat->update();
	return true;
}
	
void Enemy::draw() const {
	if (!alive) {
		SetDrawScreen(screen);
		ClearDrawScreen;
		DrawGraph(0, 0, Image::getIns()->getEnemyImage()[myID], TRUE);
		GraphFilter(screen, DX_GRAPH_FILTER_HSB, 0, 0, 0, 255);
		SetDrawScreen(Image::getIns()->getScreenHandle());
		DrawRotaGraph(160 + myX + BeatedMoveX, 90 + myY, 1.0, 0, screen, TRUE, reverseFlag);
	}
	else {
		DrawRotaGraph(160 + myX + BeatedMoveX, 90 + myY, 1.0, 0, Image::getIns()->getEnemyImage()[myID], TRUE, reverseFlag);
	}
	damageBeat->draw();
}

void Enemy::getSize() {
	GetGraphSize(Image::getIns()->getEnemyImage()[myID], &enemyImageX, &enemyImageY);
}

void Enemy::setNewEnemy(int EnemyID) {
	myID = EnemyID;
	HP = 1000;
	alive = true;
	DeleteGraph(screen);
	getSize();
	screen = MakeScreen(enemyImageX, enemyImageY, TRUE);
}

void Enemy::getDamage(int valueOfDamage) {
	reverseFlag = !reverseFlag;
	HP -= valueOfDamage;
	isBeated = true;
	frameFromBeatTime = 0;
	damageBeat->addDamage(valueOfDamage, myX, myY);
}

