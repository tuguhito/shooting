#pragma once
#include "CharaBase.h"

class Player : public CharaBase, public SphereCollider
{
private:
	int score;  //���݃X�R�A
	int life;   //HP

public:
	Player(T_Location location, float radius);

public:
	void Update() override;
	void Draw() override;
	void Hit() override;
	void Hit(int BulletsCount);
	void Hit(class ItemBase* item);
	bool LifeCheck();
	int GetScore();
	void addScore(int point);
};

