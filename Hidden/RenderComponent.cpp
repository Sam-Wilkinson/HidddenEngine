#include "HiddenPCH.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Transform.h"

Hidden::RenderComponent::RenderComponent()
	:Component(), m_SizeDefined{false}, m_SourceDefined{false}
{
}

Hidden::RenderComponent::~RenderComponent()
{}

void Hidden::RenderComponent::SetTexture(const std::string& filename)
{
	SetTexture(Hidden::ResourceManager::GetInstance().LoadTexture(filename));
}

void Hidden::RenderComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_Texture = std::move(texture);

	if (!m_SizeDefined)
	{
		SDL_QueryTexture(texture->GetSDLTexture(), nullptr, nullptr, &m_DestinationSize.x, &m_DestinationSize.y);
	}
}

void Hidden::RenderComponent::SetDestinationSize(const SDL_Point& destSize)
{
	SetDestinationSize(destSize.x, destSize.y);
}

void Hidden::RenderComponent::SetDestinationSize(int width, int height)
{
	m_DestinationSize.x = width;
	m_DestinationSize.y = height;

	m_SizeDefined = true;
}

void Hidden::RenderComponent::RemoveDestinationSize()
{
	m_SizeDefined = false;
	SDL_QueryTexture(m_Texture->GetSDLTexture(), nullptr, nullptr, &m_DestinationSize.x, &m_DestinationSize.y);
}

void Hidden::RenderComponent::SetSourceRect(const SDL_Rect& srcRect)
{
	m_SourceRect = srcRect;
	m_SourceDefined = true;
}

void Hidden::RenderComponent::RemoveSourceRect()
{
	m_SizeDefined = false;
}

void Hidden::RenderComponent::Render() const
{
	SDL_Rect destination{};

	glm::vec3 location{ m_pParent.lock()->GetTransform().GetPosition() };
	destination.x = static_cast<int>(location.x) - m_DestinationSize.x / 2;
	destination.y = static_cast<int>(location.y) - m_DestinationSize.y / 2;
	destination.w = m_DestinationSize.x;
	destination.h = m_DestinationSize.y;

	if (m_SourceDefined)
	{
		Renderer::GetInstance().RenderTexture(*m_Texture, destination, m_SourceRect);
	}
	else
	{
		Renderer::GetInstance().RenderTexture(*m_Texture, destination);
	}



}

void Hidden::RenderComponent::Update()
{

}
