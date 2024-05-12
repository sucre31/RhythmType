#include "Image.h"

#include "Define.h"

#include <DxLib.h>

Image::Image()
{
    screenHandle = MakeScreen(Define::WIN_W, Define::WIN_H, FALSE);
    SetTransColor(50, 78, 91);
    backImage = myLoadGraph("Assets/Sprites/backImage.png");
    windowImage = myLoadGraph("Assets/Sprites/window.png");
    beltImage = myLoadGraph("Assets/Sprites/belt2.png");
    MrBattyImage = myLoadGraph("Assets/Sprites/Enemy/batty.png");
    LucasBattleImage = myLoadGraph("Assets/Sprites/Lucas/LucasBattle.png");
    myLoadDivGraph("Assets/Sprites/status.png", 80, 10, 8, 8, 8, drumroll);
    myLoadDivGraph("Assets/Sprites/hiragana.png", 90, 10, 9, 7, 7, characterHiragana);
    myLoadDivGraph("Assets/Sprites/katakana.png", 90, 10, 9, 7, 7, characterKatakana);
    myLoadDivGraph("Assets/Sprites/alphaA.png", 90, 10, 9, 7, 7, characterAlphaA);
    myLoadDivGraph("Assets/Sprites/backgroundsA.png", 14, 4, 4, 256, 256, backgroundsA);
}

/*!
@brief ���܂Ń��[�h�����摜���������
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
@brief LoadGraph�����āA�����̃n���h���������o�ϐ��ɒǉ�����
*/
int Image::myLoadGraph(char* fileName)
{
    int ret = LoadGraph(fileName);
    images.push_back(ret);
    return ret;
}

/*!
@brief LoadGraph�����āA�����̃n���h���������o�ϐ��ɒǉ�����
*/
int Image::myLoadGraph(const char* fileName)
{
    int ret = LoadGraph(fileName);
    images.push_back(ret);
    return ret;
}

/*!
@brief LoadDivGraph�����āA�����̃n���h���������o�ϐ��ɒǉ�����
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