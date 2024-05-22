#pragma once

#include "Singleton.h"
#include <vector>

class Sound final : public Singleton<Sound>
{
public:
	Sound();
	~Sound() = default;
	void load() {};
	void release();
	const int* getLucasBattleSounds() { return lucasBattleSounds; }
	const int* getDusterBattleSounds() { return dusterBattleSounds; }
	const int* getBoneyBattleSounds() { return boneyBattleSounds; }
	const int* getKumatoraBattleSounds() { return kumatoraBattleSounds; }
	const int* getBattleSE() { return BattleSE; }
	const int* getBackgroundMusic() { return BackgroundMusic; }

private:
	int myLoadSoundMem(char*);
	int myLoadSoundMem(const char*);
	std::vector<int> sounds;
	int lucasBattleSounds[24];
	int dusterBattleSounds[10];
	int boneyBattleSounds[8];
	int kumatoraBattleSounds[14];
	int BackgroundMusic[2];
	int BattleSE[4];
};

