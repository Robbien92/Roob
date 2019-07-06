#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Roob {
	class ROOB_API Log {
	public:
		static void Init(); 

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ROOB_CORE_TRACE(...) ::Roob::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ROOB_CORE_INFO(...) ::Roob::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ROOB_CORE_WARN(...) ::Roob::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ROOB_CORE_ERROR(...) ::Roob::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ROOB_CORE_CRITICAL(...) ::Roob::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ROOB_TRACE(...) ::Roob::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ROOB_INFO(...) ::Roob::Log::GetClientLogger()->info(__VA_ARGS__)
#define ROOB_WARN(...) ::Roob::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ROOB_ERROR(...) ::Roob::Log::GetClientLogger()->error(__VA_ARGS__)
#define ROOB_CRITICAL(...) ::Roob::Log::GetClientLogger()->critical(__VA_ARGS__)
