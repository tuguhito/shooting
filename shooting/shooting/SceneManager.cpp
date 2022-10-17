#include"DxLib.h"
#include"SceneManager.h"
#include"KeyManager.h"

AbstractScene* SceneManager::Update()
{

	KeyManager::Update();

	AbstractScene* nextScene = m_Scene->Update();
	if (nextScene!=m_Scene)
	{
		delete m_Scene;
		m_Scene = nextScene;
	}
	return nextScene;
}

void SceneManager::Draw() const
{
	m_Scene->Draw();
}
