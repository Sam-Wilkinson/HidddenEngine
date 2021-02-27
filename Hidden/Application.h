#pragma once
struct SDL_Window;

namespace Hidden
{
	class Application
	{
	public:
		void Initialize();
		virtual void LoadGame() const;
		virtual void Cleanup();
		void Run();
	private:
		SDL_Window* m_Window{};

		void LoadDemo() const ;

	};

	// To be defined in client
	Application* CreateApplication();

}