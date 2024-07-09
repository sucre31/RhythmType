#include <Dxlib.h>

#include "BackImage.h"
#include "Image.h"
#include "Define.h"
#include "GameManager.h"

BackImage::BackImage() {
	AnimeNum = 0;
	tmpScreenHandle = MakeScreen(Define::WIN_W, Define::WIN_H, FALSE);;
}

bool BackImage::update() {
	if (GameManager::getIns()->getFpsIns()->isFrameChanged()) {
		deley++;
		if (deley % 10 == 0) {
			AnimeNum = (++AnimeNum) % 14;
		}
	}
	return true;
}

void BackImage::draw() const {
	SetDrawScreen(tmpScreenHandle);
	ClearDrawScreen;
	DrawRotaGraph(160, 90, 1.25, 0, Image::getIns()->getBackgroundsA()[AnimeNum], TRUE);
	GraphFilter(tmpScreenHandle, DX_GRAPH_FILTER_GAUSS, 16, 400);
	GraphFilter(tmpScreenHandle, DX_GRAPH_FILTER_GAUSS, 16, 1200);
	SetDrawScreen(Image::getIns()->getScreenHandle());
	DrawGraph(0, 0, tmpScreenHandle, TRUE);
}

void BackImage::drawSecond() const {
	DrawGraph(0, 0, Image::getIns()->getBeltImage2(), TRUE);
	DrawGraph(0, 160, Image::getIns()->getBeltImage(), TRUE);
}