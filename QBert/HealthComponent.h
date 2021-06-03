#pragma once

#include "Subject.h"
#include "Component.h"

using namespace Hidden;

class HealthComponent : public Hidden::Component
{
public:

	enum class Event
	{
		lifeLost,
		death
	};

	HealthComponent(size_t initialHealth);
	~HealthComponent() = default;

	HealthComponent(const HealthComponent & other) = default;
	HealthComponent(HealthComponent && other) = default;
	HealthComponent& operator=(const HealthComponent & other) = default;
	HealthComponent& operator=(HealthComponent && other) = default;

	void Update() override;
	const size_t GetHealth() const;
	void DecrementHealth();
	void SetHealth(size_t health);
	const Event GetCurrentEvent() const;

	std::weak_ptr<Subject<HealthComponent>> GetSubject();

private:
	size_t m_Health;
	Event m_CurrentEvent;

	std::shared_ptr<Subject<HealthComponent>> m_pSubject;

};

