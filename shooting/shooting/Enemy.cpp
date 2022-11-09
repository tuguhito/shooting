#include"DxLib.h"
#include"Enemy.h"
#include"EneBullet.h"

Enemy::Enemy(T_Location location, float radius) :SphereCollider(location, radius)
{
	hp = 10;
	point = 10;
	speed = T_Location{0,1};
	//image‚Ì‰Šú‰» 
	//speed‚Ì‰Šú‰»

	enemy = new BulletBase * [30];
	for (int i = 0; i < 30; i++)
	{
		enemy[i] = nullptr;
	}
}


void Enemy::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);

	int Enemybullet;
	for (Enemybullet = 0; Enemybullet < 30; Enemybullet++)
	{
		if (enemy[Enemybullet] == nullptr)
		{
			break;
		}
		enemy[Enemybullet]->Update();

		if (enemy[Enemybullet]->isDeath())
		{
			delete enemy[Enemybullet];
			enemy[Enemybullet] = nullptr;

			for (int i = (Enemybullet + 1); i < 30; i++)
			{
				if (enemy[i] == nullptr)
				{
					break;
				}
				enemy[i - 1] = enemy[i];
				enemy[i] = nullptr;
			}
			Enemybullet--;
		}
	}
}

void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 10, 255));
	//DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 0));
	int Enemybullet;
	for (Enemybullet = 0; Enemybullet < 30; Enemybullet++)
	{
		if (enemy[Enemybullet] == nullptr)
		{
			break;
		}
		enemy[Enemybullet]->Draw();
	}
}

void Enemy::Hit()
{

}

void Enemy::Hit(int damage)
{
	if (0<damage)
	{
		hp -= damage;
		if (hp<0)
		{
			hp = 0;
		}
	}
}

bool Enemy::HpCheck()
{
	bool ret = (hp <= 0);
	return ret;
}

int Enemy::GetPoint()
{
	return point;
}



