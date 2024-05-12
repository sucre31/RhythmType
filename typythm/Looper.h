#pragma once

#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnSceneChangedListener.h"
#include "FpsControl.h"
#include "Define.h"

class Looper final : public IOnSceneChangedListener
{
public:
    Looper();
    ~Looper() = default;
    bool loop() const;
    void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) override;

private:
    int screenRate;
    std::stack<std::shared_ptr<AbstractScene>> _sceneStack; //シーンのスタック
    std::shared_ptr<FpsControl> _fps;
};