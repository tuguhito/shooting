#pragma once
#include"BulletBase.h"
class StraightBullet :public BulletBase
{
private:
	int image;

public:
	StraightBullet(T_Location location, T_Location speed);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isDeath() override;
};
