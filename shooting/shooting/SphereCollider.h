#pragma once

struct T_Location
{
	float x;
	float y;
};

class SphereCollider
{
private:
	T_Location location;//中心座標
	float radius;//半径
	

public:
	bool HitSphere(SphereCollider s);//　コライダー同士のヒット判定
	T_Location GetLocation();
	void SetLocation(T_Location value);

};