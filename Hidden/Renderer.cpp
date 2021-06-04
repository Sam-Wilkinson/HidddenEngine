#include "HiddenPCH.h"
#include "Renderer.h"
#include <SDL.h>
#include "SceneManager.h"
#include "Texture2D.h"


void Hidden::Renderer::Init(SDL_Window * window)
{
	m_Window = window;
	m_Renderer = SDL_CreateRenderer(window, GetOpenGLDriverIndex(), SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(window, SDL_GL_GetCurrentContext());
	ImGui_ImplOpenGL2_Init();

}

void Hidden::Renderer::Render()
{
	SDL_RenderClear(m_Renderer);

	SceneManager::GetInstance().Render();

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(m_Window);
	ImGui::NewFrame();
	if (m_ShowDemo)
	{
		ImGui::ShowDemoWindow(&m_ShowDemo);
	}
	ImGui::Begin("Game Modes");
	ImGui::Button("single player");
	ImGui::Button("co-op");
	ImGui::Button("versus");

	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	
	SDL_RenderPresent(m_Renderer);
}

void Hidden::Renderer::Destroy()
{

	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	if (m_Renderer != nullptr)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void Hidden::Renderer::RenderTexture(const Texture2D& texture, const int x, const int y) const
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

void Hidden::Renderer::RenderTexture(const Texture2D& texture, const int x, const int y, const int width, const int height) const
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = width;
	dst.h = height;
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

void Hidden::Renderer::RenderTexture(const Texture2D& texture, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight) const
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);

	SDL_Rect src;
	src.x = srcX;
	src.y = srcY;
	src.w = srcWidth;
	src.h = srcHeight;

	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &src, &dst);
}

void Hidden::Renderer::RenderTexture(const Texture2D& texture, int x, int y, int width, int height, int srcX, int srcY, int srcWidth, int srcHeight) const
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = width;
	dst.h = height;

	SDL_Rect src;
	src.x = srcX;
	src.y = srcY;
	src.w = srcWidth;
	src.h = srcHeight;

	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &src, &dst);
}

void Hidden::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& destRect) const
{
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr,  &destRect);
}

void Hidden::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& destRect, const SDL_Rect& srcRect) const
{
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &srcRect, &destRect);
}


int Hidden::Renderer::GetOpenGLDriverIndex()
{
	auto openglIndex = -1;
	const auto driverCount = SDL_GetNumRenderDrivers();
	for (int i = 0; i < driverCount; ++i)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
			if (!strcmp(info.name, "opengl"))
				openglIndex = i;
	}
	return openglIndex;
}
