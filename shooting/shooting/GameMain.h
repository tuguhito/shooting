#pragma once
#include"SceneManager.h"
#include "player.h"
class GameMain : public AbstractScene
{
private:
	Player* player;

public:
	GameMain()
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius=10.f;

		player = new Player(location, radius);

	}

	virtual ~GameMain() 
	{
		delete player;
	};

	virtual AbstractScene* Update() override;

	virtual void Draw() const override;
};