#include "HiddenPCH.h"
#include "HealthComponent.h"

void HealthComponent::Update()
{
	m_pSubject.lock()->Notify(*this);
}

const unsigned int HealthComponent::getHealth() const
{
	return m_Health;
}

std::weak_ptr<Subject<HealthComponent>> HealthComponent::GetSubject()
{
	return m_pSubject;
}
