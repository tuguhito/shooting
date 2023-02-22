#pragma once
#include"BulletBase.h"
class SpinBullet :public BulletBase
{

public:
	SpinBullet(T_Location location, float speed, int degAngle);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isDeath() override;
};
