#pragma once

#include "Roob/Layer.h"
#include "Roob/Events/KeyEvent.h"
#include "Roob/Events/MouseEvent.h"
#include "Roob/Events/ApplicationEvent.h"

namespace Roob {
	class ROOB_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}
