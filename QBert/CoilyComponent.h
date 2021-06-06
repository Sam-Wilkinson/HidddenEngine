#pragma once
#include <Component.h>
#include "Subject.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "MovementObserver.h"
#include <queue>

class CoilyComponent : public Hidden::Component
{
public:

	enum class State
	{
		sitting = 0,
		moving = 1,
		dying = 4
	};

	enum class Rotation
	{
		backRight = 0,
		backLeft = 1,
		frontRight = 2,
		frontLeft = 3
	};

	CoilyComponent(std::weak_ptr<Hidden::SpriteComponent> eggSprite, std::weak_ptr<Hidden::SpriteComponent> coilySprite, std::weak_ptr<MovementComponent> movementComponent, int pyramidSize );
	~CoilyComponent() = default;

	CoilyComponent(const CoilyComponent & other) = default;
	CoilyComponent(CoilyComponent && other) = default;
	CoilyComponent& operator=(const CoilyComponent & other) = default;
	CoilyComponent& operator=(CoilyComponent && other) = default;

	void Update() override;

	std::weak_ptr<Hidden::Subject<CoilyComponent>> GetSubject();
	std::shared_ptr<MovementObserver> GetMovementObserver();
	void SetQbertIntialPos(const std::pair<int, int> qbertPos);

private:
	std::shared_ptr<Hidden::Subject<CoilyComponent>> m_pSubject;
	std::weak_ptr<Hidden::SpriteComponent> m_CoilySpriteComponent;
	std::weak_ptr<Hidden::SpriteComponent> m_EggSpriteComponent;
	std::weak_ptr<MovementComponent> m_MovementComponent;
	std::shared_ptr<MovementObserver> m_QbertMovementObserver;
	
	State m_CurrentState;
	Rotation m_CurrentRotation;
	int m_PyramidSize;

	std::queue<std::pair<int, int>> m_QbertPositions;


	bool m_IsEgg;
	int m_NrTrackesPositions;

	//TODO remove time and replace with observer of movementComponent to see when movement is over
	float m_DeltaTime;
	float m_MoveDelay;
	void ProcessSprite();
};

