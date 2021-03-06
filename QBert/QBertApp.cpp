#pragma once
#include "QbertApp.h"
#include "Main.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "GameObject.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include "HealthComponent.h"
#include "UILivesComponent.h"

Hidden::Application* Hidden::CreateApplication()
{
	return new QBert{};
}

using namespace Hidden;

void QBert::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	// Register components here

	// Background
	// **********
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


	// Logo
	// ****

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

	// Title
	// *****
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

	// FPS 
	// ***
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

	// QBert
	// *****
	size_t initialHealth{ 10 };
	go = std::make_shared<GameObject>();
	auto QBertHealth = std::make_shared<HealthComponent>(initialHealth);
	go->AddComponent(QBertHealth);
	scene.Add(go);
	//TODO add input here



	// UI 
	// **
	go = std::make_shared<GameObject>();
	auto UIRenderComponent = std::make_shared<RenderComponent>();
	auto UIHealthText = std::make_shared<TextComponent>("NrLives: " + std::to_string(initialHealth), fpsFont, UIRenderComponent);
	auto UIHealth = std::make_shared<UILivesComponent>(initialHealth, UIHealthText);

	QBertHealth->GetSubject().lock()->AddObserver(UIHealth);

	go->AddComponent(UIHealth);
	go->AddComponent(UIHealthText);
	go->AddComponent(UIRenderComponent);
	UIRenderComponent->SetParentGameObject(go);
	go->SetPosition(10, 150);
	scene.Add(go);
	scene.AddRenderable(UIRenderComponent);

}

void QBert::Cleanup()
{
}
