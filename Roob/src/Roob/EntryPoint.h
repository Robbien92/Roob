#pragma once

#ifdef ROOB_PLATFORM_WINDOWS

extern Roob::Application* Roob::CreateApplication();

int main(int argc, char** argv) {
	Roob::Log::Init();
	ROOB_CORE_INFO("Initialized Log!");

	auto app = Roob::CreateApplication();
	app->Run();
	delete app;
}

#endif
