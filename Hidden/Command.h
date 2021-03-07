#pragma once
#include <memory>

namespace Hidden
{
    //class Component;
    class GameObject;
    class Command
    {
    public:
        Command() = default;
        virtual ~Command() = default;
        Command(const Command& other) = default; // copy constructor
        Command(Command&& other) noexcept = default; // move constructor
        Command& operator=(const Command& other) = default; // copy assignment
        Command& operator=(Command&& other) noexcept = default; // move assignment

        virtual int execute(std::shared_ptr<GameObject> pGameObject) = 0;

    protected:

    private:

    };

}


