#include "roobpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Roob {
	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle)
		: m_WindowHandle(windowHandle) {
		ROOB_CORE_ASSERT(windowHandle, "Window Handle is null!");
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ROOB_CORE_ASSERT(status, "Failed to initialize glad!");

		ROOB_CORE_INFO("OpenGL Info:");
		ROOB_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ROOB_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ROOB_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandle);
	}
}