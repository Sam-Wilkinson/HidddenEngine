#include "MiniginPCH.h"
#include "TextComponent.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"


Hidden::TextComponent::TextComponent(const std::string& text, const std::shared_ptr<Font>& font, const std::weak_ptr<RenderComponent>& renderComponent)
	:Component(), m_Font{ font }, m_Text{ text }, m_RenderComponent{ renderComponent }, m_NeedsUpdate{ true }
{
	Update();
}
void Hidden::TextComponent::Update()
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now

		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);

		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);

		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		std::shared_ptr<Texture2D> sharedTexture = std::make_shared<Texture2D>(texture);
		// Change texture in associated renderComponent
		m_RenderComponent.lock()->SetTexture(sharedTexture);
		m_NeedsUpdate = false;
	}
}

void Hidden::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}



