#pragma once
#include"common.h"

class SphereCollider
{
private:
	T_Location location;//���S���W
	float radius;//���a

public:
	SphereCollider(T_Location location, float radius);

public:
	bool HitSphere(SphereCollider* s);//�@�R���C�_�[���m�̃q�b�g����
	T_Location GetLocation() const;
	void SetLocation(T_Location value);
	float GetRadius() const;

};