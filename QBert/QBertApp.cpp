#pragma once
#include "Application.h"
#include "Main.h"

class QBert : public Hidden::Application
{
public:
	QBert() = default;
	~QBert() = default;

private:

};


Hidden::Application* Hidden::CreateApplication()
{
	return new QBert{};
}

