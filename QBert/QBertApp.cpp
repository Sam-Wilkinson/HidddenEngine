#pragma once
#include "QbertApp.h"
#include "Main.h"
#include "SceneManager.h"
#include "Scene.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "ResourceManager.h"

#include "TextComponent.h"
#include "FPSComponent.h"

Hidden::Application* Hidden::CreateApplication()
{
	return new QBert{};
}

using namespace Hidden;

void QBert::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	// Register components here

	auto go = std::make_shared<GameObject>();
	// Create RenderComponent and add Texture to it
	auto renderComponent = std::make_shared<RenderComponent>();
	renderComponent->SetTexture("background.jpg");
	// Register the gameObject with the renderComponent
	renderComponent->SetParentGameObject(go);
	// Register it as renderable for the scene
	scene.AddRenderable(renderComponent);
	// Add the component to the gameObject ( This step is important!, scene only has weak_ptr to renderComponent so it wont keep it alive!)
	go->AddComponent(renderComponent);
	scene.Add(go);

	go = std::make_shared<GameObject>();
	// Create RenderComponent and add Texture to it
	renderComponent = std::make_shared<RenderComponent>();
	renderComponent->SetTexture("logo.png");
	// Register the gameObject with the renderComponent
	renderComponent->SetParentGameObject(go);
	// Register it as renderable for the scene
	scene.AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	go->AddComponent(renderComponent);
	go->SetPosition(216, 180);
	scene.Add(go);

	go = std::make_shared<GameObject>();

	renderComponent = std::make_shared<RenderComponent>();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComponent = std::make_shared<TextComponent>("Programming 4 Assignment", font, renderComponent);
	//auto to = std::make_shared<TextObject>("Programming 4 Assignment", font);
	go->AddComponent(textComponent);
	go->AddComponent(renderComponent);
	renderComponent->SetParentGameObject(go);
	go->SetPosition(80, 20);
	scene.AddRenderable(renderComponent);
	scene.Add(go);


	go = std::make_shared<GameObject>();
	auto fpsFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	renderComponent = std::make_shared<RenderComponent>();
	textComponent = std::make_shared<TextComponent>("0", fpsFont, renderComponent);
	auto fpsComponent = std::make_shared<FPSComponent>(textComponent);

	go->AddComponent(fpsComponent);
	go->AddComponent(textComponent);
	go->AddComponent(renderComponent);
	renderComponent->SetParentGameObject(go);

	go->SetPosition(10, 20);

	scene.Add(go);
	scene.AddRenderable(renderComponent);

}

void QBert::Cleanup()
{
}
