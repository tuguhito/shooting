#pragma once
#include"CharaBase.h"

class Enemy :public CharaBase, public SphereCollider
{
private:
	int hp;
	int point;
	int WaitCount;

public:
	Enemy(T_Location location, float radius);

public:
	void Update() override;
	void Draw() override;
	void Hit() override;
	void Hit(int damage);
	bool HpCheck();
	int GetPoint();
};



