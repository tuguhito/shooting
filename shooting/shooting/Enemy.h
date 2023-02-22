#pragma once
#include"CharaBase.h"

#define _ENEMY_BULLET_ALL_ 300

struct T_MoveInformation
{
	int pattern;   //�s���p�^�[��
	T_Location destination;  //�ړI�n
	int nextArrayNum;    //���̔z��ԍ�
	int waitFrameTime;   //�҂����� 
	int attackPattern;   //�U���̎��
};

class Enemy :public CharaBase,public SphereCollider
{
private:
	int hp;
	int point;
	int shotNum;
	int WaitCount;
	int bulletCount;
	T_MoveInformation moveInfo[5] = {}; //�G�̈ړ�����
	int current;
	int WaitTime;


public:
	Enemy(T_Location location, float radius);

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



