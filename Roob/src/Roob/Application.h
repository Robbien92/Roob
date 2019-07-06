#pragma once
#include "Core.h"
#include "Window.h"
#include "Roob/LayerStack.h"
#include "Roob/Events/Event.h"
#include "Roob/Events/ApplicationEvent.h"
#include "Roob/ImGui/ImGuiLayer.h"
#include "Roob/Renderer/Shader.h"
#include "Roob/Renderer/Buffer.h"

namespace Roob {
	class ROOB_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

		std::unique_ptr<Shader> m_Shader;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
