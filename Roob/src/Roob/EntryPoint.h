#pragma once

#ifdef ROOB_PLATFORM_WINDOWS

extern Roob::Application* Roob::CreateApplication();

int main(int argc, char** argv) {
	auto app = Roob::CreateApplication();
	app->Run();
	delete app;
}

#endif
