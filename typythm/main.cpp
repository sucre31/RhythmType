#include <DxLib.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    // while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
    while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}
