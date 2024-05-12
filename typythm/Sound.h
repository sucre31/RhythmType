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

private:
	int myLoadSoundMem(char*);
	int myLoadSoundMem(const char*);
	std::vector<int> sounds;
	int lucasBattleSounds[24];
};

