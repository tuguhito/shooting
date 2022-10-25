#include"DxLib.h"
#include"GameMain.h"

AbstractScene* GameMain::Update()
{
	player->Update();//�������g�̃|�C���^
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
				//�v���C���[�̒e�ƃG�l�~�[����������
				//�e�̃_���[�W���G�l�~�[�ɗ^����
				//�e������
				//�G�l�~�[��HP���[���ȉ��ł���΁A�G�l�~�[������
				//�G�l�~�[�����������A�v���C���[�̃X�R�A�ɁA�G�l�~�[�̃|�C���g�����Z����
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