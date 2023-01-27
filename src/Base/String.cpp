#ifndef __NEUTRON_BASE_STRING_CPP__
#define __NEUTRON_BASE_STRING_CPP__

#include "String.hpp"

namespace ntk
{
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicString() : BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType() {}
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicString(const char *str) { *this = str; }
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicString(const wchar_t *wstr) { *this = wstr; }
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicString(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType &str) { *this = str; }
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicString(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType &wstr) { *this = wstr; }
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::BasicString(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &from) { *this = from; }
    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::~BasicString() {}

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator=(const char *str)
    {
        *this = std::string(str);
        return *this;
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator=(const wchar_t *wstr)
    {
        BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType::operator=(wstr);
        return *this;
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator=(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType &str)
    {
        BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType::operator=(to_wstring(str));
        return *this;
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator=(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType &wstr)
    {
        BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType::operator=(wstr);
        return *this;
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator=(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::SelfType &from)
    {
        BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType::operator=(from);
        return *this;
    }

    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator StdStringType() const
    {
        return to_string();
    }

    BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::operator StdWStringType() const
    {
        return static_cast<typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::ParentType>(*this);
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::to_string() const
    {
        return to_string(*this);
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::to_string(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType &wstr) const
    {
        typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType result;
        for (auto iter = wstr.cbegin(); iter != wstr.cend(); iter++)
        {
            result.push_back(*iter);
        }
        return result;
    }

    typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::to_wstring(const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdStringType &str) const
    {
        typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType result;
        for (auto iter = str.cbegin(); iter != str.cend(); iter++)
        {
            result.push_back(*iter);
        }
        return result;
    }

    std::ostream &operator<<(std::ostream &os, const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>> &str)
    {
        os << str.to_string();
        return os;
    }

    std::wostream &operator<<(std::wostream &os, const BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>> &str)
    {
        os << static_cast<typename BasicString<std::char_traits<wchar_t>, std::allocator<wchar_t>>::StdWStringType>(str);
        return os;
    }
} // namespace ntk

#endif