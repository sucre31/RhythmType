#include "Pad.h"
#include <DxLib.h>
#include "Keyboard.h"
#include "Define.h"
#include <string>
#include <algorithm>

using namespace std;

Pad::Pad()
{
    SetJoypadDeadZone(DX_INPUT_PAD1, 0.5);
    _idArray[ePad::down] = 0;
    _idArray[ePad::left] = 1;
    _idArray[ePad::right] = 2;
    _idArray[ePad::up] = 3;
    _idArray[ePad::A] = 5;
    _idArray[ePad::B] = 4;
    _idArray[ePad::X] = 7;
    _idArray[ePad::Y] = 6;
    _idArray[ePad::L] = 8;
    _idArray[ePad::R] = 9;
    _idArray[ePad::start] = 13;
    _idArray[ePad::change] = 12;
}

void Pad::update() {
    int padInput;
    padInput = GetJoypadInputState(DX_INPUT_PAD1);//パッドの入力状態を取得
    for (int i = 0; i < 16; i++) {
        if (padInput & (1 << i)) {
            _pad[i]++;
        }
        else {
            _pad[i] = 0;
        }
    }
    merge();
}

/*!
@brief パッドと、それに対応するキーボードの入力状態をマージする
*/
void Pad::merge() {
    _pad[_idArray[ePad::down]] = max(_pad[_idArray[ePad::down]], Keyboard::getIns()->getPressingCount(KEY_INPUT_DOWN));
    _pad[_idArray[ePad::left]] = max(_pad[_idArray[ePad::left]], Keyboard::getIns()->getPressingCount(KEY_INPUT_LEFT));
    _pad[_idArray[ePad::right]] = max(_pad[_idArray[ePad::right]], Keyboard::getIns()->getPressingCount(KEY_INPUT_RIGHT));
    _pad[_idArray[ePad::up]] = max(_pad[_idArray[ePad::up]], Keyboard::getIns()->getPressingCount(KEY_INPUT_UP));
    _pad[_idArray[ePad::A]] = max(_pad[_idArray[ePad::A]], Keyboard::getIns()->getPressingCount(KEY_INPUT_Z));
    _pad[_idArray[ePad::B]] = max(_pad[_idArray[ePad::B]], Keyboard::getIns()->getPressingCount(KEY_INPUT_X));
    _pad[_idArray[ePad::X]] = max(_pad[_idArray[ePad::X]], Keyboard::getIns()->getPressingCount(KEY_INPUT_A));
    _pad[_idArray[ePad::Y]] = max(_pad[_idArray[ePad::Y]], Keyboard::getIns()->getPressingCount(KEY_INPUT_C));
    _pad[_idArray[ePad::L]] = max(_pad[_idArray[ePad::L]], Keyboard::getIns()->getPressingCount(KEY_INPUT_LSHIFT));
    _pad[_idArray[ePad::R]] = max(_pad[_idArray[ePad::R]], Keyboard::getIns()->getPressingCount(KEY_INPUT_S));
    _pad[_idArray[ePad::start]] = max(_pad[_idArray[ePad::start]], Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN));
    _pad[_idArray[ePad::change]] = max(_pad[_idArray[ePad::change]], Keyboard::getIns()->getPressingCount(KEY_INPUT_BACK));
}

/*!
@brief 渡されたパッドキー番号の入力フレーム数を返す
*/
int Pad::get(ePad eID) const
{
    return _pad[_idArray[eID]];
}