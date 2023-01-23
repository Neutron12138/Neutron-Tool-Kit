#ifndef __NEUTRON_UTILS_BASICLOG_CPP__
#define __NEUTRON_UTILS_BASICLOG_CPP__

#include "BasicLog.hpp"

namespace ntk
{
    namespace Utils
    {
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::BasicLog() : m_auto_output(true), m_output(&std::wcout) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::BasicLog(bool auto_output) : m_auto_output(auto_output), m_output(&std::wcout) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::BasicLog(m_OutputStreamType *output) : m_auto_output(true), m_output(output) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::BasicLog(bool auto_output, m_OutputStreamType *output) : m_auto_output(auto_output), m_output(output) {}
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::BasicLog(const BasicLog &from) { *this = from; }
        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::~BasicLog() {}

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::SelfType &BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::operator=(const BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::SelfType &from)
        {
            m_items = from.m_items;
            m_auto_output = from.m_auto_output;
            m_output = from.m_output;
            return *this;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        const typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::ContainerType &BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::get_items() const
        {
            return m_items;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::SelfType &BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::set_auto_output(bool auto_output)
        {
            m_auto_output = auto_output;
            return *this;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        bool BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::is_auto_output() const
        {
            return m_auto_output;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::SelfType &BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::set_output(typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::OutputStreamType *output)
        {
            m_output = output;
            return *this;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::OutputStreamType *BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::get_output()
        {
            return m_output;
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::StringType BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::format_log(const typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::LogItemType &item)
        {
            typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::StringStreamType sstr;
            const std::tm *tm = item.get_time();
            sstr << "--------------------" << std::endl
                 << "Time:" << asctime(tm)
                 << "Level:" << get_log_level_string(item.get_level()) << std::endl
                 << "Title:" << item.get_title() << std::endl
                 << "Content:" << item.get_content() << std::endl
                 << std::endl;
            return sstr.to_string();
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::output_all()
        {
            for (size_t i = 0; i < m_items.size(); i++)
            {
                *m_output << format_log(m_items.at(i));
            }
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::clear_all()
        {
            m_items.clear();
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::log(LogLevel::LogLevel level, const m_StringType &title, const m_StringType &content)
        {
            typename BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::LogItemType item(level, title, content);
            m_items.push_back(item);
            if (m_auto_output)
                *m_output << format_log(item);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::logu(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Unknown, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::logi(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Info, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::logd(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Debug, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::logw(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Warning, title, content);
        }

        template <typename m_StringType, typename m_LogItemType, typename m_OutputStreamType, typename m_ContainerType, typename m_StringStreamType>
        void BasicLog<m_StringType, m_LogItemType, m_OutputStreamType, m_ContainerType, m_StringStreamType>::loge(const m_StringType &title, const m_StringType &content)
        {
            log(LogLevel::LogLevel::Error, title, content);
        }
    } // namespace Utils

} // namespace ntk

#endif