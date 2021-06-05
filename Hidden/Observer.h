#pragma once

class Component;

namespace Hidden
{
	template <class T>
	class Observer
	{
		public:
			Observer() = default;
			virtual ~Observer() = default;
	
	
			Observer(const Observer& other) = default; // copy constructor
			Observer(Observer&& other) noexcept = default; // move constructor
			Observer& operator=(const Observer& other) = default; // copy assignment
			Observer& operator=(Observer&& other) noexcept = default; // move assignment
	
			virtual void onNotify(const T& data) = 0;

			virtual bool IsNotified();
			virtual void SetIsNotified(bool isNotified);

		protected:
			
			bool m_IsNotified;
		private:
	};

	template<class T>
	inline bool Observer<T>::IsNotified()
	{
		return m_IsNotified;
	}
	template<class T>
	inline void Observer<T>::SetIsNotified(bool isNotified)
	{
		m_IsNotified = isNotified;
	}
}


