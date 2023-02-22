#include "Title.h"
#include "DxLib.h"
#include "KeyManager.h"
#include "GameMain.h"

Title::Title()
{

}

AbstractScene* Title::Update() 
{
	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		return new GameMain();
	}
	return this;
}

void Title::Draw() const
{
	DrawString(550, 200, "Title", GetColor(255, 255, 255));
	DrawString(520, 500, "Push to SPACE",GetColor(255,255,255));
}
