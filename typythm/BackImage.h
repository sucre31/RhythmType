#pragma once
#include "GameObject.h"

class BackImage : public GameObject
{
public:
	BackImage();
	~BackImage() = default;
	bool update() override;
	void draw() const override;
	void drawSecond() const;
private:
	int AnimeNum;
	int deley;
	int tmpScreenHandle;
};

