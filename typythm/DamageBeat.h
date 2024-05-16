#pragma once
#include "GameObject.h"
#include "DamageCharacter.h"
#include <vector>
class DamageBeat : GameObject
{
public:
	DamageBeat();
	~DamageBeat() = default;
	bool update() override;
	void draw() const override;
	void addDamage(int valueOfDamage, int EnemyPosX, int EnemyPosY);
	void calcDamagePos();
private:
	int numberOfDamage;
	std::vector<DamageCharacter*> damageNumber;
};

