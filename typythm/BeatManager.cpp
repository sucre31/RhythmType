#include "BeatManager.h"
#include "Sound.h"

BeatManager::BeatManager() {
	bpm = 165;
	//currentTime = 0;
	startTime = GetNowHiPerformanceCount();
	//timeOfOneStep = (60000 / bpm / 4);		//Ç∏ÇÍÇ‹Ç≠ÇÈÅ@Ç»Ç®Ç¡ÇΩÅAÇ∆Ç¢Ç§Ç©å¥ã»ÇÃbpmÇ™à·Ç¡ÇΩ
	deleyTime = (int)((60000 / bpm / 4) / 2);
	targetTime = 0;
	//activeNumberOfStep = 0;
	nowScore = 0;
	nowScore = -1;
	timeOfLoopHead = 0;
	stepChangeFlag = false;
	numberOfStep = -1;
}

bool BeatManager::update() {
	int tmpStep;
	nowTime = GetNowHiPerformanceCount();
	//currentTime = (int)((nowTime - startTime) / 1000);
	//tmpStep = (int)(((nowTime - startTime) / 1000) / (15000 / bpm));
	tmpStep = (int)(((nowTime - startTime) / 1000.0) / (15000 / bpm));
	if (numberOfStep != tmpStep){
		stepChangeFlag = true;
		numberOfStep = tmpStep;
		if (numberOfStep % 128 == 0) {
			timeOfLoopHead = GetNowHiPerformanceCount();
		}
	}
	else {
		stepChangeFlag = false;
	}
	//activeNumberOfStep = (int) ((currentTime + deleyTime)/ timeOfOneStep);
	//if (activeNumberOfStep < 1) activeNumberOfStep = 1;
	return true;
}

void BeatManager::draw() const{
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", numberOfStep);
	//DrawFormatString(100, 0, GetColor(255, 255, 255), "%f", (((nowTime - startTime) / 1000) / (15000 / bpm)));
	//DrawFormatString(0, 10, GetColor(255, 255, 255), "%d", activeNumberOfStep);
	//DrawFormatString(40, 0, GetColor(255, 255, 255), "%d", nowScore);
}

void BeatManager::startMusic(int musicNumber) {
	PlaySoundMem(Sound::getIns()->getBackgroundMusic()[musicNumber], DX_PLAYTYPE_BACK);
	startTime = GetNowHiPerformanceCount();
	timeOfLoopHead = GetNowHiPerformanceCount();
}

int BeatManager::checkNowScore(int targetStep) {
	targetStep = targetStep % 128;
	targetTime = ((int)((60000 / bpm / 4) * targetStep) % (int)((60000 / bpm / 4) * 128));
	if (abs(((nowTime - startTime) / 1000) - targetTime) < (deleyTime * 2)) {
		return (int)abs(((nowTime - startTime) / 1000) - targetTime);
	}
	return -1;
}