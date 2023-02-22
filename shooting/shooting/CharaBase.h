#pragma once
#include"SphereCollider.h"
#include"BulletBase.h"

class CharaBase
{
protected:
	T_Location speed; //�ړ����x
	BulletBase** bullets;//���˂���e
	int* image /*= nullptr*/; //�`�悷��摜

public:
	virtual ~CharaBase();


public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit(int damage) = 0;

	T_Location GetSpeed();
	void SetSpeed(T_Location speed);
	BulletBase** GetBullets();//���˂���e
};
