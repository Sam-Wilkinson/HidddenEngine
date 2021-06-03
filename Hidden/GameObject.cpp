#include "HiddenPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include <algorithm>

#include "Component.h"

Hidden::GameObject::GameObject(bool isActive)
	:m_IsActive{isActive}
{
}

Hidden::GameObject::~GameObject() = default;

void Hidden::GameObject::Update()
{
	for (auto& component : m_Components)
	{
		component->Update();
	}
}

void Hidden::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

const Hidden::Transform& Hidden::GameObject::GetTransform() const
{
	return m_Transform;
}

void Hidden::GameObject::AddComponent(const std::shared_ptr<Component>& component)
{
	component->SetParentGameObject(this->shared_from_this());
	m_Components.push_back(component);
}

void Hidden::GameObject::RemoveComponent(const std::shared_ptr<Component>& component)
{
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), component));
}

bool Hidden::GameObject::GetIsActive()
{
	return m_IsActive;
}

void Hidden::GameObject::SetIsActive(bool isActive)
{
	m_IsActive = isActive;
}



