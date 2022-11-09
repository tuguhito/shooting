#pragma once
#include"BulletBase.h"
class EneBullet:public BulletBase
{
private:
	int image;
	BulletBase** enemy;//”­ŽË‚·‚é’e
	int* image = nullptr; //•`‰æ‚·‚é‰æ‘œ

public:
	EneBullet(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isDeath() override;
};

