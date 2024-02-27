#pragma once
#include "Transform.h"
#include "GameObject.h"
namespace dae
{
	class Component
	{
	protected:
		Component(GameObject* gameObject);
		Component() = default;

	public:
		virtual void Update(float deltaTime);
		virtual void FixedUpdate();
		virtual void Render() const = 0;

		virtual ~Component();
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;


	private:
		Transform* m_pTransform;
		GameObject* m_pGameObject;
	};
}

