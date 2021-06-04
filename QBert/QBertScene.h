#pragma once
#include <Scene.h>

class QBertScene : public Hidden::Scene
{
public:
	QBertScene();
	~QBertScene() = default;

	void Initialize() override;
	void Update() override;
	void Render() const override;

private:
	float m_ElapsedTime;
	float m_ChangeTime;
	std::shared_ptr<Hidden::GameObject> m_Qbert;

};

