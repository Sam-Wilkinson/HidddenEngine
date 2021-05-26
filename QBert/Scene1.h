#pragma once
#include <Scene.h>

class Level;

class Scene1 final : public Hidden::Scene
{
public:
	Scene1();
	~Scene1() = default;

	void Initialize() override;
	void Update() override;
	void Render() const override;


private:
};

