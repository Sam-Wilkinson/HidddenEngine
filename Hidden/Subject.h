#pragma once
#include <list>
#include "Observer.h"

class Component;

namespace Hidden
{
    template <class T>
class Subject
{
    public:
        Subject() = default;
        virtual ~Subject() = default;

        Subject(const Subject& other) = delete; // copy constructor
        Subject(Subject&& other) noexcept = delete; // move constructor
        Subject& operator=(const Subject& other) = delete; // copy assignment
        Subject& operator=(Subject&& other) noexcept = delete; // move assignment


        void AddObserver(const std::weak_ptr<Observer<T>>& pObserver);
        void RemoveObserver(const std::shared_ptr<Observer<T>>& pObserver);

        //std::shared_ptr<Observer<T>> GetObserver();

        void Notify(const T& data);
    protected:

    private:
        std::list<std::weak_ptr<Observer<T>>> m_pObservers;

};

   //template<typename T>
   //inline std::shared_ptr<Observer<T>> Subject::GetObserver()
   //{
   //
   //    for (auto bc : m_pObservers)
   //    {
   //        if (std::dynamic_pointer_cast<std::shared_ptr<T>>(bc))
   //            return std::static_pointer_cast<T>(bc);
   //    }
   //    return nullptr;
   //}
}


