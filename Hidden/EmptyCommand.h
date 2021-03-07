#pragma once
#include "Command.h"
#include "GameObject.h"

namespace Hidden
{
    class EmptyCommand : public Command
    {
    public:
        EmptyCommand() = default;
        virtual ~EmptyCommand() = default;
        EmptyCommand(const EmptyCommand& other) = default; // copy constructor
        EmptyCommand(EmptyCommand&& other) noexcept = default; // move constructor
        EmptyCommand& operator=(const EmptyCommand& other) = default; // copy assignment
        EmptyCommand& operator=(EmptyCommand&& other) noexcept = default; // move assignment
        // Inherited via Command
        virtual int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override { return 0; };

    private:
    };
}


