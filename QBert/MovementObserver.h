#pragma once
#include <Observer.h>

class MovementComponent;

class MovementObserver : public Hidden::Observer<MovementComponent>
{
public:
	MovementObserver() = default;
	virtual ~MovementObserver() = default;

	MovementObserver(const MovementObserver & other) = default; // copy constructor
	MovementObserver(MovementObserver && other) noexcept = default; // move constructor
	MovementObserver& operator=(const MovementObserver & other) = default; // copy assignment
	MovementObserver& operator=(MovementObserver && other) noexcept = default; // move assignment


	virtual void onNotify(const MovementComponent & data) override;

	int GetColumn();
	int GetRow();

private:
	int m_Row;
	int m_Col;
};

