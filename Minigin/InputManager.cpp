#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>

Hidden::InputManager::InputManager()
	:m_pEmptyCommand{ std::make_shared<EmptyCommand>(EmptyCommand{}) }
	, m_pErrorCommand{ std::make_shared<ErrorCommand>(ErrorCommand{}) }
{
	for (int i{}; i < XUSER_MAX_COUNT; ++i)
	{
		m_Controllers.push_back({ true, std::make_unique<XBox360Controller>(XBox360Controller{}) });
	}
}


bool Hidden::InputManager::ProcessInput()
{
	for (unsigned int i{}; i < XUSER_MAX_COUNT; ++i)
	{
		m_Controllers[i].first = m_Controllers[i].second->ProcessInput(i);
	}

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		//if (e.type == SDL_KEYDOWN) {
		//
		//}
		//if (e.type == SDL_MOUSEBUTTONDOWN) {
		//
		//}
	}

	return true;

}

std::weak_ptr<Hidden::Command> Hidden::InputManager::IsPressed(std::pair<unsigned int, XBox360Controller::ControllerButton> commandKey) const
{
	if (m_Controllers[commandKey.first].first)
	{
		if (m_Controllers[commandKey.first].second->IsPressed(commandKey.second))
		{
			std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> fullCommandKey{ commandKey.first, commandKey.second, XBox360Controller::ButtonEventType::IsPressed };
			for (const auto& entry : m_ConsoleCommmands)
			{
				if (fullCommandKey == entry.first)
				{
					return entry.second;
				}
			}
		}
		return m_pEmptyCommand;
	}
	return m_pErrorCommand;
}

std::weak_ptr<Hidden::Command> Hidden::InputManager::OnPressed(std::pair<unsigned int, XBox360Controller::ControllerButton> commandKey) const
{
	if (m_Controllers[commandKey.first].first)
	{
		if (m_Controllers[commandKey.first].second->OnPressed(commandKey.second))
		{
			std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> fullCommandKey{ commandKey.first, commandKey.second, XBox360Controller::ButtonEventType::OnPressed };

			for (const auto& entry : m_ConsoleCommmands)
			{

				if (fullCommandKey == entry.first)
				{
					return entry.second;
				}
			}
		}
		return m_pEmptyCommand;
	}
	return m_pErrorCommand;
}

std::weak_ptr<Hidden::Command> Hidden::InputManager::OnReleased(std::pair<unsigned int, XBox360Controller::ControllerButton> commandKey) const
{
	// Check if controller is active
	if (m_Controllers[commandKey.first].first)
	{
		// Check if buttonEvent has triggered
		if (m_Controllers[commandKey.first].second->OnReleased(commandKey.second))
		{
			//Create commandKey based on input and function
			std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> fullCommandKey{ commandKey.first, commandKey.second, XBox360Controller::ButtonEventType::OnRelease };
			// Find related command
			for (const auto& entry : m_ConsoleCommmands)
			{
				if (fullCommandKey == entry.first)
				{
					// return related command
					return entry.second;
				}
			}
		}
		return m_pEmptyCommand;
	}
	return m_pErrorCommand;
}

std::weak_ptr<Hidden::Command> Hidden::InputManager::IsActivated(std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey) const
{
	//Check if controller is valid
	// Go to corresponding method in Controller
	// If activated, return corresponding command
	if (m_Controllers[std::get<0>(commandKey)].first)
	{
		if (m_Controllers[std::get<0>(commandKey)].second->IsActivated(std::pair< XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType>(std::get<1>(commandKey), std::get<2>(commandKey))))
		{
			for (const auto& entry : m_ConsoleCommmands)
			{
				if (commandKey == entry.first)
				{
					return entry.second;
				}
			}
		}
		return m_pEmptyCommand;
	}
	return m_pErrorCommand;
}

void Hidden::InputManager::CreateCommand(const std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey, std::shared_ptr<Command> command)
{
	m_ConsoleCommmands[commandKey] = command;
}

void Hidden::InputManager::RebindCommand(const std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey, std::shared_ptr<Command> newCommand)
{
	m_ConsoleCommmands.erase(commandKey);
	m_ConsoleCommmands[commandKey] = newCommand;
}


void Hidden::InputManager::DeleteCommand(const std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey)
{
	m_ConsoleCommmands.erase(commandKey);
}

