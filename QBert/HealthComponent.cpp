#include "QBertPCH.h"
#include "HealthComponent.h"
#include "InputManager.h"

HealthComponent::HealthComponent(std::weak_ptr<Hidden::GameObject> pParent, size_t initialHealth)
	:Component(pParent), m_Health{initialHealth}, m_CurrentEvent{}, m_pSubject{ std::make_shared<Subject<HealthComponent>>() }
{}

void HealthComponent::Update()
{
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::ButtonA, XBox360Controller::ButtonEventType::OnPressed });
	if (std::shared_ptr<Command> shrdCommand = command.lock())
		if (shrdCommand->execute(m_pParent.lock()) == 1)
		{
			m_CurrentEvent = Event::lifeLost;
			m_pSubject->Notify(*this);
		}

	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::ButtonB, XBox360Controller::ButtonEventType::OnPressed });
	if (command.lock()->execute(m_pParent.lock()) == 1)
	{
		m_CurrentEvent = Event::death;
		m_pSubject->Notify(*this);
	}
}

const size_t HealthComponent::GetHealth() const
{
	return m_Health;
}

void HealthComponent::DecrementHealth()
{
	--m_Health;
}

void HealthComponent::SetHealth(size_t health)
{
	m_Health = health;
}

const HealthComponent::Event HealthComponent::GetCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Subject<HealthComponent>> HealthComponent::GetSubject()
{
	return m_pSubject;
}
