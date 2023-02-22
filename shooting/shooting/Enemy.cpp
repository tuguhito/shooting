#include"DxLib.h"
#include"Enemy.h"
#include"SpinBullet.h"
#include"SphereCollider.h"
#include"EnemyStraightBullet.h"
#include "gameclear.h"

#define ATTACK_INTERVAL 10

void Enemy::inputCSV()
{
	FILE *fp;      //FILE型構造体　//ファイルを開ける　
	errno_t error;
	error = fopen_s(&fp, "csv/text.csv", "r");
	if (error!=0)
	{
		//ファイルが開けてない
		return;
	}
	else 
	{
		//ファイルが開けた
		char line[100];
		for (int i = 0; fgets(line, 100,fp)!=NULL ; i++)
		{
			sscanf_s(line, "%d, %f,%f,%d,%d,%d",
				&moveInfo[i].pattern,
				&moveInfo[i].destination.x,
				&moveInfo[i].destination.y, 
				&moveInfo[i].nextArrayNum, 
				&moveInfo[i].waitFrameTime, 
				&moveInfo[i].attackPattern );
		}
		return;
	}
	fclose(fp);   //ファイルを閉じる
}

Enemy::Enemy(T_Location location, float radius):SphereCollider(location, radius)
{
	bullets = new BulletBase * [_ENEMY_BULLET_ALL_];
	for (int i = 0; i < _ENEMY_BULLET_ALL_; i++)
	{
		bullets[i] = nullptr;
	}
	hp = 10;
	point = 10;
	WaitCount = 0;
	/*shotNum=*/
	speed = { 1,1 };
	shotNum = 0;
	bulletCount = 0;
}


void Enemy::Update()
{
	//T_Location newLocation = GetLocation();
	//newLocation.y += speed.y;
	//SetLocation(newLocation);

	inputCSV();

	switch(moveInfo[current].pattern)
	{
		case 0:
			Move();
			break;
		case 1:
			WaitTime++;
			if (moveInfo[current].waitFrameTime <= WaitTime)
			{
				WaitTime = 0;
				current = moveInfo[current].nextArrayNum;
			}
			break;
		default:
			break;
		//return;
	}

	//Move();

	

	
	for (bulletCount = 0; bulletCount < _ENEMY_BULLET_ALL_; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		if (bullets[bulletCount]->isDeath())
		{
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}

	if (moveInfo[current].attackPattern != 0)
	{
		WaitCount++;
		if (ATTACK_INTERVAL <= WaitCount)
		{
			if (bulletCount < 30 && bullets[bulletCount] == nullptr)
			{
				WaitCount = 0;
				if (moveInfo[current].attackPattern == 1)
				{
					bullets[bulletCount] = new EnemyStraightBullet(GetLocation());
				}
				else if (moveInfo[current].attackPattern == 2)
				{
					shotNum++;
					bullets[bulletCount] = new SpinBullet(GetLocation(), 5.f, (20 * shotNum));
				}
			}
		}

	}
}

void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));
	DrawFormatString(10, 30, GetColor(255, 255, 255), "hp=%d", this->hp);

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

void Enemy::DeleteBullet(int bulletCount)
{
	delete bullets[bulletCount];
	bullets[bulletCount] = nullptr;
	for (int i = (bulletCount+1); i < 30; i++)
	{
		if (bullets[i]==nullptr)  //敵を消す
		{
			break;
		}
		bullets[i - 1] = bullets[i];
		bullets[i] = nullptr;
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


void Enemy::Move()
{
	T_Location newLocation = GetLocation();

	if ((newLocation.x == moveInfo[current].destination.x) && (newLocation.y == moveInfo[current].destination.y))
	{
		current = moveInfo[current].nextArrayNum;  //目的地に辿り着いたら
		return;
	}
	else
	{
		if (newLocation.x != moveInfo[current].destination.x)
		{
			if (newLocation.x<moveInfo[current].destination.x)    //今いる座標よりx座標が大きければ
			{
				newLocation.x += speed.x;    //スピードを足していく
				if (moveInfo[current].destination.x < newLocation.x)   //不等号は開いてる所が必ず右になる
				{
					newLocation.x = moveInfo[current].destination.x;
				}
			}
			else  //今いる座標よりもx座標が小さければ
			{
				newLocation.x -= speed.x;    //スピードを引いていく
				if (newLocation.x < moveInfo[current].destination.x)
				{
					newLocation.x = moveInfo[current].destination.x;
				}
			}
		}

		if (newLocation.y != moveInfo[current].destination.y)
		{
			if (newLocation.y < moveInfo[current].destination.y)    //今いる座標よりy座標が大きければ
			{
				newLocation.y += speed.y;    //スピードを足していく
				if (moveInfo[current].destination.y < newLocation.y)   
				{
					newLocation.y = moveInfo[current].destination.y;
				}
			}
			else   //今いる座標よりもy座標が小さければ
			{
				newLocation.y -= speed.y;    //スピードを引いていく
				if (newLocation.y < moveInfo[current].destination.y)
				{
					newLocation.y = moveInfo[current].destination.y;
				}
			}
		}
	}

	SetLocation(newLocation);
}