#pragma once
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager() = default;
	void plusTurn() { TurnNum++; }
	void minusTurn();		//��{�g��Ȃ�
	int getTurn() { return TurnNum; };
private:
	int TurnNum;
};

