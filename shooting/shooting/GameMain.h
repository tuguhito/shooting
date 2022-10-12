#pragma once
#include"SceneManager.h"
#include "player.h"
class GameMain : public AbstractScene
{
private:
	Player Player;
public:
	GameMain()
	{

	}

	virtual ~GameMain() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};