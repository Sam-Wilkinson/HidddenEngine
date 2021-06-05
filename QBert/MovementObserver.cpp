#include "QBertPCH.h"
#include "MovementObserver.h"
#include "MovementComponent.h"

void MovementObserver::onNotify(const MovementComponent& data)
{
	m_Col = data.GetColumn();
	m_Row = data.GetRow();
	m_IsNotified = true;
}

size_t MovementObserver::GetColumn()
{
	return m_Col;
}

size_t MovementObserver::GetRow()
{
	return m_Row;
}
