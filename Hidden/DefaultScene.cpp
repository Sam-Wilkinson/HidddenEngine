#include "HiddenPCH.h"
#include "DefaultScene.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "FPSComponent.h"
#include "RenderComponent.h"

Hidden::DefaultScene::DefaultScene()
	:Scene("DefaultScene")
{
}

void Hidden::DefaultScene::Initialize()
{
	//// Register components here
	//
	auto go = std::make_shared<GameObject>();
	// Create RenderComponent and add Texture to it
	auto renderComponent = std::make_shared<RenderComponent>();
	renderComponent->SetTexture("background.jpg");
	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Add the component to the gameObject ( This step is important!, scene only has weak_ptr to renderComponent so it wont keep it alive!)
	go->AddComponent(renderComponent);
	Add(go);
	//
	go = std::make_shared<GameObject>();
	// Create RenderComponent and add Texture to it
	renderComponent = std::make_shared<RenderComponent>();
	renderComponent->SetTexture("logo.png");
	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	go->AddComponent(renderComponent);
	go->SetPosition(216, 180);
	Add(go);
	//
	//go = std::make_shared<GameObject>();
	//
	//renderComponent = std::make_shared<RenderComponent>();
	//auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto textComponent = std::make_shared<TextComponent>(go, "Programming 4 Assignment", font, renderComponent);
	////auto to = std::make_shared<TextObject>("Programming 4 Assignment", font);
	//go->AddComponent(textComponent);
	//go->AddComponent(renderComponent);
	//go->SetPosition(80, 20);
	//AddRenderable(renderComponent);
	//Add(go);
	//
	//
	//go = std::make_shared<GameObject>();
	//auto fpsFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	//renderComponent = std::make_shared<RenderComponent>(go);
	//textComponent = std::make_shared<TextComponent>(go, "0", fpsFont, renderComponent);
	//auto fpsComponent = std::make_shared<FPSComponent>(go, textComponent);
	//
	//go->AddComponent(fpsComponent);
	//go->AddComponent(textComponent);
	//go->AddComponent(renderComponent);
	//renderComponent->SetParentGameObject(go);
	//
	//go->SetPosition(10, 20);
	//
	//Add(go);
	//AddRenderable(renderComponent);

}

void Hidden::DefaultScene::Update()
{
}

void Hidden::DefaultScene::Render() const
{
}
