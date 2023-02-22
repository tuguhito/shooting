#pragma once
#include "BulletBase.h"
class EnemyStraightBullet:public BulletBase
{
	private:
		int image;

	public:
		EnemyStraightBullet(T_Location location);

	public:
		virtual void Update() override;
		virtual void Draw() override;
		virtual bool isDeath() override;
};

