#include <math.h>
#include "DxLib.h"

class FpsControl {
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	const int N = 60;//���ς����T���v����
	const int FPS = 60;	//�ݒ肵��FPS

public:
	FpsControl() = default;
	virtual ~FpsControl() = default;
	void FpsControll_Initialize();
	bool Update();
	void Draw();
	void Wait();
};