#pragma once
#include "SceneManager.h"
class gameclear:public AbstractScene
{
private:
	int hp;
public:
	gameclear();
	virtual ~gameclear() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

};

