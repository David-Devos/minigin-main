#pragma once
#include "Component.h"

namespace dae
{
	class RenderComponent : public Component
	{
	public:
		void Update(float deltaTime) override;
		void Render(Texture2D* texture) const;
		void Render() const override;


		RenderComponent();
		virtual ~RenderComponent() = default;
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

	private:
	};

}

