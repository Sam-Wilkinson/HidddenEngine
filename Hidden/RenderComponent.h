#pragma once
#include "Component.h"
#include "Texture2D.h"
#include "TextureData.h"
#include "SDL.h"

namespace Hidden
{
	class RenderComponent final : public Component
	{
	public:
		RenderComponent();
		~RenderComponent();

		void SetTexture(const std::string& filename);
		void SetTexture(std::shared_ptr<Texture2D> texture);

		void SetDestinationSize(const SDL_Point& destSize);
		void SetDestinationSize(int width, int height);
		void RemoveDestinationSize();
		void SetSourceRect(const SDL_Rect& srcRect);
		void RemoveSourceRect();

		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Update() override;
		virtual void Render() const override;


	private:
		std::shared_ptr<Texture2D> m_Texture;
		SDL_Point m_DestinationSize{};
		SDL_Rect m_SourceRect{};
		bool m_SizeDefined;
		bool m_SourceDefined;
	};

}

