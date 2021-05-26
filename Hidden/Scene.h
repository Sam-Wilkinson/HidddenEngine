#pragma once
#include "SceneManager.h"
#include "RenderComponent.h"

namespace Hidden
{

	class SceneObject;
	class Scene
	{
	public:
		explicit Scene(const std::string& name);
		virtual ~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		const std::string& GetName();

		void RootInitialize();
		void RootUpdate();
		virtual void RootRender() const;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() const = 0 ;

	protected:
		void Add(const std::shared_ptr<SceneObject>& object);
		void AddRenderable(const std::weak_ptr<RenderComponent>& renderComponent);
		void Remove(const SceneObject& object);
		void RemoveRenderable(const RenderComponent& renderComponent);

	private: 
		std::string m_Name;

		std::vector<std::shared_ptr<SceneObject>> m_Objects{};
		std::vector<std::weak_ptr<RenderComponent>> m_Renderables{};
	};

}
