#include "QBertPCH.h"
#include "QBertScene.h"
#include "GameTime.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "QBertComponent.h"


QBertScene::QBertScene()
	:Scene("Qbert")
	, m_ElapsedTime{}
	, m_ChangeTime{1.0f}
{
}

void QBertScene::Initialize()
{
	m_Qbert = std::make_shared<Hidden::GameObject>();

	auto renderComponent = std::make_shared<Hidden::RenderComponent>();
	renderComponent->SetDestinationSize(75, 75);
	auto spriteComponent = std::make_shared<Hidden::SpriteComponent>(renderComponent, 1, 8, 256, 240);
	spriteComponent->SetTexture("QBert.png");
	auto movementComponent = std::make_shared<MovementComponent>(100, 100,0, 0);
	auto qbertComponent = std::make_shared<QBertComponent>(spriteComponent);

	// Register it as renderable for the scene
	AddRenderable(renderComponent);
	// Register the renderComponent to the GameObject
	m_Qbert->AddComponent(spriteComponent);
	m_Qbert->AddComponent(renderComponent);
	m_Qbert->AddComponent(movementComponent);
	m_Qbert->AddComponent(qbertComponent);
	m_Qbert->SetLayer(0.0f);
	m_Qbert->GetTransform().SetPosition(400, 400);
	Add(m_Qbert);
}

void QBertScene::Update()
{
	m_ElapsedTime += GameTime::GetInstance().GetTime();

	if (m_ElapsedTime > m_ChangeTime)
	{
		m_Qbert->GetComponent<SpriteComponent>()->IncrementCol();
		m_ElapsedTime = 0;
	}
}

void QBertScene::Render() const
{
}
