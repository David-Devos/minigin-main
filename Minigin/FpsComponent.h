#pragma once
#include "Component.h"

namespace dae
{
	class FpsComponent : public Component
	{
	public:
		void Update(float deltaTime) override;
		void Render() const override;


		FpsComponent();
		virtual ~FpsComponent() = default;
		FpsComponent(const FpsComponent& other) = delete;
		FpsComponent(FpsComponent&& other) = delete;
		FpsComponent& operator=(const FpsComponent& other) = delete;
		FpsComponent& operator=(FpsComponent&& other) = delete;
	private:

	};

}
