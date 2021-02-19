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
			ButtonA,
			ButtonB,
			ButtonX,
			ButtonY,
			DpadDown,
			DpadUp,
			DpadLeft,
			DpadRight,
			ButtonStart,
			ButtonBack,
			ButtonLeftBack,
			ButtonRightBack,
			ButtonLeftThumb,
			ButtonRightThumb,
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

		bool IsPressed(ControllerButton button);
		bool OnPressed(ControllerButton button);
		bool OnReleased(ControllerButton button);
		bool IsActivated(const std::pair<ControllerButton, ButtonEventType>& command);

		const float GetLeftTriggerDepression();
		const float GetRightTriggerDepression();

		void setTriggerDepressionSensitivity(float sensitivity = 0.5f);

	private:
		void SwapStates();
		const float GetPreviousLeftTriggerDepression();
		const float GetPreviousRightTriggerDepression();


		static const unsigned int m_NrStates = 2;
		XINPUT_STATE m_States[m_NrStates];

		unsigned int m_CurrentStateIndex = 0;
		unsigned int m_PreviousStateIndex = 1;

		float m_TriggerDepressionSensitivity;

	};
}




