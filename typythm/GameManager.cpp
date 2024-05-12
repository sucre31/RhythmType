#include "GameManager.h"

GameManager::GameManager() {
	nextTurnFlag = false;
	returnTurnFlag = false;
}

void GameManager::proceedTurn() {
	if (nextTurnFlag) {
		TurnNum++;
	}
	if (returnTurnFlag) {
		TurnNum--;
	}
	nextTurnFlag = false;
	returnTurnFlag = false;
}