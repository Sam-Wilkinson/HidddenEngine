#include "HiddenPCH.h"
#include "FPSComponent.h"
#include "Time.h"
#include <numeric>


Hidden::FPSComponent::FPSComponent(const std::weak_ptr<GameObject> pParent, const std::weak_ptr<TextComponent> textComponent)
	:Component(pParent), m_FPS{}, m_TextComponent{ textComponent }, m_TotalTime{}
{
}
void Hidden::FPSComponent::Update()
{
	float elapsedSec = Time::GetInstance().GetTime();
	m_FPS = (m_FPS + (1/elapsedSec)) / 2.0f;
	m_TotalTime += elapsedSec;

	if (m_TotalTime > 1)
	{
		m_TextComponent.lock()->SetText(std::to_string(m_FPS));
		m_TotalTime = 0;
	}
}
