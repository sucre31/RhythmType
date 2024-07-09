#include <Dxlib.h>
#include "BeatManager.h"
#include "Sound.h"


BeatManager::BeatManager() {
	bpm = 165;
	//currentTime = 0;
	startTime = GetNowHiPerformanceCount();
	//timeOfOneStep = (60000 / bpm / 4);		//ずれまくる　なおった、というか原曲のbpmが違った
	deleyTime = (int)((60000 / bpm / 4) / 2);
	targetTime = 0;
	//activeNumberOfStep = 0;
	//timeOfLoopHead = 0;
	stepChangeFlag = false;
	numberOfStep = -1;
	currentScore = 1;
	//WaitTime = 0;
	//StepScore = 0;
}

bool BeatManager::update() {
	int tmpStep;
	//WaitTime = 0;
	//waitForNext();
	nowTime = GetNowHiPerformanceCount();
	//currentTime = (int)((nowTime - startTime) / 1000);
	//tmpStep = (int)(((nowTime - startTime) / 1000) / (15000 / bpm));
	tmpStep = (int)(((nowTime - startTime) / 1000.0) / (15000 / bpm));
	if (numberOfStep != tmpStep){
		stepChangeFlag = true;
		numberOfStep = tmpStep;
		//if (numberOfStep % 128 == 0) {
		//	timeOfLoopHead = GetNowHiPerformanceCount();
		//}
	}
	else {
		stepChangeFlag = false;
	}
	checkNowScore(numberOfStep);
	//activeNumberOfStep = (int) ((currentTime + deleyTime)/ timeOfOneStep);
	//if (activeNumberOfStep < 1) activeNumberOfStep = 1;

	return true;
}

void BeatManager::draw() const{
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", numberOfStep);
	//DrawFormatString(100, 0, GetColor(255, 255, 255), "%f", (((nowTime - startTime) / 1000) / (15000 / bpm)));
	//DrawFormatString(0, 10, GetColor(255, 255, 255), "%d", activeNumberOfStep);
	if (isBeatEarly) {
		DrawFormatString(40 + currentScore, 10, GetColor(255, 255, 0), "%d", currentScore);
	}
	else {
		DrawFormatString(40 + currentScore, 10, GetColor(0, 255, 255), "%d", currentScore);
	}
	//if (WaitTime != 0) DrawFormatString(200, 10, GetColor(255, 255, 255), "%d", WaitTime);
}

void BeatManager::startMusic(int musicNumber) {
	if (musicNumber < 2) PlaySoundMem(Sound::getIns()->getBackgroundMusic()[musicNumber], DX_PLAYTYPE_BACK);
	startTime = GetNowHiPerformanceCount();
	//timeOfLoopHead = GetNowHiPerformanceCount();
}

/*!
@brief　目的のステップと現在の時間との差から点数(ダメージ)を算出
@param targetStep 判定するステップ
*/
int BeatManager::checkNowScore(int targetStep) {
	int tmpScore;
	//targetStep = targetStep % 128;
	//targetTime = ((int)((60000 / bpm / 4) * targetStep) % (int)((60000 / bpm / 4) * 128));
	//targetStep = targetStep;
	targetTime = ((int)((60000 / bpm / 4) * targetStep) );
	tmpScore = ((nowTime - startTime) / 1000) - targetTime;
	if (abs(tmpScore) < (deleyTime * 8)) {
		//currentScore = 80 - (int)abs(tmpScore) * 2;
		//currentScore = 80 - 21 * log10(fabs(tmpScore) + 1) + (GetRand(20) - 10);
		currentScore = 80 - 40 * log10(fabs(tmpScore) + 1) + (GetRand(20) - 10);;
		if (tmpScore < 0) {
			isBeatEarly = true;
		}
		else {
			isBeatEarly = false;
		}
		if (currentScore < 0) currentScore = 1;
		return currentScore;
	}
	currentScore = -30;
	return -1;
}



///*!
//@brief　次のビートまでの時間を算出
//*/
//int BeatManager::checkTimeNext() {
//	targetTime = ((int)((60000 / bpm / 4) * (numberOfStep + 1)));
//	return targetTime - ((nowTime - startTime) / 1000);
//}
//
//void BeatManager::waitForNext() {
//	int cotmpTime = checkTimeNext();
//	if ((cotmpTime < 20) && (cotmpTime > 15)) {
//		WaitTime = cotmpTime;
//		//Sleep(cotmpTime - 15);
//	}
//}
