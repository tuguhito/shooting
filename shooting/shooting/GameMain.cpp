#include"DxLib.h"
#include"GameMain.h"

AbstractScene* GameMain::Update()
{
	player->Update();//�������g�̃|�C���^

	return this;
}

void GameMain::Draw() const
{
	player->Draw();
}