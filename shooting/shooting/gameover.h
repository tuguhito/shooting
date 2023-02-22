#pragma once
#include "SceneManager.h"
class gameover:public AbstractScene
{
private:
	int life;

public:
	gameover();
	virtual ~gameover() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

