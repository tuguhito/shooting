#include "SpinBullet.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>

SpinBullet::SpinBullet(T_Location location, float speed, int degAngle) :BulletBase(location, 5.f, 1, T_Location{1,1})
{
	int deg = degAngle % 360;
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);
	float y = sin(rad);

	this->speed = T_Location{ (speed * x),(speed * y) };
}


void SpinBullet::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x -= speed.x;
	/*radius = angle * 3.14f / 180.0f;*/
	/*float add_x = cos(radius) * length;
	float add_y = sin(radius) * length;*/
	SetLocation(newLocation);
}

void SpinBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));
}

bool SpinBullet::isDeath()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}

	ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
	if (ret)
	{
		return ret;
	}

	ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}

	ret = (SCREEN_WIDTH <= (GetLocation().x - GetRadius()));
	return ret;
}


