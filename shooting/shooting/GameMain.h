#pragma once
#include"SceneManager.h"
#include "player.h"
#include"Enemy.h"
class GameMain : public AbstractScene
{
private:
	Player* player;
	Enemy** enemy;

public:
	GameMain()
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius=10.f;

		player = new Player(location, radius);

		enemy = new Enemy*[10];

		for (int i = 0; i < 10; i++)
		{
			enemy[i] = nullptr;
		}
		enemy[0] = new Enemy(T_Location{300, 0}, 20);

	}

	virtual ~GameMain() 
	{
		delete player;
	};

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};