#include"SphereCollider.h"
#include<math.h>

bool SphereCollider::HitSphere(SphereCollider s)
{
	//円と円の当たり判定
	//自分から相手へのベクトルを求める
	//相手　ー　自分
	T_Location location = s.GetLocation();
	float x = this->location.x - location.x;
	float y = this->location.y - location.y;

	//絶対値に変換
	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;

	//ベクトルの大きさを取得
	float x2 = x * x;
	float y2 = y * y;
	float xy = x2 + y2;
	double vectorSize = sqrt(xy);

	//
	float radius = this->radius + s.GetRadius();

	bool ret = (vectorSize <= radius);
	return ret;
}

float SphereCollider::GetRadius()
{
	return radius;
}

T_Location SphereCollider::GetLocation()
{
	return location;
}

void SphereCollider::SetLocation(T_Location value)
{
	location.x = value.x;
	location.y = value.y;
}

