#pragma once

#include "GameObject.h"
#include "DamageBeat.h"

enum eEnemy
{
	batty, pig, spider, rocket 
};

class Enemy : public GameObject
{
public:
	Enemy(int x, int y);
	~Enemy() = default;
	bool update() override;
	void draw() const override;
	void setNewEnemy(int EnemyID);
	void getDamage(int valueOfDamage);
	void getSize();
	bool getAlive() const { return alive; }
private:
	int myID;
	int HP;
	int myX, myY;
	int enemyImageX, enemyImageY;
	int BeatedMoveX;
	int count;
	int frameFromBeatTime;
	bool reverseFlag;
	bool isBeated;
	bool alive;
	int screen;
	DamageBeat* damageBeat;
};

