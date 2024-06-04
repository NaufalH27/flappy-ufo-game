#pragma once

#include <memory>
#include "spdlog/spdlog.h"



class Log
{
private:
	static std::shared_ptr<spdlog::logger> s_ClientLogger;

public:
	static void init();

	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


};


#define HM_CLIENT_ERROR(...) ::Log::GetClientLogger()->error(__VA_ARGS__)
#define HM_CLIENT_INFO(...) ::Log::GetClientLogger()->info(__VA_ARGS__)
#define HM_CLIENT_WARN(...) ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HM_CLIENT_TRACE(...) ::Log::GetClientLogger()->trace(__VA_ARGS__)
