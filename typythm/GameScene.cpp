#include "GameScene.h"
#include <Dxlib.h>
#include "GameManager.h"
#include "Sound.h"
#include "Pad.h"
#include "GameManager.h"

using namespace std;

const char* GameScene::ParameterTagStage = "ParameterTagStage";
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter) {
	
	musicNumber = parameter.get(ParameterTagLevel);
	_statusWindowA = make_shared<StatusWindow>();
	_statusWindowB = make_shared<StatusWindow>();
	_statusWindowC = make_shared<StatusWindow>();
	_statusWindowD = make_shared<StatusWindow>();
	messageWindow = new MessageWindow();
	playerA = new PlayerCharacter();
	playerB = new PlayerCharacter();
	playerC = new PlayerCharacter();
	playerD = new PlayerCharacter();
	enemyManager = new EnemyManager();
	_backImage = make_shared<BackImage>();
	beatManager = new BeatManager();

	initCharacter();
	setEnemyInstancetToCharacter();
	initWindow();
	beatManager->startMusic(musicNumber);
}

void GameScene::update() {
	beatManager->update();
	GameManager::getIns()->proceedTurn();
	playerA->update();
	playerB->update();
	playerC->update();
	playerD->update();
	enemyManager->update();
	_statusWindowA->update();
	_statusWindowB->update();
	_statusWindowC->update();
	_statusWindowD->update();
	messageWindow->update();
	_backImage->update();
	if (Pad::getIns()->get(ePad::start) == 1) {
		Parameter parameter;
		const bool stackClear = true;
		StopSoundMem(Sound::getIns()->getBackgroundMusic()[musicNumber]);
		GameManager::getIns()->initBattle();
		_implSceneChanged->onSceneChanged(eScene::Title, parameter, stackClear);
	}
}

void GameScene::draw() const {
	_backImage->draw();
	beatManager->draw();
	playerA->draw();
	playerB->draw();
	playerC->draw();
	playerD->draw();
	_statusWindowA->draw();
	_statusWindowB->draw();
	_statusWindowC->draw();
	_statusWindowD->draw();
	messageWindow->draw();
	enemyManager->draw();

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
	playerA->setPP(00);
	playerA->setName(0, 41);
	playerA->setName(1, 82);
	playerA->setName(2, 5);
	playerA->setInstrumentNumber(0);
	playerA->setCharacterId(0);
	playerA->setMyTurn(0);
	playerA->setCharacterId(0);
	playerA->setMessageWindow(messageWindow);
	playerB->setHP(160);
	playerB->setPP(0);
	playerB->setName(0, 7);
	playerB->setName(1, 30);
	playerB->setName(2, 19);
	playerB->setName(3, 40);
	playerB->setMyTurn(3);
	playerB->setInstrumentNumber(1);
	playerB->setCharacterId(1);
	playerB->setMessageWindow(messageWindow);
	playerC->setHP(250);
	playerC->setPP(0);
	playerC->setName(0, 60);
	playerC->setName(1, 12);
	playerC->setName(2, 15);
	playerC->setName(3, 89);
	playerC->setMyTurn(1);
	playerC->setInstrumentNumber(2);
	playerC->setCharacterId(2);
	playerC->setMessageWindow(messageWindow);
	playerD->setHP(150);
	playerD->setPP(0);
	playerD->setName(0, 69);
	playerD->setName(1, 21);
	playerD->setName(2, 89);
	playerD->setMyTurn(2);
	playerD->setInstrumentNumber(3);
	playerD->setCharacterId(3);
	playerD->setMessageWindow(messageWindow);
}

void GameScene::setEnemyInstancetToCharacter() {
	playerA->setBeatManager(beatManager);
	playerA->setEnemyManagerInstance(enemyManager);
	playerB->setBeatManager(beatManager);
	playerB->setEnemyManagerInstance(enemyManager);
	playerC->setBeatManager(beatManager);
	playerC->setEnemyManagerInstance(enemyManager);
	playerD->setBeatManager(beatManager);
	playerD->setEnemyManagerInstance(enemyManager);
}