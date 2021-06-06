#include "QBertPCH.h"
#include "MovementObserver.h"
#include "MovementComponent.h"

void MovementObserver::onNotify(const MovementComponent& data)
{
	m_Col = data.GetColumn();
	m_Row = data.GetRow();
	m_IsNotified = true;
}

int MovementObserver::GetColumn()
{
	return m_Col;
}

int MovementObserver::GetRow()
{
	return m_Row;
}
