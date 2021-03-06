#include "HiddenPCH.h"
#include "FPSComponent.h"
#include "GameTime.h"
#include <numeric>


Hidden::FPSComponent::FPSComponent(const std::weak_ptr<TextComponent> textComponent)
	:Component(), m_FPS{}, m_TextComponent{ textComponent }, m_TotalTime{}
{
}
void Hidden::FPSComponent::Update()
{
	float elapsedSec = GameTime::GetInstance().GetTime();
	m_FPS = (m_FPS + (1/elapsedSec)) / 2.0f;
	m_TotalTime += elapsedSec;

	if (m_TotalTime > 1)
	{
		m_TextComponent.lock()->SetText(std::to_string(m_FPS));
		m_TotalTime = 0;
	}
}
