#pragma once

namespace Hidden
{
	class GameObject;

	class Component
	{
	public:
		Component(std::weak_ptr<GameObject> pParent);
		virtual ~Component() = default;

		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		virtual void Update() = 0;
		void SetParentGameObject(const std::shared_ptr<GameObject>& parent);
		std::weak_ptr<GameObject> GetParentGameObject() const;

	protected:
		std::weak_ptr<GameObject> m_pParent;

	private:
	};

}

