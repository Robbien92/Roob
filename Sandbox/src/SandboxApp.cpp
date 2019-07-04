#include <Roob.h>

#include "ImGui/imgui.h"

class ExampleLayer : public Roob::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		if (Roob::Input::IsKeyPressed(ROOB_KEY_TAB))
			ROOB_TRACE("Tab pressed!");
	}

	void OnEvent(Roob::Event& event) override {
		ROOB_TRACE("{0}", event);
	}
};

class Sandbox : public Roob::Application {
public :
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {
	}
};

Roob::Application* Roob::CreateApplication() {
	return new Sandbox();
}
