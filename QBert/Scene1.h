#pragma once
#include <Scene.h>

#include "Level.h"

class Scene1 final : public Hidden::Scene
{
public:
	Scene1();
	~Scene1() = default;

	void Initialize() override;
	void Update() override;
	void Render() const override;


private:
	std::vector<std::unique_ptr<Level>> m_Levels{};
};

