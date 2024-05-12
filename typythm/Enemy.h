#pragma once

#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy(int x, int y);
	~Enemy() = default;
	bool update() override;
	void draw() const override;
	void reverse();
private:
	int enemyID;
	int HP;
	int myX, myY;
	int count;
	bool reverseFlag;
};

