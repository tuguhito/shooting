#include "HpPotion.h"
#include"DxLib.h"



HpPotion::HpPotion(T_Location location):ItemBase(location, 5.f, E_ITEM_TYPE::HP_Potion, T_Location{0,0.5f}),healpower(2)
{

}

void HpPotion::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}

void HpPotion::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(200, 0, 200));
}

int HpPotion::GetHealPower()
{
	return healpower;
}
