#include "TitleScene.h"
#include <DxLib.h>
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    selectNum = 0;
}

void TitleScene::update()
{
    if (Pad::getIns()->get(ePad::up) == 1) {
        selectNum = (selectNum + 2) % 3;
    }
    if (Pad::getIns()->get(ePad::down) == 1) {
        selectNum = ++selectNum % 3;
        return;
    }
    if (Pad::getIns()->get(ePad::A) == 1) {
        Parameter parameter;
        if (selectNum == 0) {
            parameter.set(GameScene::ParameterTagLevel, Define::eMusic::BGM);
        }
        else if (selectNum == 1){
            parameter.set(GameScene::ParameterTagLevel, Define::eMusic::Drum);
        }
        else {
            parameter.set(GameScene::ParameterTagLevel, Define::eMusic::NoBGM);
        }
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }
    if (selectNum == 0) {
        cursorY = 100;
    }
    else if(selectNum == 1) {
        cursorY = 120;
    }
    else {
        cursorY = 140;
    }
}

void TitleScene::draw() const
{

    DrawString(110, 40, "The Snippet", GetColor(255, 255, 255));
    DrawString(110, 100, "play with BGM", GetColor(255, 255, 255));
    DrawString(110, 120, "play with Drum", GetColor(255, 255, 255));
    DrawString(110, 140, "play with No BGM", GetColor(255, 255, 255));
    DrawString(80, cursorY, "Å®", GetColor(255, 255, 255));
}
