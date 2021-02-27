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

