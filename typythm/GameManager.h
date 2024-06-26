#pragma once
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager() = default;
	void nextTurn() { nextTurnFlag = true; }
	void minusTurn() { returnTurnFlag = true; }		//基本使わない
	int getTurn() { return TurnNum; };
	void proceedTurn();
private:
	bool nextTurnFlag;
	bool returnTurnFlag;
	int TurnNum;
};

