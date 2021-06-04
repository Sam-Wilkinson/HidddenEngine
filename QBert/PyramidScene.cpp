#include "QBertPCH.h"
#include "PyramidScene.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include "RenderComponent.h"

#include "InputManager.h"
#include "IncrementSprite.h"
#include "GameConfig.h"
#include "Transform.h"

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
	//int MovementX = 125;
	//int movementY = 75;

	float pyramidTopX{ static_cast<float>(windowWidth / 2)};
	float pyramidTopY{ static_cast<float>(marginY) };

	float tilePosX{pyramidTopX};
	float tilePosY{ pyramidTopY  };

	for (int i{}; i < m_PyramidHeight; ++i)
	{

		int j{};
		
		while (j <= i)
		{
			auto go = std::make_shared<Hidden::GameObject>();

			tilePosX = pyramidTopX - (tileSize) * i + (tileSize / 2) * i + (tileSize * j);
			go->GetTransform().MovePosition(tilePosX , tilePosY );


			auto renderComponent = std::make_shared<RenderComponent>();
			renderComponent->SetDestinationSize(tileSize, tileSize);
			auto spriteComponent = std::make_shared<SpriteComponent>(renderComponent, 2, 1, 256, 256);
			spriteComponent->SetTexture("Level1_Tiles.png");

			// Register it as renderable for the scene
			AddRenderable(renderComponent);
			// Register the renderComponent to the GameObject
			go->AddComponent(spriteComponent);
			go->AddComponent(renderComponent);
			go->SetLayer(1.0f);
			Add(go);
			m_Pyramid.push_back(go);

			++j;
		}

		tilePosY = pyramidTopY + (tileSize * 0.75f) * (i + 1);

	}

}
