#pragma once
#include "Component.h"
#include "TextComponent.h"

namespace Hidden
{
	
	class FPSComponent final : public Component
	{
	public:
		FPSComponent(const std::weak_ptr<TextComponent> textComponent);
		~FPSComponent() = default;
		
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;

		void Update() override;

	private:
		float m_TotalTime;
		float m_FPS;
		std::weak_ptr<TextComponent> m_TextComponent;
	};
}
