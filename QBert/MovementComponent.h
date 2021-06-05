#pragma once
#include <Component.h>
#include "Subject.h"

class MovementComponent : public Hidden::Component
{	
public:

	enum class Event
	{
		MoveUpLeft,
		MoveUpRight,
		MoveDownLeft,
		MoveDownRight
	};


	MovementComponent(int movementRow, int movementCol, int row, int column);
	~MovementComponent() = default;

	MovementComponent(const MovementComponent & other) = default;
	MovementComponent(MovementComponent && other) = default;
	MovementComponent& operator=(const MovementComponent & other) = default;
	MovementComponent& operator=(MovementComponent && other) = default;

	void Update() override;
	const Event GetCurrentEvent() const;
	
	std::weak_ptr<Hidden::Subject<MovementComponent>> GetSubject() const;
	
	void MoveUpLeft();
	void MoveUpRight();
	void MoveDownLeft();
	void MoveDownRight();

	int GetRow() const;
	int GetColumn() const;

private:
	std::shared_ptr<Hidden::Subject<MovementComponent>> m_pSubject;
	Event m_CurrentEvent;

	int m_MovementRow;
	int m_MovementCol;
	int m_Row;
	int m_Col;

	void Move(int rowOffset, int columnOffset);

};

