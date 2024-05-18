#pragma once
#include "BeatManager.h"

class Instrument
{
public:
	Instrument() = default;
	~Instrument() = default;
	void playMainInstrument(int NumberOfTone);
	void playSubInstrument(int NumberOfTone);
	void setMyInstrumentNumber(int Number) { myInstrumentNumber = Number; }
	bool playWithStep(int stepNumber, int checkMode);
	//void setBeatManager(BeatManager* beatManagerInstance) { beatManager = beatManagerInstance; }
private:
	int myInstrumentNumber;
	//BeatManager* beatManager;
};

