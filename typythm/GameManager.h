#pragma once
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager() = default;
	void nextTurn() { nextTurnFlag = true; }
	void minusTurn() { returnTurnFlag = true; }		//Šî–{Žg‚í‚È‚¢
	int getTurn() { return TurnNum; };
	void proceedTurn();
	void initBattle() { TurnNum = 0;}
private:
	bool nextTurnFlag;
	bool returnTurnFlag;
	int TurnNum;
};

