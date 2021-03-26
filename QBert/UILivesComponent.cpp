#include "HiddenPCH.h"
#include "UILivesComponent.h"

UILivesComponent::UILivesComponent(std::weak_ptr<Hidden::GameObject> pParent,size_t initialHealth, const std::weak_ptr<TextComponent> textComponent)
	:Component(pParent), m_NrLives{initialHealth}, m_NeedsUpdate{false}, m_TextComponent{textComponent}
{}

void UILivesComponent::Update()
{
	if (m_pLivesObserver->IsNotified())
	{
		if (m_NrLives > 0)
		{
			m_NrLives = m_pLivesObserver->GetHealth();
			m_TextComponent.lock()->SetText("NrLives: " + std::to_string(m_NrLives));
		}

		if (m_NrLives == 0)
		{
			m_TextComponent.lock()->SetText("NrLives: " + std::to_string(0));
			std::cout << "QBert Died!\n";
		}
		
		m_pLivesObserver->SetIsNotified(false);
	}
}

void UILivesComponent::SetLivesObserver(std::shared_ptr<LivesObserver> livesObserver)
{
	m_pLivesObserver = livesObserver;
}



