#pragma once
#include <Command.h>
class IncrementSprite : public  Hidden::Command
{
public:
    IncrementSprite() = default;
    virtual ~IncrementSprite() = default;
    IncrementSprite(const IncrementSprite & other) = default; // copy constructor
    IncrementSprite(IncrementSprite && other) noexcept = default; // move constructor
    IncrementSprite& operator=(const IncrementSprite & other) = default; // copy assignment
    IncrementSprite& operator=(IncrementSprite && other) noexcept = default; // move assignment
    // Inherited via Command
    int execute(std::shared_ptr<Hidden::GameObject> pGameObject) override;
};

