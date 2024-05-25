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
	//int checkTimeNext();
	//void waitForNext();
	bool isStepChanged() const { return stepChangeFlag; }
private:
	LONGLONG startTime;
	LONGLONG nowTime;
	// timeOfLoopHead;	//128�X�e�b�v���Ɏ擾
	double bpm;
	bool stepChangeFlag;
	//int currentTime;
	int numberOfStep;
	int targetTime;
	//int activeNumberOfStep;	//���ݑΏۂƂȂ�X�e�b�v(1���߂�����4��)
	int barTime;
	//double timeOfOneStep;
	int deleyTime;
	int currentScore;
	//int WaitTime;			//�f�o�b�O�p
	//int StepScore;			//�f�o�b�O�p
	bool isBeatEarly;
};
