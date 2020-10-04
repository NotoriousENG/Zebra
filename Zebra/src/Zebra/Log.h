#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Zebra
{
	class ZEBRA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log macros
#define ZB_CORE_TRACE(...) ::Zebra::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZB_CORE_INFO(...) ::Zebra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZB_CORE_WARN(...) ::Zebra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZB_CORE_ERROR(...) ::Zebra::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZB_CORE_FATAL(...) ::Zebra::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define ZB_TRACE(...) ::Zebra::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZB_INFO(...) ::Zebra::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZB_WARN(...) ::Zebra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZB_ERROR(...) ::Zebra::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZB_FATAL(...) ::Zebra::Log::GetClientLogger()->fatal(__VA_ARGS__)