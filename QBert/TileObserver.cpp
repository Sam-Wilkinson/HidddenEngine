#include "HiddenPCH.h"
#include "TileObserver.h"
#include "TileComponent.h"

void TileObserver::onNotify(const TileComponent& data)
{
	(void)data;
	m_IsNotified = true;
}
