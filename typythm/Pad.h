#pragma once

#include "Singleton.h"
#include <array>

enum ePad {
	left, up, right, down, A, B, Y, start, change
};

class Pad final : public Singleton<Pad> {

public:
	Pad();
	~Pad() = default;
	void update();
	int get(ePad eID) const;  //eID�̃{�^���̓��͏�Ԃ��擾

private:
    void merge();

    const static int PAD_KEY_NUM = 16;
    std::array<int, PAD_KEY_NUM> _idArray;  //�ǂ̃{�^�����ǂ̃{�^���Ɋ��蓖�����Ă��邩������
    std::array<int, PAD_KEY_NUM> _pad;      //16�{�^����pad���͏�Ԋi�[

};