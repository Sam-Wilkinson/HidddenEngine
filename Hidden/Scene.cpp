#include "HiddenPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "ServiceLocator.h"
#include <algorithm>

using namespace Hidden;

Scene::Scene(const std::string& name) : m_Name(name)
{
	
}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
}

void Hidden::Scene::AddRenderable(const std::weak_ptr<RenderComponent>& renderComponent)
{
	m_Renderables.push_back(renderComponent);
}

void Hidden::Scene::Remove(const GameObject& object)
{

	auto it = std::find_if(m_Objects.begin(), m_Objects.end(), [&object](std::shared_ptr<GameObject> obj)
		{
			return &object == obj.get();
		});

	if(it == m_Objects.end())
	{
		ServiceLocator::GetLoggerSystem().LogWarning("Scene::Remove(const SceneObject& object) - SceneObject was not found inside Scene!");
		return;
	}
	m_Objects.erase(it);
}

void Hidden::Scene::RemoveRenderable(const Component& renderComponent)
{
	auto it = std::find_if(m_Renderables.begin(), m_Renderables.end(), [&renderComponent](std::weak_ptr<Component> obj)
		{
			return &renderComponent == obj.lock().get();
		});

	if (it == m_Renderables.end())
	{
		ServiceLocator::GetLoggerSystem().LogWarning("Scene::RemoveRenderable(const RenderComponent& renderComponent) - renderComponent was not found inside Scene renderables!");
		return;
	}
	m_Renderables.erase(it);
}

void Hidden::Scene::RefreshRenderables()
{	
	//TODO sort renderables
	std::sort(m_Renderables.begin(), m_Renderables.end(), [](std::weak_ptr<Component> lhs, std::weak_ptr<Component> rhs) 
		{

			return lhs.lock()->GetParentGameObject().lock()->GetTransform().GetPosition().z > rhs.lock()->GetParentGameObject().lock()->GetTransform().GetPosition().z;
		});
}

const std::string& Hidden::Scene::GetName()
{
	return m_Name;
}

void Hidden::Scene::RootInitialize()
{
	Initialize();
}

void Hidden::Scene::RootUpdate()
{
	for (auto go : m_Objects)
	{
		if (go->GetIsActive())
		{
			go->Update();
		}
	}
	Update();

	RefreshRenderables();
}

void Hidden::Scene::RootRender() const
{
	for (auto render : m_Renderables)
	{
		auto shrdRender = render.lock();

		if (shrdRender->GetParentGameObject().lock()->GetIsActive())
		{
			shrdRender->Render();
		}
	}
	Render();
}

