#include "HiddenPCH.h"
#include "UILivesComponent.h"

UILivesComponent::UILivesComponent(std::weak_ptr<Hidden::GameObject> pParent,size_t initialHealth, const std::weak_ptr<TextComponent> textComponent)
	:Component(pParent), m_NrLives{initialHealth}, m_NeedsUpdate{false}, m_TextComponent{textComponent}
{}

void UILivesComponent::Update()
{
	if (m_pLivesObserver->GetIsNotified())
	{
		HealthComponent::Event healthEvent = m_pLivesObserver->m_Event;
		if (healthEvent == HealthComponent::Event::lifeLost)
		{
			if (m_NrLives != 0)
			{
				m_NrLives = m_pLivesObserver->m_Health;
				m_TextComponent.lock()->SetText("NrLives: " + std::to_string(m_NrLives));
			}
		}
		else if (healthEvent == HealthComponent::Event::death)
		{
			m_TextComponent.lock()->SetText("NrLives: " + std::to_string(0));
			std::cout << "QBert Died!\n";
		}

		m_pLivesObserver->SetIsNotified(false);
	}


	if (m_NeedsUpdate == true)
	{
		std::cout << "UILivesNeedsUpdating\n";

		m_NeedsUpdate = false;
	}
}

void UILivesComponent::SetLivesObserver(std::shared_ptr<LivesObserver> livesObserver)
{
	m_pLivesObserver = livesObserver;
}



