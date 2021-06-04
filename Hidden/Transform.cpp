#include "HiddenPCH.h"
#include "Transform.h"

void Hidden::Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void Hidden::Transform::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Hidden::Transform::MovePosition(float x, float y, float z)
{
	m_Position += glm::vec3(x, y, z);
}

void Hidden::Transform::MovePosition(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}
