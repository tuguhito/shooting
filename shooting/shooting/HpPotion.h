#pragma once
#include "ItemBase.h"
class HpPotion :public ItemBase
{
private:
	int healpower;

public:
	HpPotion(T_Location);

public:
	virtual void Update();
	virtual void Draw();
	int GetHealPower();
};

