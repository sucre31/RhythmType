#include <Dxlib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager() {
	int i;
	for (i = 0; i < NumberOfEnemy; i++) {

		enemy[i] = new Enemy(-120 + 60 * i, 0);
	}
}

bool EnemyManager::update() {
	for (int i = 0; i < NumberOfEnemy; i++) {
		if (!enemy[i]->getAlive()) {
			WaitTimer(100);	//‘ã‘Ö‚·‚×‚«
			enemy[i]->setNewEnemy(GetRand(2));
		}
		enemy[i]->update();
	}
	return true;
}

void EnemyManager::draw() const {
	for (int i = 0; i < NumberOfEnemy; i++) {
		enemy[i]->draw();
	}
}