#include "HiddenPCH.h"
#include "UILivesComponent.h"

UILivesComponent::UILivesComponent(std::weak_ptr<Hidden::GameObject> pParent,size_t initialHealth, const std::weak_ptr<TextComponent> textComponent)
	:Component(pParent), Observer(), m_NrLives{initialHealth}, m_NeedsUpdate{false}, m_TextComponent{textComponent}
{}

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
	HealthComponent::events event = data.GetCurrentEvent();
	if(event == HealthComponent::events::lifeLost )
	{
		if(m_NrLives != 0)
		{
			m_NrLives = data.GetHealth();
			m_TextComponent.lock()->SetText("NrLives: " + std::to_string(m_NrLives));
		}
	}
	else if(event == HealthComponent::events::death)
	{
		std::cout << "Player died!\n";
	}
}


