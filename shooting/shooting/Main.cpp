#include"DxLib.h"
#include"SceneManager.h"
#include"GameMain.h"
#include"common.h"
#include "Title.h"
//#define SCREEN_WIDTH
//#define SCREEN_HEIGHT
//#define SCREEN_COLOR_BIT_16


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    //�^�C�g���� test �ɕύX
    SetMainWindowText("�V���[�e�B���O");

    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SetFontSize(20);		// �����T�C�Y��ݒ�

    SceneManager sceneMng(new Title());

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        ClearDrawScreen();


      

        sceneMng.Draw();

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}