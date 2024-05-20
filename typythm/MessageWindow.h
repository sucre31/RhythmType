#pragma once
#include <memory>
#include "GameObject.h"
//#include "StringImage.h"

class MessageWindow : GameObject
{
public:
	MessageWindow();
	~MessageWindow() = default;
	bool update() override;
	void draw() const override;
private:
	//std::string strBattleMessage[4];
	//std::shared_ptr<StringImage> stringImage;
	int currentTurn;
	int messageCounter;
	int myX, myY;
	bool messageFlag;
};

