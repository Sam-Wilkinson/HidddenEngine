#include "HiddenPCH.h"
#include "Application.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
//#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include "GameTime.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"

using namespace std;
using namespace std::chrono;

void Hidden::Application::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);

}

/**
 * Code constructing the scene world starts here
 */
void Hidden::Application::LoadGame() const
{
	LoadDemo();
}

void Hidden::Application::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void Hidden::Application::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	auto& renderer = Renderer::GetInstance();
	auto& sceneManager = SceneManager::GetInstance();
	auto& input = InputManager::GetInstance();

	bool doContinue = true;
	auto lastTime = high_resolution_clock::now();
	while (doContinue)
	{
		const auto currentTime = high_resolution_clock::now();
		// deltaTime = how much time has passed since the last frame
		GameTime::GetInstance().SetTime(duration<float>(currentTime - lastTime).count());

		doContinue = input.ProcessInput();
		sceneManager.Update();
		renderer.Render();

		lastTime = currentTime;

		const auto sleepTime = currentTime + milliseconds(GameConfig::MsPerFrame) - high_resolution_clock::now();
		this_thread::sleep_for(sleepTime);
	}
	
	Cleanup();
	Application::Cleanup();
}


void Hidden::Application::LoadDemo() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	// Register components here

	auto go = std::make_shared<GameObject>();
	// Create RenderComponent and add Texture to it
	auto renderComponent = std::make_shared<RenderComponent>(go);
	renderComponent->SetTexture("background.jpg");
	// Register it as renderable for the scene
	scene.AddRenderable(renderComponent);
	// Add the component to the gameObject ( This step is important!, scene only has weak_ptr to renderComponent so it wont keep it alive!)
	go->AddComponent(renderComponent);
	scene.Add(go);

	go = std::make_shared<GameObject>();
	// Create RenderComponent and add Texture to it
	renderComponent = std::make_shared<RenderComponent>(go);
	renderComponent->SetTexture("logo.png");
	// Register it as renderable for the scene
	scene.AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	go->AddComponent(renderComponent);
	go->SetPosition(216, 180);
	scene.Add(go);

	go = std::make_shared<GameObject>();

	renderComponent = std::make_shared<RenderComponent>(go);
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComponent = std::make_shared<TextComponent>(go,"Programming 4 Assignment", font, renderComponent);
	//auto to = std::make_shared<TextObject>("Programming 4 Assignment", font);
	go->AddComponent(textComponent);
	go->AddComponent(renderComponent);
	renderComponent->SetParentGameObject(go);
	go->SetPosition(80, 20);
	scene.AddRenderable(renderComponent);
	scene.Add(go);


	go = std::make_shared<GameObject>();
	auto fpsFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	renderComponent = std::make_shared<RenderComponent>(go);
	textComponent = std::make_shared<TextComponent>(go,"0", fpsFont, renderComponent);
	auto fpsComponent = std::make_shared<FPSComponent>(go,textComponent);

	go->AddComponent(fpsComponent);
	go->AddComponent(textComponent);
	go->AddComponent(renderComponent);
	renderComponent->SetParentGameObject(go);

	go->SetPosition(10, 20);

	scene.Add(go);
	scene.AddRenderable(renderComponent);
}
