#pragma once
#include "Minigin.h"
#include "Main.h"

class QBert : public Hidden::Minigin
{
public:
	QBert() = default;
	~QBert() = default;

private:

};


Hidden::Minigin* Hidden::CreateApplication()
{
	return new QBert{};
}

