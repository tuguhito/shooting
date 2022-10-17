#include"DxLib.h"
#include"GameMain.h"

AbstractScene* GameMain::Update()
{
	player->Update();//自分自身のポインタ

	return this;
}

void GameMain::Draw() const
{
	player->Draw();
}