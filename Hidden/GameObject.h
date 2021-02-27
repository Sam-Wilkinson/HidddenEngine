#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "Component.h"


namespace Hidden
{
	class GameObject final : public SceneObject
	{
	public:
		void Update() override;

		void SetPosition(float x, float y);
		const Transform& GetTransform() const;

		void AddComponent(const std::shared_ptr<Component>& component);

		void RemoveComponent(const std::shared_ptr<Component>& component);

		template <typename T>
		std::shared_ptr<T> GetComponent();

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform;
		std::vector<std::shared_ptr<Component>> m_Components;
	};

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent()
	{
		for (auto bc : m_Components)
		{
			if (std::dynamic_pointer_cast<std::shared_ptr<T>>(bc))
				return std::static_pointer_cast<T>(bc);
		}
		return nullptr;
	}
}
