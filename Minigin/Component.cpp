#include "Component.h"

dae::Component::Component(GameObject* gameObject) : m_pGameObject{gameObject}
{
	m_pTransform = m_pGameObject->GetTransform();
}

dae::Component::~Component( )
{
}

void dae::Component::Update(float /*deltaTime*/)
{
}

void dae::Component::FixedUpdate()
{
}
