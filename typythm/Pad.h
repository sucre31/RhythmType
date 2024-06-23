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
	int get(ePad eID) const;  //eID�̃{�^���̓��͏�Ԃ��擾

private:
    void merge();

    const static int PAD_KEY_NUM = 20;
    std::array<int, PAD_KEY_NUM> _idArray;  //�ǂ̃{�^�����ǂ̃{�^���Ɋ��蓖�����Ă��邩������
    std::array<int, PAD_KEY_NUM> _pad;      //16�{�^����pad���͏�Ԋi�[

};