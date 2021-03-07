#include "HiddenPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include <algorithm>

#include "Component.h"

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
	m_Components.push_back(component);
}

void Hidden::GameObject::RemoveComponent(const std::shared_ptr<Component>& component)
{
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), component));
}



