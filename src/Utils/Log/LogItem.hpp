#ifndef __NEUTRON_UTILS_LOGITEM_HPP__
#define __NEUTRON_UTILS_LOGITEM_HPP__

#include <ctime>
#include "LogLevel.hpp"
#include "../../Base/Object.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 日志项目
        class LogItem : public Object
        {
        private:
            /// @brief 时间
            std::tm *m_time;

            /// @brief 等级
            LogLevel::LogLevel m_level;

            /// @brief 标题
            std::string m_title;

            /// @brief 内容
            std::string m_content;

        public:
            LogItem(LogLevel::LogLevel level, std::string title, std::string content);
            LogItem(const LogItem &from);
            ~LogItem();

        public:
            LogItem &operator=(const LogItem &from);

        public:
            /// @brief 获取日志的时间
            /// @return 日志的时间
            const std::tm *get_time() const;

            /// @brief 获取日志的等级
            /// @return 日志的等级
            LogLevel::LogLevel get_level() const;

            /// @brief 获取日志的标题
            /// @return 日志的标题
            const std::string &get_title() const;

            /// @brief 获取日志的内容
            /// @return 日志的内容
            const std::string &get_content() const;
        };
    } // namespace Utils

} // namespace ntk

#endif