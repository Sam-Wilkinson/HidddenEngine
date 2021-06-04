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

	enum class Rotation
	{
		backRight,
		backLeft,
		frontRight,
		frontLeft
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
	std::weak_ptr<SpriteComponent> m_SpriteComponent;

};

