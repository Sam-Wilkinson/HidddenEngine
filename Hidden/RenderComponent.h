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

		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Update() override;
		virtual void Render() const override;


	private:
		std::shared_ptr<Texture2D> m_Texture;
	};

}

