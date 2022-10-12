#pragma once
#include"SphereCollider.h"

class CharaBase
{
private:
	T_Location speed; //ˆÚ“®‘¬“x

protected:
	int* image = nullptr; //•`‰æ‚·‚é‰æ‘œ

public:
	virtual ~CharaBase();


public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;

	T_Location GetSpeed();
	void SetSpeed(T_Location speed);
};
