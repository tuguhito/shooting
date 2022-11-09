#include"DxLib.h"
#include"GameMain.h"
#include"HpPotion.h"

AbstractScene* GameMain::Update()
{
	player->Update();//自分自身のポインタ
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] == nullptr)
		{
			break;
		}
		enemy[i]->Update();
	}

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Update();
	}
	BulletBase** bullets = player->GetBullets();
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		for (int EnemyCount = 0; EnemyCount < 10; EnemyCount++)
		{
			if (enemy[EnemyCount] == nullptr)
			{
				break;
			}
			if (bullets[bulletCount]->HitSphere(enemy[EnemyCount]))
			{
				enemy[EnemyCount]->Hit(bullets[bulletCount]->GetDamage());
				player->Hit(bulletCount);//弾の削除
				bullets = player->GetBullets();
				bulletCount--;
				//エネミーのHPがゼロ以下であれば、エネミーを消す
				if (enemy[EnemyCount]->HpCheck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new HpPotion(enemy[EnemyCount]->GetLocation());
						}
					}
					//エネミーを消した時、プレイヤーのスコアに、エネミーのポイントを加算する
					player->addScore(enemy[EnemyCount]->GetPoint());//delete前に実行したいプログラムを打ち込む

					delete enemy[EnemyCount];
					enemy[EnemyCount] = nullptr;

					for (int i = (EnemyCount + 1); i < 10; i++)
					{
						if (enemy[i] == nullptr)
						{
							break;
						}
						enemy[i - 1] = enemy[i];
						enemy[i] = nullptr;
					}

				}

			}
			

			}
		
	}

	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (items[itemCount]==nullptr)
		{
			break;
		}
		if (player->HitSphere(items[itemCount]))
		{
			delete items[itemCount];
			items[itemCount] = nullptr;
			for (int i = itemCount+1; i < 10; i++)
			{
				if (items[i]==nullptr)
				{
					break;
				}
				items[i - 1] = items[i];
				items[i] = nullptr;
			}
		}
	}

	return this;
}

void GameMain::Draw() const
{
	player->Draw();
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] == nullptr)
		{
			break;
		}
		enemy[i]->Draw();
	}

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
	}
}