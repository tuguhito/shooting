#pragma once
#include"BulletBase.h"
class EneBullet:public BulletBase
{
private:
	int image;
	BulletBase** enemy;//���˂���e
	int* image = nullptr; //�`�悷��摜

public:
	EneBullet(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isDeath() override;
};

