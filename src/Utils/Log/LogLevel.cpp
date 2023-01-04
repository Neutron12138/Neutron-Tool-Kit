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
            case LogLevel::LogLevel::UNKNOWN:
                result = "UNKNOWN";
                break;

            case LogLevel::LogLevel::INFO:
                result = "INFO";
                break;

            case LogLevel::LogLevel::DEBUG:
                result = "DEBUG";
                break;

            case LogLevel::LogLevel::WARNING:
                result = "WARNING";
                break;

            case LogLevel::LogLevel::ERROR:
                result = "ERROR";
                break;

            default:
                result = "UNDEFINED";
                break;
            }
            return result;
        }

        LogLevel::LogLevel get_log_level_enum(const std::string& level)
        {
            LogLevel::LogLevel result;
            if (level == "INFO")
            {
                result = LogLevel::LogLevel::INFO;
            }
            else if (level == "DEBUG")
            {
                result = LogLevel::LogLevel::DEBUG;
            }
            else if (level == "WARNING")
            {
                result = LogLevel::LogLevel::WARNING;
            }
            else if (level == "ERROR")
            {
                result = LogLevel::LogLevel::ERROR;
            }
            else
            {
                result = LogLevel::LogLevel::UNKNOWN;
            }
            return result;
        }
    } // namespace Utils

} // namespace ntk

#endif