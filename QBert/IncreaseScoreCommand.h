#pragma once
#include <Command.h>
class IncreaseScoreCommand : public Hidden::Command
{
    IncreaseScoreCommand() = default;
    virtual ~IncreaseScoreCommand() = default;
    IncreaseScoreCommand(const IncreaseScoreCommand& other) = default; // copy constructor
    IncreaseScoreCommand(IncreaseScoreCommand&& other) noexcept = default; // move constructor
    IncreaseScoreCommand& operator=(const IncreaseScoreCommand& other) = default; // copy assignment
    IncreaseScoreCommand& operator=(IncreaseScoreCommand&& other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
private:
};

