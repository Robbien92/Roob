#include "roobpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Roob {
	VertexArray* VertexArray::Create() {
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			ROOB_CORE_ASSERT(false, "RendererAPI:: None is currently not supported!");
			return nullptr;
			break;

		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
			break;
		}

		ROOB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}