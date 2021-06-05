#include "QBertPCH.h"
#include "MovementComponent.h"
#include "GameObject.h"
#include "Transform.h"

void MovementComponent::Move(int rowOffset, int columnOffset)
{
	auto& transform = m_pParent.lock()->GetTransform();

	float movementRow{};
	float movementCol{};

	// move movement code to a function that does distance between hexTiles
	movementCol = (static_cast<float>(m_MovementCol) - (static_cast<float>(m_MovementCol) / 2)) * rowOffset + (static_cast<float>(m_MovementCol) * columnOffset);
	movementRow = (static_cast<float>(m_MovementRow) * 0.75f) * (rowOffset);

	transform.MovePosition(movementCol, movementRow);
}

MovementComponent::MovementComponent(int movementRow, int movementCol, int row, int column)
	:m_MovementRow{ movementRow }, m_MovementCol{ movementCol }, m_Row{ row }, m_Col{ column }, m_CurrentEvent{}, m_pSubject{ std::make_shared<Subject<MovementComponent>>() }
{
}

void MovementComponent::Update()
{
}

const MovementComponent::Event MovementComponent::GetCurrentEvent() const
{
	return m_CurrentEvent;
}

std::weak_ptr<Hidden::Subject<MovementComponent>> MovementComponent::GetSubject() const
{
	return m_pSubject;
}

void MovementComponent::MoveUpLeft()
{
	--m_Row;
	--m_Col;
	Move(-1, 0);
	m_CurrentEvent = MovementComponent::Event::MoveUpLeft;
	m_pSubject->Notify(*this);

}

void MovementComponent::MoveUpRight()
{
	--m_Row;
	Move(-1, 1);
	m_CurrentEvent = MovementComponent::Event::MoveUpRight;
	m_pSubject->Notify(*this);
}

void MovementComponent::MoveDownLeft()
{
	++m_Row;
	Move(1, -1);
	m_CurrentEvent = MovementComponent::Event::MoveDownLeft;
	m_pSubject->Notify(*this);
}

void MovementComponent::MoveDownRight()
{
	++m_Row;
	++m_Col;
	Move(1, 0);
	m_CurrentEvent = MovementComponent::Event::MoveDownRight;
	m_pSubject->Notify(*this);
}

int MovementComponent::GetRow() const
{
	return m_Row;
	
}

int MovementComponent::GetColumn() const
{
	return m_Col;
}
