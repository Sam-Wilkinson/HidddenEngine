#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void Hidden::SceneManager::Update()
{
	for(auto& scene : m_Scenes)
	{
		scene->Update();
	}
}

void Hidden::SceneManager::Render()
{
	for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}
}

void Hidden::SceneManager::Destroy()
{
}

Hidden::Scene& Hidden::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *scene;
}
