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
	int ShowDamageHit;				//�{�^���������ꂽ�Ƃ��̃q�b�g�G�t�F�N�g 0�͂����Ȃ�
	int DamageHitPosX;
	int DamageHitPosY;
	std::vector<DamageCharacter*> damageNumber;
};

