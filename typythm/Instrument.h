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
	void playWithStep(int stepNumber);
	//void setBeatManager(BeatManager* beatManagerInstance) { beatManager = beatManagerInstance; }
private:
	int myInstrumentNumber;
	//BeatManager* beatManager;
};

