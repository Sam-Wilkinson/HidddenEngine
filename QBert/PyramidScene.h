#pragma once
#include <Scene.h>
#include "SpriteComponent.h"

class PyramidScene final : public Hidden::Scene
{
public:
	PyramidScene();
	~PyramidScene() = default;

	void Initialize() override;
	void Update() override;
	void Render() const override;

private:

	size_t m_PyramidHeight;
	std::vector<std::shared_ptr<Hidden::GameObject>> m_Pyramid;
	std::shared_ptr<Hidden::GameObject> m_Tile;

	float m_PyramidTopX;
	float m_PyramidTopY;
	int m_TileSize;

	void CreateTiles();

};

