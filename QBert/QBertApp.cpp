#pragma once
#include "QbertApp.h"
#include "Main.h"
#include "SceneManager.h"

#include "Scene1.h"

Hidden::Application* Hidden::CreateApplication()
{
	return new QBert{};
}

using namespace Hidden;

void QBert::LoadGame() const
{
	auto scene = std::make_shared<Scene1>();

	SceneManager::GetInstance().AddScene(scene);

}

void QBert::Cleanup()
{
}
