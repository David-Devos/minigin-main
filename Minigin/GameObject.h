#pragma once
#include <memory>
#include "Transform.h"
#include <string>
#include <list>

namespace dae
{
	class Texture2D;
	class Component;

	class GameObject final
	{
	public:
		void Update(float deltaTime);
		void FixedUpdate();
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
		Transform* GetTransform();
		void AddComponent(Component* newComponent);
		void RemoveComponent(Component* toRemoveComponent);
		template<typename T>
		const T* GetComponent();
		template<typename T>
		bool HasComponent();

		GameObject() = default;
		 ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};
		std::list<Component*>* m_pComponents = new std::list<Component*>;
	};
}
