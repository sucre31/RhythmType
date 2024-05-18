#include "Sound.h"
#include <Dxlib.h>

Sound::Sound() {
    BackgroundMusic[0] = myLoadSoundMem("Assets/Sounds/Music/Original.wav");
    BackgroundMusic[1] = myLoadSoundMem("Assets/Sounds/Music/Drum.wav");
    lucasBattleSounds[0] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet1.wav");
    lucasBattleSounds[1] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet2.wav");
    lucasBattleSounds[2] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet3.wav");
    lucasBattleSounds[3] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet4.wav");
    lucasBattleSounds[4] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet5.wav");
    lucasBattleSounds[5] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet6.wav");
    lucasBattleSounds[6] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet7.wav");
    lucasBattleSounds[7] = myLoadSoundMem("Assets/Sounds/Lucas/Snippet8.wav");
    lucasBattleSounds[8] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetA1.wav");
    lucasBattleSounds[9] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetB1.wav");
    lucasBattleSounds[10] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetC1.wav");
    lucasBattleSounds[11] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetD1.wav");
    lucasBattleSounds[12] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetA2.wav");
    lucasBattleSounds[13] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetB2.wav");
    lucasBattleSounds[14] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetC2.wav");
    lucasBattleSounds[15] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetD2.wav");
    lucasBattleSounds[16] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetA3.wav");
    lucasBattleSounds[17] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetB3.wav");
    lucasBattleSounds[18] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetC3.wav");
    lucasBattleSounds[19] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetD3.wav");
    lucasBattleSounds[20] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetA4.wav");
    lucasBattleSounds[21] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetB4.wav");
    lucasBattleSounds[22] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetC4.wav");
    lucasBattleSounds[23] = myLoadSoundMem("Assets/Sounds/Lucas/SnippetD4.wav");
    kumatoraBattleSounds[0] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar0.wav");
    kumatoraBattleSounds[1] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar1.wav");
    kumatoraBattleSounds[2] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar2.wav");
    kumatoraBattleSounds[3] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar3.wav");
    kumatoraBattleSounds[4] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar4.wav");
    kumatoraBattleSounds[5] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar5.wav");
    kumatoraBattleSounds[6] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar6.wav");
    kumatoraBattleSounds[7] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar7.wav");
    kumatoraBattleSounds[8] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar8.wav");
    kumatoraBattleSounds[9] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar9.wav");
    kumatoraBattleSounds[10] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar10.wav");
    kumatoraBattleSounds[11] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar11.wav");
    kumatoraBattleSounds[12] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar12.wav");
    kumatoraBattleSounds[13] = myLoadSoundMem("Assets/Sounds/Kumatora/Guitar13.wav");
    dusterBattleSounds[0] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass0.wav");
    dusterBattleSounds[1] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass1.wav");
    dusterBattleSounds[2] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass2.wav");
    dusterBattleSounds[3] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass3.wav");
    dusterBattleSounds[4] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass4.wav");
    dusterBattleSounds[5] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass5.wav");
    dusterBattleSounds[6] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass6.wav");
    dusterBattleSounds[7] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass7.wav");
    dusterBattleSounds[8] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass8.wav");
    dusterBattleSounds[9] = myLoadSoundMem("Assets/Sounds/Duster/DusterBass9.wav");
    boneyBattleSounds[0] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark0.wav");
    boneyBattleSounds[1] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark1.wav");
    boneyBattleSounds[2] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark2.wav");
    boneyBattleSounds[3] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark3.wav");
    boneyBattleSounds[4] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark4.wav");
    boneyBattleSounds[5] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark5.wav");
    boneyBattleSounds[6] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark6.wav");
    boneyBattleSounds[7] = myLoadSoundMem("Assets/Sounds/Boney/BoneyBark7.wav");
    BattleSE[0] = myLoadSoundMem("Assets/Sounds/Battle/Bash.wav");
    BattleSE[1] = myLoadSoundMem("Assets/Sounds/Battle/AllyTurn.wav");
    BattleSE[2] = myLoadSoundMem("Assets/Sounds/Battle/Smaash.wav");
}

/*!
@brief 今までロードした音声を解放する
*/
void Sound::release()
{
    const int size = sounds.size();
    for (int i = 0; i < size; i++) {
        DeleteSoundMem(sounds[i]);
    }
    sounds.clear();
}

/*!
@brief LoadSoundMemをして、かつそのハンドルをメンバ変数に追加する
*/
int Sound::myLoadSoundMem(char* fileName)
{
    int ret = LoadSoundMem(fileName);
    sounds.push_back(ret);
    return ret;
}

/*!
@brief LoadSoundMemをして、かつそのハンドルをメンバ変数に追加する
*/
int Sound::myLoadSoundMem(const char* fileName)
{
    int ret = LoadSoundMem(fileName);
    sounds.push_back(ret);
    return ret;
}