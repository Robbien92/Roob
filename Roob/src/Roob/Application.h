#pragma once
#include "Core.h"

namespace Roob {
	class ROOB_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
