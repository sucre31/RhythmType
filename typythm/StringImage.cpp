#include "StringImage.h"
#include <string>
#include <Dxlib.h>
#include "Image.h"

using namespace std;


//フォント入れたからいらなくなった

void StringImage::setPos(int x, int y) {
	myX = x;
	myY = y;
}


void StringImage::drawStringToImage(string str) {
	int SpriteNumber;
	SpriteNumber = changeStringToImage('あ');
	DrawGraph(myX, myY, Image::getIns()->getCharacterHiragana()[SpriteNumber], TRUE);
}

void StringImage::drawString() const {

}


/*!
@brief charからintのスプライト番号へ
*/
int StringImage::changeStringToImage(char StrNumber) {
	//ひらがな→カタカナ→アルファベット  40ずつ
	if (StrNumber >= 'あ' && StrNumber <= 'ん') {
		return StrNumber - 'あ';
	}
	return 0;
}