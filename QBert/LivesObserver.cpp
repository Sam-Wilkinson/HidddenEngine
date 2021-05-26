#include "QBertPCH.h"
#include "LivesObserver.h"

void LivesObserver::onNotify(const HealthComponent& data)
{
	HealthComponent::Event e = data.GetCurrentEvent();

	if (e== HealthComponent::Event::lifeLost)
	{
		m_Health = data.GetHealth();
		m_IsNotified = true;
	} 
	else if (e == HealthComponent::Event::death)
	{
		m_Health = data.GetHealth();
		m_IsNotified = true;
	}
}

bool LivesObserver::IsNotified()
{
	return m_IsNotified;
}

void LivesObserver::SetIsNotified(bool isNotified)
{
	m_IsNotified = isNotified;
}

HealthComponent::Event LivesObserver::GetEvent()
{
	return m_Event;
}

size_t LivesObserver::GetHealth()
{
	return m_Health;
}


