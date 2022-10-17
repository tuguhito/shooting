#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static int oldKey; //�O��̓��̓L�[ �@�@static�͏��߂�����̎���
	static int nowKey; //����̓��̓L�[

private:
	KeyManager() = default;

public:
	void Update()
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	static bool OnClick(int inputKey)//�{�^�����������u��
	{
		int keyFlg = (nowKey & ~oldKey);
		bool ret = (keyFlg & inputKey);
		return ret;
	}

	static bool OnPressed(int inputKey)//�{�^���������Ă��
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

