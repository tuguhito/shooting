#include"DxLib.h"
#include"GameMain.h"

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
				player->Hit(bulletCount);//�e�̍폜
				bullets = player->GetBullets();
				bulletCount--;
				//�G�l�~�[��HP���[���ȉ��ł���΁A�G�l�~�[������
				if (enemy[EnemyCount]->HpCheck())
				{
					//�G�l�~�[�����������A�v���C���[�̃X�R�A�ɁA�G�l�~�[�̃|�C���g�����Z����
					player->addScore(enemy[EnemyCount]->GetPoint());//delete�O�Ɏ��s�������v���O������ł�����

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

}