#ifndef __NEUTRON_UTILS_LOGLEVEL_CPP__
#define __NEUTRON_UTILS_LOGLEVEL_CPP__

#include "LogLevel.hpp"

namespace ntk
{
    namespace Utils
    {
        std::string get_log_level_string(LogLevel::LogLevel level)
        {
            std::string result;
            switch (level)
            {
            case LogLevel::LogLevel::Unknown:
                result = "Unknown";
                break;

            case LogLevel::LogLevel::Info:
                result = "Info";
                break;

            case LogLevel::LogLevel::Debug:
                result = "Debug";
                break;

            case LogLevel::LogLevel::Warning:
                result = "Warning";
                break;

            case LogLevel::LogLevel::Error:
                result = "Error";
                break;

            default:
                result = "Undefined";
                break;
            }
            return result;
        }

        LogLevel::LogLevel get_log_level_enum(const std::string &level)
        {
            LogLevel::LogLevel result;
            if (level == "Info")
            {
                result = LogLevel::LogLevel::Info;
            }
            else if (level == "Debug")
            {
                result = LogLevel::LogLevel::Debug;
            }
            else if (level == "Warning")
            {
                result = LogLevel::LogLevel::Warning;
            }
            else if (level == "Error")
            {
                result = LogLevel::LogLevel::Error;
            }
            else
            {
                result = LogLevel::LogLevel::Unknown;
            }
            return result;
        }
    } // namespace Utils

} // namespace ntk

#endif