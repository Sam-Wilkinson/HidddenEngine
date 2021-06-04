#include "HiddenPCH.h"
#include "SpriteComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "ServiceLocator.h"
#include "RenderComponent.h"
#include <SDL.h>

Hidden::SpriteComponent::SpriteComponent(std::weak_ptr<RenderComponent> render, int nrRows, int nrCols, int rectWidth, int rectHeight, int startingRow, int startingCol)
	:m_RenderComponent{std::move(render)},
	m_NrRows{ nrRows }, 
	m_NrCols{ nrCols }, 
	m_ClipWidth{ rectWidth }, 
	m_ClipHeight{ rectHeight }, 
	m_Row{ startingRow }, 
	m_Col{ startingCol }, 
	m_NeedsUpdate{true}
{

}

void Hidden::SpriteComponent::SetTexture(const std::string& filename)
{
	SetTexture(Hidden::ResourceManager::GetInstance().LoadTexture(filename));
}

void Hidden::SpriteComponent::SetTexture(const std::shared_ptr<Texture2D>& texture)
{
	m_Texture = texture;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::Update()
{
	if (m_NeedsUpdate)
	{
		auto shrdRender = m_RenderComponent.lock();

		shrdRender->SetTexture(m_Texture);

		SDL_Rect srcRect{ m_ClipWidth * m_Col, m_ClipHeight * m_Row, m_ClipWidth, m_ClipHeight};

		shrdRender->SetSourceRect(srcRect);



		m_NeedsUpdate = false;
	}
}

void Hidden::SpriteComponent::Render() const
{
	Hidden::Transform location{ m_pParent.lock()->GetTransform() };

	int srcX{m_ClipWidth * m_Col};
	int srcY{m_ClipHeight * m_Row};

	Renderer::GetInstance().RenderTexture(*m_Texture, static_cast<int>(location.GetPosition().x), static_cast<int>(location.GetPosition().y), m_ClipWidth, m_ClipHeight, srcX, srcY, m_ClipWidth, m_ClipHeight );
}

void Hidden::SpriteComponent::SetNrRows(int nrRows)
{
	m_NrRows = nrRows;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::SetNrCols(int nrCols)
{
	m_NrCols = nrCols;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::SetRow(int row)
{
	if (row > m_NrRows)
	{
		ServiceLocator::GetLoggerSystem().LogError("void Hidden::SpriteComponent::SetRow(int row) - row > nrRows!");
		return;
	}
	m_Row = row;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::SetCol(int col)
{
	if (col > m_NrCols)
	{
		ServiceLocator::GetLoggerSystem().LogError("void Hidden::SpriteComponent::SetCol(int col) - col > nrColumns!");
		return;
	}
	m_Col = col;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::SetRectWidth(int width)
{
	m_ClipWidth = width;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::SetRectHeight(int height)
{
	m_ClipHeight = height;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::SetRect(int width, int height)
{
	SetRectWidth(width);
	SetRectHeight(height);
}

void Hidden::SpriteComponent::IncrementRow()
{
	m_Row = ++m_Row % m_NrRows;
	m_NeedsUpdate = true;
}

void Hidden::SpriteComponent::IncrementCol()
{
	m_Col = ++m_Col % m_NrCols;
	m_NeedsUpdate = true;
}

