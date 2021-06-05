#pragma once
#include "Observer.h"
#include "Subject.h"

#include "GameObject.h"
#include "QBertComponent.h"

class QBertObserver : public Hidden::Observer<QBertComponent>
{
public:
	QBertObserver();
	virtual ~QBertObserver() = default;

	QBertObserver(const QBertObserver & other) = default; // copy constructor
	QBertObserver(QBertObserver && other) noexcept = default; // move constructor
	QBertObserver& operator=(const QBertObserver & other) = default; // copy assignment
	QBertObserver& operator=(QBertObserver && other) noexcept = default; // move assignment


	virtual void onNotify(const QBertComponent & data) override;

	virtual bool IsNotified() override;
	virtual void SetIsNotified(bool isNotified) override;

	QBertComponent::Event GetEvent();
	size_t GetScore();

protected:

private:
	bool m_IsNotified;
	QBertComponent::Event m_Event;
	size_t m_Score;

};

