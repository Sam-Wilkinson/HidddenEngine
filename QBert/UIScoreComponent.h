#pragma once
#include <Component.h>
#include <memory>
#include "Observer.h"
#include "Component.h"
#include "TextComponent.h"
#include "TileComponent.h"
#include "QBertObserver.h"

using namespace Hidden;

class UIScoreComponent final : public Hidden::Component
{
public:
	UIScoreComponent(std::weak_ptr<Hidden::GameObject> pParent, size_t initialScore, const std::weak_ptr<TextComponent> textComponent);
	~UIScoreComponent() = default;

	UIScoreComponent(const UIScoreComponent & other) = delete;
	UIScoreComponent(UIScoreComponent && other) = delete;
	UIScoreComponent& operator=(const UIScoreComponent & other) = delete;
	UIScoreComponent& operator=(UIScoreComponent && other) = delete;

	void Update() override;

	void SetQBertObserver(std::shared_ptr<QBertObserver> qBertObserver);


private:
	size_t m_Score{};
	bool m_NeedsUpdate{ false };
	std::weak_ptr<TextComponent> m_TextComponent;

	std::shared_ptr<QBertObserver> m_pQbertObserver;

};

