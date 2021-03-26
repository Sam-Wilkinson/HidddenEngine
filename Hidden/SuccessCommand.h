#pragma once
#include "Command.h"

namespace Hidden
{
	class SuccessCommand : public Command
	{
    public:

        SuccessCommand() = default;
        virtual ~SuccessCommand() = default;
        SuccessCommand(const SuccessCommand & other) = default; // copy constructor
        SuccessCommand(SuccessCommand && other) noexcept = default; // move constructor
        SuccessCommand& operator=(const SuccessCommand & other) = default; // copy assignment
        SuccessCommand& operator=(SuccessCommand && other) noexcept = default; // move assignment
        // Inherited via Command
        virtual int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override { return 1; };

    private:
	};
}


