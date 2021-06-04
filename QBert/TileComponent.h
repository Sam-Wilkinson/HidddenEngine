#pragma once
#include <memory>
#include <Component.h>
#include "Subject.h"
#include "SpriteComponent.h"
using namespace Hidden;


class TileComponent : public Hidden::Component
{
public:
	TileComponent(size_t row, size_t col, std::weak_ptr<SpriteComponent> spriteComponent);
	~TileComponent() = default;

	TileComponent(const TileComponent & other) = default;
	TileComponent(TileComponent && other) = default;
	TileComponent& operator=(const TileComponent & other) = default;
	TileComponent& operator=(TileComponent && other) = default;

	void Update() override;
	void ChangeTileColor();

	std::weak_ptr<Subject<TileComponent>> GetSubject();

private:
	std::shared_ptr<Subject<TileComponent>> m_pSubject;

	size_t m_Row;
	size_t m_Col;
	std::weak_ptr<SpriteComponent> m_pSpriteComponent;
};

