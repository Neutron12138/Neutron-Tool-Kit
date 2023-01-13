#ifndef __NEUTRON_UTILS_LOGITEM_CPP__
#define __NEUTRON_UTILS_LOGITEM_CPP__

#include "LogItem.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_StringType>
        LogItem<m_StringType>::LogItem(LogLevel::LogLevel level, const LogItem<m_StringType>::StringType &title, const LogItem<m_StringType>::StringType &content) : m_level(level), m_title(title), m_content(content)
        {
            time_t now = time(nullptr);
            m_time = localtime(&now);
        }

        template <typename m_StringType>
        LogItem<m_StringType>::LogItem(const LogItem<m_StringType>::SelfType &from) { *this = from; }
        template <typename m_StringType>
        LogItem<m_StringType>::~LogItem() {}

        template <typename m_StringType>
        LogItem<m_StringType>::SelfType &LogItem<m_StringType>::operator=(const LogItem<m_StringType>::SelfType &from)
        {
            m_time = from.m_time;
            m_level = from.m_level;
            m_title = from.m_title;
            m_content = from.m_content;
            return *this;
        }

        template <typename m_StringType>
        const std::tm *LogItem<m_StringType>::get_time() const
        {
            return m_time;
        }

        template <typename m_StringType>
        LogLevel::LogLevel LogItem<m_StringType>::get_level() const
        {
            return m_level;
        }

        template <typename m_StringType>
        const LogItem<m_StringType>::StringType &LogItem<m_StringType>::get_title() const
        {
            return m_title;
        }

        template <typename m_StringType>
        const LogItem<m_StringType>::StringType &LogItem<m_StringType>::get_content() const
        {
            return m_content;
        }
    } // namespace Utils

} // namespace ntk

#endif