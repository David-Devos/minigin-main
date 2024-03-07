#pragma once
#include <string>
#include <sstream>
#include <memory>
#include "Component.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class RenderComponent;
	class TextComponent final : public Component
	{
	public:
		void Update(float deltaTime) override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);

		TextComponent(const std::string& text, std::shared_ptr<Font> font, GameObject* gameObject);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;
		Transform m_transform{};
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
		RenderComponent* m_pRenderComponent{ nullptr };
	};
}
