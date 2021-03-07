#pragma once
#include <memory>
#include <Component.h>
#include "Subject.h"

using namespace Hidden;


class TileComponent : public Hidden::Component
{

	enum class events
	{
		colorChange
	};

	TileComponent(std::weak_ptr<Hidden::GameObject> pParent, size_t initialTile);
	~TileComponent() = default;

	TileComponent(const TileComponent & other) = default;
	TileComponent(TileComponent && other) = default;
	TileComponent& operator=(const TileComponent & other) = default;
	TileComponent& operator=(TileComponent && other) = default;

	void Update() override;
	void ChangeTileColor();
	const events GetCurrentEvent() const;

	std::weak_ptr<Subject<TileComponent>> GetSubject();


private:
	events m_CurrentEvent;

	std::shared_ptr<Subject<TileComponent>> m_pSubject;
};

