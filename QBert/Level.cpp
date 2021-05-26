#include "QBertPCH.h"
#include "Level.h"
#include "RenderComponent.h"

int Level::m_I{};

Level::Level()
{
	go = std::make_shared<GameObject>();

	auto render = std::make_shared<RenderComponent>(go);



	std::string filePath{};

	switch (m_I)
	{
	case 1:
		filePath = "logo.png";
		break;
	case 2:
		filePath = "GameBoyQbert.jpg";
		break;
	case 3:
		filePath = "Qbert.jpg";
		break;
	default:
		filePath = "background.jpg";
	}

	render->SetTexture(filePath);
	++m_I;
}

void Level::Initialize()
{
}

void Level::Update()
{
}

void Level::Render()
{

}
