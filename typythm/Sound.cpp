#include "Sound.h"
#include <Dxlib.h>

Sound::Sound() {
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