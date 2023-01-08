#ifndef __NEUTRON_UTILS_LOGITEM_CPP__
#define __NEUTRON_UTILS_LOGITEM_CPP__

#include "LogItem.hpp"

namespace ntk
{
    namespace Utils
    {
        LogItem::LogItem(LogLevel::LogLevel level, std::string title, std::string content) : m_level(level), m_title(title), m_content(content)
        {
            time_t now = time(nullptr);
            m_time = localtime(&now);
        }

        LogItem::LogItem(const LogItem &from) { *this = from; }

        LogItem::~LogItem() {}

        LogItem &LogItem::operator=(const LogItem &from)
        {
            m_time = from.m_time;
            m_level = from.m_level;
            m_title = from.m_title;
            m_content = from.m_content;
            return *this;
        }

        const std::tm *LogItem::get_time() const
        {
            return m_time;
        }

        LogLevel::LogLevel LogItem::get_level() const
        {
            return m_level;
        }

        const std::string &LogItem::get_title() const
        {
            return m_title;
        }

        const std::string &LogItem::get_content() const
        {
            return m_content;
        }
    } // namespace Utils

} // namespace ntk

#endif