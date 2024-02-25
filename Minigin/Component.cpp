#include "Component.h"

dae::Component::Component(GameObject* gameObject) : m_GameObject{gameObject}
{
	m_Transform = m_GameObject->GetTransform();
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
