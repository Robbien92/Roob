#include <Roob.h>

class Sandbox : public Roob::Application {
public :
	Sandbox() {

	}

	~Sandbox() {

	}
};

Roob::Application* Roob::CreateApplication() {
	return new Sandbox();
}
