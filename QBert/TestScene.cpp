#include "QBertPCH.h"
#include "TestScene.h"
#include "Level.h"
#include "InputManager.h"
#include "Command.h"
#include "SuccessCommand.h"


TestScene::TestScene()
	:Scene("TestScene")
	, m_NrLevels{4}
	, m_ActiveLevel{0}
{
}

void TestScene::Initialize()
{
	std::string filePath{};
	for (unsigned int i{}; i < m_NrLevels; ++i)
	{
		m_GO.push_back(std::make_shared<Hidden::GameObject>());
		Add(m_GO[i]);
		auto render = std::make_shared<RenderComponent>(m_GO[i]);
		m_GO[i]->AddComponent(render);

		switch (i)
		{
		case 1:
			filePath = "Qbert.jpg";
			break;
		case 2:
			filePath = "QbertPyramid.png";
			break;
		case 3:
			filePath = "GameBoyQbert.jpg";
			break;
		default:
			filePath = "Background.jpg";
		}
		render->SetTexture(filePath);
		m_RenderComponents.push_back(render);
	}

	// Logo
	// ****

	auto go = std::make_shared<Hidden::GameObject>();
	// Create RenderComponent and add Texture to it
	auto renderComponent = std::make_shared<RenderComponent>(go);
	renderComponent->SetTexture("logo.png");
	// Register the gameObject with the renderComponent
	renderComponent->SetParentGameObject(go);
	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	go->AddComponent(renderComponent);
	go->SetPosition(216, 180);
	Add(go);

	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonA, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());

}

void TestScene::Update()
{
	auto command = InputManager::GetInstance().OnPressed({ 0,XBox360Controller::ControllerButton::ButtonA});

	if (command.lock()->execute(NULL))
	{
		unsigned int prev = m_ActiveLevel;
		m_ActiveLevel = ++m_ActiveLevel % m_NrLevels;

		//Remove(*m_GO[prev]);
	}

}

void TestScene::Render() const
{
	if (!m_RenderComponents[m_ActiveLevel].expired())
	{
		m_RenderComponents[m_ActiveLevel].lock()->Render();
	}
}
