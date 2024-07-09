#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    ChangeFont("Mother3Message");
    SetFontSpace(1);
    SetFontSize(9);
    SetFontThickness(1);
    selectNum = 0;
}

void TitleScene::update()
{
    if (Pad::getIns()->get(ePad::up) == 1) {
        selectNum = (selectNum + 3) % 4;
        StartJoypadVibration(DX_INPUT_PAD1, 1000, 2000, 0);
    }
    if (Pad::getIns()->get(ePad::down) == 1) {
        selectNum = ++selectNum % 4;
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
        else if (selectNum == 2) {
            parameter.set(GameScene::ParameterTagLevel, Define::eMusic::NoBGM);
        }
        else {
            //quit
            DxLib_End();
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
    else if (selectNum == 2) {
        cursorY = 140;
    }
    else {
        cursorY = 160;
    }
}

void TitleScene::draw() const
{

    DrawString(110, 40, "The Snippet", GetColor(255, 255, 255));
    DrawString(110, 100, "play with BGM", GetColor(255, 255, 255));
    DrawString(110, 120, "play with Drum", GetColor(255, 255, 255));
    DrawString(110, 140, "play with No BGM", GetColor(255, 255, 255));
    DrawString(110, 160, "quit", GetColor(255, 255, 255));
    DrawString(80, cursorY, "ÅE", GetColor(255, 255, 255));
}
