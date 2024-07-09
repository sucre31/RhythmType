#include <math.h>
#include "DxLib.h"
#include "FpsControl.h"
#include "BeatManager.h"

void FpsControl::FpsControll_Initialize() {
	mStartTime = GetNowCount();
	mCount = 0;
	mFps = 0;
}

bool FpsControl::Update(){
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	if (rCount == FPS) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		rFps = 1000.f / ((t - rStartTime) / (float)FPS);
		rCount = 0;
		rStartTime = t;
	}
	rCount++;
	mCount++;
	FrameCount++;
	return true; 
}

void FpsControl::Draw(){
	DrawFormatString(280, 10, GetColor(255, 255, 255), "%.1f", rFps / 25);
}

int FpsControl::getFrameRateNumber() {
	return FrameCount / 25;
}

bool FpsControl::isFrameChanged() {
	if ((int)(mFps / 60) == 0) {
		return false;
	}
	return (FrameCount % (int)(mFps / 60) == 0);
}

void FpsControl::Wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

