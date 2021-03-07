#pragma once
#include "Component.h"
#include "RenderComponent.h"

namespace Hidden
{
	class Font;
	class Texture2D;
	class TextComponent final : public Component
	{
	public:
		explicit TextComponent(std::weak_ptr<GameObject> pParent, const std::string& text, const std::shared_ptr<Font>& font, const std::weak_ptr<RenderComponent>& renderComponent);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

		void Update() override;
		void SetText(const std::string& text);

	private:

		bool m_NeedsUpdate;
		std::string m_Text;
		std::shared_ptr<Font> m_Font;
		std::weak_ptr<RenderComponent> m_RenderComponent;

	};

}

