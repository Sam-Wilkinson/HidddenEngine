#include "QBertPCH.h"
#include "TileComponent.h"
#include "InputManager.h"
#include "SpriteComponent.h"

TileComponent::TileComponent(size_t row, size_t col, std::weak_ptr<SpriteComponent> spriteComponent)
	:Component()
	,m_pSpriteComponent{spriteComponent}
	,m_Row{row}
	,m_Col{col}
	,m_pSubject{std::make_shared<Subject<TileComponent>>()}
	,m_pObserver{std::make_shared<MovementObserver>()}
	,m_HasChanged{false}
{
}

void TileComponent::Update()
{
	if (m_pObserver->IsNotified())
	{
		size_t row = m_pObserver->GetRow();
		size_t col = m_pObserver->GetColumn();

		if (row == m_Row && col == m_Col)
		{
			ChangeTileColor();
		}
		m_pObserver->SetIsNotified(false);
	}
}

void TileComponent::ChangeTileColor()
{
	m_pSpriteComponent.lock()->IncrementRow();
}

std::weak_ptr<Subject<TileComponent>> TileComponent::GetSubject()
{
	return m_pSubject;
	
}

std::shared_ptr<Observer<MovementComponent>> TileComponent::GetObserver()
{
	return m_pObserver;
}

