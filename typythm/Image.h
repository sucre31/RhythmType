#pragma once

#include "Singleton.h"
#include <vector>

class Image final : public Singleton<Image>
{
public:
	Image();
	~Image() = default;
	void load() {};
	void release();
	int getBackImage() const { return backImage; }
	int getWindowImage() const { return windowImage; }
	int getBeltImage() const { return beltImage; }
	int getScreenHandle() const { return screenHandle; }
	int getEnemyBattyImage() const { return MrBattyImage;  }
	const int* getDrumroll() const { return drumroll; }
	const int* getCharacterHiragana() const { return characterHiragana; }
	const int* getCharacterKatakana() const { return characterKatakana; }
	const int* getCharacterAlphaA() const { return characterAlphaA; }
	const int* getBackgroundsA() const { return backgroundsA; }
	//int getDrumroll() const { return _drumroll[0]; }

private:
	int myLoadGraph(char*);
	int myLoadGraph(const char*);
	int myLoadDivGraph(char* fileName, int n, int xn, int yn, int w, int h, int* buf);
	int myLoadDivGraph(const char* fileName, int n, int xn, int yn, int w, int h, int* buf);
	std::vector<int> images;
	int screenHandle;
	int backImage;
	int windowImage;
	int beltImage;
	int drumroll[80];
	int characterHiragana[90];
	int characterKatakana[90];
	int characterAlphaA[90];
	int backgroundsA[14];
	int MrBattyImage;
	int LucasBattleImage;
};

