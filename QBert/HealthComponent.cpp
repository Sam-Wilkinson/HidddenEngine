#include "HiddenPCH.h"
#include "HealthComponent.h"

HealthComponent::HealthComponent(size_t initialHealth)
	:Component(), m_Health{initialHealth}, m_CurrentEvent{}, m_pSubject{ std::make_shared<Subject<HealthComponent>>() }
{}

void HealthComponent::Update()
{
	// TODO on input call notify of reduction of health or death
	--m_Health;
	m_pSubject->Notify(*this);
}

const unsigned int HealthComponent::getHealth() const
{
	return m_Health;
}

const HealthComponent::events HealthComponent::getCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Subject<HealthComponent>> HealthComponent::GetSubject()
{
	return m_pSubject;
}
