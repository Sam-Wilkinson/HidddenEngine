#pragma once
struct SDL_Window;

namespace Hidden
{
	class Application
	{
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();
	private:
		SDL_Window* m_Window{};
	};

	// To be defined in client
	Application* CreateApplication();

}