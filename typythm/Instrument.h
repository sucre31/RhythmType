#pragma once
class Instrument
{
public:
	Instrument() = default;
	~Instrument() = default;
	void playMainInstrument(int NumberOfTone);
	void playSubInstrument(int NumberOfTone);
	void setMyInstrumentNumber(int Number) { myInstrumentNumber = Number; }
private:
	int myInstrumentNumber;
};

