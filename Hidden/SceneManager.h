#pragma once
#include "Singleton.h"

namespace Hidden
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:

		void AddScene(const std::shared_ptr<Scene> pScene);
		void RemoveScene(const std::string& name);

		bool SetActiveScene(const std::string& name);

		void Update();
		void Render();

		void Destroy();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		std::weak_ptr<Scene> m_ActiveScene;
	};
}
