#include "Instrument.h"
#include "Sound.h"
#include <Dxlib.h>

void Instrument::playMainInstrument(int NumberOfTone){
	int targetPlayNum = 0;
	int tmpNum = 0;
	switch (myInstrumentNumber)
	{
	case 0:
		NumberOfTone = NumberOfTone % 12;
		switch (NumberOfTone) {
		case 0:
			targetPlayNum = 0;
			break;
		case 1:
			targetPlayNum = 1;
			break;
		case 2:
			targetPlayNum = 2;
			break;
		case 3:
			targetPlayNum = 0;
			break;
		case 4:
			targetPlayNum = 1;
			break;
		case 5:
			targetPlayNum = 2;
			break;
		case 6:
			targetPlayNum = 3;
			break;
		case 7:
			targetPlayNum = 4;
			break;
		case 8:
			targetPlayNum = 5;
			break;
		case 9:
			targetPlayNum = 6;
			break;
		case 10:
			targetPlayNum = 0;
			break;
		case 11:
			targetPlayNum = 7;
			break;
		}
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		break;
	case 1:
		NumberOfTone = NumberOfTone % 48;
		tmpNum = NumberOfTone / 6;
		switch (tmpNum) {
		case 0:
			targetPlayNum = 0;
			break;
		case 1:
			targetPlayNum = 1;
			break;
		case 2:
			targetPlayNum = 2;
			break;
		case 3:
			targetPlayNum = 3;
			break;
		case 4:
			targetPlayNum = 4;
			break;
		case 5:
			targetPlayNum = 5;
			break;
		case 6:
			targetPlayNum = 6;
			break;
		case 7:
			targetPlayNum = 6;
			break;
		}
		if (NumberOfTone % 6 != 5) {
			targetPlayNum = targetPlayNum * 2;
			PlaySoundMem(Sound::getIns()->getKumatoraBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		}
		else {
			targetPlayNum = targetPlayNum * 2 + 1;
			PlaySoundMem(Sound::getIns()->getKumatoraBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		}
		break;
	case 2:
		NumberOfTone = NumberOfTone % 64;
		tmpNum = (NumberOfTone / 8);
		switch (tmpNum) {
		case 0:
			targetPlayNum = 0;
			break;
		case 1:
			targetPlayNum = 1;
			break;
		case 2:
			targetPlayNum = 2;
			break;
		case 3:
			targetPlayNum = 3;
			break;
		case 4:
			targetPlayNum = 0;
			break;
		case 5:
			targetPlayNum = 1;
			break;
		case 6:
			targetPlayNum = 2;
			break;
		case 7:
			targetPlayNum = 2;
			break;
		}
		if (NumberOfTone >= 62) {
			targetPlayNum = 4;
		}
		if (NumberOfTone % 2 == 0) {
			targetPlayNum = targetPlayNum * 2;
			PlaySoundMem(Sound::getIns()->getDusterBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		}
		else {
			targetPlayNum = targetPlayNum * 2 + 1;
			PlaySoundMem(Sound::getIns()->getDusterBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		}
		break;
	case 3:
		NumberOfTone = NumberOfTone % 13;
		switch (NumberOfTone) {
		case 0:
			targetPlayNum = 0;
			break;
		case 1:
			targetPlayNum = 0;
			break;
		case 2:
			targetPlayNum = 1;
			break;
		case 3:
			targetPlayNum = 2;
			break;
		case 4:
			targetPlayNum = 3;
			break;
		case 5:
			targetPlayNum = 0;
			break;
		case 6:
			targetPlayNum = 1;
			break;
		case 7:
			targetPlayNum = 4;
			break;
		case 8:
			targetPlayNum = 0;
			break;
		case 9:
			targetPlayNum = 1;
			break;
		case 10:
			targetPlayNum = 5;
			break;
		case 11:
			targetPlayNum = 6;
			break;
		case 12:
			targetPlayNum = 7;
			break;
		}
		PlaySoundMem(Sound::getIns()->getBoneyBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		break;
	}
}

void Instrument::playSubInstrument(int NumberOfTone) {
	int targetPlayNum = 0;
	switch (myInstrumentNumber)
	{
	case 0:
		NumberOfTone = NumberOfTone % 28;
		switch (NumberOfTone) {
		case 0:
			targetPlayNum = 8;
			break;
		case 1:
			targetPlayNum = 9;
			break;
		case 2:
			targetPlayNum = 10;
			break;
		case 3:
			targetPlayNum = 11;
			break;
		case 4:
			targetPlayNum = 12;
			break;
		case 5:
			targetPlayNum = 13;
			break;
		case 6:
			targetPlayNum = 14;
			break;
		case 7:
			targetPlayNum = 15;
			break;
		case 8:
			targetPlayNum = 16;
			break;
		case 9:
			targetPlayNum = 17;
			break;
		case 10:
			targetPlayNum = 18;
			break;
		case 11:
			targetPlayNum = 19;
			break;
		case 12:
			targetPlayNum = 20;
			break;
		case 13:
			targetPlayNum = 21;
			break;
		case 14:
			targetPlayNum = 22;
			break;
		case 15:
			targetPlayNum = 23;
			break;
		case 16:
			targetPlayNum = 8;
			break;
		case 17:
			targetPlayNum = 9;
			break;
		case 18:
			targetPlayNum = 10;
			break;
		case 19:
			targetPlayNum = 11;
			break;
		case 20:
			targetPlayNum = 12;
			break;
		case 21:
			targetPlayNum = 13;
			break;
		case 22:
			targetPlayNum = 14;
			break;
		case 23:
			targetPlayNum = 15;
			break;
		case 24:
			targetPlayNum = 16;
			break;
		case 25:
			targetPlayNum = 17;
			break;
		case 26:
			targetPlayNum = 18;
			break;
		case 27:
			targetPlayNum = 19;
			break;
		}
		PlaySoundMem(Sound::getIns()->getLucasBattleSounds()[targetPlayNum], DX_PLAYTYPE_BACK);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

}

/*!
@brief ステップに合わせて音を鳴らす，もしくはステップに音があるかを判定
@param StepNuber ステップ数
@param checkMode 0:鳴らす	1:メインに音があるか	2:サブに音があるか
*/
bool Instrument::playWithStep(int StepNumber, int checkMode) {
	StepNumber = StepNumber % 128;
	int mainNum = -1;
	int subNum = -1;
	switch (myInstrumentNumber) {
	case 0:
		switch (StepNumber) {
		case 0:
			mainNum = 0;
			subNum = 0;
			break;
		case 2:
			subNum = 1;
			break;
		case 4:
			subNum = 2;
			break;
		case 6:
			subNum = 3;
			break;
		case 16:
			mainNum = 1;
			subNum = 4;
			break;
		case 18:
			subNum = 5;
			break;
		case 20:
			subNum = 6;
			break;
		case 22:
			subNum = 7;
			break;
		case 24:
			mainNum = 2;
			break;
		case 32:
			mainNum = 3;
			subNum = 8;
			break;
		case 34:
			subNum = 9;
			break;
		case 36:
			subNum = 10;
			break;
		case 38:
			subNum = 11;
			break;
		case 48:
			mainNum = 4;
			subNum = 12;
			break;
		case 50:
			subNum = 13;
			break;
		case 52:
			subNum = 14;
			break;
		case 54:
			subNum = 15;
			break;
		case 56:
			mainNum = 5;
			break;
		case 60:
			mainNum = 6;
			break;
		case 62:
			mainNum = 7;
			break;
		case 64:
			mainNum = 8;
			subNum = 16;
			break;
		case 66:
			subNum = 17;
			break;
		case 68:
			subNum = 18;
			break;
		case 70:
			subNum = 19;
			break;
		case 80:
			mainNum = 9;
			subNum = 20;
			break;
		case 82:
			subNum = 21;
			break;
		case 84:
			subNum = 22;
			break;
		case 86:
			subNum = 23;
			break;
		case 88:
			mainNum = 10;
			break;
		case 96:
			mainNum = 11;
			subNum = 24;
			break;
		case 98:
			subNum = 25;
			break;
		case 100:
			subNum = 26;
			break;
		case 102:
			subNum = 27;
			break;
		}
		if (mainNum != -1 && checkMode == 0) playMainInstrument(mainNum);
		if (subNum != -1 && checkMode == 0) playSubInstrument(subNum);
		break;
	case 1:
		switch (StepNumber % 16) {
		case 0:
			mainNum = 0 + StepNumber / 16 * 6;
			break;
		case 3:
			mainNum = 1 + StepNumber / 16 * 6;
			break;
		case 6:
			mainNum = 2 + StepNumber / 16 * 6;
			break;
		case 9:
			mainNum = 3 + StepNumber / 16 * 6;
			break;
		case 12:
			mainNum = 4 + StepNumber / 16 * 6;
			break;
		case 15:
			mainNum = 5 + StepNumber / 16 * 6;
			break;
		}
		if (mainNum != -1 && checkMode == 0) playMainInstrument(mainNum);
		if (subNum != -1 && checkMode == 0) playSubInstrument(subNum);
		break;
	case 2:
		if(StepNumber % 2 == 0) mainNum = StepNumber / 2;
		if (mainNum != -1 && checkMode == 0) playMainInstrument(mainNum);
		if (subNum != -1 && checkMode == 0) playSubInstrument(subNum);
		break;
	case 3:
		switch (StepNumber) {
		case 0:
			mainNum = 0;
			break;
		case 16:
			mainNum = 1;
			break;
		case 18:
			mainNum = 2;
			break;
		case 32:
			mainNum = 3;
			break;
		case 36:
			mainNum = 4;
			break;
		case 40:
			mainNum = 5;
			break;
		case 44:
			mainNum = 6;
			break;
		case 48:
			mainNum = 7;
			break;
		case 64:
			mainNum = 8;
			break;
		case 80:
			mainNum = 9;
			break;
		case 88:
			mainNum = 10;
			break;
		case 92:
			mainNum = 11;
			break;
		case 96:
			mainNum = 12;
			break;
		}
		if (mainNum != -1 && checkMode == 0) playMainInstrument(mainNum);
		if (subNum != -1 && checkMode == 0) playSubInstrument(subNum);
		break;
	}
	if (checkMode == 1) {
		if (mainNum != -1) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (checkMode == 2){
		if (subNum != -1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
