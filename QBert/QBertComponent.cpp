#include "QBertPCH.h"
#include "QBertComponent.h"
#include "InputManager.h"
#include "GameTime.h"

#include "MoveUpRightCommand.h"
#include "MoveUpLeftCommand.h"
#include "MoveDownLeftCommand.h"
#include "MoveDownRightCommand.h"

QBertComponent::QBertComponent(std::weak_ptr<SpriteComponent> spriteComponent)
	:Component(), 
	m_pSubject{ std::make_shared<Subject<QBertComponent>>()}, 
	m_CurrentEvent{Event::endStage}, 
	m_SpriteComponent{ spriteComponent },
	m_CurrentState{State::standing},
	m_CurrentRotation{Rotation::frontLeft},
	m_deltaTime{}
{
	//TODO set up commands with input manager 

	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadUp, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<MoveUpLeftCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadRight, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<MoveUpRightCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadLeft, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<MoveDownLeftCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadDown, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<MoveDownRightCommand>());


}

void QBertComponent::Update()
{
	// TODO process commands to move qbert 
	if (m_CurrentState != State::moving)
	{
		auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadUp, XBox360Controller::ButtonEventType::OnPressed });
		if (command.lock()->execute(m_pParent.lock()))
		{
			// Change the state and sprite
			m_CurrentRotation = Rotation::backLeft;
			m_CurrentState = State::moving;
		}

		command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadRight, XBox360Controller::ButtonEventType::OnPressed });
		if(command.lock()->execute(m_pParent.lock()))
		{
			m_CurrentRotation = Rotation::backRight;
			m_CurrentState = State::moving;
		}

		command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadLeft, XBox360Controller::ButtonEventType::OnPressed });
		if (command.lock()->execute(m_pParent.lock()))
		{
			m_CurrentRotation = Rotation::frontLeft;
			m_CurrentState = State::moving;
		}

		command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadDown, XBox360Controller::ButtonEventType::OnPressed });
		if (command.lock()->execute(m_pParent.lock()))
		{
			m_CurrentRotation = Rotation::frontRight;
			m_CurrentState = State::moving;
		}
	}
	else
	{
		m_deltaTime += GameTime::GetTime();

		if (m_deltaTime > 0.5f)
		{
			m_CurrentState = State::standing;
			m_deltaTime = 0;
		}
	}

	ProcessSprite();

}

const QBertComponent::Event QBertComponent::GetCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Subject<QBertComponent>> QBertComponent::GetSubject()
{
    return m_pSubject;
}

void QBertComponent::ProcessSprite()
{
	auto spriteComponent = m_SpriteComponent.lock();

	spriteComponent->SetCol((static_cast<int>(m_CurrentRotation) * 2) + static_cast<int>(m_CurrentState));
}
