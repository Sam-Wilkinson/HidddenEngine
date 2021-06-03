#include "HiddenPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include <algorithm>

#include "Component.h"
#include "ServiceLocator.h"

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
	const glm::vec3& t = m_Transform.GetPosition();
	m_Transform.SetPosition(x, y, t.z);
}


const Hidden::Transform& Hidden::GameObject::GetTransform() const
{
	return m_Transform;
}

void Hidden::GameObject::SetLayer(float z)
{
	const glm::vec3& t = m_Transform.GetPosition();
	m_Transform.SetPosition(t.x, t.y, z);
}

void Hidden::GameObject::AddComponent(const std::shared_ptr<Component>& component)
{
	auto it = std::find(m_Components.cbegin(), m_Components.cend(), component);

	if (it != m_Components.cend())
	{
		ServiceLocator::GetLoggerSystem().LogWarning("Hidden::GameObject::AddComponent(const std::shared_ptr<Component>& component) - Tried to add a component that was already in GameObject!");
	}

	component->SetParentGameObject(this->shared_from_this());
	m_Components.push_back(component);
}

void Hidden::GameObject::RemoveComponent(const std::shared_ptr<Component>& component)
{

	auto it = std::remove(m_Components.begin(), m_Components.end(), component);

	if (it != m_Components.end())
	{
		it->get()->RemoveParentGameObject(this->shared_from_this());
		m_Components.erase(it, m_Components.end());
		return;
	}

	ServiceLocator::GetLoggerSystem().LogWarning("Hidden::GameObject::RemoveComponent(const std::shared_ptr<Component>& component) - Component not found within GameObject");
	return;

}

bool Hidden::GameObject::GetIsActive()
{
	return m_IsActive;
}

void Hidden::GameObject::SetIsActive(bool isActive)
{
	m_IsActive = isActive;
}



