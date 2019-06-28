#include "roobpch.h"
#include "Application.h"

#include "Roob/Events/ApplicationEvent.h"
#include "Roob/Log.h"

namespace Roob {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}
