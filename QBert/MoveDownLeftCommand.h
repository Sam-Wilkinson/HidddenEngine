#pragma once
#include <Command.h>
class MoveDownLeftCommand : public Hidden::Command
{
public:
    MoveDownLeftCommand() = default;
    virtual ~MoveDownLeftCommand() = default;
    MoveDownLeftCommand(const MoveDownLeftCommand & other) = default; // copy constructor
    MoveDownLeftCommand(MoveDownLeftCommand && other) noexcept = default; // move constructor
    MoveDownLeftCommand& operator=(const MoveDownLeftCommand & other) = default; // copy assignment
    MoveDownLeftCommand& operator=(MoveDownLeftCommand && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
};

