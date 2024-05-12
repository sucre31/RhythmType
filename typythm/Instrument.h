#pragma once
class Instrument
{
public:
	Instrument() = default;
	~Instrument() = default;
	void playInstrument(int NumberOfBar);
	void setMyInstrumentNumber(int Number) { myInstrumentNumber = Number; }
private:
	int myInstrumentNumber;
};

