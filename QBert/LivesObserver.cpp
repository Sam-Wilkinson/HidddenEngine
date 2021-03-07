#include "LivesObserver.h"

void LivesObserver::onNotify(const HealthComponent& data)
{
	m_Event = data.GetCurrentEvent();

	if (m_Event == HealthComponent::Event::lifeLost)
	{
		m_Health = data.GetHealth();
		m_IsNotified = true;
	} 
	else if (m_Event == HealthComponent::Event::death)
	{
		m_Health = data.GetHealth();
		m_IsNotified = true;
	}
}


