#include "HiddenPCH.h"
#include "TileComponent.h"
#include "InputManager.h"

void TileComponent::Update()
{
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::ButtonB, XBox360Controller::ButtonEventType::OnPressed });
	if (command.lock()->execute(m_pParent.lock()) == 0)
	{
		m_CurrentEvent = events::colorChange;
		m_pSubject->Notify(*this);
	}

}

const TileComponent::events TileComponent::GetCurrentEvent() const
{
    return m_CurrentEvent;
}
