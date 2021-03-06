#pragma once
#include "Observer.h"
#include "Subject.h"

#include "GameObject.h"

class QBertObserver : public Hidden::Observer<Hidden::GameObject>
{
public:
	QBertObserver() = default;
	virtual ~QBertObserver() = default;


	QBertObserver(const QBertObserver & other) = default; // copy constructor
	QBertObserver(QBertObserver && other) noexcept = default; // move constructor
	QBertObserver& operator=(const QBertObserver & other) = default; // copy assignment
	QBertObserver& operator=(QBertObserver && other) noexcept = default; // move assignment

	template <class T>
	virtual void onNotify(const T & data);

	virtual void OnLifeLost() = 0;
	virtual void OnDeath() = 0;

protected:

private:
};

template<class T>
inline void QBertObserver::onNotify(const T& data)
{

}
