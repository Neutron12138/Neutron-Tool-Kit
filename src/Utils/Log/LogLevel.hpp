#ifndef __NEUTRON_UTILS_LOGLEVEL_HPP__
#define __NEUTRON_UTILS_LOGLEVEL_HPP__

#include <string>

namespace ntk
{
    namespace Utils
    {
        /// @brief 日志等级枚举的命名空间
        namespace LogLevel
        {
            /// @brief 日志等级的枚举
            enum LogLevel
            {
                /// @brief 未知等级
                Unknown = 0,

                /// @brief 信息
                Info,

                /// @brief 调试信息
                Debug,

                /// @brief 警告
                Warning,

                /// @brief 错误
                Error,

                /// @brief 总数
                Count,
            };
        } // namespace LogLevel

        /// @brief 通过LogLevel获取字符串
        /// @param level 日志等级的枚举
        /// @return 日志等级的字符串
        std::string get_log_level_string(LogLevel::LogLevel level);

        /// @brief 通过字符串获取LogLevel
        /// @param level 日志等级的字符串
        /// @return 日志等级的枚举
        LogLevel::LogLevel get_log_level_enum(const std::string& level);

    } // namespace Utils

} // namespace ntk

#endif