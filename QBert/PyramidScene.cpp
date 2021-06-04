#include "QBertPCH.h"
#include "PyramidScene.h"

// ECS
#include "GameObject.h"
#include "Transform.h"
#include "SpriteComponent.h"
#include "RenderComponent.h"
#include "TileComponent.h"

// Globals
#include "InputManager.h"
#include "GameConfig.h"

//Commands
#include "IncrementSprite.h"
#include "SuccessCommand.h"

PyramidScene::PyramidScene()
	:Scene("PyramidScene")
	,m_PyramidHeight{7}
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

	CreateTiles();


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

void PyramidScene::CreateTiles()
{
	int windowWidth = GameConfig::window.Width;
	int windowHeight = GameConfig::window.Height;

	int marginY = windowHeight / 5;

	int tileSize = 100;

	float pyramidTopX{ static_cast<float>(windowWidth / 2)};
	float pyramidTopY{ static_cast<float>(marginY) };

	float tilePosX{pyramidTopX};
	float tilePosY{pyramidTopY};

	for (int row{}; row < m_PyramidHeight; ++row)
	{

		// TODO move movement code to a function that does distance between hexTiles rather than hard coded here
		int col{};
		
		while (col <= row)
		{
			auto go = std::make_shared<Hidden::GameObject>();

			tilePosX = pyramidTopX - (tileSize - (tileSize / 2)) * row  + (tileSize * col);
			go->GetTransform().MovePosition(tilePosX , tilePosY );


			auto renderComponent = std::make_shared<RenderComponent>();
			renderComponent->SetDestinationSize(tileSize, tileSize);
			auto spriteComponent = std::make_shared<SpriteComponent>(renderComponent, 2, 1, 256, 256);
			spriteComponent->SetTexture("Level1_Tiles.png");

			auto tileComponent = std::make_shared<TileComponent>(row, col, spriteComponent);

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

		tilePosY = pyramidTopY + (tileSize * 0.75f) * (row + 1);

	}

}
