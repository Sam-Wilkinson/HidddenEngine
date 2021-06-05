#pragma once
#include <Command.h>
class MoveUpRightCommand : public Hidden::Command
{
public:
    MoveUpRightCommand() = default;
    virtual ~MoveUpRightCommand() = default;
    MoveUpRightCommand(const MoveUpRightCommand & other) = default; // copy constructor
    MoveUpRightCommand(MoveUpRightCommand && other) noexcept = default; // move constructor
    MoveUpRightCommand& operator=(const MoveUpRightCommand & other) = default; // copy assignment
    MoveUpRightCommand& operator=(MoveUpRightCommand && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
};

