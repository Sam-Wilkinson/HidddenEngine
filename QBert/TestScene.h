#pragma once
#include <Scene.h>

class TestScene : public Hidden::Scene
{
public:
	TestScene();
	~TestScene() = default;

	void Initialize() override;
	void Update() override;
	void Render() const override;

private:

	unsigned int m_NrLevels;
	std::vector<std::weak_ptr<Hidden::RenderComponent>> m_RenderComponents{};
	std::vector<std::shared_ptr<Hidden::GameObject>> m_GO{};
	unsigned int m_ActiveLevel;
};

