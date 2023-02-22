#include "EnemyStraightBullet.h"
#include "DxLib.h"
#include "common.h"

EnemyStraightBullet::EnemyStraightBullet(T_Location location) :BulletBase(location, 5.f, 1, T_Location{ 0,5 })
{
	image = 0;
}


void EnemyStraightBullet::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);


}

void EnemyStraightBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));
}

bool EnemyStraightBullet::isDeath()
{
	float y = GetLocation().y + GetRadius();
	if (y <= 0)
	{
		return true;
	}

	y = GetLocation().y - GetRadius();
	if (SCREEN_HEIGHT <= y)
	{
		return true;
	}

	float x = GetLocation().y + GetRadius();
	if (x <= 0)
	{
		return true;
	}

	x = GetLocation().y - GetRadius();
	if (SCREEN_WIDTH <= x)
	{
		return true;
	}

	return false;
}

