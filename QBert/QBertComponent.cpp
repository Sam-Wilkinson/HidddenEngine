#include "HiddenPCH.h"
#include "QBertComponent.h"
#include "InputManager.h"

QBertComponent::QBertComponent(std::weak_ptr<Hidden::GameObject> pParent)
	:Component(pParent), m_pSubject{ std::make_shared<Subject<QBertComponent>>()}, m_CurrentEvent{Event::endStage}
{
}

void QBertComponent::Update()
{
	auto command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadUp, XBox360Controller::ButtonEventType::OnPressed });
	if (std::shared_ptr<Command> shrdCommand = command.lock())
		if (shrdCommand->execute(m_pParent.lock()) == 1)
		{
			m_CurrentEvent = Event::coughtSlickOrSam;
			m_pSubject->Notify(*this);
		}

	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadDown, XBox360Controller::ButtonEventType::OnPressed });
	if (std::shared_ptr<Command> shrdCommand = command.lock())
		if (shrdCommand->execute(m_pParent.lock()) == 1)
		{
			m_CurrentEvent = Event::defeatedCoily;
			m_pSubject->Notify(*this);
		}
	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadLeft, XBox360Controller::ButtonEventType::OnPressed });
	if (std::shared_ptr<Command> shrdCommand = command.lock())
		if (shrdCommand->execute(m_pParent.lock()) == 1)
		{
			m_CurrentEvent = Event::endStage;
			m_pSubject->Notify(*this);
		}
	command = InputManager::GetInstance().IsActivated({ 0,XBox360Controller::ControllerButton::DpadRight, XBox360Controller::ButtonEventType::OnPressed });
	if (std::shared_ptr<Command> shrdCommand = command.lock())
		if (shrdCommand->execute(m_pParent.lock()) == 1)
		{
			m_CurrentEvent = Event::tileColorChange;
			m_pSubject->Notify(*this);
		}


}

const QBertComponent::Event QBertComponent::GetCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Subject<QBertComponent>> QBertComponent::GetSubject()
{
    return m_pSubject;
}