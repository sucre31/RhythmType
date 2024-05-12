#include <Dxlib.h>
#include "Enemy.h"
#include "Image.h"
#include "Pad.h"

Enemy::Enemy(int x, int y) {
	myX = x;
	myY = y;
	count = 0;
	reverseFlag = FALSE;
}

bool Enemy::update() {
	return true;
}

void Enemy::draw() const {
	DrawRotaGraph(160 + myX, 90 + myY, 1.0, 0, Image::getIns()->getEnemyBattyImage(), TRUE, reverseFlag);
}

void Enemy::reverse() {
	reverseFlag = !reverseFlag;
}