#ifndef __NEUTRON_UTILS_LOG_HPP__
#define __NEUTRON_UTILS_LOG_HPP__

#include <vector>
#include <iostream>
#include "LogItem.hpp"

namespace ntk
{
    namespace Utils
    {
        /// @brief 日志输出器
        class Log : public Object
        {
        private:
            /// @brief 日志的项目
            std::vector<LogItem> m_items;

            /// @brief 是否自动输出
            bool m_auto_output;

            /// @brief 输出流
            std::ostream *m_output;

        public:
            Log();
            Log(bool auto_output);
            Log(std::ostream *output);
            Log(bool auto_output, std::ostream *output);
            Log(const Log &from);
            ~Log();

        public:
            Log &operator=(const Log &from);

        public:
            /// @brief 获取所有日志
            /// @return 日志项目的容器
            const std::vector<LogItem> &get_items() const;

            /// @brief 设置自动输出
            /// @param auto_output 是否自动输出
            /// @return 本对象
            Log &set_auto_output(bool auto_output);

            /// @brief 是否自动输出
            /// @return 是否自动输出
            bool is_auto_output() const;

            /// @brief 设置输出流
            /// @param output 输出流
            /// @return 本对象
            Log &set_output(std::ostream *output);

            /// @brief 获取输出流
            /// @return 输出流
            std::ostream *get_output();

        public:
            /// @brief 格式化日志
            /// @param item 日志项目
            /// @return 格式化后的结果
            virtual std::string format_log(const LogItem &item);

            /// @brief 向输出流中输出所有日志
            virtual void output_all();

            /// @brief 清空m_items里储存的所有日志
            virtual void clear_all();

        public:
            /// @brief 输出一条日志
            /// @param level 日志的等级
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void log(LogLevel::LogLevel level, const std::string &title, const std::string &content);

            /// @brief 输出一条UNKNOWN等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logu(const std::string &title, const std::string &content);

            /// @brief 输出一条INFO等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logi(const std::string &title, const std::string &content);

            /// @brief 输出一条DEBUG等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logd(const std::string &title, const std::string &content);

            /// @brief 输出一条WARNING等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void logw(const std::string &title, const std::string &content);

            /// @brief 输出一条ERROR等级的日志
            /// @param title 日志的标题
            /// @param content 日志的内容
            virtual void loge(const std::string &title, const std::string &content);
        };

    } // namespace Utils

} // namespace ntk

#endif