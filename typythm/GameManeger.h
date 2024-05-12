#pragma once
#include "Singleton.h"

class GameManeger : public Singleton<GameManeger>
{
public:
	GameManeger();
	~GameManeger() = default;
	int getTurn() { return TurnNum; };

private:
	int TurnNum;
};

