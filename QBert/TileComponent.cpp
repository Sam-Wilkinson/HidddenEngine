#include "QBertPCH.h"
#include "TileComponent.h"
#include "InputManager.h"
#include "SpriteComponent.h"

TileComponent::TileComponent(size_t row, size_t col, std::weak_ptr<SpriteComponent> spriteComponent)
	:Component()
	,m_pSpriteComponent{spriteComponent}
	,m_Row{row}
	,m_Col{ col }
	,m_pSubject{}
{
}

void TileComponent::Update()
{
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::ButtonB, XBox360Controller::ButtonEventType::OnPressed });
	if (command.lock()->execute(m_pParent.lock()) == 1)
	{
		//m_pSubject->Notify(*this);

		m_pSpriteComponent.lock()->IncrementRow();
	}

}

void TileComponent::ChangeTileColor()
{
}

std::weak_ptr<Subject<TileComponent>> TileComponent::GetSubject()
{
	return m_pSubject;
	
}

