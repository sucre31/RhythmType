#include "StringImage.h"
#include <string>
#include <Dxlib.h>
#include "Image.h"

using namespace std;


//�t�H���g���ꂽ���炢��Ȃ��Ȃ���

void StringImage::setPos(int x, int y) {
	myX = x;
	myY = y;
}


void StringImage::drawStringToImage(string str) {
	int SpriteNumber;
	SpriteNumber = changeStringToImage('��');
	DrawGraph(myX, myY, Image::getIns()->getCharacterHiragana()[SpriteNumber], TRUE);
}

void StringImage::drawString() const {

}


/*!
@brief char����int�̃X�v���C�g�ԍ���
*/
int StringImage::changeStringToImage(char StrNumber) {
	//�Ђ炪�ȁ��J�^�J�i���A���t�@�x�b�g  40����
	if (StrNumber >= '��' && StrNumber <= '��') {
		return StrNumber - '��';
	}
	return 0;
}