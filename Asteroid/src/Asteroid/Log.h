#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Asteroid {

	class ASTEROID_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	
};

//Core log macros
#define AS_CORE_TRACE(...) ::Asteroid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AS_CORE_INFO(...)  ::Asteroid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AS_CORE_WARN(...)  ::Asteroid::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AS_CORE_ERROR(...) ::Asteroid::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AS_CORE_FATAL(...) ::Asteroid::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define AS_TRACE(...)      ::Asteroid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AS_INFO(...)       ::Asteroid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AS_WARN(...)       ::Asteroid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_ERROR(...)      ::Asteroid::Log::GetClientLogger()->error(__VA_ARGS__)
#define AS_FATAL(...)      ::Asteroid::Log::GetClientLogger()->fatal(__VA_ARGS__)