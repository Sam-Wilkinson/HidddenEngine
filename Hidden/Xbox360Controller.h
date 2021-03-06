#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <memory>

namespace Hidden
{
	class XBox360Controller
	{
	public:
		enum class ControllerButton
		{

			NoAction,

			ButtonA = XINPUT_GAMEPAD_A,
			ButtonB = XINPUT_GAMEPAD_B,
			ButtonX = XINPUT_GAMEPAD_X,
			ButtonY = XINPUT_GAMEPAD_Y,

			DpadDown = XINPUT_GAMEPAD_DPAD_DOWN,
			DpadUp = XINPUT_GAMEPAD_DPAD_UP,
			DpadLeft = XINPUT_GAMEPAD_DPAD_LEFT,
			DpadRight = XINPUT_GAMEPAD_DPAD_RIGHT,

			ButtonStart = XINPUT_GAMEPAD_START,
			ButtonBack = XINPUT_GAMEPAD_BACK,

			ButtonLeftBack = XINPUT_GAMEPAD_LEFT_SHOULDER,
			ButtonRightBack = XINPUT_GAMEPAD_RIGHT_SHOULDER,
			ButtonLeftThumb = XINPUT_GAMEPAD_LEFT_THUMB,
			ButtonRightThumb = XINPUT_GAMEPAD_RIGHT_THUMB,

			TriggerLeft,
			TriggerRight
		};

		enum class ButtonEventType
		{
			IsPressed,
			OnPressed,
			OnRelease
		};

		XBox360Controller();

		virtual ~XBox360Controller() = default;
		XBox360Controller(const XBox360Controller& other) = default; // copy constructor
		XBox360Controller(XBox360Controller&& other) noexcept = default; // move constructor
		XBox360Controller& operator=(const XBox360Controller& other) = default; // copy assignment
		XBox360Controller& operator=(XBox360Controller&& other) noexcept = default; // move assignment

		bool ProcessInput(unsigned int index);

		bool IsPressed(ControllerButton button) const;
		bool OnPressed(ControllerButton button) const;
		bool OnReleased(ControllerButton button) const;
		bool IsActivated(const std::pair<ControllerButton, ButtonEventType>& command) const;

		const float GetLeftTriggerDepression() const;
		const bool IsLeftTriggerPressed() const;
		const float GetRightTriggerDepression() const;
		const bool IsRightTriggerPressed() const;
		void SetTriggerDepressionSensitivity(float sensitivity = 0.5f);

	private:
		void SwapStates();
		const float GetPreviousLeftTriggerDepression() const;
		const float GetPreviousRightTriggerDepression() const;


		static const unsigned int m_NrStates = 2;
		XINPUT_STATE m_States[m_NrStates];

		unsigned int m_CurrentStateIndex;
		unsigned int m_PreviousStateIndex ;

		float m_TriggerDepressionSensitivity;

	};
}




