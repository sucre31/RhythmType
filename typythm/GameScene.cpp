#include "GameScene.h"
#include <Dxlib.h>
#include "GameManager.h"

using namespace std;

const char* GameScene::ParameterTagStage = "ParameterTagStage";
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter) {
	_level = parameter.get(ParameterTagLevel);
	_statusWindowA = make_shared<StatusWindow>();
	_statusWindowB = make_shared<StatusWindow>();
	_statusWindowC = make_shared<StatusWindow>();
	_statusWindowD = make_shared<StatusWindow>();
	playerA = new PlayerCharacter();
	playerB = new PlayerCharacter();
	playerC = new PlayerCharacter();
	playerD = new PlayerCharacter();
	enemyA = new Enemy(-120, 0);
	enemyB = new Enemy(-60, 0);
	enemyC = new Enemy(0, 0);
	enemyD = new Enemy(60, 0);
	enemyE = new Enemy(120, 0);
	_backImage = make_shared<BackImage>();

	initCharacter();
	setEnemyInstancetToCharacter();
	initWindow();
}

void GameScene::update() {
	playerA->update();
	playerB->update();
	playerC->update();
	playerD->update();
	enemyA->update();
	enemyB->update();
	enemyC->update();
	enemyD->update();
	enemyE->update();
	_statusWindowA->update();
	_statusWindowB->update();
	_statusWindowC->update();
	_statusWindowD->update();
	GameManager::getIns()->proceedTurn();
	_backImage->update();
}

void GameScene::draw() const {
	_backImage->draw();
	playerA->draw();
	playerB->draw();
	playerC->draw();
	playerD->draw();
	enemyA->draw();
	enemyB->draw();
	enemyC->draw();
	enemyD->draw();
	enemyE->draw();
	_statusWindowA->draw();
	_statusWindowB->draw();
	_statusWindowC->draw();
	_statusWindowD->draw();
}

void GameScene::initWindow() {
	_statusWindowA->setPlayerCharacterInstance(playerA);
	_statusWindowB->setPlayerCharacterInstance(playerB);
	_statusWindowC->setPlayerCharacterInstance(playerC);
	_statusWindowD->setPlayerCharacterInstance(playerD);
	_statusWindowA->setWindowPos(0);
	_statusWindowB->setWindowPos(2);
	_statusWindowC->setWindowPos(4);
	_statusWindowD->setWindowPos(6);
	_statusWindowA->setHP(playerA->getHP());
	_statusWindowB->setHP(playerB->getHP());
	_statusWindowC->setHP(playerC->getHP());
	_statusWindowD->setHP(playerD->getHP());
	_statusWindowA->setPP(playerA->getPP());
	_statusWindowB->setPP(playerB->getPP());
	_statusWindowC->setPP(playerC->getPP());
	_statusWindowD->setPP(playerD->getPP());
	_statusWindowA->setName();
	_statusWindowB->setName();
	_statusWindowC->setName();
	_statusWindowD->setName();
}

void GameScene::initCharacter() {
	playerA->setHP(120);
	playerA->setPP(20);
	playerA->setName(0, 41);
	playerA->setName(1, 82);
	playerA->setName(2, 5);
	playerA->setInstrumentNumber(0);
	playerA->setCharacterId(0);
	playerA->setMyTurn(0);
	playerA->setCharacterId(0);
	playerB->setHP(160);
	playerB->setPP(10);
	playerB->setName(0, 7);
	playerB->setName(1, 30);
	playerB->setName(2, 19);
	playerB->setName(3, 40);
	playerB->setMyTurn(3);
	playerB->setInstrumentNumber(1);
	playerB->setCharacterId(1);
	playerC->setHP(250);
	playerC->setPP(70);
	playerC->setName(0, 60);
	playerC->setName(1, 12);
	playerC->setName(2, 15);
	playerC->setName(3, 89);
	playerC->setMyTurn(1);
	playerC->setInstrumentNumber(2);
	playerC->setCharacterId(2);
	playerD->setHP(150);
	playerD->setPP(0);
	playerD->setName(0, 69);
	playerD->setName(1, 21);
	playerD->setName(2, 89);
	playerD->setMyTurn(2);
	playerD->setInstrumentNumber(3);
	playerD->setCharacterId(3);
}

void GameScene::setEnemyInstancetToCharacter() {
	playerA->setEnemyInstance(0, enemyA);
	playerA->setEnemyInstance(1, enemyB);
	playerA->setEnemyInstance(2, enemyC);
	playerA->setEnemyInstance(3, enemyD);
	playerA->setEnemyInstance(4, enemyE);
	playerB->setEnemyInstance(0, enemyA);
	playerB->setEnemyInstance(1, enemyB);
	playerB->setEnemyInstance(2, enemyC);
	playerB->setEnemyInstance(3, enemyD);
	playerB->setEnemyInstance(4, enemyE);
	playerC->setEnemyInstance(0, enemyA);
	playerC->setEnemyInstance(1, enemyB);
	playerC->setEnemyInstance(2, enemyC);
	playerC->setEnemyInstance(3, enemyD);
	playerC->setEnemyInstance(4, enemyE);
	playerD->setEnemyInstance(0, enemyA);
	playerD->setEnemyInstance(1, enemyB);
	playerD->setEnemyInstance(2, enemyC);
	playerD->setEnemyInstance(3, enemyD);
	playerD->setEnemyInstance(4, enemyE);
}