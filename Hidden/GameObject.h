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
}
