#pragma once
#include"AbstractScene.h"

class SceneManager : public AbstractScene
{
private:
	AbstractScene* m_Scene;

public:
	SceneManager(AbstractScene* scene) : m_Scene(scene) {}

	~SceneManager()
	{
		delete m_Scene;
	}
	AbstractScene* Update() override;

	void Draw() const override;
};