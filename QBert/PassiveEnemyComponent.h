#pragma once
#include <Component.h>
#include <SpriteComponent.h>
#include "MovementComponent.h"
#include "MovementObserver.h"

class PassiveEnemyComponent : public Hidden::Component
{
public:

	enum class State
	{
		sitting = 0,
		moving = 1,
		spawning = 2,
		dying = 3
	};

	enum class Rotation
	{
		backRight = 0,
		backLeft = 1,
		frontRight = 2,
		frontLeft = 3
	};

	PassiveEnemyComponent(std::weak_ptr<Hidden::SpriteComponent> spriteComponent, std::weak_ptr<MovementComponent> movementComponent, int pyramidSize);
	~PassiveEnemyComponent() = default;

	PassiveEnemyComponent(const PassiveEnemyComponent & other) = default;
	PassiveEnemyComponent(PassiveEnemyComponent && other) = default;
	PassiveEnemyComponent& operator=(const PassiveEnemyComponent & other) = default;
	PassiveEnemyComponent& operator=(PassiveEnemyComponent && other) = default;

	void Update() override;

	std::weak_ptr<Hidden::Subject<PassiveEnemyComponent>> GetSubject();
	std::shared_ptr<MovementObserver> GetMovementObserver();

private:
	std::shared_ptr<Hidden::Subject<PassiveEnemyComponent>> m_pSubject;
	std::weak_ptr<Hidden::SpriteComponent> m_SpriteComponent;
	std::weak_ptr<MovementComponent> m_MovementComponent;
	std::shared_ptr<MovementObserver> m_QbertMovementObserver;

	State m_CurrentState;
	Rotation m_CurrentRotation;
	int m_PyramidSize;

	bool m_IsEgg;
	int m_NrTrackesPositions;

	//TODO remove time and replace with observer of movementComponent to see when movement is over
	float m_DeltaTime;
	float m_MoveDelay;
	void ProcessSprite();

};

