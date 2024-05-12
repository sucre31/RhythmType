#pragma once

class Define final {
public:
	const static int WIN_W;	//ウィンドウサイズ横
	const static int WIN_H;	//ウィンドウサイズ縦
	const static int WIN_EX; //ウィンドウサイズ倍率

	const static float PI;	//円周率

	enum eStage {
		Stage1,
		Stage2
	};

	enum eLevel {
		Easy,
		Normal,
		LevelNum
	};
};