#pragma once
#include "Component.h"
#include "Texture2D.h"

namespace Hidden
{
	class Texture2D;
	class GameObject;
	class RenderComponent final : public Component
	{
	public:
		RenderComponent();
		~RenderComponent();

		void SetTexture(const std::string& filename);
		void SetTexture(const std::shared_ptr<Texture2D>& texture);
		void SetParentGameObject(const std::shared_ptr<GameObject>& parent);


		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Render() const;
		void Update() override;

	private:
		std::shared_ptr<Texture2D> m_Texture;
		std::weak_ptr<GameObject> m_Parent;
	};

}

