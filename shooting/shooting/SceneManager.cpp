#include"DxLib.h"
#include"SceneManager.h"

AbstractScene* SceneManager::Update()
{
	AbstractScene* p = m_Scene->Update();
	if (p!=m_Scene)
	{
		delete m_Scene;
		m_Scene = p;
	}
	return p;
}

void SceneManager::Draw() const
{
	m_Scene->Draw();
}
