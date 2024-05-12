#pragma once
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager() = default;
	void plusTurn() { TurnNum++; }
	void minusTurn();		//Šî–{Žg‚í‚È‚¢
	int getTurn() { return TurnNum; };
private:
	int TurnNum;
};

