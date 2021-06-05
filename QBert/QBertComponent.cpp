#include "QBertPCH.h"
#include "QBertComponent.h"
#include "InputManager.h"

#include "MoveUpRightCommand.h"
#include "MoveUpLeftCommand.h"
#include "MoveDownLeftCommand.h"
#include "MoveDownRightCommand.h"

QBertComponent::QBertComponent(std::weak_ptr<SpriteComponent> spriteComponent)
	:Component(), m_pSubject{ std::make_shared<Subject<QBertComponent>>()}, m_CurrentEvent{Event::endStage}, m_SpriteComponent{spriteComponent}
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
	
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadUp, XBox360Controller::ButtonEventType::OnPressed });
	if (command.lock()->execute(m_pParent.lock()))
	{
		// Change the state and sprite
	}

	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadRight, XBox360Controller::ButtonEventType::OnPressed });
	command.lock()->execute(m_pParent.lock());

	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadLeft, XBox360Controller::ButtonEventType::OnPressed });
	command.lock()->execute(m_pParent.lock());

	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadDown, XBox360Controller::ButtonEventType::OnPressed });
	command.lock()->execute(m_pParent.lock());






}

const QBertComponent::Event QBertComponent::GetCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Subject<QBertComponent>> QBertComponent::GetSubject()
{
    return m_pSubject;
}
