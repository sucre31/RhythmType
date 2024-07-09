#pragma once

#include <array>
#include "Singleton.h"

enum ePad {
	down, left, right, up, A, B, Y, X, L, R, start, change
};

class Pad final : public Singleton<Pad> {

public:
	Pad();
	~Pad() = default;
	void update();
	int get(ePad eID) const;  //eIDのボタンの入力状態を取得

private:
    void merge();

    const static int PAD_KEY_NUM = 20;
    std::array<int, PAD_KEY_NUM> _idArray;  //どのボタンがどのボタンに割り当たっているかを示す
    std::array<int, PAD_KEY_NUM> _pad;      //16ボタンのpad入力状態格納

};