#include "BackImage.h"
#include <Dxlib.h>
#include "Image.h"
#include "Define.h"

BackImage::BackImage() {
	AnimeNum = 0;
	tmpScreenHandle = MakeScreen(Define::WIN_W, Define::WIN_H, FALSE);;
}

bool BackImage::update() {
	deley++;
	if (deley % 10 == 0) {
		AnimeNum = (++AnimeNum) % 14;
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
	DrawGraph(0, 0, Image::getIns()->getBeltImage(), TRUE);
	DrawGraph(0, 157, Image::getIns()->getBeltImage(), TRUE);
}