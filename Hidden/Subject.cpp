#include "HiddenPCH.h"
#include "Subject.h"

template <class T>
void Hidden::Subject<T>::AddObserver(const std::weak_ptr<Observer<T>>& pObserver)
{
	m_pObservers.emplace_front(pObserver);
}

template <class T>
void Hidden::Subject<T>::RemoveObserver(const std::shared_ptr<Observer<T>>& pObserver)
{
	auto it = m_pObservers.begin();

	while (it != m_pObservers.end())
	{
		if ((*it).lock() == pObserver)
		{
			m_pObservers.erase(it);
			return;
		}
		++it;
	}

}

template <class T>
void Hidden::Subject<T>::Notify(const T& data)
{
	for (auto& observer : m_pObservers)
	{
		if (observer.lock())
		{
			observer.lock()->onNotify(data);
		}
		else
		{
			// Will this work? We are changing m_pObservers while looping through it
			RemoveObserver(observer.lock());
		}
	}
}
