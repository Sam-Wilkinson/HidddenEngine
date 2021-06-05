#include "QBertPCH.h"
#include "PyramidScene.h"

// ECS
#include "GameObject.h"
#include "Transform.h"
#include "SpriteComponent.h"
#include "RenderComponent.h"
#include "TileComponent.h"
#include "MovementComponent.h"
#include "QbertComponent.h"

// Globals
#include "InputManager.h"
#include "GameConfig.h"

//Commands
#include "IncrementSprite.h"
#include "SuccessCommand.h"

PyramidScene::PyramidScene()
	:Scene("PyramidScene")
	,m_PyramidHeight{7}
	, m_PyramidTopX{float(GameConfig::window.Width) / 2}
	, m_PyramidTopY{float(GameConfig::window.Height) / 5}
	, m_TileSize{100}
{

}

void PyramidScene::Initialize()
{
	//auto go = std::make_shared<Hidden::GameObject>();
	//// Create RenderComponent and add Texture to it
	//auto renderComponent = std::make_shared<RenderComponent>();
	//renderComponent->SetTexture("Background.jpg");
	//// Register it as renderable for the scene
	//AddRenderable(renderComponent);
	//// Register the renderComponent to the GameObject
	//go->AddComponent(renderComponent);
	//go->SetLayer(1.0f);
	//Add(go);

	//m_Tile = std::make_shared<Hidden::GameObject>();
	//auto renderComponent = std::make_shared<RenderComponent>();
	//renderComponent->SetDestinationSize(100,100);
	//auto spriteComponent = std::make_shared<SpriteComponent>(renderComponent, 2,1, 256, 256);
	//spriteComponent->SetTexture("Level1_Tiles.png");
	// Register it as renderable for the scene
	//AddRenderable(renderComponent);
	//// Register the renderComponent to the GameObject
	//m_Tile->AddComponent(spriteComponent);
	//m_Tile->AddComponent(renderComponent);
	//m_Tile->SetLayer(0.0f);
	//Add(m_Tile);

	auto go = std::make_shared<Hidden::GameObject>();

	auto renderComponent = std::make_shared<Hidden::RenderComponent>();
	renderComponent->SetDestinationSize(75, 75);
	auto spriteComponent = std::make_shared<Hidden::SpriteComponent>(renderComponent, 1, 8, 255, 255);
	spriteComponent->SetTexture("QBert.png");
	auto movementComponent = std::make_shared<MovementComponent>(m_TileSize, m_TileSize, 0, 0);
	auto qbertComponent = std::make_shared<QBertComponent>(spriteComponent);

	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	go->AddComponent(spriteComponent);
	go->AddComponent(renderComponent);
	go->AddComponent(movementComponent);
	go->AddComponent(qbertComponent);
	go->SetLayer(0.0f);
	go->GetTransform().SetPosition(m_PyramidTopX, m_PyramidTopY - m_TileSize / 2);
	Add(go);


	float tilePosX{ m_PyramidTopX };
	float tilePosY{ m_PyramidTopY };

	for (int row{}; row < m_PyramidHeight; ++row)
	{

		// TODO move movement code to a function that does distance between hexTiles rather than hard coded here
		int col{};

		while (col <= row)
		{
			go = std::make_shared<Hidden::GameObject>();

			tilePosX = m_PyramidTopX - (m_TileSize - (m_TileSize / 2)) * row + (m_TileSize * col);
			go->GetTransform().MovePosition(tilePosX, tilePosY);


			renderComponent = std::make_shared<RenderComponent>();
			renderComponent->SetDestinationSize(m_TileSize, m_TileSize);
			spriteComponent = std::make_shared<SpriteComponent>(renderComponent, 2, 1, 256, 256);
			spriteComponent->SetTexture("Level1_Tiles.png");

			auto tileComponent = std::make_shared<TileComponent>(row, col, spriteComponent);
			movementComponent->GetSubject().lock()->AddObserver(tileComponent->GetObserver());

			// Register it as renderable for the scene
			AddRenderable(renderComponent);
			// Register the renderComponent to the GameObject
			go->AddComponent(spriteComponent);
			go->AddComponent(renderComponent);
			go->AddComponent(tileComponent);
			go->SetLayer(1.0f);
			Add(go);
			m_Pyramid.push_back(go);

			++col;
		}

		tilePosY = m_PyramidTopY + (m_TileSize * 0.75f) * (row + 1);

	}


	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonA, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<IncrementSprite>());
	InputManager::GetInstance().CreateCommand({ 0,Hidden::XBox360Controller::ControllerButton::ButtonB, XBox360Controller::ButtonEventType::OnPressed }, std::make_shared<SuccessCommand>());

}

void PyramidScene::Update()
{
	auto command = InputManager::GetInstance().OnPressed({ 0,XBox360Controller::ControllerButton::ButtonA });

	command.lock()->execute(m_Tile);

}

void PyramidScene::Render() const
{
}
