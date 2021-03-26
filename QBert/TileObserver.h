#pragma once
#include <Observer.h>
#include "TileComponent.h"

class TileObserver final : public Hidden::Observer<TileComponent>
{
public:
	TileObserver() = default;
	virtual ~TileObserver() = default;


	TileObserver(const TileObserver & other) = default; // copy constructor
	TileObserver(TileObserver && other) noexcept = default; // move constructor
	TileObserver& operator=(const TileObserver & other) = default; // copy assignment
	TileObserver& operator=(TileObserver && other) noexcept = default; // move assignment

	virtual void onNotify(const TileComponent & data);

private:
	bool m_IsNotified;
};

