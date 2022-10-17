#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static char oldKey[256]; //前回の入力キー 　　staticは初めから実体持ち
	static char nowKey[256]; //今回の入力キー

private:
	KeyManager() = default;

public:
	static void Update()
	{
		for (int i = 0; i < 256; i++)
		{
			oldKey[i] = nowKey[i];
		}
		//nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if(GetHitKeyStateAll(nowKey) == -1)
		{
			throw - 1;		//エラーが出た場合、終了
		}

	}

	static bool OnClick(int inputKey)//ボタンを押した瞬間
	{
		bool ret = (nowKey[inputKey] == 1 && oldKey[inputKey] == 0);
		return ret;
	}

	static bool OnPressed(int inputKey)//ボタンを押してる間
	{
		bool ret = (nowKey[inputKey]==1);
		return ret;
	}

	static bool OnRelease(int inputKey)
	{
		bool ret = (oldKey[inputKey] == 1 && nowKey[inputKey] == 0);
		return ret;
	}

};

