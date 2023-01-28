#ifndef __NEUTRON_BASE_BASICSTRING_HPP__
#define __NEUTRON_BASE_BASICSTRING_HPP__

#include <string>
#include "Object.hpp"

namespace ntk
{
    /// @brief 字符串对象，继承自std::basic_string。其中_CharT为wchar_t
    /// @tparam m_TraitsType 字符特性类型，默认为std::char_traits<wchar_t>
    /// @tparam m_AllocatorType 分配器类型，默认为std::allocator<wchar_t>
    template <typename m_TraitsType = std::char_traits<wchar_t>, typename m_AllocatorType = std::allocator<wchar_t>>
    class BasicString : public Object, public std::basic_string<wchar_t, m_TraitsType, m_AllocatorType>
    {
    public:
        /// @brief 字符类型
        using CharType = wchar_t;
        /// @brief 字符特性类型
        using TraitsType = m_TraitsType;
        /// @brief 分配器类型
        using AllocatorType = m_AllocatorType;
        /// @brief STL单字节字符串类型
        using StdStringType = std::basic_string<char, TraitsType, AllocatorType>;
        /// @brief STL宽字符字符串类型
        using StdWStringType = std::basic_string<wchar_t, TraitsType, AllocatorType>;
        /// @brief 本对象类型的STL父级类型
        using ParentType = StdWStringType;
        /// @brief 本对象类型
        using SelfType = BasicString<TraitsType, AllocatorType>;

    public:
        BasicString() = default;
        BasicString(const char *str);
        BasicString(const wchar_t *wstr);
        BasicString(const StdStringType &str);
        BasicString(const StdWStringType &wstr);
        BasicString(const SelfType &from) = default;
        ~BasicString() = default;

    public:
        SelfType &operator=(const char *str);
        SelfType &operator=(const wchar_t *wstr);
        SelfType &operator=(const StdStringType &str);
        SelfType &operator=(const StdWStringType &wstr);
        SelfType &operator=(const SelfType &from) = default;

        operator StdStringType() const;

    public:
        /// @brief 把本对象转换为单字节字符串
        /// @return 单字节字符串
        StdStringType to_string() const;

        /// @brief 把宽字符字符串转换为单字节字符串
        /// @param wstr 宽字符字符串
        /// @return 单字节字符串
        virtual StdStringType to_string(const StdWStringType &wstr) const;

        /// @brief 把单字节字符串转换为宽字符字符串
        /// @param str 单字节字符串
        /// @return 宽字符字符串
        virtual StdWStringType to_wstring(const StdStringType &str) const;
    };

    template <typename m_TraitsType, typename m_AllocatorType>
    std::basic_ostream<char, m_TraitsType> &operator<<(std::basic_ostream<char, m_TraitsType> &os, const BasicString<m_TraitsType, m_AllocatorType> &str);
    template <typename m_TraitsType, typename m_AllocatorType>
    std::basic_ostream<wchar_t, m_TraitsType> &operator<<(std::basic_ostream<wchar_t, m_TraitsType> &os, const BasicString<m_TraitsType, m_AllocatorType> &str);
} // namespace ntk

#endif