#pragma once
#include "GameObject.h"
#include "Enemy.h"

class EnemyManager : GameObject
{
public:
	EnemyManager();
	~EnemyManager() = default;
	bool update() override;
	void draw() const override;
	void drawSecond() const;
	Enemy* getEnemyIns(int num) { return enemy[num]; }
private:
	static const int NumberOfEnemy = 8;
	static const int NumberOfKind = 5;
	Enemy* enemy[NumberOfEnemy];
};

