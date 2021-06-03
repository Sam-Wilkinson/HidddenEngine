#include "QBertPCH.h"
#include "TileComponent.h"
#include "InputManager.h"

TileComponent::TileComponent()
	:Component()
{
}

void TileComponent::Update()
{
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::ButtonB, XBox360Controller::ButtonEventType::OnPressed });
	if (command.lock()->execute(m_pParent.lock()) == 1)
	{
		m_pSubject->Notify(*this);
	}

}

void TileComponent::ChangeTileColor()
{
}

std::weak_ptr<Subject<TileComponent>> TileComponent::GetSubject()
{
	return m_pSubject;
	
}

