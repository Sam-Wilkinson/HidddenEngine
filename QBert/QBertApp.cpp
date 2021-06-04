#pragma once
#include "QBertPCH.h"
#include "QbertApp.h"
#include "Main.h"
#include "SceneManager.h"
#include "Scene1.h"
#include "GameConfig.h"

#include "TestScene.h"
#include "PyramidScene.h"
#include "QBertScene.h"

Hidden::Application* Hidden::CreateApplication()
{
	return new QBert{};
}

using namespace Hidden;

void QBert::LoadGame() const
{
	auto scene = std::make_shared<QBertScene>();

	SceneManager::GetInstance().AddScene(scene);

}

void QBert::Initialize()
{
	GameConfig::window.Width = 800;
	GameConfig::window.Height = 800;
}

void QBert::Cleanup()
{
}
