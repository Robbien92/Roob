#include "roobpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Roob {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			ROOB_CORE_ASSERT(false, "RendererAPI:: None is currently not supported!");
			return nullptr;
			break;

		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
			break;
		}

		ROOB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			ROOB_CORE_ASSERT(false, "RendererAPI:: None is currently not supported!");
			return nullptr;
			break;

		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
			break;
		}

		ROOB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}