#include "RenderComponent.h"
#include "Renderer.h"
#include "Texture2D.h"

dae::RenderComponent::RenderComponent()
{
}
void dae::RenderComponent::Update(float /*deltaTime*/)
{

}

void dae::RenderComponent::Render(Texture2D* texture) const
{
	const auto& pos = m_pGameObject->GetTransform()->GetPosition();
	Renderer::GetInstance().RenderTexture(*texture, pos.x, pos.y);
}

void dae::RenderComponent::Render() const
{
}

