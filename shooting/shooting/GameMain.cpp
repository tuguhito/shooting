#include"DxLib.h"
#include"GameMain.h"

AbstractScene* GameMain::Update()
{
	player->Update();//自分自身のポインタ
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i]==nullptr)
		{
			break;
		}
		enemy[i]->Update();
	}
	BulletBase** bullets = player->GetBullets();
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if(bullets[bulletCount]==nullptr)
		{
			break;
		}
		for (int EnemyCount = 0; EnemyCount < 10; EnemyCount++)
		{
			if (enemy[EnemyCount]==nullptr)
			{
				break;
			}
			if (bullets[bulletCount]->HitSphere(enemy[EnemyCount]))
			{
				//プレイヤーの弾とエネミーが当たった
				//弾のダメージをエネミーに与える
				//弾を消す
				//エネミーのHPがゼロ以下であれば、エネミーを消す
				//エネミーを消した時、プレイヤーのスコアに、エネミーのポイントを加算する
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
		if (enemy[i]==nullptr)
		{
			break;
		}
		enemy[i]->Draw();
	}

}