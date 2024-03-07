#include <string>
#include "GameObject.h"
#include "Component.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float /*deltaTime*/)
{
	
}

void dae::GameObject::FixedUpdate()
{
}

void dae::GameObject::Render() const
{
	for (Component* component : *m_pComponents)
	{
		component->Render();
	}
	//const auto& pos = m_transform.GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

 dae::Transform* dae::GameObject::GetTransform() 
{
	return &m_transform;
}

 void dae::GameObject::AddComponent(Component* newComponent)
 {
	 if (newComponent != nullptr)
	 {
		 m_pComponents->push_back(newComponent);
	 }
 }

 void dae::GameObject::RemoveComponent(Component* toRemoveComponent)
 {
	 if (toRemoveComponent != nullptr)
	 {
		 m_pComponents->remove(toRemoveComponent);
	 }
 }

template<typename T>
 T* dae::GameObject::GetComponent()
{
	for (Component* currentComponent: m_pComponents)
	{
		if (typeid(*currentComponent) == typeid(T))
		{
			return static_cast<T*>(currentComponent);
		}
	}
}

template<typename T>
bool dae::GameObject::HasComponent()
{
	return GetComponent<T>() != nullptr;
}
