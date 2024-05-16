#include <math.h>
#include "DxLib.h"

class FpsControl {
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	const int N = 120;//���ς����T���v����
	const int FPS = 66;	//�ݒ肵��FPS

public:
	FpsControl() = default;
	virtual ~FpsControl() = default;
	void FpsControll_Initialize();
	bool Update();
	void Draw();
	void Wait();
};