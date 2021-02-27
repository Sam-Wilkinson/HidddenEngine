#include "HiddenPCH.h"
#include "Xbox360Controller.h"


Hidden::XBox360Controller::XBox360Controller()
	:m_States{}
	, m_TriggerDepressionSensitivity{ 0.5f }
	, m_CurrentStateIndex{0}
	, m_PreviousStateIndex{1}
{

}

void Hidden::XBox360Controller::SwapStates()
{
	// Could potentially swap the indexes rather than use +1 % nrStates

	m_CurrentStateIndex = (m_CurrentStateIndex + 1) % m_NrStates;
	m_PreviousStateIndex = (m_PreviousStateIndex + 1) % m_NrStates;
}

bool Hidden::XBox360Controller::ProcessInput(unsigned int index)
{
	SwapStates();

	// Zero out the state information so that it is ready to be used later
	ZeroMemory(&m_States[m_CurrentStateIndex], sizeof(XINPUT_STATE));

	// Get the state of the first controller 
	if (XInputGetState(index, &m_States[m_CurrentStateIndex]) == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hidden::XBox360Controller::IsPressed(ControllerButton button) const
{
	// todo: return whether the given button is pressed or not.

	// Checks whether the currentState has the button pressed down and returns true if it does

	return m_States[m_CurrentStateIndex].Gamepad.wButtons & static_cast<int>(button);

	// Triggers check whether value is greater than sensitivity value
	//switch (button)
	//{
	//case ControllerButton::ButtonA:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A)
	//		return true;
	//	break;
	//case ControllerButton::ButtonB:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B)
	//		return true;
	//	break;
	//case ControllerButton::ButtonX:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X)
	//		return true;
	//	break;
	//case ControllerButton::ButtonY:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y)
	//		return true;
	//	break;
	//case ControllerButton::DpadDown:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
	//		return true;
	//	break;
	//case ControllerButton::DpadUp:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
	//		return true;
	//	break;
	//case ControllerButton::DpadLeft:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
	//		return true;
	//	break;
	//case ControllerButton::DpadRight:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
	//		return true;
	//	break;
	//case ControllerButton::ButtonStart:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START)
	//		return true;
	//	break;
	//case ControllerButton::ButtonBack:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
	//		return true;
	//	break;
	//case ControllerButton::ButtonLeftBack:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
	//		return true;
	//	break;
	//case ControllerButton::ButtonRightBack:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
	//		return true;
	//	break;
	//case ControllerButton::ButtonRightThumb:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)
	//		return true;
	//	break;
	//case ControllerButton::ButtonLeftThumb:
	//	if (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
	//		return true;
	//	break;
	//case ControllerButton::TriggerLeft:
	//	if (GetLeftTriggerDepression() > m_TriggerDepressionSensitivity)
	//		return true;
	//	break;
	//case ControllerButton::TriggerRight:
	//	if (GetRightTriggerDepression() > m_TriggerDepressionSensitivity)
	//		return true;
	//	break;
	//default:
	//	return false;
	//	break;
	//}
	//
	//return false;

}
 
bool Hidden::XBox360Controller::OnPressed(ControllerButton button) const
{

	// Checks whether the current state has the button pressed down and if the currentState does not match the state in the previous frame

	return m_States[m_CurrentStateIndex].Gamepad.wButtons & static_cast<int>(button) && ((m_States[m_CurrentStateIndex].Gamepad.wButtons & static_cast<int>(button)) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & static_cast<int>(button)));

	// Triggers check whether value is greater than sensitivity value and that the value was less than sensitivity value previous frame
	//switch (button)
	//{
	//case ControllerButton::ButtonA:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A))
	//		return true;
	//	break;
	//case ControllerButton::ButtonB:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B))
	//		return true;
	//	break;
	//case ControllerButton::ButtonX:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X))
	//		return true;
	//	break;
	//case ControllerButton::ButtonY:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y))
	//		return true;
	//	break;
	//case ControllerButton::DpadDown:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN))
	//		return true;
	//	break;
	//case ControllerButton::DpadUp:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP))
	//		return true;
	//	break;
	//case ControllerButton::DpadLeft:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT))
	//		return true;
	//	break;
	//case ControllerButton::DpadRight:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT))
	//		return true;
	//	break;
	//case ControllerButton::ButtonStart:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START))
	//		return true;
	//	break;
	//case ControllerButton::ButtonBack:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK))
	//		return true;
	//	break;
	//case ControllerButton::ButtonLeftBack:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER))
	//		return true;
	//	break;
	//case ControllerButton::ButtonRightBack:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER))
	//		return true;
	//	break;
	//case ControllerButton::ButtonRightThumb:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB))
	//		return true;
	//	break;
	//case ControllerButton::ButtonLeftThumb:
	//	if ((m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB))
	//		return true;
	//	break;
	//case ControllerButton::TriggerLeft:
	//	if (GetLeftTriggerDepression() > m_TriggerDepressionSensitivity && GetPreviousLeftTriggerDepression() < m_TriggerDepressionSensitivity)
	//		return true;
	//	break;
	//case ControllerButton::TriggerRight:
	//	if (GetRightTriggerDepression() > m_TriggerDepressionSensitivity && GetPreviousRightTriggerDepression() < m_TriggerDepressionSensitivity)
	//		return true;
	//	break;
	//default:
	//	return false;
	//	break;
	//}
	//
	//return false;
	//
}

bool Hidden::XBox360Controller::OnReleased(ControllerButton button) const
{

	// Checks whether the current state has the button not pressed down and if the currentState does not match the state in the previous frame

	return (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & static_cast<int>(button)) && ((m_States[m_CurrentStateIndex].Gamepad.wButtons & static_cast<int>(button)) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & static_cast<int>(button))));

	// Triggers check whether value is less than sensitivity value and that the value was greater than sensitivity value previous frame
	//switch (button)
	//{
	//case ControllerButton::ButtonA:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_A))
	//		return true;
	//	break;
	//case ControllerButton::ButtonB:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_B))
	//		return true;
	//	break;
	//case ControllerButton::ButtonX:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_X))
	//		return true;
	//	break;
	//case ControllerButton::ButtonY:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_Y))
	//		return true;
	//	break;
	//case ControllerButton::DpadDown:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN))
	//		return true;
	//	break;
	//case ControllerButton::DpadUp:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP))
	//		return true;
	//	break;
	//case ControllerButton::DpadLeft:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT))
	//		return true;
	//	break;
	//case ControllerButton::DpadRight:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT))
	//		return true;
	//	break;
	//case ControllerButton::ButtonStart:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_START))
	//		return true;
	//	break;
	//case ControllerButton::ButtonBack:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_BACK))
	//		return true;
	//	break;
	//case ControllerButton::ButtonLeftBack:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER))
	//		return true;
	//	break;
	//case ControllerButton::ButtonRightBack:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER))
	//		return true;
	//	break;
	//case ControllerButton::ButtonRightThumb:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB))
	//		return true;
	//	break;
	//case ControllerButton::ButtonLeftThumb:
	//	if (!(m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) && (m_States[m_CurrentStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != (m_States[m_PreviousStateIndex].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB))
	//		return true;
	//	break;
	//case ControllerButton::TriggerLeft:
	//	if (GetLeftTriggerDepression() < m_TriggerDepressionSensitivity && GetPreviousLeftTriggerDepression() > m_TriggerDepressionSensitivity)
	//		return true;
	//	break;
	//case ControllerButton::TriggerRight:
	//	if (GetRightTriggerDepression() < m_TriggerDepressionSensitivity && GetPreviousRightTriggerDepression() > m_TriggerDepressionSensitivity)
	//		return true;
	//	break;
	//default:
	//	return false;
	//	break;
	//}
	//
	//return false;
	//
}

bool Hidden::XBox360Controller::IsActivated(const std::pair<ControllerButton, ButtonEventType>& command) const
{
	// Check buttonEventType
	// Call appropriate function
	// return returned value

	switch (command.second)
	{
	case ButtonEventType::IsPressed:
		return IsPressed(command.first);
	case ButtonEventType::OnPressed:
		return OnPressed(command.first);
	case ButtonEventType::OnRelease:
		return OnReleased(command.first);
	}

	return false;
}

const float Hidden::XBox360Controller::GetLeftTriggerDepression() const
{
	const float range{ 255.0f };

	return float(m_States[m_CurrentStateIndex].Gamepad.bLeftTrigger / range);
}

const bool Hidden::XBox360Controller::IsLeftTriggerPressed() const
{
	return GetLeftTriggerDepression() > m_TriggerDepressionSensitivity;
}

const float Hidden::XBox360Controller::GetRightTriggerDepression() const
{
	const float range{ 255.0f };
	return float(m_States[m_CurrentStateIndex].Gamepad.bRightTrigger / range);
}

const bool Hidden::XBox360Controller::IsRightTriggerPressed() const
{
	return GetRightTriggerDepression() > m_TriggerDepressionSensitivity;
}

void Hidden::XBox360Controller::SetTriggerDepressionSensitivity(float sensitivity) 
{
	m_TriggerDepressionSensitivity = sensitivity;
}

const float Hidden::XBox360Controller::GetPreviousLeftTriggerDepression() const
{
	const float range{ 255.0f };
	return float(m_States[m_PreviousStateIndex].Gamepad.bLeftTrigger / range);
}

const float Hidden::XBox360Controller::GetPreviousRightTriggerDepression() const
{
	const float range{ 255.0f };
	return float(m_States[m_PreviousStateIndex].Gamepad.bRightTrigger / range);
}

