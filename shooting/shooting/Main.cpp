#include"DxLib.h"
#include"SceneManager.h"
#include"GameMain.h"
#include"common.h"
#include "Title.h"
//#define SCREEN_WIDTH
//#define SCREEN_HEIGHT
//#define SCREEN_COLOR_BIT_16


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    //タイトルを test に変更
    SetMainWindowText("シューティング");

    ChangeWindowMode(TRUE);		// ウィンドウモードで起動

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

    SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

    SetFontSize(20);		// 文字サイズを設定

    SceneManager sceneMng(new Title());

    //ゲームループ
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr) {

        ClearDrawScreen();


      

        sceneMng.Draw();

        ScreenFlip();			// 裏画面の内容を表画面に反映

    }

    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}