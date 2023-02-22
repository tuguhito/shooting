#include "gameover.h"
#include "DxLib.h"
#include "gameover.h"
#include "KeyManager.h"
#include "Title.h"


gameover::gameover()
{
	life = 0;
}

AbstractScene* gameover::Update() 
{
	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		return new Title();
	}
	return this;
}

void gameover::Draw() const
{
	DrawString(550, 200, "Game Over", GetColor(255, 255, 255));
	DrawString(400, 500, " --スペースキーを押してタイトルに戻る-- ", GetColor(255, 255, 255));
}

