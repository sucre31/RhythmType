#pragma once

#include <math.h>
#include "DxLib.h"

class FpsControl {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //瞬間のfps
	int rStartTime;         //測定開始時刻
	int rCount;             //カウンタ
	float rFps;				//実際のfps
	const int N = 60;//平均を取るサンプル数
	const int FPS = 1500;	//設定したFPS

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