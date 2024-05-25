#include "Image.h"

#include "Define.h"

#include <DxLib.h>

Image::Image()
{
    screenHandle = MakeScreen(Define::WIN_W, Define::WIN_H, FALSE);
    SetTransColor(50, 78, 91);
    backImage = myLoadGraph("Assets/Sprites/backImage.png");
    windowImage = myLoadGraph("Assets/Sprites/window.png");
    beltImage = myLoadGraph("Assets/Sprites/belt.png");
    beltImage2 = myLoadGraph("Assets/Sprites/belt2.png");
    EnemyImage[0] = myLoadGraph("Assets/Sprites/Enemy/batty.png");
    EnemyImage[1] = myLoadGraph("Assets/Sprites/Enemy/PigMask.png");
    EnemyImage[2] = myLoadGraph("Assets/Sprites/Enemy/Spider!.png");
    LucasBattleImage = myLoadGraph("Assets/Sprites/Lucas/LucasBattle.png");
    BoneyBattleImage = myLoadGraph("Assets/Sprites/Boney/BoneyBattle.png");
    KumatoraBattleImage = myLoadGraph("Assets/Sprites/Kumatora/KumatoraBattle.png");
    DusterBattleImage = myLoadGraph("Assets/Sprites/Duster/DusterBattle.png");
    MessageWindow = myLoadGraph("Assets/Sprites/Battle/Message.png");
    myLoadDivGraph("Assets/Sprites/status.png", 80, 10, 8, 8, 8, drumroll);
    myLoadDivGraph("Assets/Sprites/hiragana.png", 90, 10, 9, 7, 7, characterHiragana);
    myLoadDivGraph("Assets/Sprites/katakana.png", 90, 10, 9, 7, 7, characterKatakana);
    myLoadDivGraph("Assets/Sprites/alphaA.png", 90, 10, 9, 7, 7, characterAlphaA);
    myLoadDivGraph("Assets/Sprites/Battle/Number.png", 30, 10, 3, 16, 16, battleCharacter);
    myLoadDivGraph("Assets/Sprites/backgroundsA.png", 14, 4, 4, 256, 256, backgroundsA);

}


int Image::getCharacterBattleImage(int characterNumber) const{
    switch (characterNumber) {
    case 0:
        return LucasBattleImage;
    case 1:
        return KumatoraBattleImage;
    case 2:
        return DusterBattleImage;
    case 3:
        return BoneyBattleImage;
    }
    return LucasBattleImage;
}

/*!
@brief 今までロードした画像を解放する
*/
void Image::release()
{
    const int size = images.size();
    for (int i = 0; i < size; i++) {
        DeleteGraph(images[i]);
    }
    images.clear();
}


/*!
@brief LoadGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadGraph(char* fileName)
{
    int ret = LoadGraph(fileName);
    images.push_back(ret);
    return ret;
}

/*!
@brief LoadGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadGraph(const char* fileName)
{
    int ret = LoadGraph(fileName);
    images.push_back(ret);
    return ret;
}

/*!
@brief LoadDivGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadDivGraph(char* fileName, int n, int xn, int yn, int w, int h, int* buf)
{
    int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
    for (int i = 0; i < n; i++) {
        images.push_back(buf[i]);
    }
    return ret;
}

int Image::myLoadDivGraph(const char* fileName, int n, int xn, int yn, int w, int h, int* buf)
{
    int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
    for (int i = 0; i < n; i++) {
        images.push_back(buf[i]);
    }
    return ret;
}