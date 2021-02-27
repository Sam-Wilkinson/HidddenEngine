#pragma once
#include "Command.h"

namespace Hidden
{
    class ErrorCommand : public Command
    {
    public:

        ErrorCommand() = default;
        virtual ~ErrorCommand() = default;
        ErrorCommand(const ErrorCommand& other) = default; // copy constructor
        ErrorCommand(ErrorCommand&& other) noexcept = default; // move constructor
        ErrorCommand& operator=(const ErrorCommand& other) = default; // copy assignment
        ErrorCommand& operator=(ErrorCommand&& other) noexcept = default; // move assignment
        // Inherited via Command
        virtual int execute() override { std::cout << "Error, controller not found!" << std::endl; return -1; };

    private:
    };

}

