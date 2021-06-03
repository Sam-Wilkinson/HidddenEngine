#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <vector>
// TODO remove this include
#include "..\QBert\HealthComponent.h"
#include "ServiceLocator.h"

namespace Hidden
{
	class Component;
	class GameObject final : std::enable_shared_from_this<GameObject>
	{
	public:
		GameObject(bool isActive = true);
		virtual ~GameObject();
		GameObject(const GameObject & other) = delete;
		GameObject(GameObject && other) = delete;
		GameObject& operator=(const GameObject & other) = delete;
		GameObject& operator=(GameObject && other) = delete;

		void Update();

		void SetPosition(float x, float y);
		const Transform& GetTransform() const;

		void AddComponent(const std::shared_ptr<Component>& component);

		void RemoveComponent(const std::shared_ptr<Component>& component);

		bool GetIsActive();
		void SetIsActive(bool isActive);

		template <typename T>
		std::shared_ptr<T> GetComponent();

	private:
		bool m_IsActive;
		Transform m_Transform;
		std::vector<std::shared_ptr<Component>> m_Components;

	};

	template<typename T>
	inline std::shared_ptr<T> GameObject::GetComponent()
	{
		for (auto bc : m_Components)
		{
			if (std::dynamic_pointer_cast<T>(bc))
			{
				return std::static_pointer_cast<T>(bc);
			}
		}
		
		ServiceLocator::GetLoggerSystem().LogWarning("GameObject::GetComponent() - Component not found within game object, returning nullptr!");
		return nullptr;
	}
}
