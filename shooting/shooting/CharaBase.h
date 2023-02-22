#pragma once
#include"SphereCollider.h"
#include"BulletBase.h"

class CharaBase
{
protected:
	T_Location speed; //ˆÚ“®‘¬“x
	BulletBase** bullets;//”­ŽË‚·‚é’e
	int* image /*= nullptr*/; //•`‰æ‚·‚é‰æ‘œ

public:
	virtual ~CharaBase();


public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit(int damage) = 0;

	T_Location GetSpeed();
	void SetSpeed(T_Location speed);
	BulletBase** GetBullets();//”­ŽË‚·‚é’e
};
