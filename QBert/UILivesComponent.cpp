#include "HiddenPCH.h"
#include "UILivesComponent.h"

void UILivesComponent::Update()
{
	if (m_NeedsUpdate == true)
	{
		std::cout << "UILivesNeedsUpdating\n";
		m_NeedsUpdate = false;
	}
}

void UILivesComponent::onNotify(const HealthComponent& data)
{
	// Change nr lives based on nr of lives in health component
	m_NrLives = data.getHealth();
	m_NeedsUpdate = true;
	// if lived = 0, death!!!

}
