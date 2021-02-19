#pragma once
#include <XInput.h>
#include "Singleton.h"
#include <map>
#include "XBox360Controller.h"
#include "Command.h"
#include "EmptyCommand.h"
#include "ErrorCommand.h"
#include <vector>

namespace Hidden
{
	class InputManager final : public Singleton<InputManager>
	{
	public:

		friend class Singleton;

		InputManager(const InputManager& other) = default; // copy constructor
		InputManager(InputManager&& other) noexcept = default; // move constructor
		InputManager& operator=(const InputManager& other) = default; // copy assignment
		InputManager& operator=(InputManager&& other) noexcept = default; // move assignment

		bool ProcessInput();
		std::weak_ptr<Command> IsPressed(std::pair<unsigned int, XBox360Controller::ControllerButton> commandKey) const;
		std::weak_ptr<Command> OnPressed(std::pair<unsigned int, XBox360Controller::ControllerButton> commandKey) const;
		std::weak_ptr<Command> OnReleased(std::pair<unsigned int, XBox360Controller::ControllerButton> commandKey) const;
		std::weak_ptr<Command> IsActivated(std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey) const;

		void CreateCommand(const std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey, std::shared_ptr<Command> command);
		void RebindCommand(const std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey, std::shared_ptr<Command> newCommand);
		void DeleteCommand(const std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType> commandKey);

	private:
		InputManager();
		virtual ~InputManager() = default;

		std::map<std::tuple<unsigned int, XBox360Controller::ControllerButton, XBox360Controller::ButtonEventType>, std::shared_ptr<Command>> m_ConsoleCommmands;

		std::vector<std::pair<bool, std::unique_ptr<XBox360Controller>>> m_Controllers{};

		std::shared_ptr<Command> m_pEmptyCommand;
		std::shared_ptr<Command> m_pErrorCommand;
	};
}
