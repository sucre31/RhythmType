#pragma once

#include <math.h>
#include "DxLib.h"

class FpsControl {
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	const int N = 1200;//���ς����T���v����
	const int FPS = 1200;	//�ݒ肵��FPS

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