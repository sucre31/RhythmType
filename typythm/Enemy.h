#pragma once

#include "GameObject.h"
#include "DamageBeat.h"
class Enemy : public GameObject
{
public:
	Enemy(int x, int y);
	~Enemy() = default;
	bool update() override;
	void draw() const override;
	void getDamage(int valueOfDamage);
	bool getAlive() const { return alive; }
private:
	int enemyID;
	int HP;
	int myX, myY;
	int BeatedMoveX;
	int count;
	int frameFromBeatTime;
	bool reverseFlag;
	bool isBeated;
	bool alive;
	int screen;
	DamageBeat* damageBeat;
};

