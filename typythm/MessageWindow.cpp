#include "MessageWindow.h"
#include <Dxlib.h>
#include <string>
#include "Image.h"
#include "GameManager.h"

using namespace std;

MessageWindow::MessageWindow() {
	myX = 47;
	myY = 2;
	currentTurn = 0;
	messageCounter = 32;
	messageFlag = false;
	//stringImage = make_shared<StringImage>();
	//stringImage->setPos(myX + 4, myY + 4);
	//strBattleMessage[0] = "ああ";
}

bool MessageWindow::update() {
	messageCounter++;
	if (currentTurn != GameManager::getIns()->getTurn()) {
		messageCounter = 0;
		messageFlag = true;
		currentMessageID = currentTurn % 4;
	}
	if (messageCounter > 30) messageFlag = false;
	return true;
}

void MessageWindow::draw() const{
	if (messageFlag) {
		switch (currentMessageID) {
		case 0:
			DrawGraph(myX, myY, Image::getIns()->getMessageWindow(), TRUE);
			DrawString(myX + 6, myY + 9, "リュカの こうげき!", GetColor(0, 0, 0));
			break;
		case 1:
			DrawGraph(myX, myY, Image::getIns()->getMessageWindow(), TRUE);
			DrawString(myX + 6, myY + 9, "クマトラの こうげき!", GetColor(0, 0, 0));
			break;
		case 2:
			DrawGraph(myX, myY, Image::getIns()->getMessageWindow(), TRUE);
			DrawString(myX + 6, myY + 9, "ダスターの こうげき!", GetColor(0, 0, 0));
			break;
		case 3:
			DrawGraph(myX, myY, Image::getIns()->getMessageWindow(), TRUE);
			DrawString(myX + 6, myY + 9, "ボニーの こうげき!", GetColor(0, 0, 0));
			break;
		}
	}
}

void MessageWindow::setMessage(int ID) {
	currentMessageID = ID;
	messageCounter = 0;
	messageFlag = true;
}