#pragma once
#include "GameObject.h"


class Level final
{
public:
	Level();
	~Level() = default;

	void Initialize();
	void Update();
	void Render();

protected:

private:
	std::shared_ptr<Hidden::GameObject> go;
	static int m_I;
};

