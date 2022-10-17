#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static int oldKey; //前回の入力キー 　　staticは初めから実体持ち
	static int nowKey; //今回の入力キー

private:
	KeyManager() = default;

public:
	void Update()
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	static bool OnClick(int inputKey)//ボタンを押した瞬間
	{
		int keyFlg = (nowKey & ~oldKey);
		bool ret = (keyFlg & inputKey);
		return ret;
	}

	static bool OnPressed(int inputKey)//ボタンを押してる間
	{
		bool ret = (nowKey & inputKey);
		return ret;
	}

	static bool OnRelease(int inputKey)
	{
		int keyFlg = (oldKey & ~nowKey);
		bool ret = (&inputKey);
		return ret;
	}

};

