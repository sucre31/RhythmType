#include "Looper.h"
#include "TitleScene.h"
#include "Error.h"
#include "GameScene.h"
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Image.h"
#include "GameManager.h"

using namespace std;

Looper::Looper()
{
    screenRate = Define::WIN_EX;

    Image::getIns()->load();

    Parameter parameter;
    //_fps = make_shared<FpsControl>();
    _sceneStack.push(make_shared<TitleScene>(this, parameter)); //タイトル画面シーンを作ってpush
    _fps = new FpsControl();
    GameManager::getIns()->setFpsIns(_fps);
}
/*!
@brief スタックのトップのシーンの処理をする
*/
bool Looper::loop() const
{
    SetDrawScreen(Image::getIns()->getScreenHandle());
    ClearDrawScreen();

    Keyboard::getIns()->update();   //キーボードの更新
    Pad::getIns()->update();        //ジョイパッドの更新
    _sceneStack.top()->update();    //スタックのトップのシーンを更新
    _sceneStack.top()->draw();      //スタックのトップのシーンを描画
    _fps->Update();
    _fps->Draw();
    _fps->Wait();

    //最後に画面の倍率に合わせて描画
    SetDrawScreen(DX_SCREEN_BACK);
    DrawExtendGraph(0, 0, (Define::WIN_W * screenRate), (Define::WIN_H * screenRate), Image::getIns()->getScreenHandle(), FALSE);
    return true;
}

/*!
@brief シーン変更(各シーンからコールバックされる)
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
    if (stackClear) {
        while (!_sceneStack.empty()) {
            _sceneStack.pop();
        }
    }
    switch (scene) {
    case Title:
        _sceneStack.push(make_shared<TitleScene>(this, parameter));
        break;
    case Game:
        _sceneStack.push(make_shared<GameScene>(this, parameter));
        break;
    default:
        ERR("存在しないシーン");
        break;
    }
}
