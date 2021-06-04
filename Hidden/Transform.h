#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/glm.hpp>
#pragma warning(pop)

namespace Hidden
{
	class Transform final
	{
	public:


		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
		void SetPosition(float x, float y);
		void MovePosition(float x, float y, float z);
		void MovePosition(float x, float y);

	private:
		glm::vec3 m_Position;
	};
}
