#pragma once
#include "QbertApp.h"
#include "Main.h"


Hidden::Application* Hidden::CreateApplication()
{
	return new QBert{};
}

using namespace Hidden;

void QBert::LoadGame() const
{
}

void QBert::Cleanup()
{
}
