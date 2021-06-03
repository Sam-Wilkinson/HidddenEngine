#include "QBertPCH.h"
#include "Scene1.h"

#include "ServiceLocator.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "LoggingSoundSystem.h"
#include "SimpleSDL2SoundSystem.h"

#include "GameObject.h"

#include "TextComponent.h"
#include "RenderComponent.h"
#include "FPSComponent.h"
#include "QBertComponent.h"
#include "UILivesComponent.h"
#include "UIScoreComponent.h"

#include "SuccessCommand.h"
#include "DeathCommand.h"
#include "LoseLifeCommand.h"

using namespace Hidden;

Scene1::Scene1()
	:Scene("Scene1")
{
}

void Scene1::Initialize()
{
	// Register components here

	// Background
	// **********
	auto go = std::make_shared<Hidden::GameObject>();
	// Create RenderComponent and add Texture to it
	auto renderComponent = std::make_shared<RenderComponent>();
	renderComponent->SetTexture("background.jpg");
	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Add the component to the gameObject ( This step is important!, scene only has weak_ptr to renderComponent so it wont keep it alive!)
	go->AddComponent(renderComponent);
	Add(go);


	// Logo
	// ****

	go = std::make_shared<Hidden::GameObject>();
	// Create RenderComponent and add Texture to it
	renderComponent = std::make_shared<RenderComponent>();
	renderComponent->SetTexture("logo.png");
	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	go->AddComponent(renderComponent);
	go->SetPosition(216, 180);
	Add(go);

	go = std::make_shared<Hidden::GameObject>();

	// Title
	// *****
	renderComponent = std::make_shared<RenderComponent>();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComponent = std::make_shared<TextComponent>("Programming 4 Assignment", font, renderComponent);
	//auto to = std::make_shared<TextObject>("Programming 4 Assignment", font);
	go->AddComponent(textComponent);
	go->AddComponent(renderComponent);
	go->SetPosition(80, 20);
	AddRenderable(renderComponent);
	Add(go);

	// FPS 
	// ***
	go = std::make_shared<Hidden::GameObject>();
	auto fpsFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	renderComponent = std::make_shared<RenderComponent>();
	textComponent = std::make_shared<TextComponent>("0", fpsFont, renderComponent);
	auto fpsComponent = std::make_shared<FPSComponent>(textComponent);

	go->AddComponent(fpsComponent);
	go->AddComponent(textComponent);
	go->AddComponent(renderComponent);

	go->SetPosition(10, 20);

	Add(go);
	AddRenderable(renderComponent);

	// QBert
	// *****
	size_t initialHealth{ 10 };
	go = std::make_shared<Hidden::GameObject>();
	auto QBertHealth = std::make_shared<HealthComponent>(initialHealth);
	auto QBert = std::make_shared<QBertComponent>();
	go->AddComponent(QBertHealth);
	go->AddComponent(QBert);
	Add(go);

	// add input for health
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonRightBack, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<LoseLifeCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonRightThumb, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<DeathCommand>());

	// Add input for score
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonA, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonB, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonX, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonY, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());



	//Qbert 2
	go = std::make_shared<Hidden::GameObject>();
	auto QBertHealth2 = std::make_shared<HealthComponent>( initialHealth);
	auto QBert2 = std::make_shared<QBertComponent>();
	go->AddComponent(QBertHealth2);
	go->AddComponent(QBert2);
	Add(go);

	// add input for health
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonLeftBack, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<LoseLifeCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonLeftThumb, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<DeathCommand>());

	// Add input for score
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadDown, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadRight, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadLeft, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::DpadUp, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());

	// UI 
	// **

	size_t initialScore{ 0 };

	// QBert 1 UI

	go = std::make_shared<Hidden::GameObject>();
	auto UIRenderComponent = std::make_shared<RenderComponent>();
	auto UIHealthText = std::make_shared<TextComponent>("NrLives: " + std::to_string(initialHealth), fpsFont, UIRenderComponent);
	auto UIHealth = std::make_shared<UILivesComponent>(initialHealth, UIHealthText);

	auto lifeObserver = std::make_shared<LivesObserver>();

	QBertHealth->GetSubject().lock()->AddObserver(lifeObserver);
	UIHealth->SetLivesObserver(lifeObserver);

	go->AddComponent(UIHealth);
	go->AddComponent(UIHealthText);
	go->AddComponent(UIRenderComponent);
	go->SetPosition(10, 150);
	Add(go);
	AddRenderable(UIRenderComponent);


	go = std::make_shared<Hidden::GameObject>();
	UIRenderComponent = std::make_shared<RenderComponent>();
	auto UIScoreText = std::make_shared<TextComponent>("Score: " + std::to_string(initialScore), fpsFont, UIRenderComponent);
	auto UIScore = std::make_shared<UIScoreComponent>(0, UIScoreText);

	auto qbertObserver = std::make_shared<QBertObserver>();

	QBert->GetSubject().lock()->AddObserver(qbertObserver);
	UIScore->SetQBertObserver(qbertObserver);

	go->AddComponent(UIScore);
	go->AddComponent(UIScoreText);
	go->AddComponent(UIRenderComponent);
	go->SetPosition(10, 200);
	Add(go);
	AddRenderable(UIRenderComponent);



	//QBert2 UI

	go = std::make_shared<Hidden::GameObject>();
	UIRenderComponent = std::make_shared<RenderComponent>();
	UIHealthText = std::make_shared<TextComponent>("NrLives: " + std::to_string(initialHealth), fpsFont, UIRenderComponent);
	UIHealth = std::make_shared<UILivesComponent>(initialHealth, UIHealthText);

	lifeObserver = std::make_shared<LivesObserver>();

	QBertHealth2->GetSubject().lock()->AddObserver(lifeObserver);
	UIHealth->SetLivesObserver(lifeObserver);

	go->AddComponent(UIHealth);
	go->AddComponent(UIHealthText);
	go->AddComponent(UIRenderComponent);
	go->SetPosition(10, 250);
	Add(go);
	AddRenderable(UIRenderComponent);


	initialScore = 10;

	go = std::make_shared<Hidden::GameObject>();
	UIRenderComponent = std::make_shared<RenderComponent>();
	UIScoreText = std::make_shared<TextComponent>("Score: " + std::to_string(initialScore), fpsFont, UIRenderComponent);
	UIScore = std::make_shared<UIScoreComponent>( 0, UIScoreText);

	qbertObserver = std::make_shared<QBertObserver>();

	QBert2->GetSubject().lock()->AddObserver(qbertObserver);
	UIScore->SetQBertObserver(qbertObserver);

	go->AddComponent(UIScore);
	go->AddComponent(UIScoreText);
	go->AddComponent(UIRenderComponent);
	go->SetPosition(10, 300);
	Add(go);
	AddRenderable(UIRenderComponent);


	//Sounds & Music

	std::shared_ptr<SoundSystem> ss = std::make_shared<LoggingSoundSystem>(std::make_unique<SimpleSDL2SoundSystem>());
	//std::shared_ptr<SoundSystem> ss = std::make_shared<SimpleSDL2SoundSystem>();
	ServiceLocator::RegisterSoundSystem(ss);

	const std::string& filePath{ "./Log.txt" };
	ServiceLocator::GetLoggerSystem().StartFileLogging(filePath);

	ServiceLocator::GetSoundSystem().PlayMusic("../3rdParty/Simple-SDL2-Audio-master/music/highlands.wav", 1.0f);

}

void Scene1::Update()
{

}

void Scene1::Render() const
{

}
