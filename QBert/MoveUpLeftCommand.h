#pragma once
#include "QBertPCH.h"
#include "Command.h"

class MoveUpLeftCommand final : public Hidden::Command
{
public:
    MoveUpLeftCommand() = default;
    virtual ~MoveUpLeftCommand() = default;
    MoveUpLeftCommand(const MoveUpLeftCommand & other) = default; // copy constructor
    MoveUpLeftCommand(MoveUpLeftCommand && other) noexcept = default; // move constructor
    MoveUpLeftCommand& operator=(const MoveUpLeftCommand & other) = default; // copy assignment
    MoveUpLeftCommand& operator=(MoveUpLeftCommand && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
private:

};