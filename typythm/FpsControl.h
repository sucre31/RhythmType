#include <math.h>
#include "DxLib.h"

class FpsControl {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	const int N = 120;//平均を取るサンプル数
	const int FPS = 66;	//設定したFPS

public:
	FpsControl() = default;
	virtual ~FpsControl() = default;
	void FpsControll_Initialize();
	bool Update();
	void Draw();
	void Wait();
};