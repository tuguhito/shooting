#include "EneBullet.h"
#include"DxLib.h"


EneBullet::EneBullet(T_Location location) :BulletBase(location, 5.f, 1, T_Location{ 0, 2 })
{
	image = 0;
}


void EneBullet::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);


}

void EneBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 0));
}

bool EneBullet::isDeath()
{
	float y = GetLocation().y + GetRadius();
	if (y <= 0)
	{
		return true;
	}

	return false;
}

