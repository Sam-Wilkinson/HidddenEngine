#include "HiddenPCH.h"
#include "Component.h"
#include "GameConfig.h"
#include "GameObject.h"
#include "ServiceLocator.h"

std::weak_ptr<Hidden::GameObject> Hidden::Component::GetParentGameObject() const
{
	return m_pParent;
}

Hidden::Component::Component()
	:m_pParent {}
{

}

//Hidden::Component::Component(std::weak_ptr<GameObject> pParent)
//	:m_pParent{pParent}
//{
//}

void Hidden::Component::Render()
{
}

void Hidden::Component::SetParentGameObject(std::weak_ptr<Hidden::GameObject> parent)
{
	if (!m_pParent.expired())
	{
		ServiceLocator::GetLoggerSystem().LogError("Hidden::Component::SetParentGameObject(std::weak_ptr<Hidden::GameObject> parent) - Component already has a parent! Parent of component not updated!");
		return;
	}
	m_pParent = parent;
}