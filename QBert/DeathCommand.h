#pragma once
#include "Command.h"

using namespace Hidden;

class DeathCommand : public Hidden::Command
{
public:
    DeathCommand() = default;
    virtual ~DeathCommand() = default;
    DeathCommand(const DeathCommand & other) = default; // copy constructor
    DeathCommand(DeathCommand && other) noexcept = default; // move constructor
    DeathCommand& operator=(const DeathCommand & other) = default; // copy assignment
    DeathCommand& operator=(DeathCommand && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
private:
};

