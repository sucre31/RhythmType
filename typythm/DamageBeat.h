#pragma once
#include <vector>
#include "GameObject.h"
#include "DamageCharacter.h"
class DamageBeat : GameObject
{
public:
	DamageBeat();
	~DamageBeat() = default;
	bool update() override;
	void draw() const override;
	void addDamage(int valueOfDamage, bool isFast, int EnemyPosX, int EnemyPosY);
	void calcDamagePos();
private:
	int numberOfDamage;
	int ShowDamageHit;				//ボタンが押されたときのヒットエフェクト 0はださない
	int DamageHitPosX;
	int DamageHitPosY;
	std::vector<DamageCharacter*> damageNumber;
};

