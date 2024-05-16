#pragma once
#include <Dxlib.h>
#include "GameObject.h"

class BeatManager : public GameObject
{
public:
	BeatManager();
	~BeatManager() = default;
	bool update() override;
	void draw() const override;
	void startMusic(int musicNumber);
	int checkNowScore(int targetStep);
	int getNumberOfStep() const { return numberOfStep;  }
	bool isStepChanged() const { return stepChangeFlag; }
private:
	LONGLONG startTime;
	LONGLONG nowTime;
	LONGLONG timeOfLoopHead;	//128ステップ毎に取得
	double bpm;
	bool stepChangeFlag;
	//int currentTime;
	int numberOfStep;
	int targetTime;
	int activeNumberOfStep;	//現在対象となるステップ(1小節あたり4個)
	int barTime;
	//double timeOfOneStep;
	int deleyTime;
	int nowScore;
};
