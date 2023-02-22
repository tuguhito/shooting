#pragma once
#include"CharaBase.h"

#define _ENEMY_BULLET_ALL_ 300

struct T_MoveInformation1
{
	int pattern;   //行動パターン
	T_Location destination;  //目的地
	int nextArrayNum;    //次の配列番号
	int waitFrameTime;   //待ち時間 
	int attackPattern;   //攻撃の種類
};

class Enemy1 :public CharaBase, public SphereCollider
{
private:
	int hp;
	int point;
	int shotNum;
	int WaitCount;
	int bulletCount;
	T_MoveInformation1 moveInfo[5] = {}; //敵の移動処理
	int current;
	int WaitTime;


public:
	Enemy1(T_Location location, float radius);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	bool HpCheck();
	int GetPoint();
	void DeleteBullet(int bulletCount);
	void Move();
	void inputCSV();
};



