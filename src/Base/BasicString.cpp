#ifndef __NEUTRON_BASE_BASICSTRING_CPP__
#define __NEUTRON_BASE_BASICSTRING_CPP__

#include "BasicString.hpp"

namespace ntk
{
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::BasicString() : BasicString<m_TraitsType, m_AllocatorType>::ParentType() {}
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::BasicString(const char *str) { *this = str; }
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::BasicString(const wchar_t *wstr) { *this = wstr; }
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::BasicString(const BasicString<m_TraitsType, m_AllocatorType>::StdStringType &str) { *this = str; }
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::BasicString(const BasicString<m_TraitsType, m_AllocatorType>::StdWStringType &wstr) { *this = wstr; }
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::BasicString(const BasicString<m_TraitsType, m_AllocatorType>::SelfType &from) { *this = from; }
    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::~BasicString() {}

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::SelfType &BasicString<m_TraitsType, m_AllocatorType>::operator=(const char *str)
    {
        *this = std::string(str);
        return *this;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::SelfType &BasicString<m_TraitsType, m_AllocatorType>::operator=(const wchar_t *wstr)
    {
        BasicString<m_TraitsType, m_AllocatorType>::ParentType::operator=(wstr);
        return *this;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::SelfType &BasicString<m_TraitsType, m_AllocatorType>::operator=(const BasicString<m_TraitsType, m_AllocatorType>::StdStringType &str)
    {
        BasicString<m_TraitsType, m_AllocatorType>::ParentType::operator=(to_wstring(str));
        return *this;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::SelfType &BasicString<m_TraitsType, m_AllocatorType>::operator=(const BasicString<m_TraitsType, m_AllocatorType>::StdWStringType &wstr)
    {
        BasicString<m_TraitsType, m_AllocatorType>::ParentType::operator=(wstr);
        return *this;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::SelfType &BasicString<m_TraitsType, m_AllocatorType>::operator=(const BasicString<m_TraitsType, m_AllocatorType>::SelfType &from)
    {
        BasicString<m_TraitsType, m_AllocatorType>::ParentType::operator=(from);
        return *this;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::operator StdStringType() const
    {
        return to_string;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    BasicString<m_TraitsType, m_AllocatorType>::operator StdWStringType() const
    {
        return static_cast<typename BasicString<m_TraitsType, m_AllocatorType>::ParentType>(*this);
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::StdStringType BasicString<m_TraitsType, m_AllocatorType>::to_string() const
    {
        return to_string(*this);
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::StdStringType BasicString<m_TraitsType, m_AllocatorType>::to_string(const BasicString<m_TraitsType, m_AllocatorType>::StdWStringType &wstr) const
    {
        typename BasicString<m_TraitsType, m_AllocatorType>::StdStringType result;
        for (auto iter = wstr.cbegin(); iter != wstr.cend(); iter++)
        {
            result.push_back(*iter);
        }
        return result;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    typename BasicString<m_TraitsType, m_AllocatorType>::StdWStringType BasicString<m_TraitsType, m_AllocatorType>::to_wstring(const BasicString<m_TraitsType, m_AllocatorType>::StdStringType &str) const
    {
        typename BasicString<m_TraitsType, m_AllocatorType>::StdWStringType result;
        for (auto iter = str.cbegin(); iter != str.cend(); iter++)
        {
            result.push_back(*iter);
        }
        return result;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    std::basic_ostream<char, m_TraitsType> &operator<<(std::basic_ostream<char, m_TraitsType> &os, const BasicString<m_TraitsType, m_AllocatorType> &str)
    {
        os << str.to_string();
        return os;
    }

    template <typename m_TraitsType, typename m_AllocatorType>
    std::basic_ostream<wchar_t, m_TraitsType> &operator<<(std::basic_ostream<wchar_t, m_TraitsType> &os, const BasicString<m_TraitsType, m_AllocatorType> &str)
    {
        os << static_cast<typename BasicString<m_TraitsType, m_AllocatorType>::StdWStringType>(str);
        return os;
    }
} // namespace ntk

#endif