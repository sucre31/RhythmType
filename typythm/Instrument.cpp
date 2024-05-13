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