#pragma once
#include <Command.h>
class ChangeSceneCommand : public Hidden::Command
{
    ChangeSceneCommand() = default;
    virtual ~ChangeSceneCommand() = default;
    ChangeSceneCommand(const ChangeSceneCommand& other) = default; // copy constructor
    ChangeSceneCommand(ChangeSceneCommand&& other) noexcept = default; // move constructor
    ChangeSceneCommand& operator=(const ChangeSceneCommand& other) = default; // copy assignment
    ChangeSceneCommand& operator=(ChangeSceneCommand&& other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
};

