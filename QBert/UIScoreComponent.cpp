#include "QBertPCH.h"
#include "UIScoreComponent.h"

UIScoreComponent::UIScoreComponent(std::weak_ptr<Hidden::GameObject> pParent, size_t initialScore, const std::weak_ptr<TextComponent> textComponent)
	:Component(pParent), m_Score{initialScore}, m_TextComponent{textComponent}
{
}

void UIScoreComponent::Update()
{
	if (m_pQbertObserver->IsNotified())
	{
		m_Score = m_pQbertObserver->GetScore();
		m_TextComponent.lock()->SetText("Score: " + std::to_string(m_Score));

		m_pQbertObserver->SetIsNotified(false);
	}
}

void UIScoreComponent::SetQBertObserver(std::shared_ptr<QBertObserver> qBertObserver)
{
	m_pQbertObserver = qBertObserver;
}
