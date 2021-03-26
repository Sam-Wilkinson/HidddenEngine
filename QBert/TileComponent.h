#pragma once
#include <memory>
#include <Component.h>
#include "Subject.h"

using namespace Hidden;


class TileComponent : public Hidden::Component
{
public:
	TileComponent(std::weak_ptr<Hidden::GameObject> pParent);
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
};

