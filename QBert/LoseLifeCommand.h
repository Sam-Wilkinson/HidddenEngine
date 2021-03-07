#pragma once

#include "Command.h"

#include "GameObject.h"

class LoseLifeCommand : public Hidden::Command
{
public:
    LoseLifeCommand() = default;
    virtual ~LoseLifeCommand() = default;
    LoseLifeCommand(const LoseLifeCommand & other) = default; // copy constructor
    LoseLifeCommand(LoseLifeCommand && other) noexcept = default; // move constructor
    LoseLifeCommand& operator=(const LoseLifeCommand & other) = default; // copy assignment
    LoseLifeCommand& operator=(LoseLifeCommand && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
private:


};

