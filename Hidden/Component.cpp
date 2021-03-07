#include "HiddenPCH.h"
#include "Component.h"
#include "GameConfig.h"
#include "GameObject.h"

std::weak_ptr<Hidden::GameObject> Hidden::Component::GetParentGameObject() const
{
	return m_pParent;
}

Hidden::Component::Component(std::weak_ptr<GameObject> pParent)
	:m_pParent{pParent}
{
}

void Hidden::Component::SetParentGameObject(const std::shared_ptr<Hidden::GameObject>& parent)
{
	m_pParent = parent;
}