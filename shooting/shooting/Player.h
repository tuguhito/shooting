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
	bool LifeCheck();
	int GetScore();
};

