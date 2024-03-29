#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "FpsComponent.h"
#include "TextComponent.h"
#include "RenderComponent.h"
#include "Scene.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::GameObject>();
	dae::RenderComponent* pRenderComponent = new dae::RenderComponent{};
	to->AddComponent(pRenderComponent);
	dae::TextComponent* pTextComponent = new dae::TextComponent{ "Programming 4 Assignment", font, to.get()};
	dae::FpsComponent* pFpsComponent = new dae::FpsComponent{pTextComponent};
	to->AddComponent(pFpsComponent);
	to->AddComponent(pTextComponent);
	to->SetPosition(80, 20);
	scene.Add(to);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}