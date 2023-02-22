#include "gameclear.h"
#include "DxLib.h"
#include "gameclear.h"
#include "KeyManager.h"
#include "Title.h"

gameclear::gameclear()
{
	hp = 0;
}

AbstractScene* gameclear::Update()
{
	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		return new Title();
	}
	
	return this;
}

void gameclear::Draw() const
{
	DrawString(550, 200, "Game Clear", GetColor(255, 255, 255));
	DrawString(400, 500, " --スペースキーを押してタイトルに戻る-- ", GetColor(255, 255, 255));
}