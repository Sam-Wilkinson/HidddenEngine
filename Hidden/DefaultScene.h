#pragma once
#include "Scene.h"

namespace Hidden
{
	class DefaultScene : public Scene
	{
	public:
		DefaultScene();
		~DefaultScene() = default;

		void Initialize() override;
		void Update() override;
		void Render() const override;
	};
}


