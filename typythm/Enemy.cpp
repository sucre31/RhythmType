#include <Dxlib.h>
#include "Enemy.h"
#include "Image.h"
#include "Pad.h"
#include "Define.h"

Enemy::Enemy(int x, int y) {
	myX = x;
	myY = y;
	count = 0;
	BeatedMoveX = 0;
	reverseFlag = false;
	isBeated = false;
	damageBeat = new DamageBeat();
}

bool Enemy::update() {
	if (isBeated) {
		
		BeatedMoveX = (int)(5 * sin(Define::PI *( frameFromBeatTime / 4.0)));

		if (frameFromBeatTime == 16) {
			BeatedMoveX = 0;
			isBeated = false;
			frameFromBeatTime = 0;
		}
		else {
			frameFromBeatTime++;
		}
	}
	damageBeat->update();
	return true;
}
	
void Enemy::draw() const {
	DrawRotaGraph(160 + myX + BeatedMoveX, 90 + myY, 1.0, 0, Image::getIns()->getEnemyBattyImage(), TRUE, reverseFlag);
	damageBeat->draw();
}

void Enemy::getDamage(int valueOfDamage) {
	reverseFlag = !reverseFlag;
	isBeated = true;
	frameFromBeatTime = 0;
	damageBeat->addDamage(valueOfDamage, myX, myY);
}