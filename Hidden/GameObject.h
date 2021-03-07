#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <vector>
// TODO remove this include
#include "..\QBert\HealthComponent.h"

namespace Hidden
{
	class Component;
	class GameObject final : public SceneObject
	{
	public:
		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject & other) = delete;
		GameObject(GameObject && other) = delete;
		GameObject& operator=(const GameObject & other) = delete;
		GameObject& operator=(GameObject && other) = delete;

		void Update() override;

		void SetPosition(float x, float y);
		const Transform& GetTransform() const;

		void AddComponent(const std::shared_ptr<Component>& component);

		void RemoveComponent(const std::shared_ptr<Component>& component);

		template <typename T>
		std::shared_ptr<T> GetComponent();

	private:
		Transform m_Transform;
		std::vector<std::shared_ptr<Component>> m_Components;
	};

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent()
	{
		for (auto bc : m_Components)
		{
			auto result = std::dynamic_pointer_cast<HealthComponent>(bc);

			if (std::dynamic_pointer_cast<T>(bc))
			{
				return std::static_pointer_cast<T>(bc);
			}
		}
		return nullptr;
	}
}
