#include "SpinBullet.h"
#include"DxLib.h"
#include"common.h"

StraightBullet::StraightBullet(T_Location location, T_Location speed) :BulletBase(location, 5.f, 1, speed)
{
	image = 0;
}


void StraightBullet::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x -= speed.x;
	SetLocation(newLocation);
}

void StraightBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));
}

bool StraightBullet::isDeath()
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

