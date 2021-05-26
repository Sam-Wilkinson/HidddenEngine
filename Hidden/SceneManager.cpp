#include "HiddenPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Logger.h"
#include "ServiceLocator.h"

void Hidden::SceneManager::Update()
{
	m_ActiveScene.lock()->RootUpdate();
}

void Hidden::SceneManager::Render()
{
	m_ActiveScene.lock()->RootRender();
}

void Hidden::SceneManager::Destroy()
{
}


void Hidden::SceneManager::AddScene(const std::shared_ptr<Scene> pScene)
{
	auto it = std::find(m_Scenes.cbegin(), m_Scenes.cend(), pScene);

	if (it != m_Scenes.cend())
	{
		ServiceLocator::GetLoggerSystem().LogWarning("SceneManager::AddScene(const std::shared_ptr<Scene>()) - Scene was already found inside SceneManager!");
		return;
	}

	pScene->RootInitialize();

	m_Scenes.push_back(pScene);

	if (m_ActiveScene.lock() == nullptr)
	{
		m_ActiveScene = pScene;
	}

}

void Hidden::SceneManager::RemoveScene(const std::string& name)
{
	const auto it = std::find_if(m_Scenes.cbegin(), m_Scenes.cend(), [&name](std::shared_ptr<Scene> pScene)
		{
			return name == pScene->GetName();
		});

	if (it == m_Scenes.cend())
	{
		ServiceLocator::GetLoggerSystem().LogWarning("Hidden::SceneManager::RemoveScene(const std::string& name) - Scene was not found!");
		return;
	}

	if (*it == m_ActiveScene.lock())
	{
		ServiceLocator::GetLoggerSystem().LogError("Hidden::SceneManager::RemoveScene(const std::string& name) - Tried to remove the active Scene!");
		return;
	}

	m_Scenes.erase(it);
}



bool Hidden::SceneManager::SetActiveScene(const std::string& name)
{
	const auto it = std::find_if(m_Scenes.cbegin(), m_Scenes.cend(), [&name](std::shared_ptr<Scene> pScene)
		{
			return name == pScene->GetName();
		});

	if (it != m_Scenes.cend())
	{
		m_ActiveScene = *it;
		return true;
	}

	return false;
}
