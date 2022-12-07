#include"DxLib.h"
#include"GameMain.h"
#include"HpPotion.h"

AbstractScene* GameMain::Update()
{
	player->Update();//�������g�̃|�C���^
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
	//BulletBase** bullets = enemy->GetBullets();
	//EneBullet** bullets=enemy->
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
				player->Hit(bulletCount);//�e�̍폜
				bullets = player->GetBullets();
				bulletCount--;
				//�G�l�~�[��HP���[���ȉ��ł���΁A�G�l�~�[������
				if (enemy[EnemyCount]->HpCheck())
				{
					for (int i = 0; i < 10; i++)
					{
						if (items[i] == nullptr)
						{
							items[i] = new HpPotion(enemy[EnemyCount]->GetLocation());
							break;
						}
					}
					//�G�l�~�[�����������A�v���C���[�̃X�R�A�ɁA�G�l�~�[�̃|�C���g�����Z����
					player->addScore(enemy[EnemyCount]->GetPoint());//delete�O�Ɏ��s�������v���O������ł�����

					delete enemy[EnemyCount];//�G��������
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

	//���@�̓����蔻��
	for (int Enemycount = 0; Enemycount < 10; Enemycount++)//�G�L������for���@��́i�j�̒��ɋL�ڂ�����A���̃v���O�����͎��s����Ȃ�
	{
		if (enemy[Enemycount] == nullptr)
		{
			break;
		}
		BulletBase** enemyBullet = enemy[Enemycount]->GetBullets();

		for (int bulletsCount = 0; bulletsCount < 30; bulletsCount++)//�G�̒e�i�����j
		{
			if (enemyBullet[bulletsCount] == nullptr)
			{
				break;
			}

			if (enemyBullet[bulletsCount]->HitSphere(player))
			{
				//�����ɗ���Βe�ƃv���C���[���������Ă���
				player->Hit(enemyBullet[bulletsCount]);
				enemy[Enemycount]->DeleteBullet(bulletsCount);
				bulletsCount--;
			}
		}
	}


	for (int itemCount = 0; itemCount < 10; itemCount++)//�A�C�e���i�񕜃A�C�e����for���i�G��|������o�Ă���j�j
	{
		if (items[itemCount] == nullptr)
		{
			break;
		}
		if (player->HitSphere(items[itemCount]))
		{
			player->Hit(items[itemCount]);
			delete items[itemCount];
			items[itemCount] = nullptr;
			for (int i = itemCount + 1; i < 10; i++)
			{
				if (items[i] == nullptr)
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