#pragma once
#include "Core.h"
#include "Window.h"
#include "Roob/LayerStack.h"
#include "Roob/Events/Event.h"
#include "Roob/Events/ApplicationEvent.h"
#include "Roob/ImGui/ImGuiLayer.h"
#include "Roob/Renderer/Shader.h"
#include "Roob/Renderer/VertexArray.h"

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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<Shader> m_BlueShader;

		std::shared_ptr<VertexArray> m_TriangleVA;
		std::shared_ptr<VertexArray> m_SquareVA;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
