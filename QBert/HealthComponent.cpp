#include "HiddenPCH.h"
#include "HealthComponent.h"
#include "InputManager.h"

HealthComponent::HealthComponent(std::weak_ptr<Hidden::GameObject> pParent,size_t initialHealth)
	:Component(pParent), m_Health{initialHealth}, m_CurrentEvent{}, m_pSubject{ std::make_shared<Subject<HealthComponent>>() }
{}

void HealthComponent::Update()
{
	// TODO on input call notify of reduction of health or death
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::ButtonA, XBox360Controller::ButtonEventType::OnPressed });
	if (std::shared_ptr<Command> shrdCommand = command.lock())
		if(shrdCommand->execute(m_pParent.lock()) == 1)
			m_pSubject->Notify(*this);
}

const unsigned int HealthComponent::GetHealth() const
{
	return m_Health;
}

void HealthComponent::DecrementHealth()
{
	--m_Health;
}

const HealthComponent::events HealthComponent::GetCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Subject<HealthComponent>> HealthComponent::GetSubject()
{
	return m_pSubject;
}
