#pragma once
#include <Component.h>
#include "Subject.h"
#include "SpriteComponent.h"

using namespace Hidden;
class QBertComponent : public Hidden::Component
{
public:

	enum class Event
	{
		tileColorChange,
		defeatedCoily,
		coughtSlickOrSam,
		endStage
	};

	enum class State
	{
		standing = 0,
		moving = 1

		// The numbers correspond to the offset of the image on the sprite sheet
	};

	enum class Rotation
	{
		backRight = 0,
		backLeft = 1,
		frontRight = 2,
		frontLeft = 3

		// The numbers correspond to order of the information in the sprite sheet
	};

	QBertComponent(std::weak_ptr<SpriteComponent> spriteComponent);
	~QBertComponent() = default;

	QBertComponent(const QBertComponent & other) = default;
	QBertComponent(QBertComponent && other) = default;
	QBertComponent& operator=(const QBertComponent & other) = default;
	QBertComponent& operator=(QBertComponent && other) = default;

	void Update() override;
	const Event GetCurrentEvent() const;

	std::weak_ptr<Subject<QBertComponent>> GetSubject();
private:

private:
	std::shared_ptr<Subject<QBertComponent>> m_pSubject;
	Event m_CurrentEvent;
	State m_CurrentState;
	Rotation m_CurrentRotation;
	std::weak_ptr<SpriteComponent> m_SpriteComponent;

	//TODO remove time and replace with observer of movementComponent to see when movement is over
	float m_deltaTime;

	void ProcessSprite();

};

