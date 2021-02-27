#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "Time.h"

Hidden::FPSComponent::FPSComponent(const std::weak_ptr<TextComponent> textComponent)
	:Component(), m_FPS{}, m_TextComponent{ textComponent }, m_TotalTime{}, m_NrUpdates{}
{
}

void Hidden::FPSComponent::Update()
{
	//m_FPS = 1 / Time::GetInstance().GetTime();
	
	//std::string fps = std::to_string(m_FPS).substr(0, 5);

	//m_TextComponent.lock()->SetText(fps);

	m_TotalTime += Time::GetInstance().GetTime();
	++m_NrUpdates;
	if (m_TotalTime > 1)
	{
		m_TextComponent.lock()->SetText(std::to_string(m_NrUpdates));
		m_NrUpdates = 0;
		m_TotalTime = 0;
	}
}
