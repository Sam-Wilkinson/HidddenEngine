#include "HiddenPCH.h"
#include "Scene.h"
#include "GameObject.h"

using namespace Hidden;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<SceneObject>& object)
{
	m_Objects.push_back(object);
}

void Hidden::Scene::AddRenderable(const std::weak_ptr<RenderComponent>& renderComponent)
{
	m_Renderables.push_back(renderComponent);
}

void Hidden::Scene::Remove(const std::shared_ptr<SceneObject>& object)
{
	m_Objects.erase(std::remove(m_Objects.begin(), m_Objects.end(), object));
}

void Hidden::Scene::RemoveRenderable(const std::weak_ptr<RenderComponent>& renderComponent)
{
	int idx{};

	for (unsigned int i{}; i < m_Renderables.size() ; m_Renderables)
	{
		if (m_Renderables[i].lock() == renderComponent.lock())
		{
			idx = i;
			break;
		}
	}
	
	m_Renderables.erase(m_Renderables.begin() + idx);
}

void Scene::Update()
{
	for(auto& object : m_Objects)
	{
		object->Update();
	}
}

void Scene::Render() const
{
	for (const auto& renderable : m_Renderables)
	{
		renderable.lock()->Render();
	}
}

