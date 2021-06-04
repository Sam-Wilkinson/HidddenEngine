#pragma once
struct SDL_Window;

namespace Hidden
{
	class Application
	{
	public:
		virtual void Initialize();
		virtual void LoadGame() const;
		virtual void Cleanup();
		void Run();

	protected:
		SDL_Window* m_Window{};

	private:

		void LoadDemo() const ;

	};

	// To be defined in client
	Application* CreateApplication();

}