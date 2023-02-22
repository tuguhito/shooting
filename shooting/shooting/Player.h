#pragma once
#include "CharaBase.h"
#include"BulletBase.h"

class Player : public CharaBase, public SphereCollider
{
private:
	int score;  //åªç›ÉXÉRÉA
	int life;   //HP

public:
	Player(T_Location location, float radius);

public:
	void Update() override;
	void Draw() override;
	void Hit();
	void Hit(class BulletBase* bulletsCount);
	void Hit(int BulletsCount);
	void Hit(class ItemBase* item);
	bool LifeCheck();
	int GetScore();
	void addScore(int point);
};

