#include <Roob.h>

class ExampleLayer : public Roob::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
	}

	void OnEvent(Roob::Event& event) override {
		ROOB_TRACE("{0}", event);
	}
};

class Sandbox : public Roob::Application {
public :
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Roob::ImGuiLayer());
	}

	~Sandbox() {
	}
};

Roob::Application* Roob::CreateApplication() {
	return new Sandbox();
}
