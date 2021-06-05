#pragma once
#include <Command.h>
class MoveDownRightCommand : public Hidden::Command
{
public:
    MoveDownRightCommand() = default;
    virtual ~MoveDownRightCommand() = default;
    MoveDownRightCommand(const MoveDownRightCommand & other) = default; // copy constructor
    MoveDownRightCommand(MoveDownRightCommand && other) noexcept = default; // move constructor
    MoveDownRightCommand& operator=(const MoveDownRightCommand & other) = default; // copy assignment
    MoveDownRightCommand& operator=(MoveDownRightCommand && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
};

