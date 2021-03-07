#pragma once
#include <Component.h>
#include <memory>
#include "Observer.h"
#include "Component.h"
#include "TextComponent.h"
#include "TileComponent.h"

using namespace Hidden;

class UIScoreComponent : public Hidden::Component
{
	UIScoreComponent(std::weak_ptr<Hidden::GameObject> pParent, size_t initialHealth, const std::weak_ptr<TextComponent> textComponent);
	~UIScoreComponent() = default;

	UIScoreComponent(const UIScoreComponent & other) = delete;
	UIScoreComponent(UIScoreComponent && other) = delete;
	UIScoreComponent& operator=(const UIScoreComponent & other) = delete;
	UIScoreComponent& operator=(UIScoreComponent && other) = delete;

	void Update() override;

private:
	unsigned int m_Score{};
	bool m_NeedsUpdate{ false };
	std::weak_ptr<TextComponent> m_TextComponent;
};

