#pragma once
#include "Component.h"
#include "TextComponent.h"

#include "HealthComponent.h"

#include "Observer.h"

using namespace Hidden;

class UILivesComponent final : public Hidden::Component, public Observer<HealthComponent>
{
public:
	UILivesComponent(std::weak_ptr<Hidden::GameObject> pParent, size_t initialHealth, const std::weak_ptr<TextComponent> textComponent);
	~UILivesComponent() = default;

	UILivesComponent(const UILivesComponent & other) = delete;
	UILivesComponent(UILivesComponent && other) = delete;
	UILivesComponent& operator=(const UILivesComponent & other) = delete;
	UILivesComponent& operator=(UILivesComponent && other) = delete;

	void Update() override;

	virtual void onNotify(const HealthComponent& data) override;

private:
	unsigned int m_NrLives{};
	bool m_NeedsUpdate{false};
	std::weak_ptr<TextComponent> m_TextComponent;

};

