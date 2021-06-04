#pragma once
#include "Singleton.h"

struct SDL_Rect;
struct SDL_Window;
struct SDL_Renderer;

namespace Hidden
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void Init(SDL_Window* window);
		void Render();
		void Destroy();

		void RenderTexture(const Texture2D& texture, int x, int y) const;
		void RenderTexture(const Texture2D& texture, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight) const;

		void RenderTexture(const Texture2D& texture, int x, int y, int width, int height) const;
		void RenderTexture(const Texture2D& texture, int x, int y, int width, int height, int srcX, int srcY, int srcWidth, int srcHeight) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& destRect) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& destRect, const SDL_Rect& srcRect) const;

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }
	private:

		int GetOpenGLDriverIndex();

		SDL_Renderer* m_Renderer{};
		SDL_Window* m_Window;

		bool m_ShowDemo = false;

	};
}

