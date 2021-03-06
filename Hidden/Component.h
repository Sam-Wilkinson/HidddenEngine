#pragma once
class Component
{
public:
	Component() = default;
	virtual ~Component() = default;

	Component(const Component& other) = default;
	Component(Component&& other) = default;
	Component& operator=(const Component& other) = default;
	Component& operator=(Component&& other) = default;

	virtual void Update() = 0;

protected:

private:

};

