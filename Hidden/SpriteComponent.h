#pragma once
#include "Component.h"

namespace Hidden
{
	class Texture2D;
	class RenderComponent;
	class SpriteComponent : public Component
	{
	public:
		SpriteComponent(std::weak_ptr<RenderComponent> render,  int nrRows, int nrCols, int rectWidth = 0, int rectHeight = 0, int startingRow = 0, int startingCol = 0);
		~SpriteComponent() = default;

		void SetTexture(const std::string& filename);
		void SetTexture(const std::shared_ptr<Texture2D>& texture);

		SpriteComponent(const SpriteComponent& other) = delete;
		SpriteComponent(SpriteComponent&& other) = delete;
		SpriteComponent& operator=(const SpriteComponent& other) = delete;
		SpriteComponent& operator=(SpriteComponent&& other) = delete;

		void Update() override;
		virtual void Render() const override;

		void SetNrRows(int nrRows);
		void SetNrCols(int nrCols);
		
		void SetRow(int row);
		void SetCol(int col);

		void SetRectWidth(int width);
		void SetRectHeight(int height);
		void SetRect(int width, int height);

		void IncrementRow();
		void IncrementCol();

	private:
		std::shared_ptr<Texture2D> m_Texture;

		int m_NrRows;
		int m_NrCols;

		int m_Row;
		int m_Col;
		int m_ClipWidth;
		int m_ClipHeight;

		std::weak_ptr<RenderComponent> m_RenderComponent;

		bool m_NeedsUpdate;

	};
}


