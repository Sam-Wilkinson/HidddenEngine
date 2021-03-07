#pragma once
#include "Observer.h"
#include "HealthComponent.h"

using namespace Hidden;

class LivesObserver : public Hidden::Observer<HealthComponent>
{
public:
	LivesObserver() = default;
	virtual ~LivesObserver() = default;


	LivesObserver(const LivesObserver & other) = default; // copy constructor
	LivesObserver(LivesObserver && other) noexcept = default; // move constructor
	LivesObserver& operator=(const LivesObserver & other) = default; // copy assignment
	LivesObserver& operator=(LivesObserver && other) noexcept = default; // move assignment

	virtual void onNotify(const HealthComponent & data);

	HealthComponent::Event m_Event{};
	size_t m_Health{};
protected:

private:

};

