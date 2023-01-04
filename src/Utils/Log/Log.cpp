#ifndef __NEUTRON_UTILS_LOG_CPP__
#define __NEUTRON_UTILS_LOG_CPP__

#include <sstream>
#include "Log.hpp"

namespace ntk
{
    namespace Utils
    {
        Log::Log() : m_auto_output(true), m_output(&std::cout) {}
        Log::Log(bool auto_output) : m_auto_output(auto_output), m_output(&std::cout) {}
        Log::Log(std::ostream *output) : m_auto_output(true), m_output(output) {}
        Log::Log(bool auto_output, std::ostream *output) : m_auto_output(auto_output), m_output(output) {}
        Log::Log(const Log &from) { *this = from; }
        Log::~Log() {}

        Log &Log::operator=(const Log &from)
        {
            m_items = from.m_items;
            m_auto_output = from.m_auto_output;
            m_output = from.m_output;
            return *this;
        }

        const std::vector<LogItem> &Log::get_items() const
        {
            return m_items;
        }

        Log &Log::set_auto_output(bool auto_output)
        {
            m_auto_output = auto_output;
            return *this;
        }

        bool Log::is_auto_output() const
        {
            return m_auto_output;
        }

        Log &Log::set_output(std::ostream *output)
        {
            m_output = output;
            return *this;
        }

        std::ostream *Log::get_output()
        {
            return m_output;
        }

        std::string Log::format_log(const LogItem &item)
        {
            std::stringstream sstr;
            const std::tm *tm = item.get_time();
            sstr << "--------------------" << std::endl
                 << "Time:" << asctime(tm)
                 << "Level:" << get_log_level_string(item.get_level()) << std::endl
                 << "Title:" << item.get_title() << std::endl
                 << "Content:" << item.get_content() << std::endl
                 << std::endl;
            return sstr.str();
        }

        void Log::output_all()
        {
            for (size_t i = 0; i < m_items.size(); i++)
            {
                *m_output << format_log(m_items.at(i));
            }
        }

        void Log::clear_all()
        {
            m_items.clear();
        }

        void Log::log(LogLevel::LogLevel level, const std::string &title, const std::string &content)
        {
            LogItem item(level, title, content);
            m_items.push_back(item);
            if (m_auto_output)
                *m_output << format_log(item);
        }

        void Log::logu(const std::string &title, const std::string &content)
        {
            log(LogLevel::LogLevel::UNKNOWN, title, content);
        }

        void Log::logi(const std::string &title, const std::string &content)
        {
            log(LogLevel::LogLevel::INFO, title, content);
        }

        void Log::logd(const std::string &title, const std::string &content)
        {
            log(LogLevel::LogLevel::DEBUG, title, content);
        }

        void Log::logw(const std::string &title, const std::string &content)
        {
            log(LogLevel::LogLevel::WARNING, title, content);
        }

        void Log::loge(const std::string &title, const std::string &content)
        {
            log(LogLevel::LogLevel::ERROR, title, content);
        }
    } // namespace Utils

} // namespace ntk

#endif