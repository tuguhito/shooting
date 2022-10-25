#include "player.h"
#include"DxLib.h"
#include"KeyManager.h"
#include"StraightBullet.h"

T_Location getNewLocation(T_Location newLocation);
//newLocation.x = GetLocation().x;
//newLocation.y = GetLocation().y;

Player::Player(T_Location location, float radius):SphereCollider(location, radius)
{
	score = 0;
	life = 10;
	//imageの初期化 
	//speedの初期化

	bullets = new BulletBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update() 
{
	T_Location newLocation = getNewLocation(GetLocation());
	SetLocation(newLocation);

	int bulletCount;
	for (bulletCount=0; bulletCount<30; bulletCount++)
	{
		if (bullets[bulletCount]==nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		if (bullets[bulletCount]->isDeath())
		{
			delete bullets[bulletCount];
			bullets[bulletCount] = bullets[bulletCount + 1];
			bullets[bulletCount + 1] = nullptr;

			for (int i = bulletCount+1; i < 30; i++)
			{
				if (bullets[i+1]==nullptr)
				{
					break;
				}
				bullets[i] = bullets[i + 1];
				bullets[i + 1] = nullptr;
			}
		}
	}

	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		int i;
			if (bulletCount<30&&bullets[bulletCount] == nullptr)
			{
				bullets[bulletCount] = new StraightBullet(GetLocation());
			}
	}
}

void Player::Draw() 
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));

	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}

void Player::Hit() 
{

}

bool Player::LifeCheck()
{
	bool ret = (life <= 0);
	return ret;
}

int Player::GetScore()
{
	return score;
}

T_Location getNewLocation(T_Location newLocation)
{
	

	if (KeyManager::OnPressed(KEY_INPUT_W))
	{
		newLocation.y -= 2.0;
	}
	if (KeyManager::OnPressed(KEY_INPUT_A))
	{
		newLocation.x -= 2.0;
	}
	if (KeyManager::OnPressed(KEY_INPUT_S))
	{
		newLocation.y += 2.0;
	}
	if (KeyManager::OnPressed(KEY_INPUT_D))
	{
		newLocation.x += 2.0;
	}
	return newLocation;
}