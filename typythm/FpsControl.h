#pragma once

#include <math.h>
#include "DxLib.h"

class FpsControl {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	const int N = 1200;//平均を取るサンプル数
	const int FPS = 1200;	//設定したFPS

public:
	FpsControl() = default;
	virtual ~FpsControl() = default;
	void FpsControll_Initialize();
	bool Update();
	int getFrameRateNumber();
	bool isFrameChanged();
	void Draw();
	void Wait();
	int FrameCount;
};