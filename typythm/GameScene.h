#pragma once

#include <memory>
#include "AbstractScene.h"
#include "StatusWindow.h"
#include "BackImage.h"
#include "Enemy.h"

class GameScene : public AbstractScene
{
public:
	const static char* ParameterTagStage;
	const static char* ParameterTagLevel;

	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override;

private:
	int _level;
	void initWindow();
	void setEnemyInstancetToCharacter();
	void initCharacter();
	PlayerCharacter* playerA;
	PlayerCharacter* playerB;
	PlayerCharacter* playerC;
	PlayerCharacter* playerD;
	Enemy* enemyA;
	Enemy* enemyB;
	Enemy* enemyC;
	Enemy* enemyD;
	Enemy* enemyE;
	std::shared_ptr<StatusWindow> _statusWindowA;
	std::shared_ptr<StatusWindow> _statusWindowB;
	std::shared_ptr<StatusWindow> _statusWindowC;
	std::shared_ptr<StatusWindow> _statusWindowD;
	std::shared_ptr<BackImage> _backImage;

};

