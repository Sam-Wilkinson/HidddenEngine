#include "MiniginPCH.h"
#include "Texture2D.h"
#include <SDL.h>

Hidden::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

SDL_Texture* Hidden::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

Hidden::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_Texture = texture;
}
