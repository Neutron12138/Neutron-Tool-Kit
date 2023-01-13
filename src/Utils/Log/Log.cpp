#ifndef __NEUTRON_UTILS_LOG_CPP__
#define __NEUTRON_UTILS_LOG_CPP__

#include <sstream>
#include "Log.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::Log() : m_auto_output(true), m_output(&std::wcout) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::Log(bool auto_output) : m_auto_output(auto_output), m_output(&std::wcout) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::Log(m_OutputStreamType *output) : m_auto_output(true), m_output(output) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::Log(bool auto_output, m_OutputStreamType *output) : m_auto_output(auto_output), m_output(output) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::Log(const Log &from) { *this = from; }
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::~Log() {}

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::SelfType &Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::operator=(const Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType> &from)
        {
            m_items = from.m_items;
            m_auto_output = from.m_auto_output;
            m_output = from.m_output;
            return *this;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        const m_ContainerType &Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::get_items() const
        {
            return m_items;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::SelfType &Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::set_auto_output(bool auto_output)
        {
            m_auto_output = auto_output;
            return *this;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        bool Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::is_auto_output() const
        {
            return m_auto_output;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType> &Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::set_output(m_OutputStreamType *output)
        {
            m_output = output;
            return *this;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        m_OutputStreamType *Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::get_output()
        {
            return m_output;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        m_StringType Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::format_log(const m_LogItemType &item)
        {
            m_StringTypestream sstr;
            const std::tm *tm = item.get_time();
            sstr << "--------------------" << std::endl
                 << "Time:" << asctime(tm)
                 << "Level:" << get_log_level_string(item.get_level()) << std::endl
                 << "Title:" << item.get_title() << std::endl
                 << "Content:" << item.get_content() << std::endl
                 << std::endl;
            return sstr.str();
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::output_all()
        {
            for (size_t i = 0; i < m_items.size(); i++)
            {
                *m_output << format_log(m_items.at(i));
            }
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::clear_all()
        {
            m_items.clear();
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::log(LogLevel::LogLevel level, const m_StringType &title, const m_StringType &content)
        {
            typename Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::LogItemType item(level, title, content);
            m_items.push_back(item);
            if (m_auto_output)
                *m_output << format_log(item);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::logu(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Unknown, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::logi(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Info, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::logd(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Debug, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::logw(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Warning, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType>
        void Log<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType>::loge(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Error, title, content);
        }
    } // namespace Utils

} // namespace ntk

#endif